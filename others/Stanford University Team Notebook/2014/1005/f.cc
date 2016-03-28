#include<cstdio>
typedef long long ll;
int n;
ll d[30][30];
ll a[10];
int main()
{
    int i, j;
    scanf("%d", &n);
    for(i=n;i>=0;i--) scanf("%lld", &a[i]);
    for(i=0;i<=n;i++)
    {
        d[0][i]=0;
        for(j=n;j>=0;j--) d[0][i]=d[0][i]*i+a[j];
    }
    for(i=1;i<=n;i++)
    {
        for(j=n-i;j>=0;j--) d[i][j]=d[i-1][j+1]-d[i-1][j];
    }
    for(i=0;i<=n;i++) printf("%lld ", d[i][0]);
    printf("\n");
    return 0;
}

