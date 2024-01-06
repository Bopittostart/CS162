/*********************************************************************
** Program Filename: linked_list.cpp
** Author: Quinn Roth
** Date: 12/10/23
** Description: Contains all all of the functions for the linked list
** Input: Enter
** Output: Tests
*********************************************************************/
#include "linked_list.h"

/*********************************************************************
** Function: get_length
** Description: returns the length of the linked list
** Parameters: none 
** Pre-Conditions: length has a value
** Post-Conditions: the length is returned
*********************************************************************/
int Linked_List::get_length() {
	// note: there is no set_length(unsigned int) (the reasoning should be intuitive)
	// Your code goes here:
	return this->length;
}
/*********************************************************************
** Function: print
** Description: prints the values in the list
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: list is printed
*********************************************************************/
void Linked_List::print(){
	// output a list of all integers contained within the list
	// Your code goes here:
	Node* current = head;
	while (current != nullptr){
		cout << current->val << " ";
		current = current->next;
	}

	cout << "\n";
	return;
}
/*********************************************************************
** Function: clear
** Description: deletes the linked list
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: linked list is deleted
*********************************************************************/
void Linked_List::clear(){
	// delete the entire list (remove all nodes and reset length to 0)
	// Your code goes here:
	Node* current = head;
	Node* temp = nullptr;
	while (current != nullptr){
		temp = current->next;
		delete current;
		current = temp; 
		this->length = this->length-1;
	}
	head = nullptr;	
	return;
}
/*********************************************************************
** Function: push_front
** Description: pushes a new element to the front of the list
** Parameters: int val, the value of the element to be added
** Pre-Conditions: none
** Post-Conditions: element added to front of list
*********************************************************************/
void Linked_List::push_front(int val){
	// insert a new value at the front of the list 
	// Your code goes here:
	Node* new_node = new Node(val);
	
	new_node->next = head;
	head = new_node;
	this->length = this->length + 1;
	return;
}
/*********************************************************************
** Function: push_back
** Description: adds an element to the back of the list
** Parameters: int val, alue of the element to be added
** Pre-Conditions: none
** Post-Conditions: element added to the end of the list
*********************************************************************/
void Linked_List::push_back(int val){
	// insert a new value at the back of the list  
	// Your code goes here:
	Node *new_node = new Node(val);
	
	if(head == nullptr){
		head = new_node;
		this->length = this->length + 1;

		return;
	}
	Node* current = head;
	while (current != nullptr && current->next != nullptr){
		current = current->next;
	}
	current->next = new_node;
	this->length = this->length + 1;

	return;
}
/*********************************************************************
** Function: insert
** Description: inserts an element into a specified index of the list
** Parameters: int val, int index, 
** Pre-Conditions: none
** Post-Conditions: element inserted into the list
*********************************************************************/
void Linked_List::insert(int val, int index){
	// insert a new value in the list at the specified index 
	// Your code goes here:
	//edge case if index is oob
	//edge is index = first and last
	//
	if(index > this->length){
		return;
	}
	if(index == 0){
		push_front(val);
		return;
	}
	if(index == this->length){
		push_back(val);
		return;
	}
	
	Node* current = head;
	Node* new_node;
	new_node = new Node;
	new_node->val = val;
	new_node->next = nullptr;

	for(int i = 0; i < index-1; i++){
		current = current->next;
	}

	new_node->next = current->next;
	current ->next = new_node;
	
	this->length = this->length + 1;
	return;
}
/*********************************************************************
** Function: pop_back
** Description: removes the last element of the list
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: last element of the list is removed
*********************************************************************/
void Linked_List::pop_back(){
	// remove the node at the back of the list
	// Your code goes here:
	if(head == nullptr){
		return;
	}
	if(head->next == nullptr){
		delete head;
		head = nullptr;
		this->length = this->length-1;

		return;
	}
	Node* current = head;
	while(current != nullptr && current->next != nullptr && current->next->next != nullptr){
		current = current->next;
	}
	delete current->next;
	current->next = nullptr;
	this->length = this->length-1;

	return;
}
/*********************************************************************
** Function: pop_front
** Description: removes the first element of the list
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: first element is removes
*********************************************************************/
void Linked_List::pop_front(){
	// remove the node at the front of the list
	// Your code goes here:
	if(head == nullptr){
		return;
	}
	Node* current = head;
	head = head->next;
	delete current;
	this->length = this->length-1;

	return;
}
/*********************************************************************
** Function: remove
** Description: removes an element at a specified location
** Parameters: index
** Pre-Conditions: none
** Post-Conditions: element at a specified location is removed
*********************************************************************/
void Linked_List::remove(int index){
	// remove the node at index of the list
	// Your code goes here:
	if(index > this->length){
		return;
	}
	if(index == 0){
		pop_front();
		return;
	}
	if(index == this->length -1 ){
		pop_back();
		return;
	}
	Node* current = head;
	for(int i = 0; i < index -1 ; i++){
		current = current->next;
	}
	Node* temp = current->next->next;
	delete current->next;
	current->next = temp;
	this->length = this->length-1;
	return;
}


