#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <graphics.h>

void Bresenham(int x1, int y1, int x2, int y2) {
	
	int dx, dy;
	int d, x, y;
	int incE, incNE;
	
	
	dx = x2 - x1;
	dy = y2 - y1;
	
	x = x1;
	y = y1;
	
	d = 2 * (dy - dx);
	incE = 2 * dy;
	incNE = 2 * (dy - dx);
	
	int gd=DETECT, gm;
	initgraph(&gd, &gm, (char*)"");
	
	putpixel(x, y, WHITE);
	
	while (x < x2) {
		
		if (d <= 0) {
			d += incE;
			x++;
		} else {
			d += incNE;
			x++;
			y++;
		}
		putpixel(x, y, WHITE);
		delay(1);
	}
	
	getch();
    closegraph();
}


