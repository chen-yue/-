#include<bits/stdc++.h>
using namespace std;
const int n=5;
int a[n]={5,4,3,2,1};
void bubbleSort()
{
	for(int i=0;i<n;i++)//n趟排序 
		for(int j=0;j<n-i-1;j++)//每趟都把最大元素 交换到无序区最后 
			if(a[j]>a[j+1])
				swap(a[j],a[j+1]);
}
void selectSort()
{
	for(int i=0;i<n;i++)
	{
		int k=i;
		for(int j=i;j<n;j++)//选出待排序部分 最小元素
			if(a[j]<a[k])
				k=j;
		swap(a[i],a[k]);//交换待排序部分 第一个元素
	}
}
void insertSort()
{
	for(int i=1;i<n;i++)//进行n-1趟排序，每趟多次交换 
	{
		int tp=a[i],j=i;//选出待插入部分 第一个元素A[i] 
		while(j>0 && tp<a[j-1])//tp小于已排序部分的前一个元素，就往前继续交换 
		{
			a[j]=a[j-1];
			j--;
		}
		a[j]=tp;//插入已有序部分
	}
}

//快速排序
int Parition(int arr[], int left,int right){
	int tp=arr[left];
	while(left<right)
	{
		while(left<right && arr[right]>tp)
			right--;
		arr[left]=arr[right];
		while(left<right && arr[left]<tp)
			left++;
		arr[right]=arr[left];
	}
	arr[left]=tp;
	return left;
}//分区(two pointers)
void QuickSort(int arr[], int left, int right){
    if(left<right)
    {
        int pivot=Parition(arr,left, right);
        QuickSort(arr, left,pivot-1);
        QuickSort(arr, pivot+1,right);
    }
}//递归 

//归并排序
void Merge(int arr[], int left, int mid, int right){//合并[left,mid]和[mid+1,right] 
    int n=right-left+1;
    int* tmp=new int[n];//临时数组存合并后的有序序列
    int index=0;//合并数组下标 
    int i=left;//左数组下标 
    int j=mid+1;//右数组下标 
    //two pointers
    while(i<=mid && j<=right)
        tmp[index++]= arr[i]<arr[j] ? arr[i++]:arr[j++];
    while(i<=mid)
        tmp[index++]=arr[i++];
    while(j<=right)
        tmp[index++]=arr[j++];

    for(int k=0;k<n;++k)
        arr[left+k]=tmp[k];
    delete [] tmp;//删掉堆区的内存
}//分治 
//归并排序的递归实现 
void MergeSort(int arr[], int left, int right){
    if(left==right)
        return;  //递归基是让数组中的每个数单独成为长度为1的区间
    int mid=(left+right)/2;
    MergeSort(arr,left,mid);
    MergeSort(arr,mid+1,right);
    Merge(arr,left,mid,right);
} 
//归并排序的非递归实现
void MergeSort(int arr[])
{
	for(int step=2;step/2<=n;step*=2)
	{
		for(int i=0;i<n;i+=step)
		{
			int right=i+step-1;
			int mid=(i+right)/2;
			if(mid+1<n)//若右子区间存在，则合并 
				Merge(arr,i,mid,min(right,n-1));
		}
	}
}

int main()
{
//	SortFunct(); 
	QuickSort(a,0,4);
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}
