#include<cstdio>
inline int min(int x, int y){return x<y?x:y;}
int main()
{
    int i;
    int tcn, tc;
    scanf("%d", &tc);
    char s[128], t[128];
    int a, b, c, d;
    for(tcn=1;tcn<=tc;tcn++)
    {
        scanf("%s%s", s, t);
        printf("Case %d: ", tcn);
        a=b=c=d=0;
        for(i=0;s[i];i++)
        {
            if(s[i]==t[i]) continue;
            if(s[i]=='?' && t[i]=='0') a++;
            if(s[i]=='?' && t[i]=='1') b++;
            if(s[i]=='0' && t[i]=='1') c++;
            if(s[i]=='1' && t[i]=='0') d++;
        }
        if(d>b+c){printf("-1\n"); continue;}
        int ans=0;
        int t=min(c, d); c-=t; d-=t; ans+=t;
        if(c==0)
        {
            t=min(b, d); b-=t; d-=t; a+=t; ans+=t;
            //guaranteed that b>=0
            ans+=a+b;
        }
        else // d=0
        {
            ans+=a+b+c;
        }
        printf("%d\n", ans);
    }
    return 0;
}

