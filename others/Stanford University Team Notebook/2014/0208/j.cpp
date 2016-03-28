#include <cstring>
#include<cstdio>
#include <algorithm>
using namespace std;

char s[20];
int n;

int d[1<<18][18];

int distc (int st, int l1, int l2) {
    int res=0;
    while (l1<l2) {
        res += (st>>l1)&1;
        l1++;
    }
    while (l1>l2) {
        l1--;
        res += (st>>l1)&1;
    }
    return res;
}

int dista (int a, int b)
{
    if (a>b) swap (a, b);
    return min (b-a, 26-b+a);
}

void renew (int& a, int b) {
    if (!a || a>b) a=b;
}

void update (int st, int c, int t)
{
    renew(d[st|(1<<t)][t], d[st][c] + distc (st, c+1, t) + dista (s[c], s[t]) + 1);
}

int main()
{
    while (true) {
        scanf ("%s", s);
        if (s[0]=='0') break;
        n = strlen(s);
        for (int i=0; i<n; i++) {
            s[i]-='A';
        }
        
        for (int i=0; i<(1<<n); i++) for (int j=0; j<n; j++) d[i][j]=0;
        for (int i=0; i<n; i++) d[1<<i][i] = dista (0, s[i]) + 1;
        
        for (int i=1; i<(1<<n); i++) {
            for (int j=0; j<n; j++) if (d[i][j]) {
                for (int k=0; k<n; k++) {
                    if (!(i&(1<<k)))
                        update (i, j, k);
                }
            }
        }
        
        int ans=0;
        for (int i=0; i<n; i++)
            if (d[(1<<n)-1][i] && (!ans || ans > d[(1<<n)-1][i]))
            ans = d[(1<<n)-1][i];
            
        printf ("%d\n", ans);
    }
    return 0;
}

