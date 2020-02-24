#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <vector>
#include <math.h>
class Matrix
{
    public:
        Matrix(size_t mat_size = 6);

        double& operator()(size_t i, size_t j);
        Matrix operator *(Matrix B);

        void display();

        Matrix cofactor(size_t p, size_t q);
        double determinant();
        Matrix inverse();

        virtual ~Matrix();


    protected:

    private:
        size_t n;
        std::vector<double> mData;

};

#endif // MATRIX_H
