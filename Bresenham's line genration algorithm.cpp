#include <graphics.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int x1 = 100, y1 = 100, x2 = 200, y2 = 200;
    int dx = abs(x2 - x1), dy = abs(y2 - y1);
    int x = x1, y = y1;
    int sx = (x2 > x1) ? 1 : -1;
    int sy = (y2 > y1) ? 1 : -1;
    if (dx > dy) {
        int p = 2 * dy - dx;
        while (x != x2) {
            putpixel(x, y, WHITE);
            x += sx;
            if (p < 0) {
                p += 2 * dy;
            } else {
                p += 2 * (dy - dx);
                y += sy;
            }
        }
    } else {
        int p = 2 * dx - dy;
        while (y != y2) {
            putpixel(x, y, WHITE);
            y += sy;
            if (p < 0) {
                p += 2 * dx;
            } else {
                p += 2 * (dx - dy);
                x += sx;
            }
        }
    }
    getch();
    closegraph();
    return 0;
}
