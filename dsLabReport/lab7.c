//Write a program to print truth table of AND operation.

#include <stdio.h>
int main() {
    int a, b;
    printf("A B A AND B\n");
    for (a = 0; a <= 1; a++) {
        for (b = 0; b <= 1; b++) {
            printf("%d %d    %d\n", a, b, a & b);
        }
    }
        printf("©2024 Abinash Regmi");

    return 0;
}
