//Write a program to implement Euclidean algorithm.

#include <stdio.h>
int main() {
    int a, b;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    printf("GCD is %d\n", a);
        printf("©2024 Abinash Regmi");

    return 0;
}
