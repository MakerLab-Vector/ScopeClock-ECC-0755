#define V_PEN_UP 127
#define V_END    126

//======================================CHAR DRAWING============================================
void drawChar(char c, int x, int y, int size) {
  
  int hsize = size / 2; // Mid-point for rounding
  int qsize = size / 4; // Quarter-point for smoother corners

  switch (c) {
    case '0':
      Line(x + qsize, y, x + size - qsize, y); Line(x + size - qsize, y, x + size, y + qsize);
      Line(x + size, y + qsize, x + size, y + size - qsize); Line(x + size, y + size - qsize, x + size - qsize, y + size);
      Line(x + size - qsize, y + size, x + qsize, y + size); Line(x + qsize, y + size, x, y + size - qsize);
      Line(x, y + size - qsize, x, y + qsize); Line(x, y + qsize, x + qsize, y); break;

    case '1':
      Line(x + qsize, y + size - qsize, x + hsize, y + size); Line(x + hsize, y + size, x + hsize, y); Line(x + qsize, y, x + size - qsize, y); break;

    case '2':
      Line(x, y + size - qsize, x + qsize, y + size); Line(x + qsize, y + size, x + size - qsize, y + size);
      Line(x + size - qsize, y + size, x + size, y + size - qsize); Line(x + size, y + size - qsize, x + size, y + hsize + qsize);
      Line(x + size, y + hsize + qsize, x + size - qsize, y + hsize); Line(x + size - qsize, y + hsize, x, y); Line(x, y, x + size, y); break;

    case '3':
      Line(x, y + size - qsize, x + qsize, y + size); Line(x + qsize, y + size, x + size - qsize, y + size);
      Line(x + size - qsize, y + size, x + size, y + size - qsize); Line(x + size, y + size - qsize, x + size, y + hsize + qsize);
      Line(x + size, y + hsize + qsize, x + hsize, y + hsize); Line(x + hsize, y + hsize, x + size, y + hsize - qsize);
      Line(x + size, y + hsize - qsize, x + size, y + qsize); Line(x + size, y + qsize, x + size - qsize, y);
      Line(x + size - qsize, y, x + qsize, y); Line(x + qsize, y, x, y + qsize); break;

    case '4':
      Line(x + size, y + hsize, x, y + hsize); Line(x, y + hsize, x + size - qsize, y + size); Line(x + size - qsize, y + size, x + size - qsize, y); break;

    case '5':
      Line(x + size, y + size, x, y + size); Line(x, y + size, x, y + hsize + qsize); Line(x, y + hsize + qsize, x + size - qsize, y + hsize + qsize);
      Line(x + size - qsize, y + hsize + qsize, x + size, y + hsize); Line(x + size, y + hsize, x + size, y + qsize);
      Line(x + size, y + qsize, x + size - qsize, y); Line(x + size - qsize, y, x, y); break;

    case '6':
      Line(x + size - qsize, y + size, x + qsize, y + size); Line(x + qsize, y + size, x, y + size - qsize);
      Line(x, y + size - qsize, x, y + qsize); Line(x, y + qsize, x + qsize, y);
      Line(x + qsize, y, x + size - qsize, y); Line(x + size - qsize, y, x + size, y + qsize);
      Line(x + size, y + qsize, x + size, y + hsize - qsize); Line(x + size, y + hsize - qsize, x + size - qsize, y + hsize);
      Line(x + size - qsize, y + hsize, x, y + hsize); break;

    case '7':
      Line(x, y + size, x + size, y + size); Line(x + size, y + size, x + hsize, y); break;

    case '8':
      Line(x + qsize, y + size, x + size - qsize, y + size); Line(x + size - qsize, y + size, x + size, y + size - qsize);
      Line(x + size, y + size - qsize, x + size, y + hsize + qsize); Line(x + size, y + hsize + qsize, x + size - qsize, y + hsize);
      Line(x + size - qsize, y + hsize, x + qsize, y + hsize); Line(x + qsize, y + hsize, x, y + hsize + qsize);
      Line(x, y + hsize + qsize, x, y + size - qsize); Line(x, y + size - qsize, x + qsize, y + size);
      Line(x + qsize, y + hsize, x + size - qsize, y + hsize); Line(x + size - qsize, y + hsize, x + size, y + hsize - qsize);
      Line(x + size, y + hsize - qsize, x + size, y + qsize); Line(x + size, y + qsize, x + size - qsize, y);
      Line(x + size - qsize, y, x + qsize, y); Line(x + qsize, y, x, y + qsize);
      Line(x, y + qsize, x, y + hsize - qsize); Line(x, y + hsize - qsize, x + qsize, y + hsize); break;

    case '9':
      Line(x + size, y + hsize, x + qsize, y + hsize); Line(x + qsize, y + hsize, x, y + hsize + qsize);
      Line(x, y + hsize + qsize, x, y + size - qsize); Line(x, y + size - qsize, x + qsize, y + size);
      Line(x + qsize, y + size, x + size - qsize, y + size); Line(x + size - qsize, y + size, x + size, y + size - qsize);
      Line(x + size, y + size - qsize, x + size, y + qsize); Line(x + size, y + qsize, x + size - qsize, y);
      Line(x + size - qsize, y, x + qsize, y); break;

    case ':': {
        int r = size / 8 > 0 ? size / 8 : 1;
        int cx = x + hsize;

        int cyTop = y + size - qsize;
        Line(cx - r, cyTop, cx, cyTop + r); Line(cx, cyTop + r, cx + r, cyTop);
        Line(cx + r, cyTop, cx, cyTop - r); Line(cx, cyTop - r, cx - r, cyTop);

        int cyBot = y + qsize;
        Line(cx - r, cyBot, cx, cyBot + r); Line(cx, cyBot + r, cx + r, cyBot);
        Line(cx + r, cyBot, cx, cyBot - r); Line(cx, cyBot - r, cx - r, cyBot);
        break;
      }

    case '.': {
        int r = size / 8 > 0 ? size / 8 : 1;
        int cx = x + hsize;
        int cy = y + hsize;
        Line(cx - r, cy, cx, cy + r); Line(cx, cy + r, cx + r, cy); Line(cx + r, cy, cx, cy - r); Line(cx, cy - r, cx - r, cy);
        break;
      }

    case '-': Line(x, y + size / 2, x + size, y + size / 2); break;

    case 'A':
      Line(x, y, x, y + size - qsize); Line(x, y + size - qsize, x + qsize, y + size);
      Line(x + qsize, y + size, x + size - qsize, y + size); Line(x + size - qsize, y + size, x + size, y + size - qsize);
      Line(x + size, y + size - qsize, x + size, y); Line(x, y + hsize, x + size, y + hsize); break;

    case 'B':
      Line(x, y, x, y + size); Line(x, y + size, x + size - qsize, y + size); Line(x + size - qsize, y + size, x + size, y + size - qsize);
      Line(x + size, y + size - qsize, x + size, y + hsize + qsize); Line(x + size, y + hsize + qsize, x + size - qsize, y + hsize);
      Line(x + size - qsize, y + hsize, x, y + hsize); Line(x, y + hsize, x + size - qsize, y + hsize);
      Line(x + size - qsize, y + hsize, x + size, y + hsize - qsize); Line(x + size, y + hsize - qsize, x + size, y + qsize);
      Line(x + size, y + qsize, x + size - qsize, y); Line(x + size - qsize, y, x, y); break;

    case 'C':
      Line(x + size, y + qsize, x + size - qsize, y); Line(x + size - qsize, y, x + qsize, y); Line(x + qsize, y, x, y + qsize);
      Line(x, y + qsize, x, y + size - qsize); Line(x, y + size - qsize, x + qsize, y + size);
      Line(x + qsize, y + size, x + size - qsize, y + size); Line(x + size - qsize, y + size, x + size, y + size - qsize); break;

    case 'D':
      Line(x, y, x, y + size); Line(x, y + size, x + size - qsize, y + size); Line(x + size - qsize, y + size, x + size, y + size - qsize);
      Line(x + size, y + size - qsize, x + size, y + qsize); Line(x + size, y + qsize, x + size - qsize, y); Line(x + size - qsize, y, x, y); break;

    case 'E':
      Line(x + size, y, x, y); Line(x, y, x, y + size); Line(x, y + size, x + size, y + size); Line(x, y + hsize, x + size - qsize, y + hsize); break;

    case 'F':
      Line(x, y, x, y + size); Line(x, y + size, x + size, y + size); Line(x, y + hsize, x + size - qsize, y + hsize); break;

    case 'G':
      Line(x + size, y + hsize, x + size, y + qsize); Line(x + size, y + qsize, x + size - qsize, y); Line(x + size - qsize, y, x + qsize, y);
      Line(x + qsize, y, x, y + qsize); Line(x, y + qsize, x, y + size - qsize); Line(x, y + size - qsize, x + qsize, y + size);
      Line(x + qsize, y + size, x + size - qsize, y + size); Line(x + size - qsize, y + size, x + size, y + size - qsize);
      Line(x + size, y + hsize, x + hsize, y + hsize); break;

    case 'H':
      Line(x, y, x, y + size); Line(x + size, y, x + size, y + size); Line(x, y + hsize, x + size, y + hsize); break;

    case 'I':
      Line(x + qsize, y, x + size - qsize, y); Line(x + hsize, y, x + hsize, y + size); Line(x + qsize, y + size, x + size - qsize, y + size); break;

    case 'J':
      Line(x, y + qsize, x + qsize, y); Line(x + qsize, y, x + size - qsize, y); Line(x + size - qsize, y, x + size, y + qsize); Line(x + size, y + qsize, x + size, y + size); break;

    case 'K':
      Line(x, y, x, y + size); Line(x, y + hsize, x + size, y + size); Line(x, y + hsize, x + size, y); break;

    case 'L':
      Line(x, y + size, x, y); Line(x, y, x + size, y); break;

    case 'M':
      Line(x, y, x, y + size); Line(x, y + size, x + hsize, y + hsize); Line(x + hsize, y + hsize, x + size, y + size); Line(x + size, y + size, x + size, y); break;

    case 'N':
      Line(x, y, x, y + size); Line(x, y + size, x + size, y); Line(x + size, y, x + size, y + size); break;

    case 'O':
      Line(x + qsize, y, x + size - qsize, y); Line(x + size - qsize, y, x + size, y + qsize); Line(x + size, y + qsize, x + size, y + size - qsize);
      Line(x + size, y + size - qsize, x + size - qsize, y + size); Line(x + size - qsize, y + size, x + qsize, y + size);
      Line(x + qsize, y + size, x, y + size - qsize); Line(x, y + size - qsize, x, y + qsize); Line(x, y + qsize, x + qsize, y); break;

    case 'P':
      Line(x, y, x, y + size); Line(x, y + size, x + size - qsize, y + size); Line(x + size - qsize, y + size, x + size, y + size - qsize);
      Line(x + size, y + size - qsize, x + size, y + hsize + qsize); Line(x + size, y + hsize + qsize, x + size - qsize, y + hsize); Line(x + size - qsize, y + hsize, x, y + hsize); break;

    case 'Q':
      Line(x + qsize, y, x + size - qsize, y); Line(x + size - qsize, y, x + size, y + qsize); Line(x + size, y + qsize, x + size, y + size - qsize);
      Line(x + size, y + size - qsize, x + size - qsize, y + size); Line(x + size - qsize, y + size, x + qsize, y + size);
      Line(x + qsize, y + size, x, y + size - qsize); Line(x, y + size - qsize, x, y + qsize); Line(x, y + qsize, x + qsize, y);
      Line(x + hsize, y + hsize, x + size, y); break;

    case 'R':
      Line(x, y, x, y + size); Line(x, y + size, x + size - qsize, y + size); Line(x + size - qsize, y + size, x + size, y + size - qsize);
      Line(x + size, y + size - qsize, x + size, y + hsize + qsize); Line(x + size, y + hsize + qsize, x + size - qsize, y + hsize);
      Line(x + size - qsize, y + hsize, x, y + hsize); Line(x + hsize, y + hsize, x + size, y); break;

    case 'S':
      Line(x, y + qsize, x + qsize, y); Line(x + qsize, y, x + size - qsize, y); Line(x + size - qsize, y, x + size, y + qsize);
      Line(x + size, y + qsize, x + size, y + hsize - qsize); Line(x + size, y + hsize - qsize, x + size - qsize, y + hsize);
      Line(x + size - qsize, y + hsize, x + qsize, y + hsize); Line(x + qsize, y + hsize, x, y + hsize + qsize);
      Line(x, y + hsize + qsize, x, y + size - qsize); Line(x, y + size - qsize, x + qsize, y + size);
      Line(x + qsize, y + size, x + size - qsize, y + size); Line(x + size - qsize, y + size, x + size, y + size - qsize); break;

    case 'T':
      Line(x, y + size, x + size, y + size); Line(x + hsize, y + size, x + hsize, y); break;

    case 'U':
      Line(x, y + size, x, y + qsize); Line(x, y + qsize, x + qsize, y); Line(x + qsize, y, x + size - qsize, y);
      Line(x + size - qsize, y, x + size, y + qsize); Line(x + size, y + qsize, x + size, y + size); break;

    case 'V':
      Line(x, y + size, x + hsize, y); Line(x + hsize, y, x + size, y + size); break;

    case 'W':
      Line(x, y + size, x + qsize, y); Line(x + qsize, y, x + hsize, y + hsize); Line(x + hsize, y + hsize, x + size - qsize, y); Line(x + size - qsize, y, x + size, y + size); break;

    case 'X':
      Line(x, y, x + size, y + size); Line(x, y + size, x + size, y); break;

    case 'Y':
      Line(x, y + size, x + hsize, y + hsize); Line(x + size, y + size, x + hsize, y + hsize); Line(x + hsize, y + hsize, x + hsize, y); break;

    case 'Z':
      Line(x, y + size, x + size, y + size); Line(x + size, y + size, x, y); Line(x, y, x + size, y); break;

    case ' ': break;
  }
}

