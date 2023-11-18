#include <iostream>
#include <windows.h>
#include <stdbool.h>
class StringHandler{
private:
    
public:
    bool IsAvailable(int va_1,int va_2){
        if((va_1 < 2*va_2) || (va_1 <= 0) || (va_2 <= 0)) {
            std::cout<<"\n[错误]输入值不符合要求，存在非法输入,重输:";
            MessageBox(NULL,TEXT("请重输"),TEXT("警告"),MB_ICONWARNING);
            return false;
        }else return true;
    }
    void str_gets(char str[]){
        int i = 0;
        char ch;
        while ((ch = getchar()) != 10){//输入
            str[i] = ch;
            i++;
        }
        str[i] = '\0';
    }
    void str_puts(char str[]){//输出
        int i = 0;
        while (str[i] != '\0'){
            // printf("%c",str[i]);
            putchar(str[i]);
            i++;
        }
    }
    int str_strlen(char str[]){//长度
        int i = 0;
        while (str[i] != '\0'){
            i++;
        }
        return i;
    }
    // char *str_strcat(char str1[],char str2[]){//拼接（会改变str1的值）
    //     int i = str_strlen(str1),j = 0;
    //     while (str2[j] != '\0'){
    //         str1[i] = str2[j];
    //         i++;j++;
    //     }
    //     str1[i + j - 1] = '\n';
    //     return str1;
    // }
    void str_strcat(char *str1,char *str2){
        int End_pos = str_strlen(str2) + str_strlen(str1) ;int Beg_pos = str_strlen(str1);
        for(int i = Beg_pos ; i < End_pos; i++ ){
            str1[i] = str2[i - Beg_pos];
        }
    }

    char *str_strcpy(char str1[],char str2[]){//复制（会改变str1的值）
        int i = 0;
        while(str2[i] != '\0'){
            str1[i] = str2[i];
            i++;
        }
        str1[i] = '\0';
        return str1;
    }
    short int str_strcmp(char str1[],char str2[]){//比较
        int len1 = str_strlen(str1);
        int len2 = str_strlen(str2);
        int t= len1 > len2?len1:len2;
        int i,k;
        for (i = 0;i < t;){
        k = str1[i] - str2[i];
            if (k) break;
            else i++;
        }
        if (k > 0) return 1;
        else if (k == 0) return 0;
        return -1; 
    }
    void FUN(short int Value){//将 -1，0，1 转化为文字语言 小，等，大
        if (Value > 0) std::cout<<"前者更大";
        else if(Value == 0) std::cout<<"两者相等";
        else std::cout<<"后者更大";
    }
};
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
}//真实感受：耗时4个小时完成（debug到想吐）