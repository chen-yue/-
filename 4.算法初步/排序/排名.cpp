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
//把排名记录下来 
	stu[0].r=1;
	for(int i=1;i<n;i++)
	{
		//1，分数相等，排名不变 
		if(stu[i].score==stu[i-1].score)
			stu[i].r=stu[i-1].r;
		//2，分数不等，排名更新 
		else
			stu[i].r=i+1;
	}

//只输出但不记录排名 
	int r=1;
	for(int i=0;i<n;i++)//i从0开始，是为了应对只有1个学生的情况 
	{
		if(i>0 && stu[i].score!=stu[i-1].score)
			r=i+1;
//		printf("%d ",&stu[i].r); //输出排名 
	}
	 
}