void drawString(String text, int x, int y, int size) {
  for (int i = 0; i < text.length(); i++) {
    drawChar(text[i], x + (i * (size + 4)), y, size);
  }
}
//==============================================================================================


//==================================HERSHEY CHAR DRAWING========================================
int drawCharHershey(char c, int x_offset, int y_offset, int size, bool render) {
    int idx = c - 32; 
    if (idx < 0 || idx >= 95) return 0; 
    
    float scale = (float)size / FONT_NATIVE_HEIGHT;
    int num_pairs = simplex[idx][0];
    
    int min_x = 127;  
    int max_x = -127;
    bool has_vectors = false;
    
    for (int i = 0; i < num_pairs; i++) {
        int rx = simplex[idx][2 + (i * 2)];
        int ry = simplex[idx][3 + (i * 2)];
        if (rx != -1 && ry != -1) {
            if (rx < min_x) min_x = rx;
            if (rx > max_x) max_x = rx;
            has_vectors = true;
        }
    }
    
    int active_width = has_vectors ? (int)(((max_x - min_x) * scale) + 0.5f) : (int)((FONT_NATIVE_HEIGHT * 0.35f) * scale + 0.5f);
    int total_advance = active_width + size / 3;

    if (!render || !has_vectors) {
        return total_advance; 
    }
    
    int last_x = 0;
    int last_y = 0;
    bool pen_down = false; 
    
    for (int i = 0; i < num_pairs; i++) {
        int rx = simplex[idx][2 + (i * 2)];
        int ry = simplex[idx][3 + (i * 2)];
        
        if (rx == -1 && ry == -1) {
            pen_down = false;
        } else {
            int screen_x = x_offset + (int)(((rx - min_x) * scale) + 0.5f);
            int screen_y = y_offset + (int)((ry * scale) + 0.5f); 
            
            if (pen_down) {
                LineClear(last_x, last_y, screen_x, screen_y);
            }
            
            last_x = screen_x;
            last_y = screen_y;
            pen_down = true;
        }
    }
    
    return total_advance; 
}

