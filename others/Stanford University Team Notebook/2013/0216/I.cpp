#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int maxn = 10010;

vector<pair<int, int> > a;
int pai[maxn+1];
long long f[maxn+1];
int n,resulttop;
int result[maxn+1][2];

bool init()
{
	int i,x;
	scanf("%d",&n);
	if (n==0)
		return false;
	a.clear();
	a.push_back(pair<int, int>(-10000,1000));
	for (i=1; i<=n; ++i)
	{
		scanf("%d",&x);
		a.push_back(pair<int, int>(x,i));
	}
	sort(a.begin(),a.end());
	return true;
}

void work()
{
	int i,j,k;
	int zd=0;
	long long tmp;
	f[0]=0;
	for (i=1; i<=n; ++i)
	{
		zd=0;
		f[i]=-1;
		for (j=i; j>=1; --j)
		{
			if (a[j].first>zd)
				zd=a[j].first;
			tmp=zd;
			tmp*=n-j+1;
			tmp+=f[j-1];
			if ((f[i]==-1)||(tmp<f[i]))
			{
				f[i]=tmp;
				pai[i]=j-1;
			}
		}
	}
}

void output()
{
	int i,j;
	printf("%lld\n",f[n]);
	i=n;
        resulttop=0;	
	while (i)
	{
		result[++resulttop][0]=pai[i]+1;
		result[resulttop][1]=i;
		i=pai[i];
        }
	printf("%d\n",resulttop);
	for (i=resulttop; i>=1; --i)
	{
		printf("%d",result[i][1]-result[i][0]+1);
		for (j=result[i][0]; j<=result[i][1]; ++j)
			printf(" %d",a[j].second);
		printf("\n");
	
	}
}

int main()
{
	freopen("iq.in","r",stdin);
	freopen("iq.out","w",stdout);	
	while (init())
	{
		work();
		output();
	}
	return 0;
}
