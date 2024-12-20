//Write a program to find Cartesian product of two set.

#include <stdio.h>
int main() {
    int set1[] = {1, 2, 3};
    int set2[] = {4, 5};
    int size1 = sizeof(set1) / sizeof(set1[0]);
    int size2 = sizeof(set2) / sizeof(set2[0]);
    printf("Cartesian Product:\n");
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            printf("(%d, %d)\n", set1[i], set2[j]);
        }
    }
        printf("©2024 Abinash Regmi");
    return 0;
}

