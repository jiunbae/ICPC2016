#include<cstdio>
#include<cmath>
struct point{double x, y;};
int n;
point a[30];
double r;
const double eps=1e-6;
double dist(point &p, point &q){return hypot(p.x-q.x, p.y-q.y);}
double norm(point &p){return hypot(p.x, p.y);}
int test(point &p)
{
    int i;
    int ret=0;
    for(i=1;i<=n;i++)
    {
        if(dist(a[i], p)<=r+eps) ret++;
    }
    return ret;
}
int main()
{
    int tc;
    int i, j;
    for(scanf("%d", &tc);tc--;)
    {
        scanf("%lf%d", &r, &n);
        for(i=1;i<=n;i++) scanf("%lf%lf", &a[i].x, &a[i].y);
        int ans=0;
        if(n>=1) ans=1;
        for(i=1;i<=n;i++)
        {
            int t=test(a[i]); if(ans<t) ans=t;
            for(j=i+1;j<=n;j++)
            {
                if(dist(a[i], a[j])>2*r) continue;
                if(ans<=1) ans=2;
                point mid;
                mid.x=(a[i].x+a[j].x)/2.0;
                mid.y=(a[i].y+a[j].y)/2.0;
                point diff;
                diff.x=a[i].x-a[j].x;
                diff.y=a[i].y-a[j].y;
                point perp;
                perp.x=diff.y; perp.y=-diff.x;
                double len=norm(perp); perp.x/=len; perp.y/=len;
                double d=dist(mid, a[i]);
                if(r*r-d*d<0) continue;
                double d2=sqrt(r*r-d*d);
                point p1, p2;
                p1.x=mid.x+d2*perp.x;
                p1.y=mid.y+d2*perp.y;
                p2.x=mid.x-d2*perp.x;
                p2.y=mid.y-d2*perp.y;
                int t=test(p1);
                if(ans<t) ans=t;
                t=test(p2);
                if(ans<t) ans=t;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

