#include <iostream>
#define Max(a,b) (a <= b? b : a)
#define Min(a,b) (a <= b? a : b)
class ArrayClass{
private:
    int maxvalue,minvalue;
    int sum,PIN_MIN,PIN_MAX;
protected:
    // int sum_Array(int *Array,int Number){
    //     int sum = Array[Number]
    // }
public:
    void ReadArray(int *Array,int Array_Length){
        std::cout<<"\n���������Ԫ��(Ԫ�ظ�����"<<Array_Length<<"):";
        for(int i = 0;i <= Array_Length - 1; i++){
            std::cin>>Array[i];
        }
    }
    
    void OperationArray(int *Array,int Array_Length){//��ͣ�����ֵ
        minvalue = Array[0];maxvalue = minvalue;sum = 0;PIN_MIN = 0;PIN_MAX = 0;
        for(int i = 0;i <= Array_Length -1 ; i++){
            sum += Array[i];
            if (minvalue > Array[i]){
                minvalue = Array[i];PIN_MIN = i;
            }
            if (maxvalue < Array[i]){
                maxvalue = Array[i];PIN_MAX = i;
            }
        }
    }
    void ShowMAXMIN(){
        std::cout<<"\n��������������Ϊ"<<maxvalue<<"����Ӧ�±�Ϊ"<<PIN_MAX<<std::endl;
        std::cout<<"\n����������С����Ϊ"<<minvalue<<"����Ӧ�±�Ϊ"<<PIN_MIN<<std::endl;
    }
    void UpdownArray(int *Array,int Array_Length){
        std::cout<<"\n����������Ϊ:";
        std::cout<<Array[Array_Length - 1];
        for (int i = Array_Length - 2; 0 <= i ; i--){
            std::cout<<","<<Array[i];
        }
    }

};
int main(){
    ArrayClass object;
    int Length;
    std::cout<<"����������ĳ���";
    std::cin>>Length;
    #define ArrayLength Length
    int arrayobject[ArrayLength] = {0};
    object.ReadArray(arrayobject,ArrayLength);
    object.OperationArray(arrayobject,ArrayLength);
    object.ShowMAXMIN();
    object.UpdownArray(arrayobject,ArrayLength);
    return 0;
}