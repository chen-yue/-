#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
struct student{
	int r;
	int score;
}stu[maxn];
int main()
{
	int n;
	scanf("%d",&n);
//��������¼���� 
	stu[0].r=1;
	for(int i=1;i<n;i++)
	{
		//1��������ȣ��������� 
		if(stu[i].score==stu[i-1].score)
			stu[i].r=stu[i-1].r;
		//2���������ȣ��������� 
		else
			stu[i].r=i+1;
	}

//ֻ���������¼���� 
	int r=1;
	for(int i=0;i<n;i++)//i��0��ʼ����Ϊ��Ӧ��ֻ��1��ѧ������� 
	{
		if(i>0 && stu[i].score!=stu[i-1].score)
			r=i+1;
//		printf("%d ",&stu[i].r); //������� 
	}
	 
}









