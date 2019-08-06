//基于有序数列！！！ 
#include<cstdio>
using namespace std;
int binarySearch(int a[],int left,int right,int x)
{
	while(left<=right)
	{
		int mid=(left+right)/2;
		if(a[mid]==x)
			return mid;
		else if(a[mid]>x)
			right=mid-1;
		else
			left=mid+1;
	}
	return -1;
}
int main()
{
	int a[5]={1,2,3,4,5};
	printf("%d",binarySearch(a,0,4,2));
	return 0;
}
