#include <stdio.h>
#include <graphics.h>


int pontoDentroFora(int x, int y, int poly[][2], int n) {
  int i, j, c = 0;
  for (i = 0, j = n-1; i < n; j = i++) {
    if (((poly[i][1]>y) != (poly[j][1]>y)) && (x < (poly[j][0]-poly[i][0]) * (y-poly[i][1]) / (poly[j][1]-poly[i][1]) + poly[i][0]))
      c = !c;
  }
  return c;
}

int main() {
  int gd = DETECT, gm;
  initgraph(&gd, &gm, (char*)"");


  int poly[9][2] = {{100, 50}, {150, 150}, {200, 100}, {250, 150}, {300, 50}, {250, 250}, {200, 200}, {150, 250}, {100, 150}};


  drawpoly(9, (int *)poly);


  setfillstyle(SOLID_FILL, BLUE);


  int xmin = poly[0][0], xmax = poly[0][0], ymin = poly[0][1], ymax = poly[0][1];
  int i;
  for (i = 1; i < 9; i++) {
    if (poly[i][0] < xmin) xmin = poly[i][0];
    if (poly[i][0] > xmax) xmax = poly[i][0];
    if (poly[i][1] < ymin) ymin = poly[i][1];
    if (poly[i][1] > ymax) ymax = poly[i][1];
  }


  int x, y;
  for (y = ymin; y <= ymax; y++) {
    for (x = xmin; x <= xmax; x++) {


      if (pontoDentroFora(x, y, poly, 9)) {

        putpixel(x, y, DARKGRAY);
      }
    }
  }

  getch();
  closegraph();
  return 0;
}

