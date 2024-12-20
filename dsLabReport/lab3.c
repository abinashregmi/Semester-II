//Write a program to implement fuzzy set of operations.

#include <stdio.h>
int main() {
    float set1[] = {0.2, 0.5, 0.7, 0.9};
    float set2[] = {0.1, 0.6, 0.3, 0.8};
    int size = 4;
    printf("Union: ");
    for (int i = 0; i < size; i++)
        printf("%.2f ", (set1[i] > set2[i]) ? set1[i] : set2[i]);
    printf("\nIntersection: ");
    for (int i = 0; i < size; i++)
        printf("%.2f ", (set1[i] < set2[i]) ? set1[i] : set2[i]);
    printf("\nComplement of Set 1: ");
    for (int i = 0; i < size; i++)
        printf("%.2f ", 1.0 - set1[i]);
            printf("\n©2024 Abinash Regmi");

    return 0;
}

