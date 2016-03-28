#include <stdio.h>
#include <memory.h>

int d[10];

bool possible(int c){
    if (c==4) return true;
    for (int i=1; i<=9; i++) {
        if (d[i]==3) {
            d[i]=0;
            if (possible(c+1)) return true;
            d[i]=3;
        }
        if (i<=7 && d[i] && d[i+1] && d[i+2]) {
            d[i]--; d[i+1]--; d[i+2]--;
            if (possible(c+1)) return true;
            d[i]++; d[i+1]++; d[i+2]++;
        }
    }
    return false;
}

int main()
{
    int t;
    scanf ("%d", &t);
    while (t--) {
        int x;
        memset (d, 0, sizeof(d));
        for (int i=0; i<14; i++) scanf ("%d", &x), d[x]++;
        
        bool ans=false;
        for (int i=1; i<=9; i++) {
            if (d[i]>=2) {
                d[i]-=2;
                if (possible(0)) {
                    ans=true;
                    break;
                }
                d[i]+=2;
            }
        }
        printf (ans ? "Vulnerable\n" : "Immune\n");
    }
    
    return 0;
}

