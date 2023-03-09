#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

void equacaoParametricaPreenchida(int r, int cor) {
   
   int y, x, xc, yc;
   int a, b;
   float t;
   
   
   xc = 150;
   yc = 150;
   
   x = r;
   y = 0;
   
   for (t=1; t<360; t=t+0.1) {
   	
   	putpixel(x + xc, y + yc, cor);
	x = r * cos(3.14 * t/180);
	y = r * sin(3.14 * t/180);
   }
   
   for (b = -r; b<=r; b++) {
   	for (a = -r; a<=r; a++) {
   		
   		if (a*a + b*b <= r*r) {
   			putpixel(xc + a, yc + b, RED);
		   }
	   }
   }
   
   
}



int main() {
	
   int gd=DETECT, gm;
   initgraph(&gd, &gm, (char*)"");	
   
   equacaoParametricaPreenchida(100, WHITE);
   
   getch();
   closegraph();
   
   return 0;
}

