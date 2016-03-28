#include<cstdio>
#include<memory.h>
int n, m;
int a[512];
bool b[512][512];
int main()
{
    int tc;
    int i, j;
    for(scanf("%d", &tc);tc--;)
    {
        scanf("%d", &n);
        for(i=1;i<=n;i++) scanf("%d", &a[i]);
        scanf("%d", &m);
        memset(b, false, sizeof(b));
        for(i=1;i<=m;i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            b[x][y]=b[y][x]=true;
        }
        int lst=n-1;
        while(true)
        {
            bool changed=false;
            for(i=1;i<n && i<=lst;i++)
            {
                if(b[a[i]][a[i+1]])
                {
                    b[a[i]][a[i+1]]=b[a[i+1]][a[i]]=false;
                    m--;
                    int t=a[i]; a[i]=a[i+1]; a[i+1]=t;
                    changed=true;
                    lst=i+1;
                }
            }
            if(!changed) break;
        }
        if(m) printf("IMPOSSIBLE\n");
        else
        {
            for(i=1;i<=n;i++) printf("%d ", a[i]);
            printf("\n");
        }
    }
    return 0;
}

