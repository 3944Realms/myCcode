#include <iostream>
// #include <windows.h>
#include "ClassExperiment.h"//�뽫student.h����ͬһĿ¼��
double TempValueStorer[6]={0};
int INPUTDATA(student *arr,int count);
int GetAverageAndTotal(student *arr,int count,double *temp);
int Sort(student *arr,int count);
int Print_SCOREREPORT(student *arr,int count);
int main(){
    int n;
    std::cout<<"������Ҫ¼�����������ѧ��1��ʼ����";
    std::cin>>n;
    // HANDLE cout_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    // SetConsoleTextAttribute(console_handle, FOREGROUND_RED | BACKGROUND_INTENSITY);
    student stu[n];
    INPUTDATA(stu,n);
    Sort(stu,n);
    GetAverageAndTotal(stu,n,TempValueStorer);
    Print_SCOREREPORT(stu,n);
    return 0;
}
int INPUTDATA(student *arr,int count){
    for (int i = 0;i <= count - 1; i++){
        double MS, CS, ES;
        std::cout<<"������ѧ��Ϊ"<<i+1<<"����ѧ�����ĺ�Ӣ��ɼ���";
        std::cin>>MS>>CS>>ES;
        arr[i].INPUTINFORMATION(MS,CS,ES,i+1);
    }
    return 105;//105-��״̬��105:¼�����ִ�гɹ�
}
int GetAverageAndTotal(student *arr,int count,double *temp){
    double MsSUM = 0,CsSUM = 0,EsSUM = 0;
    for (int i = 0 ; i <= count - 1 ; i++){
        arr[i].BackScore();
        MsSUM += arr[i].MSO;
        CsSUM += arr[i].CSO;
        EsSUM += arr[i].ESO;
    }
    double MsAverage = MsSUM / count , CsAverage = CsSUM / count , EsAverage = EsSUM / count;
    temp[0] = MsSUM;temp[1] = CsSUM;temp[2] = EsSUM;temp[3] = MsAverage;temp[4] = CsAverage;temp[5] = EsAverage;
    return 202;//202-��״̬��202:¼��������ִ�гɹ�
}
int Sort(student *arr,int count){
    for (int i = 0; i <= count - 2; i++){
        for (int j = 0; j <= count - 2 - i; j++){
            student temp;
            if (arr[j].REBackTotalScore() <= arr[j + 1].REBackTotalScore()){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            } 
        }
    }
    return 102;//102-��״̬��102:�������ִ�гɹ�
}
int Print_SCOREREPORT(student *arr,int count){
     std::cout<<"------------------------------\n";
    std::cout<<"ȫ����ѧ�ɼ��ܷ�Ϊ��"<<TempValueStorer[0]<<",��ѧƽ����Ϊ��"<<TempValueStorer[3]<<"\n";
    std::cout<<"ȫ�����ĳɼ��ܷ�Ϊ��"<<TempValueStorer[1]<<",����ƽ����Ϊ��"<<TempValueStorer[4]<<"\n";    
    std::cout<<"ȫ��Ӣ��ɼ��ܷ�Ϊ��"<<TempValueStorer[2]<<",Ӣ��ƽ����Ϊ��"<<TempValueStorer[5]<<"\n";
    std::cout<<"-----------�ɼ�����-----------"<<"\n";
    for (int i = 0 ;i <= count - 1; i++){
        arr[i].Show();
    }   
    return 103; //103������״̬��103:��ӡ�����ɹ�
}
/*
���� ��ѧ Ӣ�� �ܷ� ƽ����
������ȫ������ 
�����ܷ� -��ƽ����
����
ÿ��ͬѧ���ܷ� ƽ����

*/