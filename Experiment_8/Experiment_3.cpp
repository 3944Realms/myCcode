#include <iostream>
#include "Experiment.h"
// #define N 20//�����Ԫ�ظ���
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
    std::cout<<"����������Ԫ�ظ�����";
    std::cin>>N;
    int arr[N];
    std::cout<<"������Ԫ��(һ��"<<N<<"������";    
    obj.inputElement(arr,0,N-1);
    std::cout<<"�����β������麯��������:";
    updownPUT1(arr,0,N-1);
    std::cout<<"\n";
    std::cout<<"�����β���ָ�뺯��������:";
    updownPUT2(arr,0,N-1);
}