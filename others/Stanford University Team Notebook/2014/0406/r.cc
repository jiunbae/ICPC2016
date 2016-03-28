#include<cstdio>
#include<cmath>
struct point{double x, y, z;};
struct circle{double x, y, r;};
point a[16];
circle b[16];
double H;
bool works(double r)
{
    double L;
    if(r>=H) L=sqrt(H*(2*r-H));
    else L=r;
    if(2*L>100.0) return false;
    int i;
    for(i=1;i<=n;i++)
    {
        b[i].x=a[i].x; b[i].y=a[i].y;
        if(r>=a[i].z) b[i].z=sqrt(a[i].z*(2*r-a[i].z));
        else b[i].z=r;
    }
}
int main()
{
    while(true)
    {
        scanf("%d%lf", &n, &H);
        if(!n) break;
        for(i=1;i<=n;i++) scanf("%lf%lf%lf", &a[i].x, &a[i].y, &a[i].z);
        double s=0.0, e=160.0, mid;
        while(e-s>1e-5)
        {
            mid=(s+e)/2.0;
            if(works(mid)) s=mid;
            else e=mid;
        }
        printf("%.6lf\n", (s+e)/2.0);
    }
    return 0;
}

