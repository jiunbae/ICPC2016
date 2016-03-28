#include<cstdio>
#include<set>
#include<map>
using namespace std;
int a[600100];
int b[2200000], sp;
map<int, int> mapforw;
int mapback[600100];
int n, m;
void out()
{
    int x=1;
    int st=(b[1]&1)?(b[1]+1)/2:(b[1]/2)+1;
    while(x<=sp)
    {
        int lc=x<<1, rc=(x<<1)+1;
        if(b[lc]<st){st-=b[lc]; x=rc;}
        else x=lc;
    }
    printf("%d\n", mapback[x-sp]);
    while(x>=1){b[x]--; x>>=1;}
}
void insert(int x)
{
    x+=sp;
    while(x>=1){b[x]++; x>>=1;}
}
int main()
{
    char buf[32];
    while(scanf("%s", buf)==1)
    {
        if(buf[0]=='#') a[++n]=-1;
        else
        {
            sscanf(buf, "%d", &a[++n]);
            mapforw[a[n]]=0;
            m++;
        }
    }
    map<int, int>::iterator it;
    int k;
    for(it=mapforw.begin(), k=1;it!=mapforw.end();++it, k++)
    {
        it->second=k;
        mapback[k]=it->first;
    }
    int i;
    for(i=1;i<=n;i++) if(a[i]>=0)
        a[i]=mapforw[a[i]];
    for(sp=1;sp<m;sp<<=1); sp--;
    for(i=1;i<=n;i++)
    {
        if(a[i]==-1) out();
        else insert(a[i]);
    }
    return 0;
}

