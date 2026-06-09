#include <driver/i2s.h>
#include <soc/rtc.h>
#include <math.h>
#include <Wire.h>
#include "RTClib.h"

#include "vector_assets.h"
#include "vector_font.h"

//===============================DMA CONFIG=====================================
#define I2S_NUM           I2S_NUM_0                                             
#define SAMPLE_RATE       286000 // Higher = higher refresh frequency           
#define MAX_POINTS        5000   // Maximum points per buffer frame             
#define TARGET_POINTS     5000   // Target points (for fixed framerate)         
int pointCount = 0;                                                             
//==============================================================================



//===============================DUAL CORE CONFIG===============================
uint32_t bufferA[MAX_POINTS];                                                   
uint32_t bufferB[MAX_POINTS];

uint32_t* backBuffer = bufferA;  // Buffer being drawn to
uint32_t* frontBuffer = bufferB; // Buffer being displayed
int backBufferCount = 0;
int frontBufferCount = 0;

volatile bool swapReady = false;
SemaphoreHandle_t bufferMutex;
//==============================================================================



//==================================MISC========================================
int buttonPin = 14;        // Button 1 pin
int buttonPin1 = 14;       // Button 2 pin
bool oldButtonVal = HIGH;  // 
int nPatterns = 12;        // Number of all clock faces
int clockPattern = 1;      // Start clock face

#define MUX_PIN 5              // Multiplexer selec pin
#define HUB_RADIUS 7           // Hands Hub radius
#define FONT_NATIVE_HEIGHT 21  // Hershey font true size
//==============================================================================



//===========================SECOND COUNT=======================================
static int lastSeen = 0;
volatile int secondsCounter = 0;
volatile int msCounter = 0;
hw_timer_t * timer = NULL;

void IRAM_ATTR onTimer() {
  msCounter++;
  
  if (msCounter >= 1000) {
    msCounter = 0;
    secondsCounter++; 
  }
}
//==============================================================================



//==================================USER========================================
TwoWire I2Ctwo = TwoWire(1); 
RTC_DS3231 rtc;

int h = 0, m = 0, s = 0, digith = 0;  // Default time
int day = 1, month = 1, year = 2026;
float temperature;

String customText = "MAKER CLOCK";    // Label
//==============================================================================



//==================================DOT=========================================
int lastX_raw = 128;
int lastY_raw = 128;

inline void Dot(int x, int y) {
  if (backBufferCount < MAX_POINTS) {
    lastX_raw = x;
    lastY_raw = y;

    uint8_t dacX = (uint8_t)(255-x); 
    uint8_t dacY = (uint8_t)(255-y);

    uint32_t sample = ((uint16_t)dacY << 8) << 16 | ((uint16_t)dacX << 8);
    backBuffer[backBufferCount++] = sample;
  }
}
//==============================================================================



//==================================LINE========================================
void Line(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
    int dy = -abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
    int err = dx + dy, e2;
    Dot(x1, y1);
    for (;;) {
        Dot(x1, y1);
        if (x1 == x2 && y1 == y2) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x1 += sx; }
        if (e2 <= dx) { err += dx; y1 += sy; }
    }
    Dot(x2, y2);
}

void LineClear(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
    int dy = -abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
    int err = dx + dy, e2;
    for (;;) {
        Dot(x1, y1);
        if (x1 == x2 && y1 == y2) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x1 += sx; }
        if (e2 <= dx) { err += dx; y1 += sy; }
    }
}
//==============================================================================



