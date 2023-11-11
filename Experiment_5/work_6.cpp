#include <iostream>
#include <stdio.h>
void print(int num){
    if (num < 10 && num >= 0) printf("%d",num);
    else {
       print(num/10);
       printf(" %d",num%10);
    }
}
int main(){
    int n;
    std::cin>>n;
    print(n);
    return 0;
}