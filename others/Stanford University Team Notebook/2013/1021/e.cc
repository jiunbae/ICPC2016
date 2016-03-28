#include<cstdio>
#include<cmath>
#include<memory.h>
#include<queue>
using namespace std;
int n, m;
double r;
struct point{double x, y;};
point p[210];
struct edge{int e, nxt; double ang, len;};
edge a[40000];
int sp[210];
double d[40000];
bool v[40000];
double dijkstra()
{
    int i;
    memset(v, false, sizeof(v));
    for(i=1;i<=n;i++) d[i]=1e10;
    d[1]=0;
    while(!v[n])
    {
        int mi=-1;
        double md=1e10;
        for(i=1;i<=n;i++)
        {
            if(!v[i] && (mi==-1 || md>d[i]))
            {
                mi=i; md=d[i];
            }
        }
        v[mi]=true;
        for(i=sp[mi];i;i=a[i].nxt)
        {
            if(d[a[i].e]>md+a[i].len) d[a[i].e]=md+a[i].len;
        }
    }
    return d[n];
}
double turnang(double from, double to)
{
    double x=to-from;
    while(x<-180.0) x+=360.0;
    while(x>180.0) x-=360.0;
    return fabs(x);
}
bool works(double mang)
{
    int i;
    memset(v, false, sizeof(v));
    for(i=1;i<=m;i++) d[i]=1e10;
    priority_queue<pair<double, int> > q;
    for(i=sp[1];i;i=a[i].nxt)
    {
        if(a[i].len>r) continue;
        pair<double, int> dat=make_pair(-a[i].len, i);
        q.push(dat);
        d[i]=a[i].len;
    }
    while(!q.empty())
    {
        pair<double, int> tt=q.top(); q.pop();
        int edge=tt.second; double md=-tt.first;
        if(v[edge]) continue;
        v[edge]=true;
        if(a[edge].e==n) return true;
        for(i=sp[a[edge].e];i;i=a[i].nxt)
        {
            if(turnang(a[edge].ang, a[i].ang)>mang) continue;
            if(d[i]>md+a[i].len && md+a[i].len<=r)
            {
                if(a[i].e==n) return true;
                d[i]=md+a[i].len;
                pair<double, int> dat=make_pair(-(md+a[i].len), i);
                q.push(dat);
            }
        }
    }
    return false;
}
int main()
{
    int i;
    scanf("%d%d%lf", &n, &m, &r);
    r*=(1+0.99e-6);
    for(i=1;i<=n;i++) scanf("%lf%lf", &p[i].x, &p[i].y);
    for(i=1;i<=m;i++)
    {
        int t1, t2;
        scanf("%d%d", &t1, &t2);
        a[i].e=t2; a[i].nxt=sp[t1]; sp[t1]=i;
        a[i].ang=atan2(p[t2].y-p[t1].y, p[t2].x-p[t1].x)*180.0/M_PI;
        a[i].len=hypot(p[t2].y-p[t1].y, p[t2].x-p[t1].x);
    }
    if(dijkstra()>r) printf("Impossible\n");
    else
    {
        double s=0.0, e=180.0;
        const double eps=1e-7;
        double ans=180.0;
        while(e-s>eps)
        {
            double mid=(s+e)/2.0;
            if(works(mid)){ans=mid; e=mid;}
            else s=mid;
        }
        printf("%.12lf\n", ans);
    }
    return 0;
}

