#include <stdio.h>
#include <memory.h>

int n, m;
char s[110][110];

bool chk[110][110];

void act (int x, int y)
{
    if (s[x][y]=='X') return;
    if (s[x][y]=='D') {
        chk[x][y]=true;
        if (x-1>=0 && !chk[x-1][y]) act(x-1,y);
        if (x+1< n && !chk[x+1][y]) act(x+1,y);
        if (y-1>=0 && !chk[x][y-1]) act(x,y-1);
        if (y+1< m && !chk[x][y+1]) act(x,y+1);
    }
    else s[x][y]++;
}

int main()
{
    int t;
    scanf ("%d", &t);
    while (t--) {
        scanf ("%d%d", &m, &n);
        for (int i=0; i<n; i++) scanf ("%s", s[i]);
        
        int q;
        scanf ("%d", &q);
        for (int i=0; i<q; i++) {
            int x, y;
            scanf ("%d%d", &x, &y);
            memset(chk, 0, sizeof(chk));
            if(s[y][x]<='C') s[y][x]++;
            else act (y, x);
        }
        
        for (int i=0; i<n; i++) printf ("%s\n", s[i]);
    }
    return 0;
}

