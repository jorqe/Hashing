#include "heap.h"
#include <iostream>


int get_parent_idx(const int& _idx);



void swap(int &x, int &y)
{
    int temp = x; 
    x = y;
    y = temp;
    }



heap::heap(size_type _init_capacity)
{
    used = 0;
    capacity = _init_capacity;  
    data = new int[_init_capacity];
    
    }   

heap::~heap()
{
    used = 0;
    delete [] data;   
    }


void heap::add_entry(const int& _entry)
{
    /*
    if(used == capacity)
    {
        std::cout << "Heap Full" << std::endl;
        return;
        }
        */
    used ++;

    int i = used - 1;
    data[i] = _entry;

    while(i != 0 && data[get_parent_idx(i)] < data[i])
    {
        swap(data[get_parent_idx(i)], data[i]);
        i = get_parent_idx(i);
        }

/*
    this->reserve(used);
    
    int index = used - 1; 
    data[index] = _entry; 


    int parent = get_parent_idx(_entry);

    while(index != 0 && data[parent] < data[index])
    {
        std::swap(data[index], data[parent]);

        index = parent;

        }
*/    

    }

int get_l_child_idx(const int& _idx);
int get_r_child_idx(const int& _idx);


int heap::remove_entry()
{
    if(1 == 1)
    {
        int root = data[0]; // storing the root node of the heap... 
 
        data[0] = data[used - 1];

        used --;

        
        if(data[0] < data[get_l_child_idx(0)])
        {
            swap(data[0], data[get_l_child_idx(0)]);

        }
        if(data[1] < data[get_r_child_idx(1)])
        {
            
            swap(data[1], data[get_r_child_idx(1)]);
            }

        return root;
      }    
     }
/*
     // return root;

     //while(root < data[get_l_child_idx(root)] or root < data[get_r_child_idx(root)])
        //{

     if(data[get_l_child_idx(data[0])] > data[get_r_child_idx(data[0])] )
       {
           while(root < data[get_l_child_idx(root)] or root < data[get_r_child_idx(root)])
           {
               swap(data[0], data[get_l_child_idx(data[0])]);
           }
                }
     while(data[get_l_child_idx(data[0])] < data[get_r_child_idx(data[0])] )
       {
       swap(data[0], data[get_r_child_idx(data[0])]);
             }
           //return root;

          //  }
         return root;
     }
*/
   



int heap::get_parent_idx(const int& _idx) const
{
    return (_idx - 1) / 2; 
    }




int heap::get_l_child_idx(const int& _idx)const {return 2 * _idx + 1;}


int heap::get_r_child_idx(const int& _idx)const {return 2 * _idx + 2;}



void heap::print_heap()
{
    /*
    for(int i = 0; i < used; i++)
    {
        std::cout << data[i] << "";
    std::cout << std::endl;
        }
    */
    int power = 0;
    int value = 1;
    for(int i = 0; i < used; i++)
    {
        if(i == value)
        {
            std::cout << std::endl;
            power += 1;
            value += (1 << power);
        }
        std::cout << data[i] << " ";
    }
        std::cout << std::endl;
}






