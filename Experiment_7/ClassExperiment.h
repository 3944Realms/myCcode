class student{
private:
    double MathScore,ChineseScore,EnglishScore,AverageScore,TotalScore;
    int ID;
public:
    double TS,MSO,CSO,ESO;
    int BackScore(){
        MSO = MathScore;
        CSO = ChineseScore;
        ESO = EnglishScore;
        return 201;//201-》状态码201:赋值操作执行成功

    }
    double REBackTotalScore(){
        TS = TotalScore;
        return TotalScore;
    }
    int INPUTINFORMATION(double MS,double CS ,double ES,int id){
        ID = id;
        MathScore = MS;
        ChineseScore = CS;
        EnglishScore = ES;
        TotalScore = MathScore + ChineseScore + EnglishScore;
        AverageScore = TotalScore/3;
        return 100; //100-》状态码100:输入操作执行成功
    }
    int Show(){
        std::cout<<"-------------------------\n";
        std::cout<<"学号:"<<ID<<"\n";
        std::cout<<"总分:"<<TotalScore<<"\n";
        std::cout<<"平均分:"<<AverageScore<<"\n";
        std::cout<<"-------------------------\n";
        return 101; //101-》状态码101:打印操作执行成功
    }

};
class Marxial{
public:
    void MarxialMain(int Row,int Col){
        #define ROW Row
        #define COL Col
        int Marxials[ROW][COL] = {0};
        std::cout<<"请输入该矩阵元素\n";
        for (int line = 0 ; line <= Row - 1; line++){
            std::cout<<"第"<<line + 1<<"行(共"<<Col<<"个元素):";
            for (int list = 0 ; list <= Col - 1; list++){
                std::cin>>Marxials[line][list];
            }
            std::cout<<"\n";
        }
        std::cout<<"[INFO] 录入完成!!!\n";
        int Number = Row*Col;
        int CLB = 0,CRB = Col - 1,RTB = 0,RBB = Row - 1;
        int Mode = 1,ColPIN=0,RowPIN = 0;
        std::cout<<"遍历结果为：";
        std::cout<<Marxials[RowPIN][ColPIN]<<" ";
        for(int n = 0; n <= Number - 1;n++){
            if (ColPIN < CRB && Mode == 1) {ColPIN++;std::cout<<Marxials[RowPIN][ColPIN]<<" ";continue;}
            else if (ColPIN == CRB && Mode == 1) {Mode = 2,RTB++;}

            if (RowPIN < RBB && Mode == 2) {RowPIN++;std::cout<<Marxials[RowPIN][ColPIN]<<" ";continue;}
            else if(RowPIN == RBB && Mode == 2) {Mode = 3,CRB--;}

            if(ColPIN > CLB && Mode == 3) {ColPIN--;std::cout<<Marxials[RowPIN][ColPIN]<<" ";continue;}
            else if(ColPIN == CLB && Mode == 3) {Mode = 4,RBB--;}

            if(RowPIN > RTB && Mode == 4) {RowPIN--;std::cout<<Marxials[RowPIN][ColPIN]<<" ";}
            else if(RowPIN == RTB && Mode == 4) {Mode = 1,CLB++;}

        }
    }

};