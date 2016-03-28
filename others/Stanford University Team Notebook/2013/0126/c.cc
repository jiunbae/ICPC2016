#include<cstdio>
int main()
{
    int tc;
    for(scanf("%d", &tc);tc--;)
    {
        int t, n;
        scanf("%d%d", &t, &n);
        int ans=0;
        int c;
        for(c=1;c<n-c;c++) //a<b<c
        {
            if(c+(c-1)+(c-2)<n) continue;
            //1, 2, ..., n-c-1
            if(n-c-1<c)
            {
                ans+=n-c-1;
                if((n-c)%2==0) ans-=2;
            }
            else
            {
                int b=c-1;
                int a=n-c-b;
                int k;
                if((b-a)%2==0) k=(b-a)/2-1;
                else k=(b-a)/2;
                ans+=(k+1)*2;
            }
        }
        for(c=1;c*2<n;c++) //a, b=c
        {
            if(n-c*2>=c*2) continue;
            ans++;
        }
        printf("%d %d\n", t, ans);
    }
    return 0;
}

