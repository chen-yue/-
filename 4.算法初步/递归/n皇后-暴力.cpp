//n皇后问题，暴力法（枚举所有情况） 
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
		bool flag=true;//flag=1表示当前是一个合法方案 
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(abs(i-j)==abs(P[i]-P[j]))//如果Qi和Qj同在一条对角线上 
					flag=false;
		if(flag)
			cnt++;
		return;
	}
	for(int x=1;x<=n;x++)
	{
		if(H[x]==false)
		{
			P[index]=x;
			H[x]=true;
			generateP(index+1);
			H[x]=false;
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
