#include<cstdio>
#include<cstring>
int n, m, r;
int ne;
struct edge{int e, c, nxt;};
edge a[500];
int sp[128];
char names[128][8];
int amm[128];
bool goal[128];
int d[128];
int d2[128];
const int inf=99999999;
bool v[128];
inline int min(int x, int y){return x<y?x:y;}
void dijkstra(int s, int *d)
{
    int i;
    for(i=1;i<=n;i++){d[i]=inf; v[i]=false;}
    d[s]=0;
    while(true)
    {
        int cur=-1;
        for(i=1;i<=n;i++)
        {
            if(v[i]) continue;
            if(cur==-1 || d[cur]>d[i]) cur=i;
        }
        if(cur==-1) break;
        v[cur]=true;
        for(i=sp[cur];i;i=a[i].nxt)
        {
            d[a[i].e]=min(d[a[i].e], d[cur]+a[i].c);
        }
    }
}
int main()
{
    int tc;
    int i;
    for(scanf("%d", &tc);tc--;)
    {
        scanf("%d%d", &n, &m);
        for(i=1;i<=n;i++) sp[i]=0;
        ne=0;
        r=-1;
        for(i=1;i<=n;i++)
        {
            char tmp[8];
            scanf("%s%d%s", names[i], &amm[i], tmp);
            if(tmp[0]=='y') goal[i]=true;
            else goal[i]=false;
            if(amm[i] && !goal[i] && i!=1) r=i;
        }
        ne=0;
        for(i=1;i<=m;i++)
        {
            char c1[8], c2[8];
            int c;
            int p, q;
            scanf("%s%s%d", c1, c2, &c);
            for(p=1;strcmp(names[p], c1);p++);
            for(q=1;strcmp(names[q], c2);q++);
            a[++ne].e=q; a[ne].c=c; a[ne].nxt=sp[p]; sp[p]=ne;
            a[++ne].e=p; a[ne].c=c; a[ne].nxt=sp[q]; sp[q]=ne;
        }
        dijkstra(1, d);
        int ans=inf;
        for(i=1;i<=n;i++)
        {
            if(goal[i] && amm[1]>=d[i]) ans=min(ans, d[i]);
        }
        if(r!=-1)
        {
            dijkstra(r, d2);
            for(i=1;i<=n;i++)
            {
                if(goal[i] && amm[1]>=d[r] && amm[1]+amm[r]-d[r]>=d2[i])
                    ans=min(ans, d[r]+d2[i]);
            }
        }
        if(ans==inf) printf("No safe path\n");
        else printf("%d\n", ans);
    }
    return 0;
}

