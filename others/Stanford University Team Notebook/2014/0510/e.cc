#include<cstdio>
#include<map>
typedef long long ll;
using namespace std;
map<int, ll> d[35];
int pow3[12];
int cont[12];
int n, m;
int get_index()
{
    int ret=0;
    for(int i=n;i>=1;i--) ret=ret*3+(cont[i]-1);
    return ret;
}
void f1(int i, int k, ll val)
{
    if(i>n)
    {
        d[k+1][get_index()]+=val;
        return;
    }
    if(cont[i]) f1(i+1, k, val);
    else
    {
        if(i+2<=n && !cont[i+1] && !cont[i+2])
        {
            cont[i]++; cont[i+1]++; cont[i+2]++;
            f1(i+3, k, val);
            cont[i]--; cont[i+1]--; cont[i+2]--;
        }
        cont[i]+=3;
        f1(i+1, k, val);
        cont[i]-=3;
    }
}
int main()
{
    FILE *fp=fopen("dominoes.in", "r");
    fscanf(fp, "%d%d", &n, &m);
    if(n>m){int t=n; n=m; m=t;}
    fclose(fp);
    fp=fopen("dominoes.out", "w");
    if((n*m)%3){fprintf(fp, "0\n"); fclose(fp); return 0;}
    int i, k;
    pow3[0]=1;
    for(i=1;i<=11;i++) pow3[i]=pow3[i-1]*3;
    d[0][pow3[n]-1]=1;
    for(k=0;k<=m+1;k++)
    {
        map<int, ll>::iterator it;
        for(it=d[k].begin();it!=d[k].end();++it)
        {
            int t=it->first;
            for(i=1;i<=n;i++){cont[i]=t%3; t/=3;}
            f1(1, k, it->second);
        }
    }
    fprintf(fp, "%lld\n", d[m+2][0]);
    fclose(fp);
    return 0;
}

