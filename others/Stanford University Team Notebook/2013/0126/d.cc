#include<cstdio>
#include<memory.h>
double d[2][1024];
int main()
{
    int tc;
    for(scanf("%d", &tc);tc--;)
    {
        int t, n;
        double L, R;
        scanf("%d%d%lf%lf", &t, &n, &L, &R);
        memset(d, 0, sizeof(d));
        d[0][0]=1;
        int p=0, q=1;
        for(int i=1;i<=n;i++)
        {
            memset(d[q], 0, sizeof(d[q]));
            d[q][0]+=d[p][0]*(1.0-R);
            d[q][1]+=d[p][0]*R;
            for(int j=1;j<=n;j++)
            {
                d[q][j-1]+=d[p][j]*L;
                d[q][j]+=d[p][j]*(1.0-L-R);
                d[q][j+1]+=d[p][j]*R;
            }
            p=!p; q=!q;
        }
        double ans=0;
        for(int j=0;j<=n;j++) ans+=j*d[p][j];
        printf("%d %.4lf\n", t, ans);
    }
    return 0;
}

