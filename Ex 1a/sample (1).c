#include<stdio.h>
#include<math.h>
void factorial(int i)
{
    long long int ans=1;
    for(int n;n>=1;n--)
    ans=ans*n;
    printf("%lld",ans);
}
void fun1(int i)
{
    printf("\t%d\t",i);
}
void fun2(int i)
{
    printf("%.3f\t",pow(2,i));
}
//void()
void fun3(int i)
{
    printf("%.3f\t",pow(2,(pow(2,i))));
}
void fun4(int i)
{
    printf("%.3f\t",pow(i,3));
}
void fun5(int i)
{
   printf("%.3f\t",pow(2,(pow(2,(i+1)))));
}
void fun6(int i)
{
   printf("%.3f\t",pow(1.5,i));
}
void fun7(int i)
{
 printf("%.3f\t",pow(2,log2(i)));
}
void fun8(int i)
{
 printf("%.3f\t",pow(log2(i),log2(i)));
}
void fun9(int i)
{
 printf("%.3f\t",log(log(i)));
}
void fun10(int i)
{
 printf("%.3f\t",pow(log(i),2));
}
void main()
{
	//float f1(),f2,f3,f4,f5,f6,f7,f8,f9,f10;
	int n;
	printf("Sr No.\tn\t2^n\t2^(2^n)\tn^3\t2^2^(n+1)\tn^(3/2)/t(lg n)^2\t(lgn)^lgn\tlg(lg n)\t(lg n)^2\n");
	
	 for(int i=0;i<=100;i++)
	 {
	     printf("\nFor i=%d:\t",i);
	 	fun1(i);
	 	fun2(i);
	 	fun3(i);
	 	fun4(i);
	 	fun5(i);
	 	fun6(i);
	 	fun7(i);
	 	fun8(i);
	 	fun9(i);
	 	fun10(i);
	 	if(i<=20)
	 	factorial(i);
	 
	 }	
}


