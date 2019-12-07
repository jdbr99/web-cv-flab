#define ELEM int

class Node{
private:
	ELEM data;
	Node *next;
public:
	Node(ELEM val);
	Node(ELEM val, Node *following);
	~Node();
	Node *upNext();
	ELEM get();
};
