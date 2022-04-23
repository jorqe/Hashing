#include "matrix.h"


namespace rojo_main
{
matrix::matrix()
{
    a = 1;
    b = 0;
    c = 0;
    d = 1;

    }
matrix::matrix(vector v1, vector v2)
{

    if(column != false)
    {
        a = v1.get_x();
        b = v2.get_x();
        c = v1.get_y();
        d = v2.get_y();
        }
    else
    {
        a = v1.get_x();
        b = v1.get_y();
        c = v2.get_x();
        d = v2.get_y();
        }
    }

matrix::matrix(float _a, float _b, float _c, float _d)
{
    a = _a;
    b = _b;
    c = _c;
    d = _d;

    }


float matrix::get_a(){return a;}
float matrix::get_b(){return b;}
float matrix::get_c(){return c;}
float matrix::get_d(){return d;}



void matrix::transpose()
{
    float z = b;//temporary value used to store value of b
    a = a;
    b = c;
    c = z;
    d = d;
    }



bool matrix::is_identity()
{
    if(a == 1 && b == 0 && c == 1 && d == 0) // this is checking if its an identity... 
    {
        return true;
        }
    else
    {
        return false;
        }

    }
float matrix::determinant()
{
    float det = (a * b) - (c * d);
    return det;
    }

void matrix::inverse()
{
    //assert(det > 0);
    float det = (a * b) - (c * d);
    assert(det > 0);
    a = (1/det) * a;
    b = (1/det) * -b;
    c = (1/det) * -c;
    d = (1/det) * d;


    //vector v1 = d, -b;
    //vector v2 = -c, a;
    
   // matrix m1 = (v1, v2);
        
   // inverse = (1/det) * m1;

    }

matrix matrix::dot(matrix m1, matrix m2) //member function dot(m1, m2 ), where m1 and m2 are matrices, to compute the
                                        //return m3 = dot(m1,m2), create a dot funtion to multiply 2 matrices
{ 

    float a = (m1.a * m2.a) + (m1.b * m2.c); // this arithmetic is doing the calculations for matrix 3 -- a , b , c , d
    float b = (m1.a * m2.b) + (m1.b * m2.d);
    float c = (m1.c * m2.a) + (m1.d * m2.c);
    float d = (m1.c * m2.b) + (m1.d * m2.d);
    
    matrix m3(a, b, c, d);
    return m3;

    }

vector matrix::dot(matrix m, vector v)
{


    float a = (m.a * v.get_x()) + (m.b * v.get_y());
    float c = (m.c * v.get_x()) + (m.d * v.get_y());
    
    vector v2(a, c);
    return v2;
    }


void matrix::print()
{
    std::cout << "[" << a << b << "\n" << c << d << "]" << std::endl; 
    }

matrix operator *(matrix m1, matrix m2)
{
    return matrix(m1.get_a() * m2.get_a(), m1.get_b() * m2.get_b() , m1.get_c() * m2.get_c() , m1.get_d() * m2.get_d());
    }

matrix operator -(matrix m1, matrix m2)
{
    return matrix(m1.get_a() - m2.get_a(), m1.get_b() - m2.get_b() , m1.get_c() - m2.get_c() , m1.get_d() - m2.get_d());
    }


matrix operator +(matrix m1, matrix m2)
{
    return matrix(m1.get_a() + m2.get_a(), m1.get_b() + m2.get_b() , m1.get_c() + m2.get_c() , m1.get_d() + m2.get_d());
    }



matrix operator *(float _k, matrix m1)
{
    return matrix(_k * m1.get_a() , _k * m1.get_b() , _k * m1.get_c() , _k * m1.get_d());

    }

matrix operator -(float _k, matrix m1)
{
    return matrix(_k - m1.get_a() , _k - m1.get_b() , _k - m1.get_c() , _k - m1.get_d());

    }

matrix operator +(float _k, matrix m1)
{
    return matrix(_k + m1.get_a() , _k + m1.get_b() , _k + m1.get_c() , _k + m1.get_d());

    }




















}
