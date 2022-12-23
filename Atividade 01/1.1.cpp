#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <graphics.h>

void Menu();
void equacaoGeral();
void equacaoDiferencial();
void Bresenham();

int main() {
	
	int opcao;
	Menu();
	scanf("%d", &opcao);
	system("cls");
	
	while (opcao != 4) {
		
		switch (opcao) {
			case 0:
				system("cls");
				break;
			
			case 1:
				equacaoGeral();
				break;
				
			case 2:
				equacaoDiferencial();
				break;
				
			case 3:
				Bresenham();
				break;
				
			case 4:
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
	printf("[1] - Algoritmo Reta: Equacao Geral\n");
	printf("[2] - Algoritmo Reta: Equacao Diferencial\n");
	printf("[3] - Algoritmo Reta: Bresenham\n");
	printf("[4] - Sair\n\n");
}


void equacaoGeral() {
	
	int x, x0, xf, y0, yf;
	float y, m;
	
	printf("Coordenada x0: ");
	scanf("%d", &x0);
	printf("Coordenada y0: ");
	scanf("%d", &y0);
	printf("Coordenada xf: ");
	scanf("%d", &xf);
	printf("Coordenada yf: ");
	scanf("%d", &yf);
	
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


void equacaoDiferencial() {
	
	int x1, y1, x2, y2;
	int dx, dy;
	
	int passos, x, y;
	
	float incx, incy;
	
	printf("Coordenada x1: ");
	scanf("%d", &x1);
	printf("Coordenada y1: ");
	scanf("%d", &y1);
	printf("Coordenada x2: ");
	scanf("%d", &x2);
	printf("Coordenada y2: ");
	scanf("%d", &y2);
	
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


void Bresenham() {
	
	int x1, y1, x2, y2;
	int dx, dy;
	int d, x, y;
	int incE, incNE;
	
	printf("Coordenada x1: ");
	scanf("%d", &x1);
	printf("Coordenada y1: ");
	scanf("%d", &y1);
	printf("Coordenada x2: ");
	scanf("%d", &x2);
	printf("Coordenada y2: ");
	scanf("%d", &y2);
	
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



