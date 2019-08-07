#include<cstdio>
//递归方式
unsigned int F(unsigned int n)
{
	if(n==1 || n==2)
		return 1;
	else
		return F(n-1)+F(n-2);
}

//非递归方式
unsigned int Fib2(unsigned int n)
{
    unsigned int nRet, n1, n2;
    nRet = n1 = n2 = 1;

    if ((n == 1) || (n == 2))
        return nRet;

    for (unsigned int i = 3; i <= n; i++)
    {
        nRet = n1 + n2;

        n1 = n2;
        n2 = nRet;
    }
    return nRet;
}

int main()
{
	int n;
	scanf("%d",&n);
	printf("%d",F(n));
	return 0;
}
