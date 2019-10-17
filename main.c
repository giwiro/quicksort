#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int hoare_part(int *A, int lo, int hi) {
    int pivot = A[lo + (hi - lo) / 2];
    int i = lo, j = hi;
    while(1) {
        while(pivot > A[i]) i++;
        while(pivot < A[j]) j--;
        if (i >= j) return j;
        swap(&A[i], &A[j]);
    }
}

void qs(int *A, int lo, int hi) {
    if (hi > lo) {
        int p = hoare_part(A, lo, hi);
        qs(A, lo, p);
        qs(A, p + 1, hi);
    }
}

void pa(int *A, size_t l) {
    for (int i = 0; i < l; i++) {
        printf("%d", A[i]);
        if (i + 1 < l) printf(" ");
    }
    printf("\n");
}

int main() {
    int A[] = {100000000, 5, 7, 2, 1, 8, 3, 9};
    int len = sizeof(A) / sizeof(A[0]);
    
    qs(A, 0, len - 1);
    pa(A, len);
}
