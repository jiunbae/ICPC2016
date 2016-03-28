#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
char ordering[30];
int rank[30];
int n;
string a[30];
int main()
{
    int i, j, k;
    int tc;
    for(tc=1;;tc++)
    {
        scanf("%d", &n);
        if(!n) break;
        scanf("%s", ordering);
        for(i=0;i<26;i++) rank[ordering[i]-'A'+1]=i;
        for(i=1;i<=n;i++)
        {
            char tmp[128];
            scanf("%s", tmp);
            a[i]=string(tmp);
        }
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                bool sw=false;
                for(k=0;;k++)
                {
                    if(!a[i][k] && !a[j][k]) break;
                    if(!a[i][k] && a[j][k]) break;
                    if(a[i][k] && !a[j][k]){sw=true; break;}
                    if(rank[a[i][k]-'A'+1]<rank[a[j][k]-'A'+1]) break;
                    if(rank[a[i][k]-'A'+1]>rank[a[j][k]-'A'+1]){sw=true; break;}
                }
                if(sw) swap(a[i], a[j]);
            }
        }
        printf("year %d\n", tc);
        for(i=1;i<=n;i++)
        {
            printf("%s\n", a[i].c_str());
        }
    }
    return 0;
}

