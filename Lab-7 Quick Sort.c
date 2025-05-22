#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5000

void quicksort(int[], int, int);
int partition(int[], int, int);

int main() {
    int i, n, a[MAX], ch = 1;
    clock_t start, end;

    while (ch) {
        printf("\nEnter the number of elements: ");
        scanf("%d", &n);

        for (i = 0; i < n; i++)
            a[i] = rand() % 200;

        printf("The randomly generated array is:\n");
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);

        start = clock();
        quicksort(a, 0, n - 1);
        end = clock();

        printf("\n\nThe sorted array elements are:\n");
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);

        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("\nTime taken = %f seconds", time_taken);

        printf("\n\nDo you wish to continue? (1 for yes / 0 for no): ");
        scanf("%d", &ch);
    }

    return 0;
}

void quicksort(int a[], int low, int high) {
    int mid;
    if (low < high) {
        mid = partition(a, low, high);
        quicksort(a, low, mid - 1);
        quicksort(a, mid + 1, high);
    }
}

int partition(int a[], int low, int high) {
    int key = a[low];
    int i = low + 1;
    int j = high;
    int temp;

    while (i <= j) {
        while (i <= high && a[i] <= key)
            i++;
        while (a[j] > key)
            j--;
        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        } else {
            temp = a[j];
            a[j] = a[low];
            a[low] = temp;
        }
    }
    return j;
}

OUTPUT:
Enter the number of elements: 5
The random generated array is:
13 125 97 58 72 
The sorted array elements are:
13
58
72
97
125
Time taken = 0.000056 seconds
Do you wish to continue (0/1)? 1
Enter the number of elements: 7
The random generated array is:
134 92 59 23 78 161 104 
The sorted array elements are:
23
59
78
92
104
134
161
Time taken = 0.000070 seconds
Do you wish to continue (0/1)? 0
