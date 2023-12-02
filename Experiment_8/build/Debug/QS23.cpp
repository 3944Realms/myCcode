#include <iostream>
#include "Experiment.h"
int main(){
    sort obj;
    int arr[10] = {1,3,4,6,2,4,6,4,8,2};
    obj.qSortArray(arr,0,9);
    for (int i = 0 ;i<=9;i++){
        std::cout<<arr[i]<<" ";
    }
    return 0;

}