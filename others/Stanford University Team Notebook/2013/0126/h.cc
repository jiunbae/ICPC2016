#include<cstdio>
#include<cmath>
int n, m, cur, lst;
double ang;
struct point{int n; double x, y;};
point a[32];
void advance()
{
    int nxt=-1;
    double best, nang;
    int i;
    for(i=1;i<=n;i++)
    {
        if(i==cur || i==lst) continue;
        double tang=atan2(a[i].y-a[cur].y, a[i].x-a[cur].x);
        if(tang<0) tang+=M_PI;
        double dist;
        if(tang>ang) dist=tang-ang;
        else dist=tang+M_PI-ang;
        if(nxt==-1 || best>dist){nxt=i; best=dist; nang=tang;}
    }
    lst=cur; cur=nxt; ang=nang;
}
int main()
{
    int tc;
    for(scanf("%d", &tc);tc--;)
    {
        int t;
        scanf("%d%d%d%d%lf", &t, &n, &m, &cur, &ang);
        lst=-1;
        ang=ang*M_PI/180.0;
        for(int i=1;i<=n;i++) scanf("%d%lf%lf", &a[i].n, &a[i].x, &a[i].y);
        printf("%d", t);
        for(int i=1;i<=m;i++)
        {
            advance();
            printf(" %d", a[cur].n);
        }
        printf("\n");
    }
    return 0;
}

