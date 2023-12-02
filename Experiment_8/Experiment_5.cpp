#include <iostream>
#include <windows.h>
#include <stdbool.h>
#include "Experiment.h"
int main(){
    int str1ALen ,str2ALen;
    StringHandler obj;
    std::cout<<"分别输入字符串1的最大空间长度A和字符串2的最大空间长度B（注意：A的空间至少是B的两倍）：";
Po_1:
    std::cin>>str1ALen>>str2ALen;
    if(obj.IsAvailable(str1ALen,str2ALen) == false) goto Po_1;
    #define str1Len (str1ALen + 32)
    #define str2Len (str2ALen + 32)
    char str1[str1Len];
    char str2[str2Len];
    char str[10];//BUG
    obj.str_gets(str);
    std::cout<<"\n请输入字符串1:";
    // gets(str1);
    obj.str_gets(str1);
    std::cout<<"字符串1为:";
    obj.str_puts(str1);
    std::cout<<"\n请输入字符串2:";
    obj.str_gets(str2);
    std::cout<<"字符串2为:";
    obj.str_puts(str2);
    std::cout<<"\n字符串1的长度为:"<<obj.str_strlen(str1);
    std::cout<<"\n字符串2的长度为:"<<obj.str_strlen(str2);
    std::cout<<"\n字符串1与字符串2比较结果为:";
    obj.FUN(obj.str_strcmp(str1,str2));
    std::cout<<"\n字符串1与字符串2的拼接后的新字符串1(1)为:";
    obj.str_strcat(str1,str2);
    obj.str_puts(str1);
    //obj.str_puts(strcat(str1,str2));
    std::cout<<"\n新字符串1(1)的长度为："<<obj.str_strlen(str1);
    std::cout<<"\n将字符串2复制到拼接后的字符串1的新字符1(2)为:";
    obj.str_puts(obj.str_strcpy(str1,str2));
    std::cout<<"\n新字符串1(2)的长度为："<<obj.str_strlen(str1);
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