void drawStringHershey(String text, int x, int y, int size, bool center) {
    int start_x = x;

    if (center) {
        int total_width = 0;
        
        for (int i = 0; i < text.length(); i++) {
            total_width += drawCharHershey(text[i], 0, 0, size, false);
        }
       
        start_x -= (total_width / 2);
    }

    int current_x = start_x;
    for (int i = 0; i < text.length(); i++) {
        current_x += drawCharHershey(text[i], current_x, y, size, true);
    }
}
//==============================================================================================



//===================================CLOCK DIAMOND HANDS========================================
void drawAlphaHand(int cx, int cy, float angle, float length, float width) {
    
    float rad = angle * 0.01745329;
    float sideRad = 1.570796; // 90 degrees

    
    int xt = cx + length * sin(rad);
    int yt = cy + length * cos(rad);

    
    float sDist = HUB_RADIUS + 5; 
    int xsr = cx + sDist * sin(rad) + (width / 2) * sin(rad + sideRad);
    int ysr = cy + sDist * cos(rad) + (width / 2) * cos(rad + sideRad);
    int xsl = cx + sDist * sin(rad) + (width / 2) * sin(rad - sideRad);
    int ysl = cy + sDist * cos(rad) + (width / 2) * cos(rad - sideRad);

    
    float baseOffset = 0.25; 
    int xbr = cx + HUB_RADIUS * sin(rad + baseOffset);
    int ybr = cy + HUB_RADIUS * cos(rad + baseOffset);
    int xbl = cx + HUB_RADIUS * sin(rad - baseOffset);
    int ybl = cy + HUB_RADIUS * cos(rad - baseOffset);

    
    Line(xt, yt, xsr, ysr);
    Line(xsr, ysr, xbr, ybr); 
    Line(xbl, ybl, xsl, ysl); 
    Line(xsl, ysl, xt, yt);
    
}

