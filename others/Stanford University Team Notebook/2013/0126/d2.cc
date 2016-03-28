#include<cstdio>
#include<memory.h>
#include<cmath>
int n;
double L, R;
double pr[1024];
double d[2][1024];
double fct[1024];
void getPr()
{
    memset(d, 0, sizeof(d));
    d[0][0]=1.0;
    int p=0, q=1;
    int i;
    for(int t=0;t<=n;t++)
    {
        pr[t]=0.0;
        for(i=0;i<=n;i++) pr[t]+=d[p][i];
        memset(d[q], 0, sizeof(d[q]));
        for(i=1;i<=n;i++)
        {
            d[q][i+1]+=d[p][i]*L;
            d[q][i]+=d[p][i]*(1.0-L-R);
            d[q][i-1]+=d[p][i]*R;
        }
        d[q][0]+=d[p][0]*(1.0-L-R);
        d[q][1]+=d[p][0]*R;
        p=!p; q=!q;
    }
}
double multinomial(int tot, int a, int b, int c)
{
    return fct[tot]/(fct[a]*fct[b]*fct[c]);
}
int main()
{
    int i;
    fct[0]=1.0;
    for(i=1;i<=1000;i++) fct[i]=fct[i-1]*i;
    int tc;
    for(scanf("%d", &tc);tc--;)
    {
        int tcn;
        scanf("%d%d%lf%lf", &tcn, &n, &L, &R);
        double ans=0.0;
        getPr();
        for(int h=1;h<=n;h++)
        {
            double tmp=0.0;
            for(int a=0;h+a*2<=n;a++)
            {
                for(int b=0;h+a*2+b<=n;b++)
                {
                    int t=n-2*a-b-h;
                    tmp+=pow(L, a)*pow(R, h+a)*pow(1.0-L-R, b)*pr[t]*multinomial(h+a*2+b, a, h+a, b);
                }
            }
            ans+=tmp*h;
        }
        printf("%d %.4lf\n", tcn, ans);
    }
    return 0;
}

