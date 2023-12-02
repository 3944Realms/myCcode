#include <iostream>
#include "Experiment.h"
void Fun(int *o1,int *o2,int *o3,int *o4){
    sort obj;
    int array[4] = {*o1,*o2,*o3,*o4};
    obj.qSortArray(array,0,3);
    std::cout<<"排序后为（int）：";
    obj.printall(array,0,3);
}
int main(){
    int o1,o2,o3,o4;
    std::cout<<"请输入4个整数（int）：";
    std::cin>>o1>>o2>>o3>>o4;
    Fun(&o1,&o2,&o3,&o4);
    return 0;
}