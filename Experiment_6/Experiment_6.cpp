#include <iostream>
#include <cstring>
class ArrayStorer{
private:
    char StringArray[35];//����    
public:
    int BigNumberArray[35];
    void GetCharArray(){
        int i = 0;
        char ch;
        while ((ch = getchar()) != 10){//����
            if(ch <= 57 && ch >= 48) {//�������ֲŻᱻ��¼����
                StringArray[i] = ch;
                i++;
            }
        }
        StringArray[i] = '\0';
    }
    int GetLength(char *Str){
        return strlen(Str);
    }
    void INPUT_NUM_FROM_STR(){
        int len = strlen(StringArray);
        for (int i = 0; i <= len; i++){
            BigNumberArray[i] = StringArray[i] - '0';
        }
    }
    void ShowCharArray(){
        // const int len = strlen(StringArray);
        // for (int i = 0; i <= len; i++){
        puts(StringArray);
        // }
    }
    void ShowBNArray(){
        int len = strlen(StringArray);
        for (int i = 0; i < len ; i++){
            std::cout<<BigNumberArray[i];
        }
    }
    int Len = strlen(StringArray);
    
};
int main(){
    int flag = 0;int HOP = 0;
    ArrayStorer obj;
    std::cout<<"�����������";
    obj.GetCharArray();
    obj.INPUT_NUM_FROM_STR();
    for (int i = 2 ; i <=9 ; i++){
        int s = 0;
        // if (obj.Len == 1){

        // }
        if (obj.Len == 1 && obj.BigNumberArray[0] == 0) {
            std::cout<<"��2~9�ﲻ����������С��ʹ�øô������Ա������������NONE";
            return 0;
        }
        for(int j = 0; j < obj.Len;j++){
           s = (s * 10 + obj.BigNumberArray[j]) % i;
        }
        if (s == 0){
            HOP++;
            flag = 1;
            if(HOP == 1) {
                std::cout<<"��������������С��Ϊ��";
                std::cout<<i;
            }
            else std::cout<<","<<i;
        }
    }
    if (flag == 0) std::cout<<"��2~9�ﲻ����������С��ʹ�øô������Ա������������NONE";
    return 0;
}
//���Ҫ���Ӧ����Ҳ��ͬ���ĵ�����һ���������