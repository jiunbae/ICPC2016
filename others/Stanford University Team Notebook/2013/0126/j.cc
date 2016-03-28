#include<cstdio>
#include<cstring>
char a[128];
char buf[128];
int main()
{
    int tc;
    gets(buf); sscanf(buf, "%d", &tc);
    while(tc--)
    {
        int t, l, m;
        gets(buf); sscanf(buf, "%d", &t);
        gets(a); l=strlen(a)-1;
        printf("%d ", t);
        int cur=0;
        for(scanf("%d", &m);m--;)
        {
            int off;
            scanf("%d", &off);
            cur=(((cur+off)%l)+l)%l;
            printf("%c", a[cur]);
        }
        printf("\n");
        gets(buf);
    }
    return 0;
}

