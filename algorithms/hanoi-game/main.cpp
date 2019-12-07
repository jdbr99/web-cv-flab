#include "hanoi.hpp"
#include <iostream>

using namespace std;
int main() {
	int discn, from, to, turns;
	cout << "Torres de Hanoi <C++>\n";
	cout << "Con cuántos discos desea jugar?: ";
	cin >> discn;
	cout << "Comenzando el juego...\n\n";
	Hanoi game(discn);
	
	while(!game.isOver()) {
		game.print();
		cout << "Ingrese su movimiento: ";
		cin >> from >> to;
		if(!game.move(from, to)) {
			cout << "Ingrese un movimiento válido!\n";
		}
		turns++;
	}	
	cout << "Juego Terminado!\n";
	cout << "Ha terminado en " << turns << " turnos.\n";
}
