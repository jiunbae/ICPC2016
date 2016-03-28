#include<cstdio>
typedef long long ll;
ll d[32];
bool chk[32][32];
ll memo[32][32];
ll up(int l, int r)
{
    if(chk[l][r]) return memo[l][r];
    chk[l][r]=true;
    if(l==0 && r==0) return memo[l][r]=1;
    ll ret=0;
    for(int i=1;i<=r;i++) ret+=up(r-i, l+i-1);
    return memo[l][r]=ret;
}
int main()
{
    int n;
    d[1]=1;
    for(n=2;n<=20;n++)
    {
        for(int i=1;i<=n;i++)
            d[n]+=up(i-1, n-i)+up(n-i, i-1);
    }
    int tc;
    for(scanf("%d", &tc);tc--;)
    {
        int t;
        scanf("%d%d", &t, &n);
        printf("%d %lld\n", t, d[n]);
    }
    return 0;
}

