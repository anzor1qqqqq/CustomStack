#include <iostream>

using namespace std;

class CustomStack {

private:

	int* stack;
	int sizeStack;
	int top = 0;

public:

	CustomStack() {
		sizeStack = 100;
		top = 0;
		stack = new int[sizeStack];
	};

	void addItemStack(int item) {
		if (sizeStack != top) {

			stack[top] = item;
			top++;
		}
		else {
			sizeStack *= 2;

			int* resizeStack = new int[sizeStack];

			for (int i = 0; i < top; i++) {
				resizeStack[i] = stack[i];
			};

			resizeStack[top] = item;
			top++;
			delete[] stack;

			stack = resizeStack;
		};
	};

	int getItemStack() {
		if (sizeStack != 0) {
			top--;

			return stack[top];
		};

		abort();
	};

	bool checkEmptyStack() {
		return top == 0;
	};

	void showStack() {
		for (int i = top; i > 0; i--) {
			cout << stack[i - 1] << ' ';
		};
	};

	~CustomStack() {
		delete[] stack;
	};
};

int main() {
	setlocale(LC_ALL, "RUS");

	CustomStack firstStack;

	firstStack.addItemStack(99);
	firstStack.addItemStack(5);
	firstStack.addItemStack(4);
	firstStack.addItemStack(3);
	firstStack.addItemStack(8);

	firstStack.showStack();

	cout << endl;

	int a = firstStack.getItemStack();

	cout << a << endl;

	firstStack.showStack();
};