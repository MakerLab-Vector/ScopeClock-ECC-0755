//============================================Classic Face==========================================================
void Classic12dig() {
  float sAng = (s + msCounter / 1000.0) * 6.0;
  float mAng = (m + s / 60.0) * 6.0;
  float hAng = ((h % 12) * 30.0) + (m * 0.5);
  
  PlotTable(DialDigits12, sizeof(DialDigits12), 0x00, 1, 0); 
  PlotTable(DialData, sizeof(DialData), 0x00, 1, 0); 

  
  drawAlphaHand(128, 128, hAng, 65, 9); 
  drawAlphaHand(128, 128, mAng, 88, 6); 
  drawSecondHand(128, 128, sAng);       
  drawCenterHub(128, 128);

  drawString(customText, 69, 90, 7);
  String dateStr = (day < 10 ? "0" : "") + String(day) + "." + (month < 10 ? "0" : "") + String(month) + "." + String(year);
  drawString(dateStr, 76, 75, 7);

};
//==================================================================================================================



//============================================Classic Roman Face====================================================
void ClassicRoman(){
   float sAng = (s + msCounter / 1000.0) * 6.0;
   float mAng = (m + s / 60.0) * 6.0;
   float hAng = ((h % 12) + m / 60.0) * 30.0;
  
   PlotTable(DialDigitsRoman, sizeof(DialDigitsRoman), 0x00, 1, 0); 
   PlotTable(DialData, sizeof(DialData), 0x00, 1, 0);

   
   drawAlphaHand(128, 128, hAng, 65, 9); 
   drawAlphaHand(128, 128, mAng, 88, 6); 
   drawSecondHand(128, 128, sAng);       
   drawCenterHub(128, 128);

   drawString(customText, 69, 90, 7);
   String dateStr = (day < 10 ? "0" : "") + String(day) + "." + (month < 10 ? "0" : "") + String(month) + "." + String(year);
   drawString(dateStr, 76, 75, 7);
   
};
//==================================================================================================================



//=============================================Oscillating Speeder==================================================
void MinimalisticSpeeder(){

    PlotTable(DialDots, sizeof(DialDots), 0x00, 1, 0); 
            
    String timeStr = (digith < 10 ? "0" : "") + String(digith) + ":" + (m < 10 ? "0" : "") + String(m);
    //drawString(timeStr, 30, 127, 36);
    drawString(timeStr, 31, 127, 36);

    String secStr = (s < 10 ? "0" : "") + String(s);
    drawString(secStr, 116, 205, 9);
    drawString(String("0"), 112, 195, 30);
            
    byte run_y = 128+112*cos(((360-msCounter*0.36))*(PI/180));
    byte run_x = 128-112*sin(((360-msCounter*0.36))*(PI/180));
    drawCircle(run_x, run_y, 7);

    drawString(customText, 69, 90, 7);
    String dateStr = (day < 10 ? "0" : "") + String(day) + "." + (month < 10 ? "0" : "") + String(month) + "." + String(year);
    drawString(dateStr, 76, 75, 7);
  
};
//==================================================================================================================



//===========================================Roman Face with Pendulum===============================================
void OldSchoolPendulum() {
  
  float totalTime = s + (msCounter / 1000.0);
  
  float sAng = 45 * sin(totalTime * 180.0 * (PI / 180.0)) + 180;
  float mAng = (m + s / 60.0) * 6.0;
  float hAng = ((h % 12) * 30.0) + (m * 0.5);
  
  PlotTable(DialData, sizeof(DialData), 0x00, 1, 0);
  PlotTable(DialDigitsRoman, sizeof(DialDigitsRoman), 0x00, 1, 0);
  
  drawAlphaHand(128, 128, hAng, 65, 9); 
  drawAlphaHand(128, 128, mAng, 88, 6); 
  drawPendulum(128, 128, sAng);       
  drawCenterHub(128, 128);
   
};
//==================================================================================================================



