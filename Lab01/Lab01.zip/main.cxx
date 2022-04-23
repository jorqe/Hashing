#include <iostream>
#include "vector.h"
#include "matrix.h"
using namespace rojo_main;

int main()
{

    vector v1 = vector(1, 0);

    vector v2 = vector(0, 1);

    matrix m = matrix(v1, v2);

    std::cout <<"Creating first column vector" << std::endl;
    v1.print();
    std::cout <<"Creating Second Column vector" << std::endl;
    v2.print();
    
    //m1.print();
    std::cout <<"transpose"<< std::endl;
    v1.transpose();
    v1.print();
    
    std::cout << "-------------------"<< std::endl;
    //  m1.print();
    //  m1.transpose();
    //  m1.print();
    //matrix m1 = matrix(1, 2, 1, 3);
    //matrix m2 = matrix(2, 3, 4, 5);

    //matrix m3 = dot(m1, m2);
    //m.print();
    //m.is_identity();
    //m.determinant();


    //matrix m3 = matrix(1, 2, 3, 4);

   
    //matrix m4 = matrix(dot(m, m3));
    }
