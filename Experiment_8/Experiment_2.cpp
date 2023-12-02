#include <iostream>
#include "Experiment.h"
double GetaverageANDREBACKNEARNUMBER(int *arr,int number,int *nearNUMBER){
    sort obj;
    int Sum = obj.GetSum(arr,0,number - 1);
    double average = Sum/(double)number;
    double tdif = average - (double)arr[0];
    double dif;
    int j = 0;
    for (int i = 1 ;i++ <= number - 1;){
        dif = average - (double)arr[i];
        if(dif > 0 && dif < tdif) j = i,tdif = dif;
    }
    *nearNUMBER = arr[j];
    return average;
}
int main(){
    sort obj;
    int N;
    std::cout<<"输入数组的长度:";
    std::cin>>N;
    int arr[N]; //= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    std::cout<<"输入数列【长度为"<<N<<"】:";
    obj.inputElement(arr,0,N-1);
    int *nearN = arr;
    double Average = GetaverageANDREBACKNEARNUMBER(arr,N,nearN);
    std::cout<<"平均数为: "<<Average<<",距平均值最近的小数为："<<*nearN;
    return 0;
}