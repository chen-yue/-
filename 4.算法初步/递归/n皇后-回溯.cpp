//n�ʺ����⣬���ݷ�������ݹ�߽�ǰ����ΪĳЩ��ʵ���ü������µݹ飬������һ�㣩 
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
		cnt++;
		return;
	}
	for(int x=1;x<=n;x++)
	{
		if(H[x]==false)
		{
			bool flag=true;//��ʾ��ǰ�ʺ󲻻��֮ǰ�Ļʺ��ͻ 
			for(int pre=1;pre<index;pre++)
			{
				if(abs(index-pre)==abs(x-P[pre]))
				//index��ʾ��ǰ���еĵڼ�λ����Ӧ���̵��У�x��ʾindex��Ӧ����
				//pre��֮ǰ���У�P���е��е�ӳ�� 
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
