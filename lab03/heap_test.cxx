// file: heap_test.cxx
// assignment 3

#include "heap.h"
#include <iostream>


void test1()
{
    heap h;
    for (int i=0; i<10; ++i)
    {
        h.add_entry(i+1);
        h.print_heap();
        std::cout << std::endl;
    }
    std::cout << "----------------------------\n";
    int top_val = h.remove_entry();
    std::cout << "top_val = " << top_val << std::endl << std::endl;
    h.print_heap();
}

// test2() will create a heap such that print_heap() outputs:
// 99
// 89  95
// 87  73  76  90
// 81  83  62  70  54  63  60  51
// 28  39  66  77  44  45  7  68  43  16  24  42  50  58  5  41
// 8  19  15  17  30  57  12  23  35
//
void test2()
{
    heap h;
    int entries[40] = {15, 58, 90, 83, 44, 54, 95, 30, 39, 62,  7, 76, 24, 60,
       41,  8, 81, 77, 12, 70, 45, 73, 68, 43, 16, 63, 42, 50, 99,  5, 51, 28,
       19, 89, 17, 57, 66, 87, 23, 35};
    for (int i=0; i<40; ++i)
        h.add_entry(entries[i]);
    h.print_heap();
}

int main()
{
    test1();
    std::cout << "==============================================\n";
    test2();

    return 0;
}
