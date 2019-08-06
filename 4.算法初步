//问题1：对于一个递增数列a[]和正整数M，找出i和j,使啊a[i]+a[j]=M
//原算法：（复杂度O(n^2)） 
for(int i=0;i<n;i++)
	for(int j=i+1;j<n;j++)
		if(a[i]+a[j]==m)
			printf("%d %d\n",i,j);
//注意：i和j相互牵制 
//改进算法：（复杂度O(n)） 
while(i<j)
{
	if(a[i]+a[j]==m)
	{
		printf("d %d",i,j);
		i++;
		j--;
	}
	else if(a[i]+a[j]<m)
		i++;
	else
		j--;
}

/****************************************************************
****************************************************************/

//问题2：合并2个递增序列
int merge(int a[],int b[],int c[],int n,int m)
{
	int i=0,j=0,index=0;
	while(i<n && j<m)
	{
		if(a[i]<b[j])
			c[index++]=a[i++];
		else
			c[index++]=b[j++];
	}
	while(i<n)
		c[index++]=a[i++];
	while(j<n)
		c[index++]=b[j++];
	return index;
 } 
