//n�ʺ����⣬��������ö����������� 
#include<bits/stdc++.h>
using namespace std;
const int maxn=11;
//PΪ��ǰ���У�H��¼x�Ƿ��Ѿ���P��
int n,P[maxn],H[maxn]={false};
int cnt=0;//�Ϸ�������Ŀ 

void generateP(int index)
{
	if(index==n+1)
	{
		bool flag=true;//flag=1��ʾ��ǰ��һ���Ϸ����� 
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(abs(i-j)==abs(P[i]-P[j]))//���Qi��Qjͬ��һ���Խ����� 
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
