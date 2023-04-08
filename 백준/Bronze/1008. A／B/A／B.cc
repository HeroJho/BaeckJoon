#include<stdio.h>

int main(void)
{
   double num1, num2;
   scanf("%lf %lf", &num1, &num2);
   double result;
   result = (double)num1 / (double)num2;
   printf("%.9f", result);
   return 0;
}