void drawSecondHand(int cx, int cy, float angle) {
    float rad = angle * 0.01745329;
    
    
    int sx = cx + HUB_RADIUS * sin(rad);
    int sy = cy + HUB_RADIUS * cos(rad);
    int tx = cx + 95 * sin(rad);
    int ty = cy + 95 * cos(rad);
    
    Line(sx, sy, tx, ty);

    
    int lx = cx + 75 * sin(rad);
    int ly = cy + 75 * cos(rad);
    drawCircle(lx, ly, 4);
}
//==============================================================================================



//=======================================PENDULUMS==============================================
void drawPendulum(int cx, int cy, float angle) {
    float rad = angle * 0.01745329;
    
    
    int sx = cx + HUB_RADIUS * sin(rad);
    int sy = cy + HUB_RADIUS * cos(rad);
    int tx = cx + 95 * sin(rad);
    int ty = cy + 95 * cos(rad);
    
    Line(sx, sy, tx, ty);

    
    int lx = cx + 62 * sin(rad);
    int ly = cy + 62 * cos(rad);
    drawCircle(lx, ly, 3);
    drawCircle(lx, ly, 7);
    drawCircle(lx, ly, 11);
}

void drawBigPendulum(int cx, int cy, float angle) {
    float rad = angle * 0.01745329;
    
    
    int sx = cx;
    int sy = cy;
    int tx = cx + 180 * sin(rad);
    int ty = cy + 180 * cos(rad);
    
    Line(sx, sy, tx, ty);

    
    int lx = cx + 152 * sin(rad);
    int ly = cy + 152 * cos(rad);
    drawCircle(lx, ly, 3);
    drawCircle(lx, ly, 7);
    drawCircle(lx, ly, 11);
    drawCircle(lx, ly, 15);
    drawCircle(lx, ly, 19);
    drawCircle(lx, ly, 23);
}

