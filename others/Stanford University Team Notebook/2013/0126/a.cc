#include<cstdio>
int main()
{
    int tc;
    for(scanf("%d", &tc);tc;tc--)
    {
        int t, n;
        scanf("%d%d", &t, &n);
        int ans=n;
        while(n!=1)
        {
            if(n&1) n=3*n+1;
            else n>>=1;
            if(ans<n) ans=n;
        }
        printf("%d %d\n", t, ans);
    }
    return 0;
}

