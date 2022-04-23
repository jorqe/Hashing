#include <iostream>




int multiply(int x, int y);

int main()
{
    int x = 5;
    int y = 10;
    int *pointer1 = &x; 
    
    std::cout << "Value of x = " << x << std::endl;
    std::cout << "Value of y = " << y << std::endl;
    std::cout << "pointer1   = " << pointer1 << std::endl; 
    std::cout << "*pointer1   = " << *pointer1 << std::endl; 
    
    std::cout << "----------Calling multiply Funciton---------------" << std::endl;

    std::cout << multiply(1 , 2) << std::endl;
    }

int multiply(int x, int y)
{
    
    return (x * y);

    }
