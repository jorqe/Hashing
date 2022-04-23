#include "vector.h"

namespace rojo_main
{

vector::vector()
{
    column = true;
    x = 1;
    y = 1;
}

vector::vector(float _x, float _y)
{
    column = true;
    x = _x;
    y = _y;
    
}

float vector::get_x(){return x;}
float vector::get_y(){return y;}



void vector::transpose()
{
    if (column == true)
    {
        column = false; 
        }
    else
    {
        column = true;
        }
}

void vector::print()
{
    if(column == false)
    {
    std::cout << "[" << x << " " << y << "]" << std::endl; // using inline scoperesolution
    }

    else
    {
        std::cout << "[" << x << "\n" << " " << y << "]" << std::endl;

        }
}



vector operator *(vector v1, vector v2)
{
    return vector((v1.get_x() * v2.get_x()), (v1.get_y() * v2.get_y()));
    }

vector operator -(vector v1, vector v2)
{
    return vector((v1.get_x() - v2.get_x()), (v1.get_y() - v2.get_y()));
    }

vector operator +(vector v1, vector v2)
{
    return vector((v1.get_x() + v2.get_x()), (v1.get_y() + v2.get_y()));
    }

vector operator *(float _k, vector v1)
{
    return vector(_k * v1.get_x() , _k * v1.get_y());
    }

vector operator -(float _k, vector v1)
{
    return vector(_k - v1.get_x() , _k - v1.get_y());
    }

vector operator +(float _k, vector v1)
{
    return vector(_k + v1.get_x() , _k + v1.get_y());
    }
}
