#include <iostream>
#include "TMatrix.h"
#include "SMatrix.h"

int main()
{
    SMatrix<int> mtr(4, 1, 2);
    mtr(3, 3) = 55;

    SMatrix<int> mtr2(mtr);

    std::cout<<mtr2<<std::endl;

    return 0;
}
