#include <iostream>
#include "ClassExperiment.h"

int main(){
    Marxial mar;
    int row,col;
    std::cout<<"请分别输入矩阵的列元素个数和行元素个数：";
    std::cin>>row>>col;
    mar.MarxialMain(row,col); 
    return 0;
}
/*
ColLeftBoundary-->CLB = 0
ColRightBoundary-->CRB = Col - 1
RowTOPBoundary-->RTB = 0
RowBottomBoundary-->RBB = Row - 1
ColPIN = 0
RowPIN = 0
for (Col*Row次)
    IF (ColPIN < CRB && Mode == 1) ColPIN++,continue
    ELSE Mode = 2,RTB++

    IF (RowPIN < RBB && Mode == 2) RowPIN++,continue
    ELSE Mode = 3,CRB--

    IF(ColPIN > CLB && Mode == 3) ColPIN--,continue
    ELSE Mode = 4,RBB--

    IF(RowPIN > RTB && Mode == 4) RowPIN--
    ELSE Mode = 1,CLB++
->mode 1

|
v mode 2

<-mode 3

^
|-mode 4

     0   1   2   3   4   5   6  list col

0    0   0   0   0   0   0   0

1    0   0   0   0   0   0   0

2    0   0   0   0   0   0   0

3    0   0   0   0   0   0   0

4    0   0   0   0   0   0   0

5    0   0   0   0   0   0   0

6    0   0   0   0   0   0   0

line
row
*/