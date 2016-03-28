#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
struct point
{
    int x, y, z;
    bool operator < (const point &o) const
    {
        if(x!=o.x) return x<o.x;
        if(y!=o.y) return y<o.y;
        return z<o.z;
    }
};
const int P=1<<20;
point a[300001];
int val[300001];
map<int, int> bit[P+1];
int n;
int A, B, C=~(1<<31), M=(1<<16)-1;
int r()
{
    A=36969*(A&M)+(A>>16);
    B=18000*(B&M)+(B>>16);
    return (C&((A<<16)+B))%1000000;
}
int query(int yy, int z)
{
    int ret=0;
    for(int y=yy;y;y&=y-1)
    {
        map<int, int>::iterator it=bit[y].upper_bound(z);
        if(it!=bit[y].begin()) ret=max(ret, (--it)->second);
    }
    return ret;
}
void update(int yy, int z, int val)
{
    for(int y=yy;y<=P;y+=(y&-y))
    {
        map<int, int>::iterator i, j;
        i=bit[y].upper_bound(z);
        for(j=i;j!=bit[y].end() && j->second<=val;j++);
        bit[y].erase(i, j);
        i=bit[y].upper_bound(z);
        if(i==bit[y].begin() || (--i)->second<val)
            bit[y][z]=val;
    }
}
int main()
{
    int i, j;
    while(true)
    {
        int n2;
        scanf("%d%d%d%d", &n, &n2, &A, &B);
        if(!n && !n2 && !A && !B) break;
        for(i=1;i<=n;i++) scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
        for(;i<=n+n2;i++){a[i].x=r(); a[i].y=r(); a[i].z=r();}
        n+=n2;
        for(i=1;i<=n;i++){a[i].x++; a[i].y++; a[i].z++;}
        sort(&a[1], &a[n+1]);
        for(i=1;i<=P;i++) bit[i].clear();
        for(i=1;i<=n;i=j)
        {
            for(j=i;j<=n && a[j].x==a[i].x;j++) val[j]=query(a[j].y-1, a[j].z-1)+1;
            for(j=i;j<=n && a[j].x==a[i].x;j++) update(a[j].y, a[j].z, val[j]);
        }
        int ans=0;
        for(i=1;i<=n;i++) ans=max(ans, val[i]);
        printf("%d\n", ans);
    }
    return 0;
}

