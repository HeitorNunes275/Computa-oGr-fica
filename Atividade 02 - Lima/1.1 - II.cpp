#include <stdio.h>
#include <graphics.h>

void pontoMedio(int x0, int y0, int r)
{
   int x = 0;
   int y = r;
   int d = 1 - r;

   initwindow(800, 600);

   while (x <= y)
   {
      putpixel(x0 + x, y0 + y, WHITE);
      putpixel(x0 - x, y0 + y, WHITE);
      putpixel(x0 + x, y0 - y, WHITE);
      putpixel(x0 - x, y0 - y, WHITE);
      putpixel(x0 + y, y0 + x, WHITE);
      putpixel(x0 - y, y0 + x, WHITE);
      putpixel(x0 + y, y0 - x, WHITE);
      putpixel(x0 - y, y0 - x, WHITE);

      if (d < 0)
      {
         d = d + 2*x + 3;
      }
      else
      {
         d = d + 2*(x - y) + 5;
         y--;
      }
      x++;
   }

   getch(); 
   closegraph(); 
}

int main()
{
   int x0, y0, r;

   printf("Digite as coordenadas do centro do circulo:\n");
   printf("x0 = ");
   scanf("%d", &x0);
   printf("y0 = ");
   scanf("%d", &y0);

   printf("Digite o raio do circulo: ");
   scanf("%d", &r);

   pontoMedio(x0, y0, r);

   return 0;
}

