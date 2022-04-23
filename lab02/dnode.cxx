#include "dnode.h"


void dlist_head_insert(dnode*& head_ptr, const dnode::value_type& entry) 
{
    if(head_ptr == NULL)
    {
        head_ptr = new dnode(entry);
    }
    else
    {  
        dnode* insert_ptr = new dnode(entry, head_ptr);
        head_ptr->set_back(insert_ptr);
        head_ptr = insert_ptr;
        }
}
void dlist_insert(dnode* previous_ptr, const dnode::value_type& entry)
{
    if(previous_ptr->fore() != NULL)
    {
        dnode* insert_ptr = new dnode(entry, previous_ptr->fore());
        previous_ptr->set_fore(insert_ptr);
        insert_ptr->set_back(previous_ptr);
        insert_ptr->fore()->set_back(insert_ptr); 
    }
    else if(previous_ptr->fore() == NULL)
    {
        dnode* insert_ptr = new dnode(entry);
        previous_ptr->set_fore(insert_ptr);
        insert_ptr->set_back(previous_ptr);
        }
}
 
void dlist_head_remove(dnode*& head_ptr)
{
    dnode* temp;
    temp = head_ptr;
    head_ptr = head_ptr->fore();
    delete temp;
    head_ptr->set_back(NULL);
}

void dlist_remove(dnode* previous_ptr)
{
    if(previous_ptr->fore()->fore() != NULL)
    {
        dnode* temp = previous_ptr->fore();
        previous_ptr->set_fore(temp->fore());
        temp->fore()->set_back(previous_ptr);
        delete temp;
    }
    else if(1 == 1)
    {
        dnode* temp = previous_ptr->fore();
        previous_ptr->set_fore(NULL);
        delete temp;
        }
}   
dnode* dlist_search(dnode* head_ptr, const dnode::value_type& target)
{
    while(head_ptr->fore() != NULL)
    {
        if(head_ptr->data() == target)
        {
            return head_ptr;
        }

        head_ptr = head_ptr->fore();
        }
    while(head_ptr->fore() == NULL)
    {
        if(head_ptr->data() == target)
        {
            return head_ptr;
            }
        head_ptr = head_ptr->fore();
        }

    return NULL;

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



