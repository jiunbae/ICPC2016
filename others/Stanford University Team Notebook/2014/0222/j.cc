#include<cstdio>
int n, m;
bool dead[128];
int cnt[128];
bool eq()
{
    int i;
    int x=-1;
    for(i=0;i<n;i++)
    {
        if(dead[i]) continue;
        if(x==-1) x=cnt[i];
        if(x!=cnt[i]) return false;
    }
    return true;
}
int main()
{
    int i;
    while(true)
    {
        scanf("%d", &n);
        if(!n) break;
        scanf("%d", &m);
        for(i=0;i<n;i++){dead[i]=false; cnt[i]=0;}
        int iter;
        int x=0;
        int c;
        for(iter=1;;iter++)
        {
            c=0;
            while(c<m)
            {
                while(dead[x]) x=(x+1)%n;
                cnt[x]++; c++;
                if(c==m){dead[x]=true; break;}
                x=(x+1)%n;
            }
            if(eq()) break;
        }
        int a1=0, a2=0;
        for(i=0;i<n;i++)
        {
            if(dead[i]) continue;
            a1++; a2=cnt[i];
        }
        printf("%d %d\n", a1, a2);
    }
    return 0;
}

