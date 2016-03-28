#include <stdio.h>

const int maxn = 151000;

int tree[2][maxn+1][2];
int result[maxn+1][2];
int resulttop;
int top[2];
bool deng[maxn+1];

bool init()
{
	int i,j;
	for (i=0; i<2; ++i)
	{
		scanf("%d",&top[i]);
		if (top[i]==0)
			return false;
		for (j=1; j<=top[i]; ++j)
			scanf("%d%d",&tree[i][j][0],&tree[i][j][1]);
	}
	//printf("top %d %d\n",top[0],top[1]);
	return true;
}

bool calc_deng(int p0, int p1)
{
	//printf("p0=%d p1=%d\n",p0,p1); fflush(stdout);
	if ((!p0)&&(!p1))
		return true;
	if ((!p0)&&(p1))
		return false;
	if ((p0)&&(!p1))
	{
		deng[p0]=false;
		return false;
	}
	if ((calc_deng(tree[0][p0][0],tree[1][p1][0])) && (calc_deng(tree[0][p0][1],tree[1][p1][1])))
		deng[p0]=true;
	else deng[p0]=false;

	return deng[p0];	
}

void inc()
{
	result[++resulttop][0]=0;
	result[resulttop][1]=0;
}

void dfs(int p, int now)
{
	if (tree[0][p][0])
	{
		inc();
		result[now][0]=resulttop;
		dfs(tree[0][p][0],resulttop);
	}
	if (tree[0][p][1])
	{
		inc();
		result[now][1]=resulttop;
		dfs(tree[0][p][1],resulttop);
	}
}

void gao(int p0, int p1, int now)
{
	int l0,l1,r0,r1;
	l0=tree[0][p0][0];
	l1=tree[1][p1][0];
	r0=tree[0][p0][1];
	r1=tree[1][p1][1];

	if (l0==0)
	{}
	else if (deng[l0])
	{
		inc();
		result[now][0]=resulttop;
		dfs(l0,resulttop);
		if ((!r0)||(!r1))
			return;
		else {
			inc();
			result[now][1]=resulttop;
			gao(r0,r1,resulttop);
		}
	}
	else { //l0!=0
		if (l1!=0)
		{
			inc();
			result[now][0]=resulttop;
			gao(l0,l1,resulttop);
			if ((r0)&&(r1))
			{
				inc();
				result[now][1]=resulttop;
			}
		}
	}
}

void work()
{
	int i;
	for (i=1; i<=top[0]; ++i)
		deng[i]=false;
	calc_deng(1,1);
	resulttop=1;
	result[1][0]=result[1][1]=0;
	gao(1,1,1);
}

void output()
{
	int i;
	printf("%d\n",resulttop);
	for (i=1; i<=resulttop; ++i)
		printf("%d %d\n",result[i][0],result[i][1]);
}

int main()
{
	freopen("lca.in","r",stdin);
	freopen("lca.out","w",stdout);
	while (init())
	{
		work();
		output();
	}
	return 0;
}
