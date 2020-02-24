#include "Matrix.h"


Matrix::Matrix(size_t mat_size)
: n(mat_size),  mData(mat_size*mat_size)
{
    std::fill(mData.begin(), mData.end(), 0);
}

Matrix::~Matrix()
{
    //dtor
}

double& Matrix::operator()(size_t i, size_t j)
{
    return mData[i * n + j];
}

Matrix Matrix::operator*(Matrix B)
{

    Matrix C(n);

    // matrix multiplication element by element

    for(size_t i = 0; i < n ; i++){
        for(size_t j = 0; j < n ; j++){
            for(size_t k = 0; k < n ; k++){

                C(i,j) += mData[i * n + k]* B.mData[k * n + j];

            }
        }
    }

    return C;

}

void Matrix::display(){

    // matrix display in console

    for(size_t i = 0; i < n ; i++){
        for(size_t j = 0; j < n ; j++){
             std::cout << mData[i*n + j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

Matrix Matrix::cofactor(size_t p, size_t q){

    Matrix Cof(n-1);

    // return a N-1xN-1 size matrix where row p and col q are deleted.

    size_t k = 0, l = 0;
    for(size_t i = 0; i < n; i++){
        for(size_t j = 0; j < n; j++){

            if(i != p && j != q){

                Cof(k, l) = mData[i*n + j];
                l = l + 1;

                if(l == n-1){

                    l = 0;
                    k = k + 1;
                }
            }
        }
    }

    return Cof;
}

double Matrix::determinant(){

    // calculate determinant recursively by computing the determinant of the cofactors.
    if(n == 1){
        return mData[0];
    }

    double Det = 0;
    double s;
    Matrix Cof(n-1);

    for(size_t i = 0; i < n; i++){

        Cof = cofactor(0,i);
        s = pow(-1, i);
        Det += s*mData[i]*Cof.determinant();

    }

    return Det;

}

Matrix Matrix::inverse(){

    // get determinant of the matrix
    double Det = this->determinant();

    Matrix Cof(n-1);
    Matrix Inv(n);
    double s;

    // calculate inverse as the transpose of the adjugate matrix.
    for(size_t i = 0; i < n; i++){
        for(size_t j = 0; j < n; j++){

            Cof = cofactor(i,j);
            s = pow(-1, i + j);
            Inv(j, i) = s*Cof.determinant()/Det;

        }
    }

    return Inv;
}
