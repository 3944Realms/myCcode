#include <iostream>
#include "Experiment.h"
#include <windows.h>
int main(){
    sort obj;
    int N;
    std::cout<<"����������ĳ���:";
    std::cin>>N;
    int array[N+1];
    std::cout<<"�����������Ԫ�أ�����"<<N<<"��Ԫ��):";
    obj.inputElement(array,0,N - 1);
    std::cout<<"��������X:";
    std::cin>>array[N];
    obj.qSortArray(array,0,N);
    std::cout<<"���벢��������Ϊ��";
    obj.printall(array,0,N);
    return 0;
}