//=================================SETUP========================================
void setup() {

  // I2S DMA Setup
  i2s_config_t i2s_config = {
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX | I2S_MODE_DAC_BUILT_IN),
    .sample_rate = SAMPLE_RATE,
    .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
    .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
    .communication_format = I2S_COMM_FORMAT_STAND_MSB,
    .intr_alloc_flags = 0,
    .dma_buf_count = 2,
    .dma_buf_len = 1024
  };
  i2s_driver_install(I2S_NUM, &i2s_config, 0, NULL);
  i2s_set_dac_mode(I2S_DAC_CHANNEL_BOTH_EN);
  bufferMutex = xSemaphoreCreateMutex();
  
  // Seconds Counter Setup
  timer = timerBegin(0, 80, true);
  timerAttachInterrupt(timer, &onTimer, true);
  timerAlarmWrite(timer, 1000, true);
  timerAlarmEnable(timer);

  //Button Setup
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(MUX_PIN, OUTPUT);
  digitalWrite(MUX_PIN, HIGH);
  
  I2Ctwo.begin(16, 17, 100000);
  rtc.begin(&I2Ctwo);
  //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));  //Set RTC time at compilation
  
      DateTime now = rtc.now();
      uint8_t actualHour      = now.hour();
      uint8_t actualMinute    = now.minute();
      uint8_t actualsecond    = now.second();
      uint16_t actualyear     = now.year();
      uint8_t actualMonth     = now.month();
      uint8_t actualday       = now.day();
      
      digith = actualHour;

      if (actualHour > 12) actualHour = actualHour - 12;

      h = actualHour;
      m = actualMinute;
      s = actualsecond;
      day = actualday;
      year = actualyear;
      month = actualMonth;
      temperature = rtc.getTemperature();

 rtcRefresh();
 initClouds();
 
 xTaskCreatePinnedToCore(displayTask, "Display", 4096, NULL, 10, NULL, 0); // Core 0
 xTaskCreatePinnedToCore(renderTask, "Render", 8192, NULL, 1, NULL, 1);    // Core 1
 
}
//==============================================================================


//===============================DISPLAY TASK CORE0=============================
void displayTask(void * pvParameters) {
  size_t bytes_written;
  while (1) {
    if (frontBufferCount > 0) {
      i2s_write(I2S_NUM, frontBuffer, frontBufferCount * 4, &bytes_written, portMAX_DELAY);
    }

    if (swapReady) {
      uint32_t* temp = frontBuffer;
      frontBuffer = backBuffer;
      backBuffer = temp;
      
      frontBufferCount = backBufferCount;
      
      swapReady = false; 
    }
  }
}
//=============================================================================



//=======================CLOCK FACE RENDER TASK CORE1==========================
void renderTask(void * pvParameters) {
  
  while (1) {
    if (!swapReady) { 
      if (secondsCounter != lastSeen) {
        lastSeen = secondsCounter;
        s++;
      }

      
      if (s == 60) { s = 0; m++; temperature = rtc.getTemperature();}
      if (m == 60) { m = 0; h++; digith++;}
      if (h == 12) { h = 0; }
      
      if (digith == 24) { 
        digith = 0;
        rtcRefresh();
      }

static uint32_t lastButtonPress = 0;
bool buttonVal = digitalRead(buttonPin);

 if (buttonVal == LOW && oldButtonVal == HIGH) {
    if (millis() - lastButtonPress > 300) {
        clockPattern++;
        if (clockPattern > nPatterns) clockPattern = 0; 
        lastButtonPress = millis();

        if (clockPattern == 0) {
      digitalWrite(MUX_PIN, LOW);
      } else {
      digitalWrite(MUX_PIN, HIGH);
    }
  }
}

oldButtonVal = buttonVal;

backBufferCount = 0;

if (clockPattern == 0) {
    backBufferCount = 0;
    swapReady = false; 
    vTaskDelay(pdMS_TO_TICKS(20)); 
    continue;
  }


      switch(clockPattern) {
    
        case 1: { 
          Classic12dig(); 
          break;
        }
        
        case 2: {
          ClassicRoman();
          break;
        }
        
        case 3: {
          OldSchoolPendulum();
          break;
        }
        
        case 4: {
          OldSchoolBigPendulum();
          break;
        }
        
        case 5: {
          MinimalisticSpeeder();
          break;
        }
        
        case 6: {
          MinimalisticPlanets();
          break;
        }
        
        case 7: {
          Shape3D();
          break;
        }
        
        case 8: {
          Atom3D();
          break;
        }

         case 9: {
          Cardiology();
          break;
         }
         
         case 10: {
          FractalTree();
          break;
         }

         case 11: {
          RotaryCounterFace();
          break;
         }

         case 12: {
          DayCycle();
          break;
         }
         
      }

      
      /*
      while (backBufferCount < TARGET_POINTS) {
        Dot(0, 0); 
      }
      */
      
      swapReady = true; 
    }
    vTaskDelay(1); 
  }
}
//==============================================================================



//================================MAIN==========================================
void loop() {

vTaskDelete(NULL);
  
};
//==============================================================================
