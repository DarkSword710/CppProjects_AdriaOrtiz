#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include "myStack.h"

std::stack<int> superMerge(std::stack<int> stack1, std::stack<int> stack2) {

	std::stack<int> aux;
	std::stack<int> result;

	while (!stack1.empty() || !stack2.empty())  {
		if (stack1.empty()) {
			aux.push(stack2.top());
			stack2.pop();
		}
		else if (stack2.empty()) {
			aux.push(stack1.top());
			stack1.pop();
		}
		else if (stack1.top() >= stack2.top()) {
			aux.push(stack1.top());
			stack1.pop();
		}
		else {
			aux.push(stack2.top());
			stack2.pop();
		}
	}

	while (!aux.empty()) {
		result.push(aux.top());
		aux.pop();
	}
	return result;
}

std::stack<std::string> putHat(std::stack<std::string> stack1, std::stack<std::string> stack2) {
	std::stack<std::string> aux;
	std::stack<std::string> result;

	while (!stack1.empty()) {
		aux.push(stack1.top());
		stack1.pop();
	}
	while (!stack2.empty()) {
		aux.push(stack2.top());
		stack2.pop();
	}
	while (!aux.empty()) {
		result.push(aux.top());
		aux.pop();
	}
	return result;
}

std::queue<int> TransformToQ(std::stack<int> stack) {
	std::stack<int> aux;
	std::queue<int> result;

	while (!stack.empty()) {
		aux.push(stack.top());
		stack.pop();
	}

	while (!aux.empty()) {
		result.push(aux.top());
		aux.pop();
	}
	return result;
}

bool isHat(std::stack<int> stack1, std::stack<int> stack2) {
	if (stack1.size() > stack2.size()) {
		return false;
	}
	else {
		bool hatCheck = true;

		while (!stack1.empty()) {
			if (stack1.top() != stack2.top() && hatCheck) {
				hatCheck = false;
			}
			stack1.pop();
			stack2.pop();
		}
		return hatCheck;
	}
}

bool balancedP(std::queue<char> queue) {
	int opened = 0;
	while (!queue.empty()) {
		if (queue.front() == '(') {
			opened++;
		}
		else if (queue.front() == ')') {
			if (opened == 0) {
				return false;
			}
			opened--;
		}
		queue.pop();
	}
	return (opened == 0);
}

void change(std::stack<int>& stack) {
	int aux = stack.top();
	stack.pop();
	std::stack<int> auxStack;

	while (!stack.empty()) {
		auxStack.push(stack.top());
		stack.pop();
	}

	stack.push(aux);
	aux = auxStack.top();
	auxStack.pop();

	while (!auxStack.empty()) {
		stack.push(auxStack.top());
		auxStack.pop();
	}
	stack.push(aux);
}

void main() {
	/*std::stack<int> stack1, stack2;
	stack1.push(2);
	stack1.push(4);
	stack1.push(5);
	stack1.push(7);
	stack1.push(9);
	stack2.push(1);
	stack2.push(3);
	stack2.push(6);
	stack2.push(8);

	std::stack<int> merged = superMerge(stack1, stack2);

	while (!merged.empty()) {
		std::cout << merged.top() << std::endl;
		merged.pop();
	}*/

	/*std::stack<std::string> stack1, stack2;
	stack1.push("2");
	stack1.push("9");
	stack1.push("4");
	stack1.push("7");
	stack2.push("6");
	stack2.push("3");
	stack2.push("5");

	std::stack<std::string> hated = putHat(stack1, stack2);

	while (!hated.empty()) {
		std::cout << hated.top() << std::endl;
		hated.pop();
	}*/

	/*std::stack<int> stack;
	stack.push(5);
	stack.push(3);
	stack.push(1);
	std::queue<int> queue = TransformToQ(stack);

	while (!queue.empty()) {
		std::cout << queue.front() << std::endl;
		queue.pop();
	}*/

	/*std::stack<int> p1, p2;
	p1.push(2);
	p1.push(4);
	p1.push(9);
	p1.push(7);
	p2.push(6);
	p2.push(3);
	p2.push(5);
	p2.push(2);
	p2.push(4);
	p2.push(9);
	p2.push(7);
	std::cout << isHat(p1, p2);*/

	/*std::queue<char> queue;
	queue.push('(');
	queue.push('(');
	queue.push(')');
	queue.push(')');
	queue.push(')');

	std::cout << balancedP(queue);*/

	/*std::stack<int> stack;
	stack.push(5);
	stack.push(3);
	stack.push(2);
	stack.push(1);

	change(stack);

	while (!stack.empty()) {
		std::cout << stack.top() << std::endl;
		stack.pop();
	}*/
}