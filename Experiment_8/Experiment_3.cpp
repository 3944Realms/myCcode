#include <iostream>
#include "Experiment.h"
// #define N 20//数组的元素个数
void updownPUT1(int *arr,int start,int end){
    for(int i = end;i >= start;i--){
        std::cout<<arr[i]<<" ";
    }
}
void updownPUT2(int arr[],int start,int end){
    int *p = &arr[end];
    for(int i = end;i >= start;i--,p--){
        std::cout<<*p<<" ";
    }    
}
int main(){
    sort obj;
    int N = 20;
    std::cout<<"请输入数组元素个数：";
    std::cin>>N;
    int arr[N];
    std::cout<<"请输入元素(一共"<<N<<"个）：";    
    obj.inputElement(arr,0,N-1);
    std::cout<<"调用形参用数组函数输出结果:";
    updownPUT1(arr,0,N-1);
    std::cout<<"\n";
    std::cout<<"调用形参用指针函数输出结果:";
    updownPUT2(arr,0,N-1);
}