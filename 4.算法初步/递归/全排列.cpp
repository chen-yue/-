#include<cstdio>
using namespace std;
const int maxn=11;
//PΪ��ǰ���У�H��¼x�Ƿ��Ѿ���P��
int n,P[maxn],H[maxn]={false};

//�������еĵ�index��λ
void generateP(int index)
{
	if(index==n+1)//�ݹ�߽磬��ʾ�Ѿ������굱ǰ���� 
	{
		for(int i=1;i<=n;i++)
			printf("%d",P[i]);
		printf("\n");
		return;
	}
	for(int x=1;x<=n;x++)//x��ѡ��Ҫ��Ҫ�Ž�P���е��� 
	{
		if(H[x]==false)
		{
			P[index]=x;
			H[x]=true;
			generateP(index+1);
			H[x]=false;//�Ѿ�������P[index]Ϊx�������⣬��ԭ״̬����һ��ѭ������P[index]Ϊx+1������ 
			//���ǰѵ�indexλ��x����x+1,�ݹ���˼�� 
		}
	}
}
int main()
{
	n=3;
	generateP(1);
	return 0;
}
