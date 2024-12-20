//Write a program to find subtraction of two binary number.

#include <stdio.h>
#include <string.h>
int main() {
    char bin1[100], bin2[100], result[100];
    int i, j, k, borrow = 0, bit1, bit2;
    printf("Enter first binary number: ");
    scanf("%s", bin1);
    printf("Enter second binary number: ");
    scanf("%s", bin2);
    int len1 = strlen(bin1);
    int len2 = strlen(bin2);
    k = len1 > len2 ? len1 : len2;
    result[k] = '\0';
    for (i = len1 - 1, j = len2 - 1, k--; k >= 0; i--, j--, k--) {
        bit1 = (i >= 0 ? bin1[i] - '0' : 0);
        bit2 = (j >= 0 ? bin2[j] - '0' : 0) + borrow;
        if (bit1 < bit2) {
            bit1 += 2;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result[k] = bit1 - bit2 + '0';
    }
    printf("Difference: %s\n", result[0] == '0' ? result + 1 : result);
        printf("©2024 Abinash Regmi");

    return 0;
}