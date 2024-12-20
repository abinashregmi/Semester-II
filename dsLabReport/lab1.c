//Write a program to find ceiling and floor function.

#include <stdio.h>
#include <math.h>
int main() {
    float num;
    printf("Enter the number: ");
    scanf("%f", &num);
    printf("The floor value is %.0f\n", floor(num));
    printf("The ceiling value is %.0f\n", ceil(num));
    printf("©2024 Abinash Regmi");
    return 0;
}
