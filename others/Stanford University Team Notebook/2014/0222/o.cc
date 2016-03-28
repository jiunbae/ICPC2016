#include <stdio.h>
#include <memory.h>

int n=12,m=10;
char s[121][110];

bool chk[121][121];

void ff(int x, int y)
{
    chk[x][y]=true;
    char t=s[x][y]; s[x][y]=' ';
    
    if (x-1>=0 && !chk[x-1][y  ] && t==s[x-1][y  ]) ff(x-1, y  );
    if (x+1< n && !chk[x+1][y  ] && t==s[x+1][y  ]) ff(x+1, y  );
    if (y-1>=0 && !chk[x  ][y-1] && t==s[x  ][y-1]) ff(x  , y-1);
    if (y+1< m && !chk[x  ][y+1] && t==s[x  ][y+1]) ff(x  , y+1);
}

int  ffcnt(int x, int y)
{
    chk[x][y]=true;
    char t=s[x][y];
    
    int res=0;
    if (x-1>=0 && !chk[x-1][y  ] && t==s[x-1][y  ]) res+=ffcnt(x-1, y  );
    if (x+1< n && !chk[x+1][y  ] && t==s[x+1][y  ]) res+=ffcnt(x+1, y  );
    if (y-1>=0 && !chk[x  ][y-1] && t==s[x  ][y-1]) res+=ffcnt(x  , y-1);
    if (y+1< m && !chk[x  ][y+1] && t==s[x  ][y+1]) res+=ffcnt(x  , y+1);
    return res+1;
}

bool empty_col (int j)
{
    for (int i=0; i<n; i++) if (s[i][j]!=' ') return false;
    return true;
}

void order ()
{
    for (int j=0; j<m; j++) {
        for (int i=0; i<n; i++) {
            if (s[i][j]==' ') {
                for (int k=i+1; k<n; k++) if (s[k][j]!=' ') {
                    s[i][j] = s[k][j];
                    s[k][j] = ' ';
                    break;
                }
            }
        }
    }
    
    for (int j=0; j<m; j++) {
        if (empty_col (j)) {
            for (int j2=j+1; j2<m; j2++) if (!empty_col(j2)) {
                for (int k=0; k<n; k++) s[k][j] = s[k][j2], s[k][j2]=' ';
                break;
            }
        }
    }
}

int main()
{
    int q;
    while (true) {
        scanf ("%d", &q);
        if (!q) break;
        
        for (int i=n-1; i>=0; i--) scanf ("%s", s[i]);
        for (int i=0; i<q; i++) {
            int x, y;
            char dd[4];
            scanf ("%s%d", dd, &x);
            y=dd[0]-'a'; x--;
            
            memset (chk, 0, sizeof(chk));
            if (ffcnt (x, y)>=3) {
            memset (chk, 0, sizeof(chk));
                ff (x, y);
                order ();
                }
            
            /*
            for (int i=n-1; i>=0; i--) {
                for (int j=0; j<m; j++) printf ("%c", s[i][j]);
                printf("\n");
            }
                printf("\n");
                */
        }
        
        int ans=0;
        for (int i=0; i<n; i++) for (int j=0; j<m; j++) if (s[i][j]!=' ') ans++;
        printf ("%d\n", ans);
    }
    return 0;
}

