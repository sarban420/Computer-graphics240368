#include <stdio.h>
#include <graphics.h>
#include <math.h>

int xc, yc;
int x, y;

void disp()
{
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
}

int main()
{
    int gd = DETECT, gm;
    int rx, ry;
    float p1, p2;

    initgraph(&gd, &gm, "");

    printf("Enter center point (xc yc): ");
    scanf("%d %d", &xc, &yc);

    printf("Enter Rx and Ry: ");
    scanf("%d %d", &rx, &ry);

    /* REGION 1 */
    x = 0;
    y = ry;

    p1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);

    while ((2 * ry * ry * x) <= (2 * rx * rx * y))
    {
        disp();
        x++;

        if (p1 < 0)
            p1 += (2 * ry * ry * x) + (ry * ry);
        else
        {
            y--;
            p1 += (2 * ry * ry * x) - (2 * rx * rx * y) + (ry * ry);
        }
    }

    /* REGION 2 */
    p2 = (ry * ry * (x + 0.5) * (x + 0.5)) +
         (rx * rx * (y - 1) * (y - 1)) -
         (rx * rx * ry * ry);

    while (y >= 0)
    {
        disp();
        y--;

        if (p2 > 0)
            p2 += (rx * rx) - (2 * rx * rx * y);
        else
        {
            x++;
            p2 += (2 * ry * ry * x) - (2 * rx * rx * y) + (rx * rx);
        }
    }

    getch();
    closegraph();
    return 0;
}
