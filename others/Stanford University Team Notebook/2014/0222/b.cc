#include<cstdio>
int main()
{
    int tc;
    for(scanf("%d", &tc);tc--;)
    {
        int sm, sy, em, ey;
        scanf("%d%d%d%d", &sm, &sy, &em, &ey);
        if(sy==ey)
        {
            printf("%.4lf\n", 0.5*(em-sm)/(13.0-sm));
        }
        else
        {
            double ans=0.5; sy++;
            ans+=(ey-sy);
            ans+=(double)(em-1)/12.0;
            printf("%.4lf\n", ans);
        }
    }
    return 0;
}

