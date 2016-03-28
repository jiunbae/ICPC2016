#include<cstdio>
int n;
int a[100100];
int main()
{
    int i;
    scanf("%d", &n);
    for(i=1;i<=n;i++)
    {
        a[0]++;
        scanf("%d", &a[a[0]]);
        while(a[0]>=2 && (a[a[0]]+a[a[0]-1])%2==0) a[0]-=2;
    }
    printf("%d\n", a[0]);
    return 0;
}

