#include <iostream>
#include <stdbool.h>
class ArrayOperation{
private:
void Cyinput(int *Array,int targeINT,int startPIN,bool IsFirst){//�������
    if (IsFirst == true) std::cout<<"����������(Ԫ�ظ�����"<<targeINT<<"):";
    else std::cout<<"����������(Ŀǰ������Ԫ�ظ�����"<<startPIN<<"������Ҫ����Ԫ�ظ�����"<<targeINT-startPIN<<"):";
    for (int i = startPIN;i <= targeINT - 1;i++) std::cin>>Array[i];        
}
void ShowArray(int *Array,int ArrayLength){//�������
    std::cout<<"������������Ԫ��˳��Ϊ(Ԫ�ظ�����"<<ArrayLength<<"):";
    std::cout<<Array[0];
    for (int i = 1;i <= ArrayLength - 1;i++) std::cout<<","<<Array[i];
}
void SortArray(int *Array,int ArrayLength){//����
    int temp;
    for(int i = 1 ; i <= ArrayLength - 1; i++){
        for(int j = 0 ; j <= ArrayLength - 1 - i;j++){
            if (Array[j] > Array[j + 1]){//DeBUG:�������Ǹ���ϰ��
                temp = Array[j + 1];Array[j + 1] = Array[j] ; Array[j] = temp;
                }
        }
    }      
}
void ArrayEXchange (int *OArray,int *NewArray,int ENDPIN){//������ɾ��ǰ����
    for(int i = 0; i <= ENDPIN ; i++)
        NewArray[i] = OArray[i];
}
public:
void CreateAndSortArray(){//�������������鷽��
    std::cout<<"�����������Ԫ�ظ�����";
    int AArrayLength,insertLength;
    std::cin>>AArrayLength;
    #define intLength AArrayLength
    int Array_A[intLength] = {0};// ��ʼ������
    Cyinput(Array_A,intLength,0,true);
    SortArray(Array_A,intLength);
    ShowArray(Array_A,intLength);
    std::cout<<"\n����������Ԫ�ظ�����";
    std::cin>>insertLength;
    #define ADDintLength insertLength
    // int NewArray[NewintLength + 2] = {0};//���ݼ�����ĩβָ������������������⣺���ܻ�ռ�����������ĵ�ַ����ȫ���д���ȶ����
    //���Ǵ���һ���µ�����
    int Array_B[ADDintLength + intLength] ={0};//��ʼ��������
    ArrayEXchange(Array_A,Array_B,intLength);
    Cyinput(Array_B,ADDintLength + intLength,intLength,false);
    SortArray(Array_B,ADDintLength + intLength);
    ShowArray(Array_B,ADDintLength + intLength);
}
};
/*
���鴴��+���������㷨+��������������鷨������������+����ԭ��������+�������ݣ�1�����������������ڴ���ܻ�������������Ըߡ�
&
��ԭ���鵼��ǰ���ƶ�����루���ܻ��������Ԫ�������
//100000 000
*/
int main(){
    ArrayOperation Array_1;
    Array_1.CreateAndSortArray();
    return 0;
}
/*
n ��Ԫ��ð�������������ѭ�� n - 1 ��,�� i ����ѭ���й��Ƚ� n - i �Σ���ѭ����
*/
//  1 2 3 0 -0
//  2 1 3 1 -1
//  2 3 1 2 -1
//  3 2 1 3 -2
