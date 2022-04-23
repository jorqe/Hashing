// file: heap.h
// assignment 3
//
// DO NOT MODIFY THIS FILE
//
//   typedef _____ size_type
//     heap::size_type is the data type of any variable that keeps track of how
//     many entries are in the heap.
//
//   static const size_type DEFAULT_CAPACITY = _____
//     heap::DEFAULT_CAPACITY is the initial capacity of the heap that is
//     created by the default constructor.
//
// CONSTRUCTOR for the heap class:
//   heap(size_type _init_capacity = DEFAULT_CAPACITY)
//     Postcondition: The heap is empty with an initial capacity given by the
//     parameter. The insert function will work efficiently (without
//     allocating new memory) until this capacity is reached.
//
// MODIFICATION MEMBER FUNCTIONS for the heap class:
//   void add_entry(const int& _entry)
//     Precondition: _entry is positive integer.
//     Postcondition: An entry is added to the heap. Reheapification upward
//     is applied.
//
//   int remove_entry()
//     Precondition: The heap is not empty.
//     Postcondition: The root entry is removed and return. Reheapification
//     downward is applied.
//
// NON-MODIFICATION MEMBER FUNCTIONS for the heap class:
//   void print_heap()
//     Postcondition: The entries of the heap is printed. Each level of the
//     tree is printed as a separate new line (with two spaces between each
//     entry in a level). For example, given the following heap:
//           88
//          /  \
//        33    51
//       /  \
//     11    2
//
//     print_heap() will output:
//     88
//     33  51
//     11  2
//
// CONSTANT MEMBER FUNCTIONS for the heap class:
//   int get_parent_idx(const int& _idx) const
//      Precondition: _idx is not the root and a valid index
//      Postcondition: Given a node located at some valid index (_idx) of the
//      data array representing a binary tree, the index of the parent is
//      returned. The formula is given in the textbook (pg. 482).
//
//   int get_l_child_idx(const int& _idx) const
//      Precondition: _idx is a valid index.
//      Postcondition: Given a node located at some valid index (_idx) of the
//      data array representing a binary tree, the index of the left child is
//      returned. If there is no left child, -1 is returned. The formula is
//      given in the textbook (pg. 482).
//
//   int get_r_child_idx(const int& _idx) const
//      Precondition: _idx is a valid index.
//      Postcondition: Given a node located at some valid index (_idx) of the
//      data array representing a binary tree, the index of the right child is
//      returned. If there is no right child, -1 is return. The formula is
//      given in the textbook (pg. 482).
//

#ifndef HEAP_H
#define HEAP_H

#include <cstdlib>
#include <cassert>
#include <algorithm>

class heap
{
    public:
        typedef std::size_t size_type;
        static const size_type DEFAULT_CAPACITY = 30;

        heap(size_type _init_capacity = DEFAULT_CAPACITY);
        ~heap();

        void add_entry(const int& _entry);
        int remove_entry();
        int get_parent_idx(const int& _idx) const;
        int get_l_child_idx(const int& _idx) const;
        int get_r_child_idx(const int& _idx) const;
        void print_heap();


        // Not recommended inlined function (code from Bag).
        // But, placed here for your convenience as it
        // will be used by add_entry
        void reserve(size_type _new_capacity)
        {
            int* larger_array;
            if (_new_capacity == capacity) return;
            if (_new_capacity < used) _new_capacity = used;
            larger_array = new int[_new_capacity];
            std::copy(data, data + used, larger_array);
            delete [] data;
            data = larger_array;
            capacity = _new_capacity;
        }

    private:
        int* data;                 // Pointer to partially filled dynamic array
        std::size_t used;          // How much of array is being used
        std::size_t capacity;      // Current capacity of the heap
};

#endif
