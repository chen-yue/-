#include<bits/stdc++.h>
using namespace std;
const int maxn=30010;
struct student{
	char id[15];//准考证号 
	int score;//分数 
	int l_no;//考场号 
	int l_r;//考场排名 
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
	int n,k,cnt=0;//cnt是总考生数 

//第一步，stu读入数据，还差考场排名 
	scanf("%d",&n);//几个考场 
	for(int i=0;i<n;i++)
	{
		scanf("%d",&k);//考场有几人 
		
		for(int j=0;j<k;j++)
		{
			scanf("%s %d",stu[cnt].id,&stu[cnt].score);
			stu[cnt].l_no=i+1;
			cnt++;  

		}
		
//第二步，计算考场排名并记录 
		sort(stu+cnt-k,stu+cnt,cmp);//将某考场排序
		stu[cnt-k].l_r=1;
		for(int j=cnt-k+1;j<cnt;j++)
		{
			if(stu[j].score==stu[j-1].score)
				stu[j].l_r=stu[j-1].l_r;
			else
				stu[j].l_r=j+1-(cnt-k); 
		}
	}
	
//第三步，排序所有，并输出 (只输出但不记录排名)
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









