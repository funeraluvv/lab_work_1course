#include <stdio.h>
#include <stdlib.h>
#include <math.h> // подключение библиотеки с математическими функциями
/* Вариант №6
Составить программу вычисления выражения для введенного Х
*/
int main() {
    float x, res; // введение переменных
    
    printf("x = ");
    scanf("%f", &x); // ввод х
    
    res = sqrt(1+pow(x,2)) + fabs(pow(log(x), 3) / 1.6 + pow(x, 4) * sin(7*x));
    
    printf("otvet: %f", res); // вывод результата
    return 0;
}


