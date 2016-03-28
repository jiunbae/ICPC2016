#include<cstdio>
#include<memory.h>
int n;
int p1[100100], p2[100100];
int b[300000];
int sp;
int f_get(int s, int e)
{
    int ret=0;
    s+=sp; e+=sp;
    while(s<=e)
    {
        if(s==e){ret+=b[s]; break;}
        if(s&1){ret+=b[s]; s=(s+1)>>1;}
        else s>>=1;
        if(e&1) e>>=1;
        else{ret+=b[e]; e=(e-1)>>1;}
    }
    return ret;
}
void f_insert(int x)
{
    x+=sp;
    while(x>=1){b[x]=!b[x]; x>>=1;}
}
int inv(int *a)
{
    int i;
    int ret=0;
    memset(b, 0, sizeof(b));
    for(sp=1;sp<n;sp<<=1);
    sp--;
    for(i=1;i<=n;i++)
    {
        ret+=f_get(a[i]+1, n);
        f_insert(a[i]);
    }
    return ret;
}
int main()
{
    int i;
    scanf("%d", &n);
    for(i=1;i<=n;i++) scanf("%d", &p1[i]);
    for(i=1;i<=n;i++) scanf("%d", &p2[i]);
    if((inv(p1)-inv(p2))%2==0) printf("Possible\n");
    else printf("Impossible\n");
    return 0;
}