void drawCenterHub(int cx, int cy) {
    drawCircle(cx, cy, HUB_RADIUS);
}
//==============================================================================================



//======================================CIRCLES=================================================
void drawCircle(int x, int y, int r) {
    float step = 0.785398; // 45 degrees
    for(int i=0; i<8; i++) {
        Line(x + r*sin(i*step), y + r*cos(i*step), 
             x + r*sin((i+1)*step), y + r*cos((i+1)*step));
  }
}

void drawCircleHighRes(int x, int y, int r) {
    float step = 0.087266; // 5 degrees
    for(int i=0; i<72; i++) {
        LineClear(x + r*sin(i*step), y + r*cos(i*step), 
             x + r*sin((i+1)*step), y + r*cos((i+1)*step));
  }
}

void drawOrbitWithGap(int cx, int cy, float radius, float planetAngle, float planetRadius) {
    float radAngle = planetAngle * 0.01745329; 
    
    float gapRad = asin(planetRadius / radius) * 1.2; 
    
    float startAngle = radAngle + gapRad;
    float endAngle = radAngle + TWO_PI - gapRad;
    
    int arcSteps = 32; 
    float stepSize = (endAngle - startAngle) / arcSteps;
    
    float a = startAngle;
    int lastX = cx - radius * sin(a);
    int lastY = cy - radius * cos(a); 
    
    for(int i = 1; i <= arcSteps; i++) {
        a += stepSize;
        int nx = cx - radius * sin(a);
        int ny = cy - radius * cos(a);
        Line(lastX, lastY, nx, ny);
        lastX = nx;
        lastY = ny;
    }
}

