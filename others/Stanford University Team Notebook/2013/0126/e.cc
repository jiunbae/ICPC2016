#include<cstdio>
typedef long long ll;
ll gcd(ll x, ll y)
{
    while(y){ll t=x%y; x=y; y=t;}
    return x;
}
struct frac
{
    ll u, d;
    frac operator * (const frac &o) const
    {
        frac ret;
        ret.u=u*o.u; ret.d=d*o.d;
        ll g=gcd(ret.u, ret.d);
        ret.u/=g; ret.d/=g;
        if(ret.d<0){ret.u=-ret.u; ret.d=-ret.d;}
        return ret;
    }
    frac operator - (const frac &o) const
    {
        frac ret;
        ret.u=u*o.d-d*o.u; ret.d=d*o.d;
        ll g=gcd(ret.u, ret.d);
        ret.u/=g; ret.d/=g;
        if(ret.d<0){ret.u=-ret.u; ret.d=-ret.d;}
        return ret;
    }
};
frac f[420][420];
int main()
{
    f[0][1].u=f[0][1].d=1;
    int i, j;
    for(i=1;i<=400;i++)
    {
        f[i][1].u=f[i][1].d=1;
        for(j=2;j<=i+1;j++)
        {
            frac t; t.u=i; t.d=j;
            f[i][j]=f[i-1][j-1]*t;
            f[i][1]=f[i][1]-f[i][j];
        }
    }
    int tc;
    for(scanf("%d", &tc);tc--;)
    {
        int t;
        scanf("%d%d%d", &t, &i, &j);
        if(f[i][j].d==1) printf("%d %lld\n", t, f[i][j].u);
        else printf("%d %lld/%lld\n", t, f[i][j].u, f[i][j].d);
    }
    return 0;
}