/*********************************************************************
** Function: split
** Description: splits the linked list into two halves
** Parameters: node pointer start, double node pointer ref_front, double node pointer ref_back
** Pre-Conditions: none
** Post-Conditions: list is split in half
*********************************************************************/
void Linked_List::split(Node* start, Node** ref_front, Node** ref_back){
	Node* fast;
	Node* slow;
	slow = start;
	fast = start->next;

	while( fast != nullptr){
		fast = fast->next;
		if(fast!=nullptr){
			slow = slow->next;
			fast = fast->next;
		}
	}
	*ref_front = start;
	*ref_back = slow->next;
	slow->next = nullptr;
}
/*********************************************************************
** Function: ascend_sorted_list
** Description: merges two lists together
** Parameters: ointer front, node pointer back
** Pre-Conditions: list is split
** Post-Conditions: list merged
*********************************************************************/
Node* Linked_List::ascend_sorted_list(Node* front, Node* back){
	Node* sorted = nullptr;
	if(front == nullptr){
		return back;
	}
	else if (back == nullptr){
		return front; 
	}
	if (front->val <= back->val){
		sorted = front;
		sorted->next = ascend_sorted_list(front->next, back);
	}
	else {
		sorted = back;
		sorted->next = ascend_sorted_list(front, back->next);
	}
	return sorted;
}
/*********************************************************************
** Function: merge_ascend_sort
** Description: sorts the linked list by changing the next pointers
** Parameters: double pointer ref_to_head
** Pre-Conditions: none
** Post-Conditions: list is sorted
*********************************************************************/
void Linked_List::merge_ascend_sort(Node** ref_to_head){
	Node* front;
	Node* back;
	Node* head = *ref_to_head;

	if (head == nullptr || head->next == nullptr){
		return;
	}
	split(head, &front, &back);
	merge_ascend_sort(&front);
	merge_ascend_sort(&back);
	
	*ref_to_head = ascend_sorted_list(front, back);
}
/*********************************************************************
** Function: sort_ascending
** Description: sorts the list into ascending order using merge sort
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: list is sorted in ascending order
*********************************************************************/
void Linked_List::sort_ascending(){
	// sort the nodes in ascending order. You must implement the recursive Merge Sort algorithm
	// Note: it's okay if sort_ascending() calls a recursive private function to perform the sorting.
	// Your code goes here:
	merge_ascend_sort(&head);


	return;
}
/*********************************************************************
** Function: select_sort
** Description: sorts the list into descending order
** Parameters: node pointer head
** Pre-Conditions: none
** Post-Conditions: list is sorted in ascending order
*********************************************************************/
Node* select_sort(Node* head){
	if (head == nullptr || head->next == nullptr) {
    return head;
  }

  Node* current = head;

  while (current != nullptr) {
    Node* max_node = current;

    Node* next_node = current->next;
    while (next_node != nullptr) {
      if (next_node->val > max_node->val) {
        max_node = next_node;
      }

      next_node = next_node->next;
    }

    int temp = current->val;
    current->val = max_node->val;
    max_node->val = temp;

    current = current->next;
  }

  return head;
}
/*********************************************************************
** Function: sort_descending
** Description: sorts the list into descending order
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: list is sorted in ascending order
*********************************************************************/
void Linked_List::sort_descending(){
	// sort the nodes in descending order
	// Your code goes here:
	select_sort(head);
	return;
}
