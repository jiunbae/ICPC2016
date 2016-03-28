#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
struct edg
{
    int st, et, c;
};
struct qdat
{
    int x, fuel, t;
    bool operator < (const qdat &o) const
    {
        return t>o.t;
    };
};
inline int min(int x, int y){return x<y?x:y;}
int n, m;
vector<pair<int, vector<edg> > > a[512];
int d[512][500];
void qpush(qdat &nxt, priority_queue<qdat> &q)
{
    if(d[nxt.x][nxt.fuel]==-1 || d[nxt.x][nxt.fuel]>nxt.t)
    {
        d[nxt.x][nxt.fuel]=nxt.t;
        q.push(nxt);
    }
}
int main()
{
    int i, j;
    while(true)
    {
        scanf("%d%d", &n, &m);
        if(!n && !m) break;
        for(i=0;i<n;i++) a[i].clear();
        for(i=1;i<=m;i++)
        {
            int s, e;
            scanf("%d%d", &s, &e);
            vector<edg> tmp;
            while(true)
            {
                edg t;
                scanf("%d%d%d", &t.st, &t.et, &t.c);
                tmp.push_back(t);
                if(t.et==1439) break;
            }
            a[s].push_back(make_pair(e, tmp));
            a[e].push_back(make_pair(s, tmp));
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<=480;j++) d[i][j]=-1;
        }
        d[0][480]=720;
        priority_queue<qdat> q;
        qdat cur, nxt;
        cur.x=0; cur.fuel=480; cur.t=720; q.push(cur);
        while(!q.empty())
        {
            cur=q.top(); q.pop();
            if(d[cur.x][cur.fuel]!=cur.t) continue;
            nxt.x=cur.x;
            nxt.fuel=min(480, cur.fuel+1);
            nxt.t=cur.t+1;
            qpush(nxt, q);
            for(i=0;i<a[cur.x].size();i++)
            {
                nxt.x=a[cur.x][i].first;
                vector<edg> &edglist=a[cur.x][i].second;
                for(j=0;j<edglist.size();j++)
                {
                    int used_fuel=edglist[j].c*2;
                    if(used_fuel>cur.fuel) continue;
                    int cur_time=cur.t%1440;
                    int dep_time;
                    if(edglist[j].st<=cur_time && cur_time<=edglist[j].et)
                        dep_time=cur_time;
                    else if(cur_time<edglist[j].st)
                        dep_time=edglist[j].st;
                    else
                        dep_time=edglist[j].st+1440;
                    int arr_time=dep_time+edglist[j].c;
                    nxt.fuel=cur.fuel-used_fuel;
                    nxt.t=arr_time-cur_time+cur.t;
                    qpush(nxt, q);
                }
            }
        }
        int ans=-1;
        for(i=0;i<=480;i++)
        {
            if(d[n-1][i]==-1) continue;
            if(ans==-1 || ans>d[n-1][i]) ans=d[n-1][i];
        }
        printf("%d\n", ans-720);
    }
    return 0;
}

