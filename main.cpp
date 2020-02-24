#include <iostream>
#include <vector>
#include "Matrix.h"

using namespace std;

int main()
{
    Matrix mat(3);
    Matrix inv(3);


    mat(0,0) = 3.0;
    mat(0,1) = 1.0;
    mat(1,1) = 5.0;
    mat(1,0) = 1.0;
    mat(2,2) = 1.0;
    mat(1,2) = 2.0;
    mat(2,1) = 3.0;
    //mat2 = mat1;

    //mat2 = mat2*mat1;

    mat.display();


    inv = mat.inverse();

    inv.display();

    (mat*inv).display();

    return 0;
}