//=======================================Roman Face with Large Pendulum=============================================
void OldSchoolBigPendulum() {
  
  float totalTime = s + (msCounter / 1000.0);
  
  float sAng = 25 * sin(totalTime * 180.0 * (PI / 180.0)) + 180;
  float mAng = (m + s / 60.0) * 6.0;
  float hAng = ((h % 12) * 30.0) + (m * 0.5);
  
  PlotTable(DialData, sizeof(DialData), 0x00, 1, 0);
  PlotTable(DialDigitsRoman, sizeof(DialDigitsRoman), 0x00, 1, 0);
  
  drawAlphaHand(128, 128, hAng, 65, 9);
  drawAlphaHand(128, 128, mAng, 88, 6); 
  drawBigPendulum(128, 220, sAng);       
  drawCenterHub(128, 128);
   
};
//==================================================================================================================



//============================================Solar System Face=====================================================
void MinimalisticPlanets(){
    String hourStr = (digith < 10 ? "0" : "") + String(digith);
    drawString(hourStr, 110, 135, 16);

    Line(105, 128, 151, 128);
    
    String minStr = (m < 10 ? "0" : "") + String(m);
    drawString(minStr, 110, 105, 16);
    
    drawCircleHighRes(128, 128, 35);

    float sAng = (s + msCounter / 1000.0) * 6.0 + 180;
    float mAng = (m + s / 60.0) * 6.0 + 180;
    float hAng = ((h % 12) * 30.0) + (m * 0.5) + 180;

    float rHour = 115.0;
    float rMin  = 90.0;
    float rSec  = 65.0;
    float pSizeHour = 10.0;
    float pSizeMin  = 7.0;
    float pSizeSec  = 5.0;

    drawOrbitWithGap(128, 128, rHour, hAng, pSizeHour);
    drawOrbitWithGap(128, 128, rMin, mAng, pSizeMin);
    drawOrbitWithGap(128, 128, rSec, sAng, pSizeSec);
    drawPlanet(128, 128, hAng, rHour, pSizeHour);
    drawPlanet(128, 128, mAng, rMin, pSizeMin);
    drawPlanet(128, 128, sAng, rSec, pSizeSec);
};
//==================================================================================================================



//============================================3D Nuclear Face=======================================================
void Atom3D() {

    uint32_t t = millis();
    
    String timeStr = (digith < 10 ? "0" : "") + String(digith) + ":" + (m < 10 ? "0" : "") + String(m);
    //drawString(timeStr, 43, 200, 30);
    drawString(timeStr, 44, 200, 30);
    
    Particle n[8]; 


    // Nucleus
    int baseLoc[8][3] = {{7,7,7}, {-7,-7,7}, {7,-7,-7}, {-7,7,-7}, {-7,-7,-7}, {7,7,-7}, {-7,7,7}, {7,-7,7}};
    for (int i = 0; i < 8; i++) {
        int ox = (11 * fast_sin((t / 4) + (i * 45))) >> 12;
        int oy = (11 * fast_cos((t / 5) + (i * 90))) >> 12;
        int oz = (11 * fast_sin((t / 6) + (i * 135))) >> 12;
        
        int nx = baseLoc[i][0] + ox;
        int ny = baseLoc[i][1] + oy;
        int nz = baseLoc[i][2] + oz;
        
        rotate3D(nx, ny, nz, t/30, t/40);
        n[i] = {128 + nx, 128 - ny, nz, 18}; 
    }

    for (int i = 0; i < 8; i++) drawNucleon(n[i], n, 8);

    // Electrons
    int radii[3] = {65, 95, 120};
    for (int i = 0; i < 3; i++) {
        int orbitalPos = (t / (3 + i)) % 360; 
        int tiltX = (t / (15 + i)) % 360;
        int tiltY = (t / (20 - i)) % 360;
        
        drawElectronWithTail(radii[i], orbitalPos, tiltX, tiltY, n, 8);
    }

   drawString(customText, 69, 40, 7);
   String dateStr = (day < 10 ? "0" : "") + String(day) + "." + (month < 10 ? "0" : "") + String(month) + "." + String(year);
   drawString(dateStr, 76, 25, 7);
}
//==================================================================================================================



