#include <stdio.h>

int main()
{
int N, x1, x2, x3, s;
float res, t;
printf("vvedite chislo: \n");
scanf("%d", &N);
x1 = N / 100;
x2 = (N % 100) / 10;
x3 = N % 10;

s = x1 + x2 + x3;
if (s % 2 == 0){
res = N * 2;
}

else{
t=N;
res = (t + 1)/t;
}

printf("rezultat = %f", res);
return 0;
}

