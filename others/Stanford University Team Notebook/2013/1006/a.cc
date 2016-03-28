#include<cstdio>
#include<cstring>
char spell[4][10][10]={
{"ZERO", "UNU", "DOI", "TREI", "PATRU", "CINCI", "SASE", "SAPTE", "OPT", "NOUA"},
{"SIFIR", "BIR", "IKI", "UC", "DORT", "BES", "ALTI", "YEDI", "SEKIZ", "DOKUZ"},
{"ZERO", "JEDEN", "DWA", "TRZY", "CZTERY", "PIEC", "SZESC", "SIEDEM", "OSIEM", "DZIEWIEC"},
{"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"}};
char a[100100];
int nextletter[100100][30]; //first occurrence of letter j in a[i...]
int mlen[100100];
int dig[100100], from[100100];
int nextpointer[100100][4][10];
int n;
char opt[100100]; int optlen;
char best[100100]; int bestlen;
int get_next_pointer(int s, int lang, int d)
{
    int i;
    for(i=0;spell[lang][d][i] && s<=n;i++)
    {
        if(nextletter[s][spell[lang][d][i]-'A'+1]==-1) return -1;
        s=nextletter[s][spell[lang][d][i]-'A'+1]+1;
    }
    if(spell[lang][d][i]) return -1;
    return s;
}
int main()
{
    int i, j;
    int cur[30];
    while(scanf("%s", &a[1])==1)
    {
        n=strlen(&a[1]);
        for(i=1;i<=26;i++) cur[i]=-1;
        for(i=n;i>=1;i--)
        {
            cur[a[i]-'A'+1]=i;
            for(j=1;j<=26;j++) nextletter[i][j]=cur[j];
        }
        memset(mlen, 0, sizeof(mlen));
        for(int lang=0;lang<4;lang++)
        {
            for(i=n;i>=1;i--)
            {
                for(j=0;j<=9;j++)
                    nextpointer[i][lang][j]=get_next_pointer(i, lang, j);
            }
        }
        bestlen=0;
        for(int lang=0;lang<4;lang++)
        {
            optlen=0;
            for(i=n;i>=1;i--)
            {
                mlen[i]=0;
                for(j=9;j>=0;j--)
                {
                    if(i==1 && j==0) continue;
                    if(nextpointer[i][lang][j]==-1) continue;
                    if(mlen[i]<mlen[nextpointer[i][lang][j]]+1)
                    {
                        mlen[i]=mlen[nextpointer[i][lang][j]]+1;
                        dig[i]=j;
                        from[i]=nextpointer[i][lang][j];
                    }
                }
            }
            for(i=1, j=1;i<=mlen[1];i++, j=from[j]) opt[i]='0'+dig[j];
            optlen=mlen[1]; opt[mlen[1]+1]=0;
            if(bestlen<optlen)
            {
                bestlen=optlen;
                strcpy(&best[1], &opt[1]);
            }
            else if(bestlen==optlen)
            {
                bool change=true;
                for(i=1;i<=bestlen;i++)
                {
                    if(best[i]>opt[i]){change=false; break;}
                    if(best[i]<opt[i]) break;
                }
                if(change) strcpy(&best[1], &opt[1]);
            }
        }
        printf("%s ", &best[1]);
        bestlen=0;
        for(i=n;i>=1;i--)
        {
            mlen[i]=0;
            for(j=9;j>=0;j--)
            {
                if(i==1 && j==0) continue;
                int mp=-1;
                for(int lang=0;lang<4;lang++)
                {
                    if(nextpointer[i][lang][j]==-1) continue;
                    if(mp==-1 || mp>nextpointer[i][lang][j]) mp=nextpointer[i][lang][j];
                }
                if(mp!=-1 && mlen[i]<mlen[mp]+1)
                {
                    mlen[i]=mlen[mp]+1;
                    dig[i]=j;
                    from[i]=mp;
                }
            }
        }
        for(i=1, j=1;i<=mlen[1];i++, j=from[j]) best[i]='0'+dig[j];
        best[mlen[1]+1]=0;
        printf("%s\n", &best[1]);
    }
    return 0;
}

