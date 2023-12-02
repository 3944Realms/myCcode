#include <iostream>
#include "Experiment.h"
#include <windows.h>
int main(){
    sort obj;
    int N;
    std::cout<<"请输入数组的长度:";
    std::cin>>N;
    int array[N+1];
    std::cout<<"请输入数组的元素（共有"<<N<<"个元素):";
    obj.inputElement(array,0,N - 1);
    std::cout<<"输入整数X:";
    std::cin>>array[N];
    obj.qSortArray(array,0,N);
    std::cout<<"插入并排序后输出为：";
    obj.printall(array,0,N);
    return 0;
}