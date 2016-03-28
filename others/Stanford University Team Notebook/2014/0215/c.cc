#include <stdio.h>
#include <map>
using namespace std;

int n, m;
int x[500100];

map<int, int> aa;

bool ok (int x, int y)
{
    map<int, int>::iterator a = aa.upper_bound (x); a--;
    for(;a->first <= y;a++)
    {
        map<int, int>::iterator c=a; c++;
        if(a->second == 1 && c->first <= y) return false;
    }
    return true;
}

void sortttt (int x, int y)
{
    int cnt[2]={0,0};
    
    map<int, int>::iterator a = aa.upper_bound (x); a--;
    int s=x, e;
    for(;a->first <= y;a++)
    {
        map<int, int>::iterator c=a; c++;
        e=min(y+1, c->first);
        cnt[a->second]+=(e - s);
        s = c->first;
    }
    
    map<int, int>::iterator b = aa.upper_bound (y);
    if(b->first != y+1)
    {
        b--;
        aa[y+1] = b->second;    
    }
    
    a=aa.upper_bound(x); a--;
    while(true)
    {
        map<int, int>::iterator c=a; c++;
        if(c->first <= y) aa.erase(c);
        else break;
    }
    if(cnt[0]!=0) aa[x]=0;
    if(cnt[1]!=0) aa[x+cnt[0]]=1;
    a = aa.find(x+cnt[0]); b = a; b++;
    if(a->second == b->second && b->first!=n) aa.erase(b);
    a = aa.find(x); b = a; b--;
    if(a->second == b->second) aa.erase(a);
}

int main()
{
    int t;
    scanf ("%d", &t);
    while (t--) {
        scanf ("%d", &n);
        for (int i=0; i<n; i++) scanf ("%d", &x[i]);
        
        aa.clear ();
        aa[-1] = 0;

        int prev = 0;
        for (int i=0; i<n; i++) {
            if (prev != x[i]) {
                aa[i] = x[i];
                prev = x[i];
            }
        }
        aa[n] = 1;
        
        scanf ("%d", &m);
        for (int i=0; i<m; i++) {
            char cmd[12];
            int x, y;
            scanf ("%s %d%d", cmd, &x, &y);
            if (cmd[0]=='o') printf ("%s\n", ok (x, y)?"yes":"no");
            else sortttt (x, y);
        }
        printf("\n");
    }
    
    return 0;
}

