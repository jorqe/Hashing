#include "dnode.h"


void dlist_head_insert(dnode*& head_ptr, const dnode::value_type& entry) 
{
    if (head_ptr != NULL)
}

void dlist_insert(dnode* previous_ptr, const dnode::value_type& entry)
{
	// add code here
}
  
void dlist_head_remove(dnode*& head_ptr)
{
	
}

void dlist_remove(dnode* previous_ptr)
{
	// add code here
}

dnode* dlist_search(dnode* head_ptr, const dnode::value_type& target)
{
	// add code here
}

void print_fore(const dnode* head_ptr)
{
	const dnode *cursor;
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->fore())
		std::cout << cursor->data() << " ";
	std::cout << std::endl;
}

void print_back(const dnode* head_ptr)
{
	const dnode *cursor;
	for (cursor = head_ptr; cursor->fore() != NULL; cursor = cursor->fore())
		cursor = cursor->fore();
	for (;cursor != NULL; cursor = cursor->back())
		std::cout << cursor->data() << " ";
	std::cout << std::endl;
}



