#include<cstdio>
struct line{int x1, y1, x2, y2;};
line a[200];
int n, m, r;
int max(int x, int y){return x<y?y:x;}
bool on(int x, int y, line &l)
{
    int x1=l.x1, y1=l.y1, x2=l.x2, y2=l.y2;
    return (x2-x1)*(y-y1)==(y2-y1)*(x-x1);
}
bool id(line &p, line &q)
{
    return on(p.x1, p.y1, q) && on(p.x2, p.y2, q);
}
bool parallel(line &p, line &q)
{
    int x1=p.x1, y1=p.y1, x2=p.x2, y2=p.y2;
    int x3=q.x1, y3=q.y1, x4=q.x2, y4=q.y2;
    return (y1-y2)*(x3-x4)==(x1-x2)*(y3-y4);
}
int main()
{
    int i, j;
    scanf("%d%d", &m, &n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d%d%d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
        for(j=1;j<i;j++)
        {
            if(id(a[i], a[j])){i--; n--; break;}
        }
    }
    for(i=1;i<=n && parallel(a[1], a[i]);i++);
    if(i>n) r=n+1;
    else r=n*2;
    if(r>=m) printf("0\n");
    else printf("%d\n", max(1, (m+1)/2-n));
    return 0;
}

