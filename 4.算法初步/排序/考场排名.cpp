#include<bits/stdc++.h>
using namespace std;
const int maxn=30010;
struct student{
	char id[15];//׼��֤�� 
	int score;//���� 
	int l_no;//������ 
	int l_r;//�������� 
}stu[maxn];
bool cmp(student a,student b)
{
	if(a.score!=b.score)
		return a.score>b.score;
	else
		return strcmp(a.id,b.id)<0;
}
int main()
{
	int n,k,cnt=0;//cnt���ܿ����� 

//��һ����stu�������ݣ���������� 
	scanf("%d",&n);//�������� 
	for(int i=0;i<n;i++)
	{
		scanf("%d",&k);//�����м��� 
		
		for(int j=0;j<k;j++)
		{
			scanf("%s %d",stu[cnt].id,&stu[cnt].score);
			stu[cnt].l_no=i+1;
			cnt++;  

		}
		
//�ڶ��������㿼����������¼ 
		sort(stu+cnt-k,stu+cnt,cmp);//��ĳ��������
		stu[cnt-k].l_r=1;
		for(int j=cnt-k+1;j<cnt;j++)
		{
			if(stu[j].score==stu[j-1].score)
				stu[j].l_r=stu[j-1].l_r;
			else
				stu[j].l_r=j+1-(cnt-k); 
		}
	}
	
//���������������У������ (ֻ���������¼����)
	printf("%d\n",cnt);
	sort(stu,stu+cnt,cmp);
	int r=1;
	for(int i=0;i<cnt;i++)
	{
		if(i>0 && stu[i].score!=stu[i-1].score)
			r=i+1;
		printf("%s %d %d %d\n",stu[i].id,r,stu[i].l_no,stu[i].l_r);
	}
	return 0;
}









