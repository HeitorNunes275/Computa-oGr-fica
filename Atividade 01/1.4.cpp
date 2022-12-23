#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <graphics.h>

void equacaoDiferencial(int x1, int y1, int x2, int y2);


int main() {
	
	equacaoDiferencial(25, 50, 100, 200);
	
	return 0;
}



void equacaoDiferencial(int x1, int y1, int x2, int y2) {
	
	int dx, dy;
	int aux1, aux2;
	
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
	
	aux1 = x;
	aux2 = y;
	
	incx = dx / (float) passos;
	incy = dy / (float) passos;
	
	putpixel(x, y, WHITE);
	
	for (int i=0; i<passos; i++) {
		x += incx;
		y += incy+1;
		putpixel(x, y, WHITE);
		delay(1);
	}
	
	
	for (int i=0; i<passos; i++) {
		x += incy+1;
		y += incx;
		putpixel(x, y, WHITE);
		delay(1);
	}
	
	
	
	getch();
    closegraph();
}
