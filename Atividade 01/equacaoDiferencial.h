#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <graphics.h>

void equacaoDiferencial(int x1, int y1, int x2, int y2) {
	
	int dx, dy;
	
	int passos, x, y;
	
	float incx, incy;
	
	
	dx = x2 - x1;
	dy = y2 - y1;
	
	x = x1;
	y = y1;
	
	int gd=DETECT, gm;
	initgraph(&gd, &gm, (char*)"");
	
	if (abs(dx) > abs(dy)) {
		passos = abs(dx);
	} else {
		passos = abs(dy);
	}
	
	incx = dx / (float) passos;
	incy = dy / (float) passos;
	
	putpixel(x, y, WHITE);
	
	for (int i=0; i<passos; i++) {
		x += incx;
		y += incy;
		putpixel(x, y, WHITE);
		delay(1);
	}
	
	getch();
    closegraph();
}