void drawPlanet(int cx, int cy, float angle, float orbitRadius, float planetRadius) {
    float rad = angle * 0.01745329;
    
   
    int px = cx - orbitRadius * sin(rad);
    int py = cy - orbitRadius * cos(rad); // -cos for UP
    
    
    drawCircle(px, py, planetRadius);
    
    
    if (planetRadius >= 4) {
        drawCircle(px, py, planetRadius * 0.5);
    }
}
//==============================================================================================



//========================================COMPLEX===============================================
float fast_pow_heart(float x) {
    return x * x * x;
}


void clipLineV(int x, int y1, int y2, int miny, int maxy) {
    int start = (y1 < miny) ? miny : (y1 > maxy ? maxy : y1);
    int end = (y2 < miny) ? miny : (y2 > maxy ? maxy : y2);
    if (start != end) Line(x, start, x, end);
}

void clipLineH(int x1, int x2, int y, int miny, int maxy) {
    if (y >= miny && y <= maxy) Line(x1, y, x2, y);
}

void drawDigitClipped(int x, int y, int val, int offset, int miny, int maxy, float scale) {
    int w = (int)(12 * scale);
    int h = (int)(24 * scale);
    int h2 = h / 2;
    int dy = y + offset; 
    uint8_t bits = segFont[val % 10];

    // Horizontal Segments
    if (bits & 0x01) clipLineH(x, x+w, dy+h,  miny, maxy); // Top
    if (bits & 0x40) clipLineH(x, x+w, dy+h2, miny, maxy); // Mid
    if (bits & 0x08) clipLineH(x, x+w, dy,    miny, maxy); // Bot

    // Vertical Segments
    if (bits & 0x20) clipLineV(x,   dy+h2, dy+h,  miny, maxy); // Top-L
    if (bits & 0x02) clipLineV(x+w, dy+h2, dy+h,  miny, maxy); // Top-R
    if (bits & 0x10) clipLineV(x,   dy,    dy+h2, miny, maxy); // Bot-L
    if (bits & 0x04) clipLineV(x+w, dy,    dy+h2, miny, maxy); // Bot-R
}


void drawRollingSlot(int x, int y, int cur, int next, bool active, float phase, int miny, int maxy, float scale) {
    
    int travel = (int)(30 * scale); 
    int offset = active ? (int)(phase * travel) : 0;

    drawDigitClipped(x, y, cur, offset, miny, maxy, scale);
    if (active) {
        drawDigitClipped(x, y, next, offset - travel, miny, maxy, scale);
    }
}
//==============================================================================================



