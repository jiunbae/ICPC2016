#include<cstdio>
#include<memory.h>
const double eps=1e-4;
int n, m, c;
double d[64];
struct edge{int e, c, nxt; double a, b;};
edge a[64];
int sp[64];
bool v[64];
int from[64], fromedge[64];
bool works(double x)
{
    int i, j;
    for(i=1;i<=m;i++) a[i].c=0;
    int tot=0;
    while(tot<c)
    {
        for(i=1;i<=n;i++) d[i]=1e7;
        d[1]=0;
        memset(v, false, sizeof(v));
        while(!v[n])
        {
            int mi=-1; double minl=1e7;
            for(i=1;i<=n;i++)
            {
                if(!v[i] && minl>d[i]){minl=d[i]; mi=i;}
            }
            v[mi]=true;
            for(i=sp[mi];i;i=a[i].nxt)
            {
                if(d[a[i].e]>minl+a[i].a*(a[i].c+1)+a[i].b)
                {
                    d[a[i].e]=minl+a[i].a*(a[i].c+1)+a[i].b;
                    from[a[i].e]=mi;
                    fromedge[a[i].e]=i;
                }
            }
        }
        if(d[n]>x) break;
        double ta=0.0, tb=0.0;
        for(int cur=n;cur!=1;cur=from[cur])
        {
            i=fromedge[cur];
            ta+=a[i].a; tb+=a[i].a*a[i].c+a[i].b;
        }
        int cc=(int)((x-tb)/ta);
        tot+=cc;
        for(int cur=n;cur!=1;cur=from[cur])
        {
            i=fromedge[cur];
            a[i].c+=cc;
        }
    }
    return tot>=c;
}
int main()
{
    int tc;
    int i;
    for(scanf("%d", &tc);tc--;)
    {
        scanf("%d%d%d", &n, &m, &c);
        for(i=1;i<=n;i++) sp[i]=0;
        int mm=0;
        for(i=1;i<=m;i++)
        {
            int from, to;
            double aa, bb;
            scanf("%d%d%lf%lf", &from, &to, &aa, &bb);
            from++; to++;
            a[++mm].e=to; a[mm].a=aa; a[mm].b=bb; a[mm].nxt=sp[from]; a[mm].c=0; sp[from]=mm;
        }
        m=mm;
        double s, e, mid;
        s=0.0; e=1e7;
        int ans;
        while(e-s>eps)
        {
            mid=(s+e)/2.0;
            if(works(mid)){ans=mid; e=mid;}
            else s=mid;
        }
        printf("%d\n", (int)(ans));
    }
    return 0;
}

