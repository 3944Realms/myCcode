#include <iostream>
#include <windows.h>
#include <stdbool.h>
class StringHandler{
private:
    
public:
    bool IsAvailable(int va_1,int va_2){
        if((va_1 < 2*va_2) || (va_1 <= 0) || (va_2 <= 0)) {
            std::cout<<"\n[����]����ֵ������Ҫ�󣬴��ڷǷ�����,����:";
            MessageBox(NULL,TEXT("������"),TEXT("����"),MB_ICONWARNING);
            return false;
        }else return true;
    }
    void str_gets(char str[]){
        int i = 0;
        char ch;
        while ((ch = getchar()) != 10){//����
            str[i] = ch;
            i++;
        }
        str[i] = '\0';
    }
    void str_puts(char str[]){//���
        int i = 0;
        while (str[i] != '\0'){
            // printf("%c",str[i]);
            putchar(str[i]);
            i++;
        }
    }
    int str_strlen(char str[]){//����
        int i = 0;
        while (str[i] != '\0'){
            i++;
        }
        return i;
    }
    // char *str_strcat(char str1[],char str2[]){//ƴ�ӣ���ı�str1��ֵ��
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

    char *str_strcpy(char str1[],char str2[]){//���ƣ���ı�str1��ֵ��
        int i = 0;
        while(str2[i] != '\0'){
            str1[i] = str2[i];
            i++;
        }
        str1[i] = '\0';
        return str1;
    }
    short int str_strcmp(char str1[],char str2[]){//�Ƚ�
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
    void FUN(short int Value){//�� -1��0��1 ת��Ϊ�������� С���ȣ���
        if (Value > 0) std::cout<<"ǰ�߸���";
        else if(Value == 0) std::cout<<"�������";
        else std::cout<<"���߸���";
    }
};
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
}//��ʵ���ܣ���ʱ4��Сʱ��ɣ�debug�����£