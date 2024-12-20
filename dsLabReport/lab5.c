//Write a program to find addition of two binary number.

#include <stdio.h>
#include <string.h>
int main() {
    char bin1[100], bin2[100], result[101];
    int i, j, k, sum, carry = 0;
    printf("Enter first binary number: ");
    scanf("%s", bin1);
    printf("Enter second binary number: ");
    scanf("%s", bin2);
    for (i = strlen(bin1) - 1, j = strlen(bin2) - 1, k = 100; i >= 0 || j >= 0 || carry; i--, j--, k--) {
        sum = (i >= 0 ? bin1[i] - '0' : 0) + (j >= 0 ? bin2[j] - '0' : 0) + carry;
        result[k] = sum % 2 + '0';
        carry = sum / 2;
    }
    printf("Sum: %s\n", result + k + 1);
        printf("©2024 Abinash Regmi");

    return 0;
}
