#include<cstdio>
int a, b, c;
inline int max(int x, int y){return x>y?x:y;}
inline int min(int x, int y){return x<y?x:y;}
int maxdig(int x)
{
    int ret=0;
    while(x)
    {
        ret=max(ret, x%10); x/=10;
    }
    return ret;
}
int mindig(int x)
{
    int ret=9;
    while(x)
    {
        ret=min(ret, x%10); x/=10;
    }
    return ret;
}
int conv(int x, int base)
{
    int ret=0;
    int mul=1;
    while(x){ret+=(x%10)*mul; mul*=base; x/=10;}
    return ret;
}
bool base1(int a, int b, int c)
{
    if(!a || !b || !c) return false;
    if(mindig(a)!=1 || mindig(b)!=1 || mindig(c)!=1) return false;
    if(maxdig(a)!=1 || maxdig(b)!=1 || maxdig(c)!=1) return false;
    int cnt=0;
    while(a){a/=10; cnt++;}
    while(b){b/=10; cnt++;}
    while(c){c/=10; cnt--;}
    if(cnt!=0) return false;
    return true;
}
int main()
{
    int tc;
    for(scanf("%d", &tc);tc--;)
    {
        scanf("%d + %d = %d", &a, &b, &c);
        if(base1(a, b, c))
        {
            printf("1\n"); continue;
        }
        int base=max(1, max(max(maxdig(a), maxdig(b)), maxdig(c)))+1;
        bool done=false;
        for(;base<=20;base++)
        {
            if(conv(a, base)+conv(b, base)==conv(c, base))
            {
                printf("%d\n", base);
                done=true;
                break;
            }
        }
        if(!done) printf("0\n");
    }
    return 0;
}