//=======================================GEARS==================================================
void drawGear(int cx, int cy, float radius, int teeth, float rotation) {
    if (teeth < 3) return;

    float innerRadius = radius * 0.75f; 
    float axleRadius = radius * 0.15f;  
    
    float angleStep = (2.0f * PI) / teeth;
    float quarterStep = angleStep / 4.0f;

    float lastX, lastY;
    bool first = true;

    for (int i = 0; i < teeth; i++) {
        float baseAngle = i * angleStep + rotation;

        float angles[4] = {
            baseAngle,
            baseAngle + quarterStep,
            baseAngle + 2.0f * quarterStep,
            baseAngle + 3.0f * quarterStep
        };

        float r[4] = {innerRadius, radius, radius, innerRadius};

        for (int j = 0; j < 4; j++) {
            float x = cx + cos(angles[j]) * r[j];
            float y = cy + sin(angles[j]) * r[j];

            if (!first) {
                Line((int)lastX, (int)lastY, (int)x, (int)y);
            } else {
                first = false;
            }
            lastX = x;
            lastY = y;
        }
    }
    
    float startX = cx + cos(rotation) * innerRadius;
    float startY = cy + sin(rotation) * innerRadius;
    Line((int)lastX, (int)lastY, (int)startX, (int)startY);

    int segments = 8;
    float step = (2.0f * PI) / segments;
    for (int i = 0; i < segments; i++) {
        int x1 = cx + cos(i * step) * axleRadius;
        int y1 = cy + sin(i * step) * axleRadius;
        int x2 = cx + cos((i + 1) * step) * axleRadius;
        int y2 = cy + sin((i + 1) * step) * axleRadius;
        Line(x1, y1, x2, y2);
    }
}
//==============================================================================================



//=================================TABLE PLOTTING===============================================
void PlotTable(byte *SubTable, int SubTableSize, int skip, int opt, int offset) {
  int i = offset;
  while (i < SubTableSize) {
    if (SubTable[i + 2] == skip) {
      i = i + 3;
      if (opt == 1) if (SubTable[i] == skip) i++;
    }
    Line(SubTable[i], SubTable[i + 1], SubTable[i + 2], SubTable[i + 3]);
    i = i + 2;
    if (SubTable[i + 2] == 0xFF) break;
  }
}
//==============================================================================================



//=================================FRACTAL TREE=================================================
void drawTreeBranch(int x, int y, float angle, float len, int depth, float wind) {
    if (depth == 0) return;

    int x2 = x + (int)(cos(angle) * len);
    int y2 = y + (int)(sin(angle) * len); 

    Line(x, y, x2, y2);

    float nextLen = len * 0.73f; 
    float spread = 0.45f;        

    float nextAngleLeft = angle - spread + wind;
    float nextAngleRight = angle + spread + wind;

    drawTreeBranch(x2, y2, nextAngleLeft, nextLen, depth - 1, wind);
    drawTreeBranch(x2, y2, nextAngleRight, nextLen, depth - 1, wind);

    Line(x2, y2, x, y);
}
//==============================================================================================



//==============================Day Cycle Face functions========================================
const int CLOUD_Y_MIN = 50;   
const int CLOUD_Y_MAX = 90;   
const int GROUND_LEVEL = 163;   
const int CX = 128;             
const int CY = 128;             
const int FRAME_RADIUS = 120;   
const float ORBIT_WIDTH = 88.0; 
const float ORBIT_HEIGHT = 120.0;
    

void drawClippedLine(float x0, float y0, float x1, float y1) {
    bool p0_Valid = (sq(x0 - CX) + sq(y0 - CY) <= sq(FRAME_RADIUS)) && (y0 < GROUND_LEVEL);
    bool p1_Valid = (sq(x1 - CX) + sq(y1 - CY) <= sq(FRAME_RADIUS)) && (y1 < GROUND_LEVEL);

    if (p0_Valid && p1_Valid) {
        Line((int)255-x0, (int)255-y0, (int)255-x1, (int)255-y1); 
    }
}

