//n皇后问题，回溯法（到达递归边界前，因为某些事实不用继续往下递归，返回上一层） 
#include<bits/stdc++.h>
using namespace std;
const int maxn=11;
//P为当前排列，H记录x是否已经在P中
int n,P[maxn],H[maxn]={false};
int cnt=0;//合法方案数目 

void generateP(int index)
{
	if(index==n+1)
	{
		cnt++;
		return;
	}
	for(int x=1;x<=n;x++)
	{
		if(H[x]==false)
		{
			bool flag=true;//表示当前皇后不会和之前的皇后冲突 
			for(int pre=1;pre<index;pre++)
			{
				if(abs(index-pre)==abs(x-P[pre]))
				//index表示当前排列的第几位，对应棋盘的行；x表示index对应的列
				//pre是之前的行，P是行到列的映射 
				{
					flag=false;
					break;
				}
			}
			if(flag)
			{
				P[index]=x;
				H[x]=true;
				generateP(index+1);
				H[x]=false; 
			}
		}
	}
}

int main()
{
	scanf("%d",&n);
	generateP(1);
	printf("%d\n",cnt); 
	return 0;
}
