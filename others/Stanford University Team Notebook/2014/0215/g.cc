#include<cstdio>
#include<memory.h>
int a[120][120];
const int inf=999999;
int ans;
int found;
int s, e, m;
bool v[120];
int n;
inline int min(int x, int y){return x<y?x:y;}
void f1(int x, int cap)
{
    int i;
    if(x==e){found=cap; ans+=cap; return;}
    v[x]=true;
    for(i=1;i<=n;i++)
    {
        if(v[i] || !a[x][i]) continue;
        f1(i, min(cap, a[x][i]));
        if(found)
        {
            a[x][i]-=found; a[i][x]+=found;
            return;
        }
    }
}
int main()
{
    int t1, t2, t3;
    int i;
    int tc;
    for(tc=1;;tc++)
    {
        scanf("%d", &n);
        if(n==0) break;
        scanf("%d%d%d", &s, &e, &m);
        memset(a, 0, sizeof(a));
        for(i=1;i<=m;i++)
        {
            scanf("%d%d%d", &t1, &t2, &t3);
            a[t1][t2]+=t3; a[t2][t1]+=t3;
        }
        ans=0;
        while(true)
        {
            memset(v, false, sizeof(v));
            found=0;
            f1(s, inf);
            if(!found) break;
        }
        printf("Network %d\n", tc);
        printf("The bandwidth is %d.\n\n", ans);
    }
    return 0;
}

