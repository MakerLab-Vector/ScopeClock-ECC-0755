//======================================PSEUDO 3D GRAPHICS============================================
int32_t fast_sin(int32_t x) { 
    x = ((x % 360) + 360) % 360;
    if (x <= 180) return (16384 * x * (180 - x)) / (40500 - x * (180 - x)); 
    else { x -= 180; return -((16384 * x * (180 - x)) / (40500 - x * (180 - x))); }
}

int32_t fast_cos(int32_t x) { return fast_sin(x + 90); }

void rotate3D(int &px, int &py, int &pz, int tiltX, int tiltY) {
    int32_t sx = fast_sin(tiltX), cx = fast_cos(tiltX);
    int32_t sy = fast_sin(tiltY), cy = fast_cos(tiltY);
    int32_t y1 = (py * cx - pz * sx) >> 12;
    int32_t z1 = (py * sx + pz * cx) >> 12;
    int32_t x1 = (px * cy + z1 * sy) >> 12;
    int32_t z2 = (-px * sy + z1 * cy) >> 12;
    px = (int)x1; py = (int)y1; pz = (int)z2;
}

bool isOccluded(int px, int py, int pz, Particle* parts, int num) {
    for (int j = 0; j < num; j++) {
        if (parts[j].z > pz) {
            int dx = px - parts[j].x;
            int dy = py - parts[j].y;
            if ((dx*dx + dy*dy) < (parts[j].r * parts[j].r)) return true;
        }
    }
    return false;
}

void drawNucleon(Particle p, Particle* all, int n) {
    int lastX, lastY;
    bool lastVis = false;
    for (int i = 0; i <= 12; i++) {
        int deg = i * 30;
        int px = p.x + ((p.r * fast_sin(deg)) >> 12);
        int py = p.y - ((p.r * fast_cos(deg)) >> 12);
        bool vis = !isOccluded(px, py, p.z + 1, all, n);
        if (vis && lastVis && i > 0) Line(lastX, lastY, px, py);
        lastX = px; lastY = py; lastVis = vis;
    }
}

void drawElectronWithTail(int radius, int t_now, int tiltX, int tiltY, Particle* nucleus, int nNum) {
    int lastX, lastY;
    bool lastVis = false;
    
    for (int i = 0; i <= 6; i++) {
        int deg = t_now - (i * 5); 
        int x = (radius * fast_sin(deg)) >> 12, y = 0, z = (radius * fast_cos(deg)) >> 12;
        rotate3D(x, y, z, tiltX, tiltY);
        int px = 128 + x, py = 128 - y;
        
        bool vis = !isOccluded(px, py, z, nucleus, nNum);
        if (vis && lastVis && i > 0) Line(lastX, lastY, px, py);
        
        if (i == 0) {
            
            int dynamicR = 5 + (z >> 4); 
            if (dynamicR < 1) dynamicR = 1; 

            int hLastX, hLastY;
            bool hLastVis = false;
            for (int j = 0; j <= 8; j++) {
                int hDeg = j * 45;
                int hx = px + ((dynamicR * fast_sin(hDeg)) >> 12);
                int hy = py - ((dynamicR * fast_cos(hDeg)) >> 12);
                bool hVis = !isOccluded(hx, hy, z + 1, nucleus, nNum);
                if (hVis && hLastVis && j > 0) Line(hLastX, hLastY, hx, hy);
                hLastX = hx; hLastY = hy; hLastVis = hVis;
            }
        }
        
        lastX = px; lastY = py; lastVis = vis;
    }
}

void drawWireframeScaled(const int8_t v[][3], int vC, const Edge e[], int eC, int xO, int yO, int rx, int ry, float scale) {
    int px[32], py[32]; 
    for(int i = 0; i < vC; i++) {
        int x = (int)(v[i][0] * scale);
        int y = (int)(v[i][1] * scale);
        int z = (int)(v[i][2] * scale);
        rotate3D(x, y, z, rx, ry);
        px[i] = xO + x; py[i] = yO - y;
    }
    for(int i = 0; i < eC; i++) {
        Line(px[e[i].v1], py[e[i].v1], px[e[i].v2], py[e[i].v2]);
    }
}

void draw3DConeScaled(int xO, int yO, int rx, int ry, float scale) {
    int ax = 0, ay = (int)(50 * scale), az = 0;
    rotate3D(ax, ay, az, rx, ry);
    int lx, ly;
    for(int i = 0; i <= 12; i++) {
        int deg = i * 30;
        int x = (int)((40 * fast_sin(deg)) >> 12) * scale;
        int y = (int)(-30 * scale);
        int z = (int)((40 * fast_cos(deg)) >> 12) * scale;
        rotate3D(x, y, z, rx, ry);
        int px = xO + x, py = yO - y;
        if(i > 0) {
            Line(lx, ly, px, py);
            if(i % 3 == 0) Line(px, py, xO + ax, yO - ay);
        }
        lx = px; ly = py;
    }
}

void drawStarfieldTunnel(uint32_t t, int winX, int winY) {
    const int numStars = 35; 
    const int safeZone = 45; 

    for (int i = 0; i < numStars; i++) {
        uint32_t seed = i * 157; 
        uint32_t speed = 1; 
        
        int32_t z = (1000 - ((t * speed + seed) % 1000));
        
        int32_t rawX = ((int32_t)(i * 83) % 800) - 400;
        int32_t rawY = ((int32_t)(i * 109) % 800) - 400;

        int32_t projX = (rawX * 250) / (z + 1);
        int32_t projY = (rawY * 250) / (z + 1);

        int distSq = (projX * projX + projY * projY);
        
        if (distSq > (safeZone * safeZone)) {
            int px = winX + projX;
            int py = winY + projY;

            int tailX = (rawX * 250) / (z + 25);
            int tailY = (rawY * 250) / (z + 25);
            int pTailX = winX + tailX;
            int pTailY = winY + tailY;

            if (px >= 0 && px <= 255 && py >= 0 && py <= 255 &&
                pTailX >= 0 && pTailX <= 255 && pTailY >= 0 && pTailY <= 255) {
                
                Line(px, py, pTailX, pTailY);
            }
        }
    }
}
//==========================================================================================================
