#include <iostream>
#include <windows.h>
#include <stdbool.h>
#include "Experiment.h"
int main(){
    int str1ALen ,str2ALen;
    StringHandler obj;
    std::cout<<"�ֱ������ַ���1�����ռ䳤��A���ַ���2�����ռ䳤��B��ע�⣺A�Ŀռ�������B����������";
Po_1:
    std::cin>>str1ALen>>str2ALen;
    if(obj.IsAvailable(str1ALen,str2ALen) == false) goto Po_1;
    #define str1Len (str1ALen + 32)
    #define str2Len (str2ALen + 32)
    char str1[str1Len];
    char str2[str2Len];
    char str[10];//BUG
    obj.str_gets(str);
    std::cout<<"\n�������ַ���1:";
    // gets(str1);
    obj.str_gets(str1);
    std::cout<<"�ַ���1Ϊ:";
    obj.str_puts(str1);
    std::cout<<"\n�������ַ���2:";
    obj.str_gets(str2);
    std::cout<<"�ַ���2Ϊ:";
    obj.str_puts(str2);
    std::cout<<"\n�ַ���1�ĳ���Ϊ:"<<obj.str_strlen(str1);
    std::cout<<"\n�ַ���2�ĳ���Ϊ:"<<obj.str_strlen(str2);
    std::cout<<"\n�ַ���1���ַ���2�ȽϽ��Ϊ:";
    obj.FUN(obj.str_strcmp(str1,str2));
    std::cout<<"\n�ַ���1���ַ���2��ƴ�Ӻ�����ַ���1(1)Ϊ:";
    obj.str_strcat(str1,str2);
    obj.str_puts(str1);
    //obj.str_puts(strcat(str1,str2));
    std::cout<<"\n���ַ���1(1)�ĳ���Ϊ��"<<obj.str_strlen(str1);
    std::cout<<"\n���ַ���2���Ƶ�ƴ�Ӻ���ַ���1�����ַ�1(2)Ϊ:";
    obj.str_puts(obj.str_strcpy(str1,str2));
    std::cout<<"\n���ַ���1(2)�ĳ���Ϊ��"<<obj.str_strlen(str1);
    // HandleString::
    return 0;
}
// #include <iostream>
// void str_cpy(char *str1,char *str2){
//     while (*str2){
//         *str1++ = *str2++;
//     }
//     *str1 = '\0';
// }
// int main(){
//     char str1[20] = "12345";
//     char str2[10] = "BOHI##";
//     str_cpy(str1,str2);
//     puts(str1);
//     return 0;
// }