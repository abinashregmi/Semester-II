//Write a program to implement linear search algorithm using recursion.

#include <stdio.h>
int linearSearch(int arr[], int size, int target, int index) {
    if (index >= size) return -1;
    if (arr[index] == target) return index;
    return linearSearch(arr, size, target, index + 1);
}
int main() {
    int arr[] = {2, 4, 6, 8, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target, result;
    printf("Enter the target value: ");
    scanf("%d", &target);
    result = linearSearch(arr, size, target, 0);
    if (result != -1) {
        printf("Target found at index %d\n", result);
    } else {
        printf("Target not found\n");
    }
        printf("©2024 Abinash Regmi");

    return 0;
}
