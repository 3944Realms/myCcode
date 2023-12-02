#include <iostream>
void swap(int *a1,int *a2){
    int t = *a1;
    *a1 = *a2;
    *a2 = t;
}
int quick_sort(int arr[], int startPIN, int endPIN) {
    if (startPIN >= endPIN) {
        return startPIN;
    }

    int BaseNumber = arr[endPIN];
    int i = startPIN - 1;
    int j = endPIN + 1;
    int mode = 1;

    while (i >= j) {
        if (mode == 1) {
            j++;
        } else {
            i++;
        }

        if (arr[i] > BaseNumber && mode == 1) {
            i--;
        } else if (arr[j] < BaseNumber && mode == 0) {
            j++;
        }
    }

    swap(&arr[i + 1], &arr[endPIN]);
    return quick_sort(arr, startPIN, i - 1) + 1;
}

int main() {
    int array[10] = {1, 3, 4, 6, 2, 4, 6, 4, 8, 2};
    int pivotIndex = quick_sort(array, 0, 9);

    for (int i = 0; i <= pivotIndex; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    for (int i = pivotIndex + 1; i < 10; i++) {
        std::cout << array[i] << " ";
    }

    return 0;
}
