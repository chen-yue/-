#include<cstdio>
using namespace std;
const int maxn=11;
//P为当前排列，H记录x是否已经在P中
int n,P[maxn],H[maxn]={false};

//处理排列的第index号位
void generateP(int index)
{
	if(index==n+1)//递归边界，表示已经处理完当前排列 
	{
		for(int i=1;i<=n;i++)
			printf("%d",P[i]);
		printf("\n");
		return;
	}
	for(int x=1;x<=n;x++)//x是选择要不要放进P排列的数 
	{
		if(H[x]==false)
		{
			P[index]=x;
			H[x]=true;
			generateP(index+1);
			H[x]=false;//已经处理完P[index]为x的子问题，还原状态，下一个循环处理P[index]为x+1的问题 
			//就是把第index位由x换成x+1,递归树思想 
		}
	}
}
int main()
{
	n=3;
	generateP(1);
	return 0;
}
