#include <stdio.h>
#include <algorithm>
using namespace std;

int n, d[14];

void makenum (long long& a, long long& b, int i)
{
    int c1=0, c2=0;
    a=0, b=0;
    
    for (int j=0; j<n; j++) {
        if (i&(1LL<<j)) {
            if (d[j]==0) c1++;
            else {
                a = a*10 + d[j];
                while (c1) c1--, a=a*10;
            }
        }
        else {
            if (d[j]==0) c2++;
            else {
                b = b*10 + d[j];
                while (c2) c2--, b=b*10;
            }
        }
    }
    
    if (c1!=0 || c2!=0) a=b=0;
}

int main()
{
    while (true) {
        scanf ("%d", &n);
        if (!n) break;
        
        for (int i=0; i<n; i++) scanf ("%d", &d[i]);
        //Stanford00 team00
        
        sort (d, d+n);
        long long ans=-1;
        for (int i=1; i<(1<<n)-1; i++) {
            long long a, b;
            makenum (a, b, i);
            if (a!=0 && b!=0 && (ans==-1 || a+b < ans)) ans = a+b;
        }
        printf ("%lld\n", ans);
    }
    
    return 0;
}

