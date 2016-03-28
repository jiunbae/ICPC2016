#include<cstdio>
#include<cmath>
//double f(double x){return 1.0-x*x;}
double f(double x)
{
    return tan(sin(x))-sin(tan(x))+pow(cos(x), 5.0)-0.5;
}
int main()
{
    double a, b;
    int n;
    while(scanf("%lf%lf%d", &a, &b, &n)==3)
    {
        double len=(b-a)/(double)(n);
        double s, e;
        int i;
        int ans=0;
        for(s=a, e=a+len, i=1;i<=n;s+=len, e+=len, i++)
        {
            if(f(s)*f(e)<=0) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}

