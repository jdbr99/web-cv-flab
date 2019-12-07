#include "node.hpp"
#include <string>

class Stack{
private:
	Node *top;
	int length;
public:
	Stack();
	~Stack();
	void push(ELEM val);
	ELEM pop();
	ELEM front();
	std::string printS();
	int size();
	int is_empty();
};