//=====================================Rotating Shapes in Starfield=================================================
void Shape3D() {
    
    String timeStr = (digith < 10 ? "0" : "") + String(digith) + ":" + (m < 10 ? "0" : "") + String(m);
    //drawString(timeStr, 43, 200, 30);
    drawString(timeStr, 44, 200, 30);

    uint32_t t = millis();
    
    int winX = 128, winY = 128;
    int objID = (s / 20) % 4;
    
    float zoom = 1.0;
    int cycleMs = (s % 20) * 1000 + (msCounter % 1000);
    if (cycleMs < 1500) {
        zoom = (float)cycleMs / 1500.0; 
    }
    if (cycleMs > 18500) {
        zoom = ((float)(20000 - cycleMs))/1500.0; 
    }

    int rx = (t / 35) % 360; 
    int ry = (t / 52) % 360;

    switch(objID) {
        case 0: drawWireframeScaled(starV, 12, starE, 30, winX, winY, rx, ry, zoom); break;
        case 1: drawWireframeScaled(cubeV, 8, cubeE, 12, winX, winY, rx, ry, zoom); break;
        case 2: drawWireframeScaled(pyrV, 5, pyrE, 8, winX, winY, rx, ry, zoom); break;
        case 3: draw3DConeScaled(winX, winY, rx, ry, zoom); break;
    }
    drawStarfieldTunnel(t, 127, 127); 

    drawString(customText, 69, 40, 7);
    String dateStr = (day < 10 ? "0" : "") + String(day) + "." + (month < 10 ? "0" : "") + String(month) + "." + String(year);
    drawString(dateStr, 76, 25, 7);
}
//==================================================================================================================



//==============================================Beating Heart Face==================================================
void Cardiology() {
    
    String timeStr = (digith < 10 ? "0" : "") + String(digith) + ":" + (m < 10 ? "0" : "") + String(m);
    //drawString(timeStr, 43, 200, 30);
    drawString(timeStr, 44, 200, 30);
    
    int cx = 128, cy = 135, lastX = -1, lastY = -1;
    uint32_t ms = msCounter % 1000;

    float beat = 1.0f;
    if (ms < 180) beat += 0.35f * sin(PI * ms / 180.0f);
    else if (ms < 450) beat += 0.35f * exp(-6.0f * (ms - 180) / 270.0f);

    float s = beat * 3.8f; 
    for (int i = 0; i <= 32; i++) {
        float a = PI * i / 16.0f; 
        int x = cx + (int)(16.0f * fast_pow_heart(sin(a)) * s);
        int y = cy + (int)((13.0f * cos(a) - 5.0f * cos(2.0f * a) - 2.0f * cos(3.0f * a) - cos(4.0f * a)) * s);
        
        if (i > 0) Line(lastX, lastY, x, y);
        lastX = x; lastY = y;
    }

 
    int span = (int)(45.0f * beat);
    int blipX = (cx + span) - (msCounter * (span * 2) / 1000); 

    lastX = -1;
    for (int x = cx - span; x <= cx + span; x += 2) {
        int y = cy - 15; 
        
        int idx = (x - blipX + 16) / 2; 
        if (idx >= 0 && idx < 16) y += ecgY[idx]; 

        if (lastX != -1) Line(lastX, lastY, x, y);
        lastX = x; lastY = y;
    }

    drawString(customText, 69, 40, 7);
    String dateStr = (day < 10 ? "0" : "") + String(day) + "." + (month < 10 ? "0" : "") + String(month) + "." + String(year);
    drawString(dateStr, 76, 25, 7);
}
//==================================================================================================================



