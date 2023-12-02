#include <iostream>
int quick_sort(int *arr,int startPIN,int endPIN){
    if (endPIN - startPIN == 0) return 0;
    int i = startPIN,j = endPIN;
    int BaseNumber = arr[startPIN];
    while (i < j){
        while (i < j && BaseNumber <= arr[j]){
            j--;
        }
        arr[i] = arr[j];
        while (i > j && BaseNumber >= arr[i]){
            i++;
        }
        arr[j] = arr[i];
    }
    arr[i] = BaseNumber;
    quick_sort(arr,startPIN,i-1);
    quick_sort(arr,i+1,endPIN);
    return i;
}
int main(){
    int array[10] = {1,3,4,6,2,4,6,4,8,2};
    quick_sort(array,0,9);
    for (int i = 0 ;i<=9;i++){
        std::cout<<array[i]<<" ";
    }
    return 0;
}
// int quick_sort(int *arr,int startPIN,int endPIN){
//     int BaseNumber = arr[startPIN];
//     int i = startPIN,j = endPIN;
//     int mode = 1;
//     while (i < j){
//         if (mode == 1) j--;
//         else i++;
//         if (BaseNumber > arr[j] && mode == 1){
//             arr[i] = arr[j];
//             mode = 0;
//         }
//         else (BaseNumber < arr[i && mode == 0]){
//             arr[j] = arr[i];
//             mode = 1;
//         }
//     }
//     arr[i] = BaseNumber;
//     quick_sort(arr,startPIN,i-1);
//     quick_sort(arr,i+1,endPIN);
//     return i;
// }