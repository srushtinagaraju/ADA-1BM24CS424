#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapcom(int a[], int n) {
    int i, j, k, item;
    for (i = 1; i <= n; i++) {
        item = a[i];
        j = i;
        k = j / 2;
        while (k != 0 && item > a[k]) {
            a[j] = a[k];
            j = k;
            k = j / 2;
        }
        a[j] = item;
    }
}

void adjust(int a[], int n) {
    int item, i, j;
    j = 1;
    item = a[j];
    i = 2 * j;
    while (i <= n - 1) {
        if (i + 1 <= n - 1 && a[i] < a[i + 1])
            i++;
        if (item < a[i]) {
            a[j] = a[i];
            j = i;
            i = 2 * j;
        } else {
            break;
        }
    }
    a[j] = item;
}

void heapsort(int a[], int n) {
    int i, temp;
    heapcom(a, n);
    for (i = n; i >= 1; i--) {
        temp = a[1];
        a[1] = a[i];
        a[i] = temp;
        adjust(a, i);
    }
}

int main() {
    int i, n, a[20], ch = 1;
    clock_t start, end;

    while (ch) {
        printf("\nEnter the number of elements to sort: ");
        scanf("%d", &n);

        printf("Enter the elements to sort:\n");
        for (i = 1; i <= n; i++)
            scanf("%d", &a[i]);

        start = clock();
        heapsort(a, n);
        end = clock();

        printf("\nThe sorted list of elements is:\n");
        for (i = 1; i <= n; i++)
            printf("%d\n", a[i]);

        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("\nTime taken: %lf seconds\n", time_taken);

        printf("Do you wish to run again? (1 for yes / 0 for no): ");
        scanf("%d", &ch);
    }

    return 0;
}

OUTPUT
enter the number of elements to sort : 5
enter the elements to sort : 8 5 6 3 1
the sorted list of elements is 1 3 5 6 8
