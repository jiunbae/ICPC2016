#include<cstdio>
#include<cstring>
char buf1[100100], buf2[100100];
int main()
{
    FILE *f1=fopen("myout.txt", "r"), *f2=fopen("A.OUT", "r");
    while(fscanf(f1, "%s", buf1)==1)
    {
        fscanf(f2, "%s", buf2);
        if(strcmp(buf1, buf2))
            printf("%s\n%s\n", buf1, buf2);
    }
    fclose(f1); fclose(f2);
    return 0;
}

