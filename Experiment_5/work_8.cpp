#include <iostream>
#include <windows.h>
using namespace std;
int method(int n){
    if(n == 1) return 1;
    else if (n == 2) return 2;
    return method(n-1)+method(n-2);//非最小规模，就递归
}
int main(){
    int n;
    cin>>n;
    cout<<method(n);
    return 0;
}