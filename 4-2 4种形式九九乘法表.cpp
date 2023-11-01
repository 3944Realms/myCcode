#include <iostream>
using namespace std;
int main(){
    /*
    ===========================
    |      左上-左下-右下      |
    ===========================
    */
    for (int i = 1;i <= 9; i++){//控制行的输出(右乘数)
        for(int j = 1;j <= i; j++){//控制列的输出（左乘数）
            cout.width(4);//打印宽度从上一打印的结尾（不含）到此次打印的开头（包含）
            cout<<j<<" * "<<i<<" = "<<j*i;
            if (j*i < 10) cout<<" ";//当结果小于十时，补偿一个空格（方便对齐）(下面大致相同，不赘述)
        }
        cout<<endl;//换行符
    }
    cout<<endl;
    /*
    ===========================
    |     右上-右下-左下       |
    ===========================
    */
   for (int i = 1; i <= 9; i++){//控制行的输出（右乘数）
        for(int n = 9; n > i ; n-- ) {//输出空格
            cout.width(4);
            cout<<"             ";
        }
        for(int j = 9;j >= 1;j--){//控制列的输出（左乘数）
            cout.width(4);
            if(j*i<= 9){
                if (j <= i) cout<<j<<" * "<<i<<" = "<<j*i<<" ";
            }
            else if (j <= i) cout<<j<<" * "<<i<<" = "<<j*i;
        }
        cout<<endl;
   }
    cout<<endl;
    /*
    ===========================
    |     左上-右上-右下       |
    ===========================
    */
    for (int i = 9; i >= 1; i--){
        for(int n = 0; n < 9 - i; n++ ) {//输出空格
            cout.width(4);
            cout<<"             ";
        }
        for(int j = 9; j >= 1;j--){
            cout.width(4);
            if (j*i < 10){
                if(j <= i) cout<<j<<" * "<<i<<" = "<<j*i<<" ";
            }
            else if(j <= i) cout<<j<<" * "<<i<<" = "<<j*i;
        }
        cout<<endl;
    }
    cout<<endl;
    /*
    ===========================
    |     左上-左下-右上       |
    ===========================
    */
    for (int i = 9; i > 0; i--){
        for (int j = 1; j <= i; j++){
            cout.width(4);
            cout<<j<<" * "<<i<<" = "<<j*i;
            if (j*i < 10) cout<<" ";
        }
        cout<<endl;
    }
  
    return 0;
}
/*CPU脑子快给我干爆了*/
