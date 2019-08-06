//求日期差值，若两个日期连续，则差值是1天 
#include <bits/stdc++.h>
using namespace std;
int month[2][13]={
{0,31,28,31,30,31,30,31,31,30,31,30,31},
{0,31,29,31,30,31,30,31,31,30,31,30,31}
};
bool isLeap(int year)
{
	return ((year%4==0 && year%100!=0)|| year%400==0);
}
int main()
{
	int y1,m1,d1,y2,m2,d2;
	scanf("%d:%d:%d",&y1,&m1,&d1);
	scanf("%d:%d:%d",&y2,&m2,&d2);
	
	if(y1>y2 || (y1==y2&&m1>m2) || (y1==y2&&m1==m2&&d1>d2))
	{
		swap(y1,y2);
		swap(m1,m2);
		swap(d1,d2);
	}//保证date1<date2,因为要从1加到2 
	int ans=0;
	while((y1==y2 && m1==m2 && d1==d2)==false)//日期还没到达 
	{
		d1++;
		if(d1==month[isLeap(y1)][m1]+1)
		{
			m1++;
			d1=1;
		}
		if(m1==13)
		{
			y1++;
			m1=1;
		}
		ans++;
	}
	printf("%d",ans);
	return 0;
}






