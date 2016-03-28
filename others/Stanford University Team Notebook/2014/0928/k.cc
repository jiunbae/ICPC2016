#include<cstdio>
#include<set>
#include<algorithm>
typedef long long ll;
using namespace std;
struct event
{
    int s, e, x, type;
    bool operator < (const event &o) const {return x<o.x;}
};
int n, m;
event a[2500];
multiset<pair<int, int> > d;
ll ans;
int main()
{
    int i, k, l;
    int tc;
    for(scanf("%d", &tc);tc--;)
    {
        scanf("%d", &n);
        m=0;
        for(i=1;i<=n;i++)
        {
            int x1, y1, x2, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            a[++m].s=y1; a[m].e=y2; a[m].x=x1; a[m].type=1;
            a[++m].s=y1; a[m].e=y2; a[m].x=x2; a[m].type=-1;
        }
        sort(&a[1], &a[m+1]);
        ans=0;
        int lastx=a[1].x;
        for(k=1;k<=m;k=l)
        {
            multiset<pair<int, int> >::iterator it1, it2;
            ll len=0;
            for(it1=d.begin();it1!=d.end();it1=it2)
            {
                int lim=it1->second;
                for(it2=it1;it2!=d.end() && it2->first<=lim;++it2) lim=max(lim, it2->second);
                len+=lim-(it1->first);
            }
            int newx=a[k].x;
            ans+=len*(ll)(newx-lastx);
            for(l=k;l<=m && a[k].x==a[l].x;l++)
            {
                if(a[l].type==1) d.insert(make_pair(a[l].s, a[l].e));
                else d.erase(make_pair(a[l].s, a[l].e));
            }
            lastx=newx;
        }
        printf("%lld\n", ans);
    }
    return 0;
}

