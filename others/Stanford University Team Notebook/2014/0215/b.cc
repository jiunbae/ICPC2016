#include<cstdio>
#include<queue>
#include<map>
using namespace std;
int N, x, T, K;
int budget;
struct dimsum{int price, val;};
dimsum a[120];
struct qdat
{
    int i, k, cost;
    qdat(){}
    qdat(int i, int k, int cost): i(i), k(k), cost(cost) {}
    bool operator < (const qdat &o) const
    {
        if(i!=o.i) return i<o.i;
        if(k!=o.k) return k<o.k;
        return cost<o.cost;
    };
};
map<qdat, int> d;
queue<qdat> q[120][240];
inline int max(int x, int y){return x<y?y:x;}
int get_budget(int n, int x, int T)
{
    int s=0, e=n*x;
    int ret=0;
    while(s<=e)
    {
        int z=(s+e)/2;
        if(z+n*T + (int)((z+n*T+9)/10) <= n*x)
        {
            ret=z; s=z+1;
        }
        else e=z-1;
    }
    return ret;
}
void update(qdat &nxt, int val)
{
    if(d.find(nxt)==d.end())
    {
        d[nxt]=val;
        q[nxt.i][nxt.k].push(nxt);
    }
    d[nxt]=max(val, d[nxt]);
}
int main()
{
    int i, j;
    while(true)
    {
        scanf("%d%d%d%d", &N, &x, &T, &K);
        if(!N && !x && !T && !K) break;
        budget=get_budget(N+1, x, T);
        for(i=1;i<=K;i++)
        {
            scanf("%d", &a[i].price);
            int tot=0;
            for(j=1;j<=N+1;j++)
            {
                int tmp; scanf("%d", &tmp); tot+=tmp;
            }
            a[i].val=tot;
        }
        d.clear();
        for(i=0;i<=K;i++)
        {
            for(j=0;j<=2*(N+1);j++)
            {
                while(!q[i][j].empty()) q[i][j].pop();
            }
        }
        qdat cur, nxt;
        nxt=qdat(0, 0, 0);
        q[0][0].push(nxt);
        d[nxt]=0;
        for(i=0;i<K;i++)
        {
            for(j=0;j<=2*(N+1);j++)
            {
                while(!q[i][j].empty())
                {
                    cur=q[i][j].front();
                    q[i][j].pop();
                    nxt=qdat(cur.i+1, cur.k, cur.cost);
                    update(nxt, d[cur]);
                    if(j+1 <= 2*(N+1) && cur.cost+a[i+1].price <= budget)
                    {
                        nxt=qdat(cur.i+1, cur.k+1, cur.cost+a[i+1].price);
                        update(nxt, d[cur]+a[i+1].val);
                    }
                    if(j+2 <= 2*(N+1) && cur.cost+a[i+1].price*2 <= budget)
                    {
                        nxt=qdat(cur.i+1, cur.k+2, cur.cost+a[i+1].price*2);
                        update(nxt, d[cur]+a[i+1].val*2);
                    }
                }
            }
        }
        map<qdat, int>::iterator it;
        int ans=0;
        for(it=d.begin();it!=d.end();++it) ans=max(ans, it->second);
        printf("%.2lf\n", ans/(double)(N+1));
    }
    return 0;
}

