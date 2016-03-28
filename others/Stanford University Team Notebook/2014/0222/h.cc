#include <stdio.h>
#include <string.h>

char end[20] = "END OF CASE";
char ans[1000];

int main()
{
    int t;
    scanf ("%d", &t);
    
    while (t--) {
        char c;
        int time=1;
        while (true) {
            scanf ("%c", &c);
            if (c=='\n') break;
        }
        
        int state=0;
        int p=0;
        
        while (true) {
            scanf ("%c", &c);
            
            if (c=='E') {
                p = 1;
                while (p<strlen(end)) {
                    scanf ("%c", &c);
                    if (c==end[p]) p++;
                }
                break;
            }
            else if (c=='\n') time++;
            else if (state==0) {
                if (c=='N') state=1, p=0, ans[p++] = c;
                else if (c=='Z') state=2, p=0, ans[p++] = c;
                else if (c=='R') state=3, p=0, ans[p++] = c;
            }
            else {
                ans[p++] = c;
                if (c==';') {
                    state=0;
                    ans[p] = 0;
                    printf ("%d: %s\n", time, ans);
                }
            }
        }
    }
    
    return 0;
}

