#include <graphics.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int x1 = 100, y1 = 100, x2 = 200, y2 = 200;
    int dx = x2 - x1, dy = y2 - y1;
    float m = dy / (float)dx;
    if (abs(dx) > abs(dy)) {
        int steps = abs(dx);
        float xinc = dx / (float)steps;
        float yinc = m * xinc;
        float x = x1, y = y1;
        for (int i = 0; i < steps; i++) {
            putpixel(round(x), round(y), WHITE);
            x += xinc;
            y += yinc;
        }
    } else {
        int steps = abs(dy);
        float yinc = dy / (float)steps;
        float xinc = 1 / m * yinc;
        float x = x1, y = y1;
        for (int i = 0; i < steps; i++) {
            putpixel(round(x), round(y), WHITE);
            x += xinc;
            y += yinc;
        }
    }
    getch();
    closegraph();
    return 0;
}
