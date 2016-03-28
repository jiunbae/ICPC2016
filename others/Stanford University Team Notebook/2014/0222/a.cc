#include <stdio.h>
#include <vector>
#include <memory.h>
using namespace std;

int n, m;
char s[160][160];
int num[160][160];

bool range(int x, int y) { return 0<=x && x<n && 0<=y && y<m; }
struct edge {
    edge(){}
    edge(int x, int y, int c) : x(x), y(y), c(c) {}
    int x, y, c;
};
int ec;
edge e[240000];
vector<int> egnum[60000];

void makeedge (int x, int y, int c=1)
{
    e[ec++] = edge (x, y, c);
    e[ec++] = edge (y, x, 0);
}

int sink;

bool chk[60000];
int uc;
int used[240000];
bool found;

void flow (int x)
{
    if (x==sink) {
        found=true;
        return;
    }
    
    chk[x]=true;
    
    for (int i=0; i<egnum[x].size(); i++) {
        int y = e[egnum[x][i]].y;
        int c = e[egnum[x][i]].c;
        
        if (c && !chk[y]) {
            flow (y);
            if (found) {used[uc++] = egnum[x][i]; return;}
        }
    }
}

int main()
{
    int t;
    scanf ("%d", &t);
    while (t--) {
        scanf ("%d%d", &n, &m);
        for (int i=0; i<n; i++) scanf ("%s", s[i]);
        
        ec=0;
        for (int i=0; i<n; i++) for (int j=0; j<m; j++) num[i][j] = i*m+j + 1;
        sink = n*m+1;
        
        for (int i=0; i<n; i++) for (int j=0; j<m; j++) {
            if (i==0 && s[i][j]!='X') makeedge (0, num[i][j]);
            if (i==n-1 && s[i][j]!='X') makeedge (0, num[i][j]);
            if (j==0 && s[i][j]!='X') makeedge (0, num[i][j]);
            if (j==m-1 && s[i][j]!='X') makeedge (0, num[i][j]);
            if (s[i][j]=='D') makeedge (num[i][j], sink, 1000);
            
            int dx[4]={-1, 1, 0, 0};
            int dy[4]={0, 0, -1, 1};
            for (int k=1; k<3; k++) {
                int x=i+dx[k], y=j+dy[k];
                if (range(x, y) && s[i][j]!='X' && s[x][y]!='X')
                    makeedge (num[i][j], num[x][y]), makeedge (num[x][y], num[i][j]);
            }
        }
        
        for (int i=0; i<=sink; i++) egnum[i].clear ();
        for (int i=0; i<ec; i++) egnum[e[i].x].push_back(i);
        
        int ans=0;
        
        while (true) {
            for (int i=0; i<=sink; i++) chk[i]=false;
            uc=found=0;
            
            flow(0);
            if (!found) break;

            ans++;
            for (int i=0; i<uc; i++) {
                int ee = used[i];
                e[ee].c --;
                e[ee^1].c ++;
            }
        }
        
        printf ("%d\n", ans);
    }
    
    return 0;
}

