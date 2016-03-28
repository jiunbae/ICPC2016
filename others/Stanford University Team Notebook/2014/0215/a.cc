#include<cstdio>
#include<memory.h>
int n;
char a[16][16];
bool chkcol[16], chksum[32], chkdiff[32];
int ans;
void f1(int row)
{
    if(row>n){ans++; return;}
    int col;
    for(col=1;col<=n;col++)
    {
        if(a[row][col]=='*') continue;
        if(chkcol[col]) continue;
        if(chksum[col+row]) continue;
        if(chkdiff[col-row+16]) continue;
        chkcol[col]=chksum[col+row]=chkdiff[col-row+16]=true;
        f1(row+1);
        chkcol[col]=chksum[col+row]=chkdiff[col-row+16]=false;
    }
}
int main()
{
    int i;
    int tc;
    for(tc=1;;tc++)
    {
        scanf("%d", &n);
        if(!n) break;
        for(i=1;i<=n;i++) scanf("%s", &a[i][1]);
        ans=0;
        memset(chkcol, false, sizeof(chkcol));
        memset(chkdiff, false, sizeof(chkdiff));
        memset(chksum, false, sizeof(chksum));
        f1(1);
        printf("Case %d: %d\n", tc, ans);
    }
    return 0;
}

