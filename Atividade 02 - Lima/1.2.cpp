#include <stdio.h>
#include <graphics.h>
#include <math.h>

void preencherElipse(int x0, int y0, int a, int b)
{
	
   int gd=DETECT, gm;
   initgraph(&gd, &gm, (char*)"");
   int x, y;


   for (y = -b; y <= b; y++)
   {
      for (x = -a; x <= a; x++)
      {
         if (x*x*b*b + y*y*a*a <= a*a*b*b)
         {
            putpixel(x0 + x, y0 + y, WHITE);
         }
      }
   }

   getch(); 
   closegraph(); 
}

int main()
{
   int x0, y0, a, b;

   printf("Digite as coordenadas do centro da elipse:\n");
   printf("x0 = ");
   scanf("%d", &x0);
   printf("y0 = ");
   scanf("%d", &y0);

   printf("Digite o semi-eixo maior da elipse: ");
   scanf("%d", &a);
   printf("Digite o semi-eixo menor da elipse: ");
   scanf("%d", &b);

   preencherElipse(x0, y0, a, b);

   return 0;
}

