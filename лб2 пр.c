#include <stdio.h>
#include <stdlib.h>
#include <math.h> // ����������� ���������� � ��������������� ���������
/* ������� �6
��������� ��������� ���������� ��������� ��� ���������� �
*/
int main() {
    float x, res; // �������� ����������
    
    printf("x = ");
    scanf("%f", &x); // ���� �
    
    res = sqrt(1+pow(x,2)) + fabs(pow(log(x), 3) / 1.6 + pow(x, 4) * sin(7*x));
    
    printf("otvet: %f", res); // ����� ����������
    return 0;
}


