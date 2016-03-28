#include<cstdio>
int a[25];
int main()
{
    int i;
    int tc;
    for(scanf("%d", &tc);tc--;)
    {
        for(i=1;i<=20;i++) scanf("%d", &a[i]);
        while(true)
        {
            bool flag=false;
            for(i=2;i<=20;i++)
            {
                if(a[i]>=2)
                {
                    flag=true;
                    a[i-1]+=a[i]/2;
                    a[i]%=2;
                }
            }
            if(!flag) break;
        }
        for(i=1;i<=20;i++) printf("%d ", a[i]);
        printf("\n");
    }
    return 0;
}

