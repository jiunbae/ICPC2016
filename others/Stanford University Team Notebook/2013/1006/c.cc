#include<cstdio>
#include<memory.h>
bool pos[64][256];
char a[1048576];
char buf[128];
int n;
int main()
{
    int tc;
    int i, j;
    char c;
    for(scanf("%d", &tc);tc--;)
    {
        memset(pos, false, sizeof(pos));
        scanf("%s", buf);
        n=0;
        for(i=0;buf[i];i++)
        {
            n++;
            if(buf[i]=='[')
            {
                for(j=i+1;buf[j]!=']';j++) pos[n][buf[j]]=true;
                i=j;
            }
            else if(buf[i]=='{')
            {
                for(c='A';c<='Z';c++) pos[n][c]=true;
                for(c='a';c<='z';c++) pos[n][c]=true;
                for(j=i+1;buf[j]!='}';j++) pos[n][buf[j]]=false;
                i=j;
            }
            else if(buf[i]=='?')
            {
                for(c='A';c<='Z';c++) pos[n][c]=true;
                for(c='a';c<='z';c++) pos[n][c]=true;
            }
            else pos[n][buf[i]]=true;
        }
        scanf("%s", &a[1]);
        bool flag=false;
        for(i=1;a[i];i++)
        {
            for(j=1;j<=n;j++)
            {
                if(!a[i+j-1] || !pos[j][a[i+j-1]]) break;
            }
            if(j>n)
            {
                if(flag) printf(" %d", i);
                else printf("%d", i);
                flag=true;
            }
        }
        if(!flag) printf("no match");
        printf("\n");
    }
    return 0;
}

