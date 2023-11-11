#include <iostream>
#include <stdbool.h>
#include <windows.h>//优化需考虑时间复杂度和空间复杂度
using namespace std;
bool if_prime_number(int number);
int updownumber(int number);
int OutputNumber(int value);
int main(){
    SetConsoleOutputCP(65001);
    int Left_Range_Frontier,Right_Range_Frontier;//定义左右区间
    cout<<"请输入左右区间边界点[A，B]：";
PointCheck_1:
    cin>>Left_Range_Frontier>>Right_Range_Frontier;
    if (Right_Range_Frontier <= Left_Range_Frontier) {
        cout<<"输入错误，A不得大于等于B，请重输：";
        goto PointCheck_1;//输入错误值，强制返回
    }
    int counter = 0;//初始化计数器
    #define Array_Length (Right_Range_Frontier - Left_Range_Frontier)+1// 预留一位空
    int Pre_Prime_Number_Array[Array_Length]={0};//预数组（存放的是所有的数，非质也存）
    int Prime_Number_Array[Array_Length]={0};//对预数组进行筛选（只存质
    // int ArrayPin = 0; //初始化数组的序列号
    for(int i = Left_Range_Frontier; i <= Right_Range_Frontier; i++){
        Pre_Prime_Number_Array[i - Left_Range_Frontier] = OutputNumber(i);
        if (Pre_Prime_Number_Array[i - Left_Range_Frontier] != 0) {
            Prime_Number_Array[counter] = Pre_Prime_Number_Array[i - Left_Range_Frontier];//将真质数存入新数组里
            counter ++;
        }
    }//输出部分
    if (counter == 0) cout<<"闭区间"<<"["<<Left_Range_Frontier<<" , "<<Right_Range_Frontier<<"]"<<"上没有真素数"<<endl<<"所以输出："<<"NO";
    else {
        cout<<"闭区间"<<"["<<Left_Range_Frontier<<" , "<<Right_Range_Frontier<<"]"<<"上有"<<counter<<"个真素数"<<endl<<"真素数为：";
        for(int j = 0; j < counter; j++){ 
            if (j == 0) {//控制逗号位置
                cout<<Prime_Number_Array[j];
            }
            else cout<<","<<Prime_Number_Array[j];
        }
    }
    return 0;
}
/*
优化方向：A % B
1.若 数A 被 质数B 取余不为0，则 被 质数B的倍数 取余一定不为0 -->排除质数B的倍数
2.一个正整数的因数（出本身外），其因数一定不大于其本身的二分之一 -->范围缩小
3.当一个数第一次被比自己小的数（不B包含1）整除成功后，我们就可以立刻判断出这个数不是质数，使用break
4.如果存在 数字A 能被 数字B 整除，那么一定存在这样一个 小于等于 数字A 算术平方根的 数字B（数学定理），
  所以一个数字在B ~ 本身算术平方根 这个数字区间内没有遇到能够 被整除 的 数字，那么这个数就不是质数
*/
bool if_prime_number(int number){//判断是否是质数的布尔函数
    int counter = 0;
    if (number % 2 != 0 ){
        for (int i = 2;i < (number/2);i++){
            counter ++;
            if (i % 2 == 0) continue;
            else if (number % i == 0) return false;
        }
        return true;
    }
    else return false;
}
int updownumber(int number){//倒置数位的函数（只能输入正整数）
    int OutputNumber = 0;
    while (number){
        OutputNumber *= 10;
        OutputNumber += number % 10;
        number /= 10;
    }
    return OutputNumber;
}
int OutputNumber(int value){//如果是真素数则返回其本身，否则返回0
    if (if_prime_number(value)){
        if(if_prime_number(updownumber(value))) return value;
    }
    return 0;
}