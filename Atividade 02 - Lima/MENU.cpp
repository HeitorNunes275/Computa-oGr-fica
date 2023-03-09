#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <graphics.h>

void Menu();
void equacaoParametrica(int r, int cor);
void pontoMedio(int x0, int y0, int r);
void equacaoParametricaPreenchida(int r, int cor);
void preencherElipse(int x0, int y0, int a, int b);

int main() {
	
	int opcao;
	Menu();
	scanf("%d", &opcao);
	system("cls");
	
	while (opcao != 6) {
		
		switch (opcao) {
			case 0:
				system("cls");
				break;
			
			case 1:
				equacaoParametrica(100, WHITE);
				break;
				
			case 2:
				pontoMedio(100, 100, 50);
				break;
				
			case 3:
				equacaoParametricaPreenchida(100, WHITE);
				break;
				
			case 4:
				preencherElipse(100, 150, 80, 50);
				break;
				
			case 6:
				exit(0);
				
			default:
				printf("Opcao invalida!\n");
		}
		
		system("cls");
		Menu();
		scanf("%d", &opcao);
		system("cls");
	}
	
	
	return 0;
}


void Menu() {
	
	printf("[0] - Limpar Tela\n");
	printf("[1] - Algoritmo da Equacao Parametrica\n");
	printf("[2] - Algoritmo do Ponto Medio\n");
	printf("[3] - Preenchimento de Circulos\n");
	printf("[4] - Construcao e Preenchimento de Elipses\n");
	printf("[5] - Preenchimento de Poligonos Concavos\n");
	printf("[6] - Sair\n\n");
}




void equacaoParametrica(int r, int cor) {
   
   int y, x, xc, yc;
   float t;
   
   int gd=DETECT, gm;
   initgraph(&gd, &gm, (char*)"");
   
   xc = 150;
   yc = 150;
   
   x = r;
   y = 0;
   
   for (t=1; t<360; t=t+0.1) {
   	putpixel(x + xc, y + yc, cor);
	x = r * cos(3.14 * t/180);
	y = r * sin(3.14 * t/180);
   }
   
   getch(); 
   closegraph();
}



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



void equacaoParametricaPreenchida(int r, int cor) {
   
   int gd=DETECT, gm;
   initgraph(&gd, &gm, (char*)"");
   
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
   getch(); 
   closegraph();
   
}




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




