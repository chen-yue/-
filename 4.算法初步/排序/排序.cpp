#include<bits/stdc++.h>
using namespace std;
const int n=5;
int a[n]={5,4,3,2,1};
void bubbleSort()
{
	for(int i=0;i<n;i++)//n������ 
		for(int j=0;j<n-i-1;j++)//ÿ�˶������Ԫ�� ��������������� 
			if(a[j]>a[j+1])
				swap(a[j],a[j+1]);
}
void selectSort()
{
	for(int i=0;i<n;i++)
	{
		int k=i;
		for(int j=i;j<n;j++)//ѡ�������򲿷� ��СԪ��
			if(a[j]<a[k])
				k=j;
		swap(a[i],a[k]);//���������򲿷� ��һ��Ԫ��
	}
}
void insertSort()
{
	for(int i=1;i<n;i++)//����n-1������ÿ�˶�ν��� 
	{
		int tp=a[i],j=i;//ѡ�������벿�� ��һ��Ԫ��A[i] 
		while(j>0 && tp<a[j-1])//tpС�������򲿷ֵ�ǰһ��Ԫ�أ�����ǰ�������� 
		{
			a[j]=a[j-1];
			j--;
		}
		a[j]=tp;//���������򲿷�
	}
}

//��������
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
}//����(two pointers)
void QuickSort(int arr[], int left, int right){
    if(left<right)
    {
        int pivot=Parition(arr,left, right);
        QuickSort(arr, left,pivot-1);
        QuickSort(arr, pivot+1,right);
    }
}//�ݹ� 

//�鲢����
void Merge(int arr[], int left, int mid, int right){//�ϲ�[left,mid]��[mid+1,right] 
    int n=right-left+1;
    int* tmp=new int[n];//��ʱ�����ϲ������������
    int index=0;//�ϲ������±� 
    int i=left;//�������±� 
    int j=mid+1;//�������±� 
    //two pointers
    while(i<=mid && j<=right)
        tmp[index++]= arr[i]<arr[j] ? arr[i++]:arr[j++];
    while(i<=mid)
        tmp[index++]=arr[i++];
    while(j<=right)
        tmp[index++]=arr[j++];

    for(int k=0;k<n;++k)
        arr[left+k]=tmp[k];
    delete [] tmp;//ɾ���������ڴ�
}//���� 
//�鲢����ĵݹ�ʵ�� 
void MergeSort(int arr[], int left, int right){
    if(left==right)
        return;  //�ݹ�����������е�ÿ����������Ϊ����Ϊ1������
    int mid=(left+right)/2;
    MergeSort(arr,left,mid);
    MergeSort(arr,mid+1,right);
    Merge(arr,left,mid,right);
} 
//�鲢����ķǵݹ�ʵ��
void MergeSort(int arr[])
{
	for(int step=2;step/2<=n;step*=2)
	{
		for(int i=0;i<n;i+=step)
		{
			int right=i+step-1;
			int mid=(i+right)/2;
			if(mid+1<n)//������������ڣ���ϲ� 
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
