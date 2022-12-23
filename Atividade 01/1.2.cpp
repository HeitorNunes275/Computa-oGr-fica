#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <graphics.h>

void equacaoGeral(int x0, int xf, int y0, int yf);
void equacaoDiferencial(int x1, int y1, int x2, int y2);
void Bresenham(int x1, int y1, int x2, int y2);

int main() {
	
//	equacaoGeral(25, 60, 100, 200);
//	equacaoDiferencial(25, 50, 100, 200);
//	Bresenham(25, 25, 90, 90);

	return 0;
	
}


void equacaoGeral(int x0, int xf, int y0, int yf) {
	
	int x;
	float y, m;
	
	
	int gd=DETECT, gm;
	initgraph(&gd, &gm, (char*)"");
	
	m = (yf - y0) / (xf - x0);
	
	for (x = x0; x <= xf; x++) {
		y = y0 + m * (x - x0);
		putpixel(x, round(y), WHITE);
		delay(1);
	}
	
	getch();
    closegraph();
}


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
