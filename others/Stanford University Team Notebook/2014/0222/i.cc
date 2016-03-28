#include<cstdio>
#include<memory.h>
bool a[100][100];
bool v[100];
bool found;
int n;
void f1(int x)
{
    if(x==53){found=true; return;}
    int i;
    v[x]=true;
    for(i=1;i<=53;i++)
    {
        if(v[i] || !a[x][i]) continue;
        f1(i);
        if(found){a[x][i]=false; a[i][x]=true; return;}
    }
}
int main()
{
    int i;
    while(true)
    {
        scanf("%d", &n);
        if(!n) break;
        memset(a, 0, sizeof(a));
        for(i=1;i<=n;i++)
        {
            int t1, t2;
            char tmp[128];
            scanf("%s", tmp);
            t1=tmp[0]-'A'+1;
            scanf("%s", tmp);
            t2=tmp[0]-'A'+1;
            a[t1][26+t2]=true;
        }
        for(i=1;i<=26;i++){a[0][i]=true; a[i+26][53]=true;}
        int ans=0;
        while(true)
        {
            found=false;
            memset(v, false, sizeof(v));
            f1(0);
            if(!found) break;
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}

