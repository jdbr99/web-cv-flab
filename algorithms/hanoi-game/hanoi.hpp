#include "stack.hpp"

class Hanoi {
private:
	Stack tower[3];
public:
	Hanoi(int discs);
	~Hanoi();
	bool move(int from, int to);
	void print();
	bool isOver();
};
