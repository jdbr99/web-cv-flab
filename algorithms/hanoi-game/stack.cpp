#include "stack.hpp"
#include <iostream>

Stack::Stack() : top( nullptr ), length( 0 ) {
}

Stack::~Stack() {
	while(!is_empty())
		pop();
}

void Stack::push(ELEM val) {
	//std::cout << "Push in Stack\n";
	Node *newNode = new Node(val, top);
	top = newNode;	
	length++;
}

ELEM Stack::pop() {
	//std::cout << "Pop in Stack\n";
	if(top == nullptr)
		std::cout << "Error!: Underflow in Pop!\n";
	else{
		ELEM temp = top->get();
		Node *tempNode = top;
		top = top->upNext();
		length--;
		delete tempNode;
		return temp;
	}
}

ELEM Stack::front(){
	if(top == nullptr)
		std::cout << "Error!: Underflow in front!\n";
	else 
		return top->get();
}

std::string Stack::printS() {
	Stack temp;
	std::string st;
	while(!is_empty()) {
		st += std::to_string(front());
		temp.push(pop());
	}
	while(!temp.is_empty()) {
		push(temp.pop());
	}
	int len = st.length();
	for (int i = 0; i < len / 2; i++)
        	std::swap(st[i], st[len - i - 1]);
	return st;
}

int Stack::size() {
	return length;
}

int Stack::is_empty() {
	if(top == nullptr)
		return 1;
	return 0;
}
