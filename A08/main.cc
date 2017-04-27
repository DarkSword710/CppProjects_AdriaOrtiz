#include <iostream>
#include <deque>
#include <vector>
#include <queue>

//3) Implementar las siguientes funciones. 
//a. superMergeP que recibe dos priority_queue de enteros y devuelve una nueva priority_queue que corresponde al merge de las dos.
std::priority_queue<int> superMergeP(std::priority_queue<int> &queue1, std::priority_queue<int> &queue2) {
	std::priority_queue<int> result(queue1);

	for (int i = 0; i < queue2.size(); i++) {
		result.push(queue2.top());
		queue2.pop();
	}
	return result;
}

//b. 
std::queue<std::string> concatQueue(std::queue<std::string> &string1, std::queue<std::string> &string2) {
	std::queue<std::string> result(string1);

	for (int i = 0; i < string2.size(); i++) {
		result.push(string2.front());
		string2.pop();
	}
	return result;
}

void shiftRight(std::queue<int> queue) {
	std::queue<int> aux({rand()});
	for (int i = 0; i < queue.size(); i++) {
		aux.push(queue.front());
		queue.pop();
	}
	queue.swap(aux);
}

void rotateLeft(std::queue<int> queue) {
	int aux = queue.front();
	queue.pop();
	queue.push(aux);
}

void eraseElements(std::deque<int> deque, int toErase) {
	for (int i = 0; i < deque.size(); i++) {
		if (deque[i] == toErase) {
			deque.erase(deque.begin() + i);
		}
	}
}

void eraseRepeated(std::deque<int> deque) {
	for (int i = 0; i < deque.size(); i++) {
		for (int j = i + 1; j < deque.size(); j++) {
			if (deque[i] == deque[j]) {
				deque.erase(deque.begin() + j);
			}
		}
	}
}

void main() {
	//1)
	//Crear una <deque> de float’s llamada prices de 10 elementos e inicializar cada elemento a 10.50 
	std::deque<float> prices(10, 10.5);

	//Cambiar el último elemento por el valor 32.43
	prices[9] = 32.43;

	//Borrar el primer elemento
	prices.pop_front();

	//Asignar la deque a una nueva deque
	std::deque<float> newPrices(prices);

	//Insertar 5.64 y 20.31 al comienzo de la segunda deque, 
	newPrices.push_front(5.64);
	newPrices.push_front(20.31);

	//Insertar 10 como segundo elemento de la segunda deque	newPrices.insert(newPrices.begin() + 1, 10.0);

	//Imprimir la primera deque usando un backward iterato
	for (auto it = prices.rbegin(); it != prices.rend(); ++it) {
		std::cout << *it << " ";
	}

	std::cout << std::endl;

	//Imprimir la segunda deque de otra forma

	for (auto &x : newPrices) { std::cout << x << " "; }

	std::cout << std::endl;

	//2) Hacer lo mismo que en el paso 1) pero haciendo uso de <vector>
	//Crear una <deque> de float’s llamada prices de 10 elementos e inicializar cada elemento a 10.50 
	std::vector<float> vPrices(10, 10.5);

	//Cambiar el último elemento por el valor 32.43
	vPrices[9] = 32.43;

	//Borrar el primer elemento
	vPrices.erase(vPrices.begin());

	//Asignar la deque a una nueva deque
	std::vector<float> newVPrices(vPrices);

	//Insertar 5.64 y 20.31 al comienzo de la segunda deque,

	newVPrices.insert(newVPrices.begin(), 5.64);
	newVPrices.insert(newVPrices.begin(), 20.31);

	//Insertar 10 como segundo elemento de la segunda deque	newVPrices.insert(newVPrices.begin() + 1, 10.0);

	//Imprimir la primera deque usando un backward iterato
	for (auto it = vPrices.rbegin(); it != vPrices.rend(); ++it) {
		std::cout << *it << " ";
	}

	std::cout << std::endl;

	//Imprimir la segunda deque de otra forma

	for (int i = 0; i < newVPrices.size(); i++) {
		std::cout << newVPrices[i] << " ";
	}

	std::cout << std::endl;

	std::deque<int> deque({ 1,1,2,3,2,4,5,7 });

	eraseRepeated(deque);

	for (int i = 0; i < deque.size(); i++) {
		std::cout << deque[i] << " ";
	}

	std::cout << std::endl;

}