#include<cstdio>
typedef long long ll;
const ll base=1000000007;
ll binom[5100][5100];
ll fct[5100];
int n, l, r;
ll f[5100][5100];
int main()
{
    int i, j;
    fct[0]=1;
    for(i=1;i<=5000;i++) fct[i]=(fct[i-1]*i)%base;
    for(i=0;i<=5000;i++)
    {
        binom[i][0]=binom[i][i]=1;
        for(j=1;j<i;j++)
            binom[i][j]=(binom[i-1][j-1]+binom[i-1][j])%base;
    }
    f[0][0]=1;
    for(n=1;n<=5000;n++)
    {
        for(int k=1;k<=n;k++) f[n][k]=((n-1)*f[n-1][k]+f[n-1][k-1])%base;
    }
    while(true)
    {
        scanf("%d%d%d", &n, &l, &r);
        if(!n && !l && !r) break;
        ll ans=0;
        for(int x=1;x<=n;x++)
        {
            ans=ans+(((f[x-1][l-1]*f[n-x][r-1])%base)*binom[n-1][x-1])%base;
            ans%=base;
        }
        printf("%lld\n", ans);
    }
    return 0;
}

