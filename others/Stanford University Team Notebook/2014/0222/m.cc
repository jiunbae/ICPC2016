#include <stdio.h>
#include <string.h>
#include <memory.h>

int n;
char ss[4];
bool chk[256];
bool edge[256][256];

        int d;
        
bool found;

int cap[4];
char ans[4][8];

void bt (int ch)
{
    if (ch>'Z') {
        found=true;
        return;
    }
    
    if (!chk[ch]) bt (ch+1);
    
    for (int j=0; j<d; j++) {
        if (cap[j]<6) {
            bool flag=false;
            for (int k=0; k<cap[j]; k++) if (edge[ans[j][k]][ch]) flag=true;
            if (!flag) {
                ans[j][cap[j]++] = ch;
                bt(ch+1);
                if (found) return;
                cap[j]--;
            }
        }
        
        if (!cap[j]) break;
    }
}

int main()
{
    while (true) {
        scanf("%d", &n);
        if (!n) break;
        scanf ("%s", ss);
        
        
        memset(chk, 0, sizeof(chk));
        memset (edge, 0, sizeof(edge));
        chk[ss[0]]=true;
        
        for (int i=0; i<n; i++) {
            char tmp[8];
            scanf ("%s", tmp);
            d=strlen(tmp);
            for (int j=0; j<d; j++) chk[tmp[j]]=true;
            for (int j=0; j<d; j++) for (int k=j+1; k<d; k++) edge[tmp[j]][tmp[k]]=edge[tmp[k]][tmp[j]]=true;
        }
        
        memset (cap,0, sizeof(cap));
        found=false;
        bt ('A');
        for (int i=0; i<d; i++) printf ("%s ", ans[i]);
        printf ("\n");
    }
    return 0;
}
