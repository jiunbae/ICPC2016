#include<cstdio>
#include<cstring>
char a[2000], b[2000];
int main()
{
    scanf("%s%s", a, b);
    if(strlen(a)>=strlen(b)) printf("go\n");
    else printf("no\n");
    return 0;
}

