#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int index;
} Element;

void merge(Element* arr, int left, int mid, int right, int* count) {
    int i = left, j = mid + 1, k = 0;
    Element* temp = (Element*)malloc((right - left + 1) * sizeof(Element));
    int right_smaller_count = 0;

    while (i <= mid && j <= right) {
        if (arr[j].val < arr[i].val) {
            // Element in right half is smaller; increment the counter for this merge step
            right_smaller_count++;
            temp[k++] = arr[j++];
        } else {
            // Element in left half is placed; add all right elements skipped so far
            count[arr[i].index] += right_smaller_count;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        count[arr[i].index] += right_smaller_count;
        temp[k++] = arr[i++];
    }
    while (j <= right) temp[k++] = arr[j++];

    for (i = 0; i < k; i++) arr[left + i] = temp[i];
    free(temp);
}

void mergeSort(Element* arr, int left, int right, int* count) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, count);
        mergeSort(arr, mid + 1, right, count);
        merge(arr, left, mid, right, count);
    }
}

int main() {
    int nums[] = {5, 2, 6, 1};
    int n = 4;
    int count[4] = {0};
    Element arr[4];
    for (int i = 0; i < n; i++) { arr[i].val = nums[i]; arr[i].index = i; }

    mergeSort(arr, 0, n - 1, count);

    for (int i = 0; i < n; i++) printf("%d ", count[i]); // Output: 2 1 1 0
    return 0;
}
