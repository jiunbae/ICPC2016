#include<cstdio>
int main()
{
    int n, m;
    while(true)
    {
        scanf("%d", &n);
        if(!n) break;
        scanf("%d", &m);
        int a, b, c, d;
        for(a=1, b=2, c=n-1, d=n;b<=c;a+=2, b+=2, c-=2, d-=2)
        {
            if(m==a) printf("%d %d %d\n", b, c, d);
            else if(m==b) printf("%d %d %d\n", a, c, d);
            else if(m==c) printf("%d %d %d\n", a, b, d);
            else if(m==d) printf("%d %d %d\n", a, b, c);
            else continue;
            break;
        }
    }
    return 0;
}

