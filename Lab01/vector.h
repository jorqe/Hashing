#ifndef ROJO_VECTOR
#define ROJO_VECTOR

#include <iostream>

namespace rojo_main
{
    class vector
    {
        public:
                            //constructors
        vector();
        vector(float _x, float _y);
        float get_x();
        float get_y();
                            //member functions
        void transpose();
        void print();
        
        private:
        bool column;
        float x;
        float y;
        float k;
    };

    vector operator *(vector v1 , vector v2);
    vector operator -(vector v1 , vector v2);
    vector operator +(vector v1 , vector v2);
    
    vector operator *(float _k , vector v1);
    vector operator -(float _k , vector v1);
    vector operator +(float _k , vector v1);

}
#endif