//========================================Fractal Tree Face=========================================================
void FractalTree() {
  
    PlotTable(DialDots, sizeof(DialDots), 0x00, 1, 0);
    
    String timeStr = (digith < 10 ? "0" : "") + String(digith) + "  " + (m < 10 ? "0" : "") + String(m);
    //drawString(timeStr, 22, 115, 32);
    drawString(timeStr, 23, 115, 32);
    
    int cx = 128;
    int cyBase = 85; 
    
    float wind = sin(millis() / 800.0f) * 0.13f; 

    drawTreeBranch(cx, cyBase, PI / 2.0f, 48.0f, 6, wind);

    drawString(customText, 69, 45, 7);
    String dateStr = (day < 10 ? "0" : "") + String(day) + "." + (month < 10 ? "0" : "") + String(month) + "." + String(year);
    drawString(dateStr, 76, 30, 7);
}
//==================================================================================================================



//===================================Rotary Drum Counter Face with Gears============================================
void RotaryCounterFace() {

    float scale = 1.6f; 
    int cx = 128, cy = 128;
    
    
    int boxCenterOffset = (int)(40 * scale); 
    int digitOffsetTens = (int)(-16 * scale); 
    int digitOffsetOnes = (int)(3 * scale);  
    int windowHalfWidth = (int)(60 * scale);
    int dividerPos = (int)(20 * scale);       

    int winH = (int)(20 * scale);
    int bY1 = cy - winH, bY2 = cy + winH;
    int m1 = bY1 + 2, m2 = bY2 - 2;
    
    PlotTable(DialData, sizeof(DialData), 0x00, 1, 0); 
            
    byte run_y = 128+112*cos(((288-msCounter*0.36))*(PI/180));
    byte run_x = 128-112*sin(((288-msCounter*0.36))*(PI/180));
    drawCircle(run_x, run_y, 7);

    float gearAngle = (msCounter / 1000.0f + s) * (PI / 5.0f);
    
    
    Line(cx - windowHalfWidth-4, bY1, cx + windowHalfWidth, bY1); 
    Line(cx - windowHalfWidth-4, bY2, cx + windowHalfWidth, bY2); 
    Line(cx - windowHalfWidth, bY1-4, cx - windowHalfWidth, bY2); 
    Line(cx + windowHalfWidth, bY1-4, cx + windowHalfWidth, bY2); 
    
    
    Line(cx - dividerPos, bY1-3, cx - dividerPos, bY2); 
    Line(cx + dividerPos, bY1-3, cx + dividerPos, bY2);

 
    Line(cx, bY1-2, cx, bY1+9); 
    Line(cx, bY2+2, cx, bY2-9);
    Line(cx-64, bY1-2, cx-64, bY1+9); 
    Line(cx-64, bY2+2, cx-64, bY2-9);
    Line(cx+64, bY1-2, cx+64, bY1+9); 
    Line(cx+64, bY2+2, cx+64, bY2-9);
    

    
    float phase = (msCounter > 800) ? (msCounter - 800) / 200.0f : 0;
    bool rolling = (msCounter > 800);

    
    int ns = (s + 1) % 60, nm = (s == 59) ? (m + 1) % 60 : m;
    int nh = (s == 59 && m == 59) ? (digith + 1) % 24 : digith;

    int dy = cy - (int)(12 * scale); 

    int hCenter = cx - boxCenterOffset;
    bool rollH = rolling && (s == 59 && m == 59);
    drawRollingSlot(hCenter + digitOffsetTens, dy, digith / 10, nh / 10, rollH && (digith % 10 == 9 || digith == 23), phase, m1, m2, scale);
    drawRollingSlot(hCenter + digitOffsetOnes, dy, digith % 10, nh % 10, rollH, phase, m1, m2, scale);

    
    int mCenter = cx;
    bool rollM = rolling && (s == 59);
    drawRollingSlot(mCenter + digitOffsetTens, dy, m / 10, nm / 10, rollM && (m % 10 == 9), phase, m1, m2, scale);
    drawRollingSlot(mCenter + digitOffsetOnes, dy, m % 10, nm % 10, rollM, phase, m1, m2, scale);

    
    int sCenter = cx + boxCenterOffset;
    drawRollingSlot(sCenter + digitOffsetTens, dy, s / 10, ns / 10, rolling && (s % 10 == 9), phase, m1, m2, scale);
    drawRollingSlot(sCenter + digitOffsetOnes, dy, s % 10, ns % 10, rolling, phase, m1, m2, scale); 

   
   drawGear(128, 195, 30, 24, gearAngle);
   drawGear(168, 180, 15, 12, -gearAngle * 2.0f + 0.3f);
   drawGear(190, 173, 8, 6, gearAngle * 4.0f + 0.6f);

   drawString(customText, 69, 60, 7);
   String dateStr = (day < 10 ? "0" : "") + String(day) + "." + (month < 10 ? "0" : "") + String(month) + "." + String(year);
   drawString(dateStr, 76, 45, 7);
} 
//==================================================================================================================



