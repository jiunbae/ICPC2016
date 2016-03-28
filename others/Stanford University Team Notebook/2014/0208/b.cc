#include<cstdio>
#include <cstring>
#include <memory.h>
#include <map>
using namespace std;

long long k;
char s[10010];
int idx[10010];
map<int, int> dd;

long long c[20];
bool chk[10];

int ans[20];

int m;

int main()
{
    while (true) {
        scanf ("%lld", &k);
        if(!k) break;
        scanf ("%s", s+1);
        
        int n;
        n = strlen(s+1);
        if(n==1)
        {
            if(s[1]=='?')
            {
                if(1<=k && k<=9) printf("%d\n", (int)(k));
                else printf("-1\n");
            }
            else
            {
                if(s[1]=='0') printf("-1\n");
                else if(k==1) printf("%s\n", s+1);
                else printf("-1\n");
            }
            continue;
        }
        if (n&(n+1)) printf ("-1\n");
        else {
            memset (chk, 0, sizeof(chk));
            chk[0]=true;
            dd.clear();
            m=0;
            
            while ((1<<m) < n) m++;
            bool bad=false;
            for (int i=1; i<=n; i++)
            {
                idx[i] = i - ((i-1)&i);
                if(dd.find(idx[i])==dd.end())
                {
                    if(s[i]!='?') dd[idx[i]]=s[i]-'0';
                }
                else if(s[i]!='?' && dd[idx[i]]!=s[i]-'0')
                {
                    bad=true;
                    break;
                }
            }
            if(bad){printf("-1\n"); continue;}
            for (int i=1; i<=n; i++) if (idx[i]!=1 && s[i]!='?') {
                chk[s[i]-'0'] = true;
            }
            
            memset (c, 0, sizeof(c));
            c[m]=1;
            for (int i=m-1; i>0; i--)
            {
                c[i] = c[i+1];
                if(dd.find(1<<i)==dd.end()) c[i]*=9;
            }
            if (dd.find(1) == dd.end()) {
                for (int i=1; i<=9; i++) if (!chk[i]) {
                    c[0] += c[1];
                }
            }
            else
            {
                if(dd[1]==0){printf("-1\n"); continue;}
                for (int i=1; i<=9; i++) if (!chk[i]) {
                    c[0] += c[1];
                }
                if (c[0]) c[0] = c[1];
            }
            
            if (k>c[0]) {printf("-1\n"); continue;}
            
            if (dd.find(1) == dd.end()) {
                for (int i=1; i<=9; i++) if (!chk[i]) {
                    if (k <= c[1]) {
                        ans[0] = i;
                        break;
                    }
                    k -= c[1];
                }
            }
            else ans[0] = dd[1];
            for(int i=1;i<m;i++)
            {
                if(dd.find(1<<i)!=dd.end()){ans[i]=dd[1<<i]; continue;}
                for(int g=0;g<=9;g++)
                {
                    if(g==ans[0]) continue;
                    if(k<=c[i+1]){ans[i]=g; break;}
                    k-=c[i+1];
                }
            }
            bad=false;
            for(int i=1;i<m;i++)
            {
                if(ans[i]==ans[0]){bad=true; break;}
            }
            if(bad) printf("-1\n");
            else
            {
                for(int i=0;i<m;i++) dd[1<<i]=ans[i];
                for(int i=1;i<=n;i++) printf("%d", dd[idx[i]]);
                printf("\n");
            }
        }
    }
    return 0;
}

