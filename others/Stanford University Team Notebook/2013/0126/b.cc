#include<cstdio>
char buf[10000100];
int main()
{
    int tc;
    for(scanf("%d", &tc);tc--;)
    {
        int t;
        int b;
        scanf("%d%d%s", &t, &b, buf);
        int tot=0;
        for(int i=0;buf[i];i++) tot+=buf[i]-'0';
        printf("%d %d\n", t, tot%(b-1));
    }
    return 0;
}

