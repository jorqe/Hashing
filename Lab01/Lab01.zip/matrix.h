#ifndef ROJO_MATRIX
#define ROJO_MATRIX

#include "vector.h"
#include <iostream>
#include <cassert>

namespace rojo_main
{
class matrix
{
    public:
    //Constructors 
    matrix();// Default constructor will set the matrix to the identity matrix
    matrix(vector v1, vector v2);//initializing two vectors  
    matrix(float _a, float _b, float _c, float _d);
    void transpose();
    bool is_identity();
    float determinant();
    void inverse();
    matrix dot(matrix m1, matrix m2);
    vector dot(matrix m, vector v);
    void print();

    float get_a();
    float get_b();
    float get_c();
    float get_d();

    private:
    float a;
    float b;
    float c;
    float d;
    bool column;
   
    };

    matrix operator *(matrix m1, matrix m2);//applying basic arithmetic functions to the matrices
    matrix operator -(matrix m1, matrix m2);
    matrix operator +(matrix m1, matrix m2);

    matrix operator *(float _k, matrix m1);// applying scalar to the matrices 
    matrix operator -(float _k, matrix m1);
    matrix operator +(float _k, matrix m1);





}
#endif
