#include <stdio.h>
#include <memory.h>

int n, m;
char d[110][110];

int num1[110][110], num2[110][110];
bool edge[2000][2000];

int n1, n2;

bool check[2000];
bool strong[2000];
int back[2000];

int flow (int x)
{
//    printf("%d\n", x);
    if (x==-1) {
        for (int i=0; i<n1; i++) {
            if (!check[i] && !strong[i]) {
                check[i] = true;
                if (flow (i)) {
                    strong[i] = true;
                    return true;
                }
            }
        }
    }
    
    else {
        for (int i=0; i<n2; i++) {
            if (edge[x][i]) {
                if (back[i] == -1) {
                    back[i] = x;
                    return true;
                }
                
                if (!check[back[i]]) {
                    check[back[i]] = true;
                    if (flow (back[i])) {
                        back[i] = x;
                        return true;
                    }
                }
            }
        }
    }
    
    return false;
}

int nwflow ()
{
    int res=0;
    
    memset (strong, 0, sizeof(strong));
    memset (back, -1, sizeof(back));
    
    while (true) {
        memset (check, 0, sizeof(check));
        if (!flow (-1)) break;
        res++;
        
        while (flow (-1))
            res++;
    }
    return res;
}

int main()
{
    int t;
    scanf ("%d", &t);
    while (t--) {
        scanf ("%d%d", &n, &m);
        for (int i=0; i<n; i++) scanf ("%s", d[i]);
        
        int k=0;
        for (int i=0; i<n; i++) {
            for (int j=i&1; j<m; j+=2)
                num1[i][j] = k++;
        }
        n1=k;
        
        k=0;
        for (int i=0; i<n; i++) {
            for (int j=!(i&1); j<m; j+=2)
                num2[i][j] = k++;
        }
        n2=k;
        int sum = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) if (d[i][j] == '*') sum++;
        }
        
        memset (edge, 0, sizeof(edge));
        
        for (int i=0; i<n; i++) {
            for (int j=i&1; j<m; j+=2) if (d[i][j] == '*') {
                if (j-1>=0 && d[i][j-1]=='*') edge[num1[i][j]][num2[i][j-1]] = true;
                if (i-1>=0 && d[i-1][j]=='*') edge[num1[i][j]][num2[i-1][j]] = true;
                if (j+1<m  && d[i][j+1]=='*') edge[num1[i][j]][num2[i][j+1]] = true;
                if (i+1<n  && d[i+1][j]=='*') edge[num1[i][j]][num2[i+1][j]] = true;
            }
        }
        
        printf ("%d\n", sum - nwflow ());
    }
    return 0;
}

