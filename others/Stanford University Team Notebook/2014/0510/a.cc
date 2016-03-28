#include<cstdio>
#include<iostream>
#include<fstream>
#include<cmath>
int main()
{
    double ax, ay, bx, by, cx, cy;
    FILE *fp=fopen("bomb.in", "r");
    fscanf(fp, "%lf%lf%lf%lf%lf%lf", &ax, &ay, &bx, &by, &cx, &cy);
    fclose(fp);
    double dab, dbc, dca;
    dab=hypot(ax-bx, ay-by);
    dbc=hypot(bx-cx, by-cy);
    dca=hypot(cx-ax, cy-ay);
    double alpha, beta, gamma;
    alpha=(dab+dca-dbc)/2.0;
    beta =(dbc+dab-dca)/2.0;
    gamma=(dca+dbc-dab)/2.0;
    fp=fopen("bomb.out", "w");
    fprintf(fp, "%.10lf\n%.10lf\n%.10lf\n", alpha, beta, gamma);
    return 0;
}

