#include <iostream>
#include "sequence3.h"
using namespace std;
namespace main_savitch_5{
	//default assignment constructor
	sequence::sequence(){
		head_ptr = NULL;
		tail_ptr = NULL;
		cursor = NULL;
		precursor = NULL;
		many_nodes = 0;	
	}
	//copy constructor
	sequence::sequence(const sequence& source){
		list_copy(source.head_ptr,head_ptr,tail_ptr);
		many_nodes = source.many_nodes;
		precursor = NULL;
		cursor = NULL;
	}
	//destructor
	sequence::~sequence(){
		list_clear(head_ptr);
		cursor = head_ptr;
	}
	//modification member functions
	void sequence::start(){
		precursor = head_ptr;
		cursor = head_ptr;	
	}
	void sequence::advance(){
		precursor = cursor;
		cursor = cursor->link();
	}
	void sequence::insert(const value_type& entry){
		if(cursor ==NULL){
			list_head_insert(head_ptr,entry);
		}else{
			list_insert(precursor,entry);
		}
		many_nodes+=1;
	}
	void sequence::attach(const value_type& entry){
		if(cursor != NULL){
		list_insert(cursor, entry);
		} else{
			list_insert(head_ptr,entry);
		}
		many_nodes+=1;
	}
	void sequence::operator =(const sequence& source){
		list_copy(source.head_ptr,head_ptr,tail_ptr);
		many_nodes = source.many_nodes;
		precursor = NULL;
		cursor = NULL;
	}

	void sequence::remove_current(){
	}
	//const member functions
	double sequence::current() const{
		
		return cursor->data();
	}


}
