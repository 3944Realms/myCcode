#include <iostream>
// #include <windows.h>
#include "ClassExperiment.h"//请将student.h放入同一目录里
double TempValueStorer[6]={0};
int INPUTDATA(student *arr,int count);
int GetAverageAndTotal(student *arr,int count,double *temp);
int Sort(student *arr,int count);
int Print_SCOREREPORT(student *arr,int count);
int main(){
    int n;
    std::cout<<"请输入要录入的人数（从学号1开始）：";
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
        std::cout<<"请输入学号为"<<i+1<<"的数学、语文和英语成绩：";
        std::cin>>MS>>CS>>ES;
        arr[i].INPUTINFORMATION(MS,CS,ES,i+1);
    }
    return 105;//105-》状态码105:录入操作执行成功
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
    return 202;//202-》状态码202:录入计算操作执行成功
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
    return 102;//102-》状态码102:排序操作执行成功
}
int Print_SCOREREPORT(student *arr,int count){
     std::cout<<"------------------------------\n";
    std::cout<<"全班数学成绩总分为："<<TempValueStorer[0]<<",数学平均分为："<<TempValueStorer[3]<<"\n";
    std::cout<<"全班语文成绩总分为："<<TempValueStorer[1]<<",语文平均分为："<<TempValueStorer[4]<<"\n";    
    std::cout<<"全班英语成绩总分为："<<TempValueStorer[2]<<",英语平均分为："<<TempValueStorer[5]<<"\n";
    std::cout<<"-----------成绩排名-----------"<<"\n";
    for (int i = 0 ;i <= count - 1; i++){
        arr[i].Show();
    }   
    return 103; //103——》状态码103:打印操作成功
}
/*
语文 数学 英语 总分 平均分
——》全班人数 
单科总分 -》平均分
排序
每个同学的总分 平均分

*/