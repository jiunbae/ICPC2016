#include<cstdio>
typedef long long ll;
int n;
int a[30100];
bool sieve[30100];
int prs[3300];
ll la[30100], ra[30100];
ll lsum[30100], rsum[30100];
ll ans;
inline ll min(ll x, ll y){return x<y?x:y;}
ll move(int s, int e, int dest)
{
    return la[dest]-la[s-1]-lsum[s-1]*(dest-s+1) + ra[dest]-ra[e+1]-rsum[e+1]*(e-dest+1);
}
int main()
{
    int i, j;
    for(i=2;i<=30000;i++)
    {
        if(sieve[i]) continue;
        prs[++prs[0]]=i;
        for(j=i+i;j<=30000;j+=i) sieve[j]=true;
    }
    while(true)
    {
        scanf("%d", &n);
        if(!n) break;
        for(i=1;i<=n;i++) scanf("%d", &a[i]);
        for(i=1;i<=n;i++)
        {
            lsum[i]=lsum[i-1]+a[i];
            la[i]=la[i-1]+lsum[i-1];
        }
        rsum[n+1]=ra[n+1]=0;
        for(i=n;i>=1;i--)
        {
            rsum[i]=rsum[i+1]+a[i];
            ra[i]=ra[i+1]+rsum[i+1];
        }
        ans=la[n];
        for(i=1;i<=n;i++) ans=min(ans, move(1, n, i));
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=prs[0] && prs[j]+i<=n;j++)
            {
                int x=i, y=prs[j]+i;
                int m1=(x+y)/2;
                ans=min(ans, move(1, m1, x)+move(m1+1, n, y));
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=prs[0] && prs[j]+2+i<=n;j++)
            {
                if(sieve[prs[j]+2]) continue;
                {
                int x=i, y=i+2, z=i+2+prs[j];
                int m1=(x+y)/2, m2=(y+z)/2;
                ll t=move(1, m1, x)+move(m1+1, m2, y)+move(m2+1, n, z);
                ans=min(ans, t);}
                {
                int x=i, y=i+prs[j], z=i+2+prs[j];
                int m1=(x+y)/2, m2=(y+z)/2;
                ll t=move(1, m1, x)+move(m1+1, m2, y)+move(m2+1, n, z);
                ans=min(ans, t);}
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=prs[0] && prs[j]+4+i<=n;j++)
            {
                if(sieve[prs[j]+2] || sieve[prs[j]+4]) continue;
                int w=i, x=i+2, y=i+2+prs[j], z=i+2+prs[j]+2;
                int m1=(w+x)/2, m2=(x+y)/2, m3=(y+z)/2;
                ll t=move(1, m1, w)+move(m1+1, m2, x)+move(m2+1, m3, y)+move(m3+1, n, z);
                ans=min(ans, t);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}

