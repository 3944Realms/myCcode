#include <iostream>
#include <stdbool.h>
#include <cmath>

class tip{
private:
    // // int OrginalArray[3000] = {0};
    // // bool JudgeAOE[3000] = {0};
    // tip (int A[3000] = {0},bool B[3000] = {0}){
    //     //�ع���Ա������ʼ��Ĭ��ֵ
    //     OrginalArray = A;
    //     JudgeAOE = B;
    // }
public:

    int CheckInput(int value){
        if (value <= 0) return 1;
        return 0;
    }
    void ReadArray(int *Array,int Length){
        std::cout<<"���������飺";
        for (int i = 0; i <= Length -1 ; i++){
            std::cin>>Array[i];
        }
    }
    int Diffence(int *Array,int TIP){
        return abs(Array[TIP + 1] - Array[TIP]);
    }
    void Write_Diffence_INTO_Array(int Diffence,bool *BOOLARRAY){
        BOOLARRAY[Diffence] = 1;
    }
    int FUNCTION_BOOLSUM_(bool *BOOLARRAY, int n){
        int sum = 0;
        for (int j = 1;j <= n - 2;j++){
           sum += (int)BOOLARRAY[j];
        }
        return sum;
    }
};
int main(){
    tip obj;
    int input_n;
    std::cout<<"�������г���n��ֵ��";
CHECK:
    std::cin>>input_n;
    if(obj.CheckInput(input_n) == 1) {
        std::cout<<"�������������:";
        goto CHECK;
    }
    if (input_n == 1){
        std::cout<<"��������Ȥ����Ծ";
        return 0;
    }
    #define n input_n
    int OrginalArray[n] = {0};
    bool JudgeAOE[n] = {0};
    obj.ReadArray(OrginalArray,n);
    for (int i = 0;i <= n - 2 ; i++){
        obj.Write_Diffence_INTO_Array(obj.Diffence(OrginalArray,i),JudgeAOE);
    }
    if (obj.FUNCTION_BOOLSUM_(JudgeAOE,n) == n - 2 && JudgeAOE[1] == 1) std::cout<<"������Ȥ����Ծ";
    else std::cout<<"��������Ȥ����Ծ";
    return 0;
}
