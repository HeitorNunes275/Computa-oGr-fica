#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <graphics.h>

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

