#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int PolygonPoints[3][2];

void PolyLine()
{
    int i;
    cleardevice();

    // Draw axes
    line(0,240,640,240);   // X-axis
    line(320,0,320,480);   // Y-axis

    // Draw polygon
    for(i = 0; i < 3; i++)
    {
        line(PolygonPoints[i][0], PolygonPoints[i][1],
             PolygonPoints[(i+1)%3][0], PolygonPoints[(i+1)%3][1]);
    }
}

void ReflectX()
{
    int i;
    for(i = 0; i < 3; i++)
    {
        PolygonPoints[i][1] = 480 - PolygonPoints[i][1];
    }
}

int main()
{
    int gd = DETECT, gm;
    int i, x, y;

    printf("Enter coordinates of triangle:\n");
    for(i = 0; i < 3; i++)
    {
        printf("Point %d (x y): ", i+1);
        scanf("%d %d", &x, &y);

        // Convert to screen coordinates
        PolygonPoints[i][0] = 320 + x;
        PolygonPoints[i][1] = 240 - y;
    }

    initgraph(&gd, &gm, "");

    // Draw original polygon
    PolyLine();
    getch();

    // Reflect along X-axis
    ReflectX();
    PolyLine();
    getch();

    closegraph();
    return 0;
}
