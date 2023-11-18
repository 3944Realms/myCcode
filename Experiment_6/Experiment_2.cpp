#include <iostream>
#include <stdbool.h>
class ArrayOperation{
private:
void Cyinput(int *Array,int targeINT,int startPIN,bool IsFirst){//数组读入
    if (IsFirst == true) std::cout<<"请输入数组(元素个数："<<targeINT<<"):";
    else std::cout<<"请输入数组(目前已输入元素个数："<<startPIN<<"，仍需要输入元素个数："<<targeINT-startPIN<<"):";
    for (int i = startPIN;i <= targeINT - 1;i++) std::cin>>Array[i];        
}
void ShowArray(int *Array,int ArrayLength){//数组输出
    std::cout<<"该数组排序后的元素顺序为(元素个数："<<ArrayLength<<"):";
    std::cout<<Array[0];
    for (int i = 1;i <= ArrayLength - 1;i++) std::cout<<","<<Array[i];
}
void SortArray(int *Array,int ArrayLength){//排序
    int temp;
    for(int i = 1 ; i <= ArrayLength - 1; i++){
        for(int j = 0 ; j <= ArrayLength - 1 - i;j++){
            if (Array[j] > Array[j + 1]){//DeBUG:加括弧是个好习惯
                temp = Array[j + 1];Array[j + 1] = Array[j] ; Array[j] = temp;
                }
        }
    }      
}
void ArrayEXchange (int *OArray,int *NewArray,int ENDPIN){//交换并删除前数组
    for(int i = 0; i <= ENDPIN ; i++)
        NewArray[i] = OArray[i];
}
public:
void CreateAndSortArray(){//创建和排序数组方法
    std::cout<<"请输入数组的元素个数：";
    int AArrayLength,insertLength;
    std::cin>>AArrayLength;
    #define intLength AArrayLength
    int Array_A[intLength] = {0};// 初始化数组
    Cyinput(Array_A,intLength,0,true);
    SortArray(Array_A,intLength);
    ShowArray(Array_A,intLength);
    std::cout<<"\n请输入插入的元素个数：";
    std::cin>>insertLength;
    #define ADDintLength insertLength
    // int NewArray[NewintLength + 2] = {0};//扩容即数组末尾指针向后移扩容数（问题：可能会占用其它变量的地址（安全性有待商榷））
    //还是创建一个新的数组
    int Array_B[ADDintLength + intLength] ={0};//初始化新数组
    ArrayEXchange(Array_A,Array_B,intLength);
    Cyinput(Array_B,ADDintLength + intLength,intLength,false);
    SortArray(Array_B,ADDintLength + intLength);
    ShowArray(Array_B,ADDintLength + intLength);
}
};
/*
数组创建+数组排序算法+数据排序插入数组法（创建新数组+导入原来老数组+新增数据（1个）（如果程序过大，内存可能会溢出）【可行性高】
&
在原数组导入前先移动后插入（可能会造成数组元素溢出）
//100000 000
*/
int main(){
    ArrayOperation Array_1;
    Array_1.CreateAndSortArray();
    return 0;
}
/*
n 个元素冒泡排序大体上外循环 n - 1 次,第 i 次外循环中共比较 n - i 次（内循环）
*/
//  1 2 3 0 -0
//  2 1 3 1 -1
//  2 3 1 2 -1
//  3 2 1 3 -2
