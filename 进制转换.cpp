//P进制转Q进制 
//先将P进制数x转为十进制数y
//再将十进制数y转为Q进制数z 
#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int p2d(int x,int P)//P to Decimal 
{
	int y=0,w=1;//w是P进制权重 
	while(x)
	{
		y+=(x%10)*w;//获取x个位 
		x/=10;//去掉x个位 
		w*=P; 
	}
	return y;
}
int d2q(int y,int Q)//Decimal to Q 
{
	int z=0,w=1;
	do{
		z+=(y%Q)*w;
		y/=Q;//
		w*=10;
	}while(y);
	return z;
	
}
int main()
{
	int x,P,Q;
	scanf("%d %d",&x,&Q);
	printf("%d",d2q(x,Q));
	return 0;
}
