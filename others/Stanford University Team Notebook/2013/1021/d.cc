#include<cstdio>
#define MALE 0
#define FEMALE 1
int m;
char a[120];
int cnt;
int main()
{
    int i;
    scanf("%d%s", &m, a);
    int hold=-1;
    int diff=0;
    for(i=0;a[i];i++)
    {
        if(hold==MALE && diff+1<=m)
        {
            hold=-1; cnt++; diff++;
        }
        else if(hold==FEMALE && diff-1>=-m)
        {
            hold=-1; cnt++; diff--;
        }
        if(a[i]=='M')
        {
            if(diff+1<=m){cnt++; diff++;}
            else if(hold==-1) hold=MALE;
            else break;
        }
        else
        {
            if(diff-1>=-m){cnt++; diff--;}
            else if(hold==-1) hold=FEMALE;
            else break;
        }
    }
    if(hold==MALE && diff+1<=m)
    {
        hold=-1; cnt++; diff++;
    }
    else if(hold==FEMALE && diff-1>=-m)
    {
        hold=-1; cnt++; diff--;
    }
    printf("%d\n", cnt);
    return 0;
}

