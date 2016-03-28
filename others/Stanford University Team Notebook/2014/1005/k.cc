#include<cstdio>
#include<cstring>
int n, m;
char a[100][100];
bool v[100][100];
int dx[4]={0, -1, 0, 1};
int dy[4]={-1, 0, 1, 0};
int compno[100][100];
int c[10000];
int nbuses, nislands, nbridges;
void flood(int x, int y)
{
    int i, k;
    v[x][y]=true; compno[x][y]=nislands;
    for(k=0;k<=3;k++)
    {
        int nx=x+dx[k], ny=y+dy[k];
        if(nx<1 || ny<1 || nx>n || ny>m) continue;
        if(!v[nx][ny] && (a[nx][ny]=='X' || a[nx][ny]=='#')) flood(nx, ny);
    }
}
bool horbr(int i, int j)
{
    int s, e;
    for(s=j;a[i][s]=='B';s--);
    for(e=j;a[i][e]=='B';e++);
    return a[i][s]=='X' && a[i][e]=='X';
}
int find(int x){return c[x]==x?x:c[x]=find(c[x]);}
bool filldir(int i, int j, int dx, int dy)
{
    int x, y;
    int i1, i2;
    for(x=i, y=j;a[x][y]=='B';x+=dx, y+=dy) v[x][y]=true;
    i1=compno[x][y];
    for(x=i, y=j;a[x][y]=='B';x-=dx, y-=dy) v[x][y]=true;
    i2=compno[x][y];
    c[find(i2)]=find(i1);
}
int main()
{
    bool endflag=false;
    int i, j;
    for(int tc=1;!endflag;tc++)
    {
        for(n=1;;n++)
        {
            if(!gets(&a[n][1])){endflag=true; break;}
            if(!a[n][1]) break;
        }
        n--; m=strlen(&a[1][1]);
        nbuses=nislands=nbridges=0;
        
        memset(v, false, sizeof(v));
        memset(compno, 0, sizeof(compno));
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(v[i][j] || a[i][j]=='B' || a[i][j]=='.') continue;
                nislands++; flood(i, j);
            }
        }
        for(i=1;i<=nislands;i++) c[i]=i;
        
        memset(v, false, sizeof(v));
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(v[i][j] || a[i][j]!='B') continue;
                nbridges++;
                if(horbr(i, j)) filldir(i, j, 0, 1);
                else filldir(i, j, 1, 0);
            }
        }
        
        for(i=1;i<=nislands;i++)
        {
            if(c[i]==i) nbuses++;
        }
        printf("Map %d\nislands: %d\nbridges: %d\nbuses needed: %d\n\n", tc, nislands, nbridges, nbuses);
    }
    return 0;
}

