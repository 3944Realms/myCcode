#include <iostream>
class Pascal_s_Triangle {
private:
    int step;
public:
    int MainCreater(){
        std::cout<<"ÇëÊäÈë½×Êý£¨step < 10£©£º";
        std::cin>>step;
        #define n step
        int Triangle[n*n] = {0};
        CreateTriangle(n,Triangle);
        printTriangle(n,Triangle);
        return 0;
    }
    void CreateTriangle(int line,int *Triangle){
        for (int i = 0;i <= line - 1; i++){
            for (int j = 0;j <= line -1;j++){
                if( (i == j) || (j == 0))  Triangle[i*(line-1) +j] = 1;
                else Triangle[i*(line-1) +j] = Triangle[ (i - 1) * (line - 1) + j - 1] + Triangle[(i - 1) * (line - 1) + j ];
            }
        }
    }
    void printTriangle(int line,int *Triangle){
        for (int i = 0; i <= line - 1; i++){
            for(int j = 1;j <= line - 1 - i ; j++)std::cout<<"    ";
            for(int b = 0;b <= i;b++){
                if(b == 0)std::cout<<Triangle[i*(line-1)+b];
                else std::cout<<"       "<<Triangle[i*(line-1) + b];
            }
            std::cout<<"\n";
        }

    }
};
int main(){
    Pascal_s_Triangle obj1;
    obj1.MainCreater();
    return 0;
}
/*
________1:0tab step:1 
1
_________1: 1tab ; 2 :0tab step:2
    1       ->i:0 ;j:1 1 <= 2 - 1 - i j++ --> j:2 2 <= 2 - 1 - 0:false ->output only one
1       1   ->i:1 ;   
__________1:2tab 

        1
    1       1
1       2       1
__________
            1
        1       1
    1       2       1
1       3       3       1
____________
                1
            1       1
        1       2       1
    1       3       3       1
1       4       6       4       1
______________
                    1
                1       1
            1       2       1
        1       3       3       1
    1       4       6       4       1
1       5       10      10      5       1
__________________
                        1
                    1       1
                1       2       1
            1       3       3       1
        1       4       6       4       1
    1       5       10      10      5       1
1       6       15      20      15      6       1
*/