void drawClippedLineClear(float x0, float y0, float x1, float y1) {
    bool p0_Valid = (sq(x0 - CX) + sq(y0 - CY) <= sq(FRAME_RADIUS)) && (y0 < GROUND_LEVEL);
    bool p1_Valid = (sq(x1 - CX) + sq(y1 - CY) <= sq(FRAME_RADIUS)) && (y1 < GROUND_LEVEL);

    if (p0_Valid && p1_Valid) {
        LineClear((int)255-x0, (int)255-y0, (int)255-x1, (int)255-y1); 
    }
}

void drawParametricSun(float sx, float sy, float radius) {
    int segments = 32; 
    float angleStep = TWO_PI / segments;
    
    float lastX = sx + radius;
    float lastY = sy;
    
    for (int i = 1; i <= segments; i++) {
        float angle = i * angleStep;
        float nextX = sx + cos(angle) * radius / 1.4f;
        float nextY = sy + sin(angle) * radius / 1.4f;
        
        drawClippedLine(lastX, lastY, nextX, nextY);
        
        lastX = nextX;
        lastY = nextY;
    }
    
    // Sun rays
    for (int i = 0; i < 8; i++) {
        float angle = i * (TWO_PI / 8.0);
        float startX = sx + cos(angle) * radius / 1.4f;
        float startY = sy + sin(angle) * radius / 1.4f;
        float endX = sx + cos(angle) * (radius + 6);
        float endY = sy + sin(angle) * (radius + 6);
        drawClippedLine(startX, startY, endX, endY);
        drawClippedLine(startX, startY, endX, endY);
    }
}

void drawParametricMoon(float mx, float my, float radius) {
    int segments = 30;
    float angleStep = PI / segments; 
    
    // Outer crescent back (Right side arc)
    float lastX = mx + cos(-PI/2) * radius;
    float lastY = my + sin(-PI/2) * radius;
    
    for (int i = 1; i <= segments; i++) {
        float angle = -PI/2 + (i * angleStep);
        float nextX = mx + cos(angle) * radius;
        float nextY = my + sin(angle) * radius; 
        
        drawClippedLine(lastX, lastY, nextX, nextY);
        
        lastX = nextX;
        lastY = nextY;
    }
    
    
    float innerXScale = 0.55;
    float innerXShift = radius * -0.45; 
    
    lastX = mx + cos(PI/2) * radius;
    lastY = my + sin(PI/2) * radius;
    
    for (int i = 1; i <= segments; i++) {
        float angle = PI/2 - (i * angleStep);
        
        float nextX = mx + (cos(angle) * radius * innerXScale) + innerXShift;
        float nextY = my + sin(angle) * radius;
        
        drawClippedLine(lastX, lastY, nextX, nextY);
        
        lastX = nextX;
        lastY = nextY;
    }
}

void drawParametricCloud(ParametricCloud c) {
    int points = 15; 
    float stepX = c.width / points;
    
    float lastX = c.x;
    float lastY = c.y; // Flat bottom
    
    for (int i = 1; i <= points; i++) {
        float currentX = c.x + (i * stepX);
        float normalizedX = (float)i / points; 
        float lumpHeight = abs(sin(normalizedX * PI + c.phase) * 10.0) + 
                           abs(cos(normalizedX * TWO_PI * 1.5) * 5.0);
            
        if (i == points) lumpHeight = 0; 
        
        float currentY = c.y - lumpHeight;
        
        drawClippedLine(lastX, lastY, currentX, currentY);
        lastX = currentX;
        lastY = currentY;
    }
    drawClippedLineClear(c.x, c.y, c.x + c.width, c.y);
}


void initClouds() {
    for (int i = 0; i < 3; i++) {
        clouds[i].x = 128 - FRAME_RADIUS - random(0, 100);
        clouds[i].y = 128 - random(CLOUD_Y_MIN, CLOUD_Y_MAX); 
        clouds[i].speed = random(2, 8) / 20.0f;
        clouds[i].width = random(30, 75);
        clouds[i].phase = random(0, 314) / 100.0f; 
        clouds[i].active = true;
    }
}
//==============================================================================================
