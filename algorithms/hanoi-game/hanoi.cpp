#include "hanoi.hpp"
#include <iostream>
#include <string>

using namespace std;

Hanoi::Hanoi(int discs) {
	for(int i = discs; i > 0; i--){ 
		tower[0].push(i);
	}
}

Hanoi::~Hanoi() {
}

bool Hanoi::move(int from, int to) {
	if(from > 2 || to > 2 || tower[from].is_empty()) 
		return false;
	else if(tower[to].is_empty()) {
		tower[to].push(tower[from].pop());
	}
	else if(tower[from].printS().back() > tower[to].printS().back()) {
		return false;
	}
	else 
		tower[to].push(tower[from].pop());
	return true;
}

void Hanoi::print() {
	cout << "Estado actual de las torres:\n";
	for(int i = 0; i < 3; i++) {
		cout << i << " ┣━";
		cout << tower[i].printS();
		cout << "━" << endl;;
	}
}

bool Hanoi::isOver() {
	const string correct = "321";
	string check;
	check = tower[2].printS();
	if(check == correct)
		return 1;
	return 0;
}
