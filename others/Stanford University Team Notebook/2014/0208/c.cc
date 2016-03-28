#include<cstdio>
#include<memory.h>
#include<vector>
using namespace std;
char a[1024];
bool chk[1024];
vector<int> ans;
int n;
int main()
{
    int i, j;
    while(true)
    {
        scanf("%s", a);
        if(a[0]=='0' && a[1]==0) break;
        n=strlen(a);
        ans.clear();
        for(i=1;i<n;i++) a[i]-='0';
        for(i=1;i<n;i++)
        {
            if(a[i])
            {
                ans.push_back(i);
                for(j=i;j<n;j+=i) a[j]=!a[j];
            }
        }
        for(i=0;i<ans.size();i++) printf("%d%c", ans[i], i<ans.size()-1?' ':'\n');
    }
    return 0;
}

