#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
double x[14], y[14];
double dist[14][14];
double d[1<<14][14];
int main()
{
    int i, j, k;
    int tc;
    int mask;
    for(scanf("%d", &tc);tc--;)
    {
        scanf("%d", &n); n++;
        for(i=0;i<n;i++) scanf("%lf%lf", &x[i], &y[i]);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++) dist[i][j]=hypot(x[i]-x[j], y[i]-y[j]);
        }
        for(mask=0;mask<(1<<n);mask++)
        {
            for(i=0;i<n;i++) d[mask][i]=1e10;
        }
        d[1][0]=0;
        for(mask=1;mask<(1<<n);mask++)
        {
            for(i=0;i<n;i++)
            {
                if(!(mask&(1<<i))) continue;
                for(j=0;j<n;j++)
                {
                    if(mask&(1<<j)) continue;
                    int nmask=mask|(1<<j);
                    d[nmask][j]=min(d[nmask][j], d[mask][i]+dist[i][j]);
                }
            }
        }
        double ans=1e10;
        for(i=0;i<n;i++) ans=min(ans, d[(1<<n)-1][i]+dist[i][0]);
        printf("%.2lf\n", ans);
    }
    return 0;
}

