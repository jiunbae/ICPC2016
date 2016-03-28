#include<cstdio>
#include<queue>
using namespace std;
struct edge{int e, nxt;};
edge a[20100];
int n, h, l, m;
int d[1024];
bool v[1024];
int sp[1024];
queue<int> q;
int main()
{
    int i;
    scanf("%d%d%d", &n, &h, &l);
    for(i=1;i<=h;i++)
    {
        int x;
        scanf("%d", &x); x++;
        v[x]=true; q.push(x);
    }
    for(i=1;i<=l;i++)
    {
        int t1, t2;
        scanf("%d%d", &t1, &t2);
        t1++; t2++;
        a[++m].e=t2; a[m].nxt=sp[t1]; sp[t1]=m;
        a[++m].e=t1; a[m].nxt=sp[t2]; sp[t2]=m;
    }
    while(!q.empty())
    {
        int cur=q.front(); q.pop();
        for(i=sp[cur];i;i=a[i].nxt)
        {
            if(v[a[i].e]) continue;
            v[a[i].e]=true; d[a[i].e]=d[cur]+1;
            q.push(a[i].e);
        }
    }
    int ans=-1;
    for(i=1;i<=n;i++)
    {
        if(!v[i]){ans=i; break;}
    }
    if(ans==-1)
    {
        int b=-1;
        for(i=1;i<=n;i++)
        {
            if(b<d[i]){b=d[i]; ans=i;}
        }
    }
    printf("%d\n", ans-1);
    return 0;
}