//========================================Day Cycle Face============================================================
void DayCycle() {
  
   PlotTable(DialDots, sizeof(DialDots), 0x00, 1, 0);
   Line(5,90,249,90);
   Line(66,90,66,130);
   Line(190,90,190,130);
   Line(66,130,190,130);
   
   float timeFloat = digith + (m / 60.0f);
   bool isDay = (timeFloat >= 6.0 && timeFloat < 18.0);
   float progress = 0.0f;
   
    if (isDay) {
        progress = (timeFloat - 6.0f) / 12.0f; // 0.0 at 6 AM, 1.0 at 6 PM
    } else {
        float nightTime = timeFloat < 6.0f ? timeFloat + 24.0f : timeFloat;
        progress = (nightTime - 18.0f) / 12.0f; // 0.0 at 6 PM, 1.0 at 6 AM
    }

    float angle = progress * PI; 
    float astroX = CX - cos(angle) * ORBIT_WIDTH; 
    float astroY = GROUND_LEVEL - sin(angle) * ORBIT_HEIGHT;

    if (isDay) {
        drawParametricSun(astroX, astroY, 14);
    } else {
        drawParametricMoon(astroX, astroY, 14);
    }
    
    for (int i = 0; i < 3; i++) {
        if (!clouds[i].active) continue;
        
        clouds[i].x += clouds[i].speed;
        
        if (clouds[i].x > CX + FRAME_RADIUS) {
            clouds[i].x = CX - FRAME_RADIUS - clouds[i].width;
            clouds[i].y = random(CLOUD_Y_MIN, CLOUD_Y_MAX); 
            clouds[i].phase = random(0, 314) / 100.0f;
        }
        
        drawParametricCloud(clouds[i]);
    }

   drawStringHershey(customText, 128, 25, 10, true);
   
   String hourStr = (digith < 10 ? "0" : "") + String(digith);
   String minStr =  (m < 10 ? "0" : "") + String(m);
   drawStringHershey(hourStr, 100, 95, 28, true);
   drawStringHershey(minStr, 165, 95, 28, true);
   drawStringHershey(":", 131, 95, 28, true);
   
   String dateStr = (day < 10 ? "0" : "") + String(day) + "." + (month < 10 ? "0" : "") + String(month) + "." + String(year);
   drawStringHershey(dateStr, 128, 45, 10, true);
   String dayofWeekStr = "Today is: " + String(DayStr);
   drawStringHershey(dayofWeekStr, 128, 65, 10, true);
   PlotTable(TelescopeIcon, sizeof(TelescopeIcon), 0x00, 0, 0);
    
}
//==================================================================================================================
