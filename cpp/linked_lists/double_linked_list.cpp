#include <stdbool.h>
#include <iostream>

typedef struct Lista {
	int data;
	Lista* next;
	Lista* prev;
} Lista;
Lista* head = NULL;
Lista* tail = NULL;

void chooseOption(int* opt) {
	std::cout << "\n===MENU===\n";
        std::cout << "1 - Add on the start\n";
        std::cout << "2 - Add on the end\n";
	std::cout << "3 - Print list StE\n";
	std::cout << "4 - Print list EtS\n";
        std::cout << "5 - Delete an element\n";
        std::cout << "6 - Clear the list\n";
        std::cout << "7 - Exit\n" << std::endl;
        std::cout << "$> ";
	std::cin >> *opt;
}

void addToStart() {
	std::cout << "\nType the number: ";
	Lista* novo = new Lista();
	std::cin >> novo->data;

	if(head == NULL) {
		head = novo;
		tail = novo;
		novo->next = NULL;
		novo->prev = NULL;
	} else {
		novo->next = head;
		head->prev = novo;
		novo->prev = NULL;
		head = novo;
	}
	std::cout << "\nAdded";
}

void addToEnd() {
	std::cout << "\nType the number: ";
	Lista* novo = new Lista();
	std::cin >> novo->data;

	if(head == NULL) {
		head = novo;
		tail = novo;
		novo->next = NULL;
		novo->prev = NULL;
	} else {
		tail->next = novo;
		novo->prev = tail;
		tail = novo;
		tail->next = NULL;
	}
	std::cout << "\nAdded";
}

void printL() {
	if(head == NULL)
		std::cout << "\nEmpty List" << std::endl;
	else {
		Lista* aux = head;
		while(aux != NULL) {
			std::cout << aux->data << " ";
			aux = aux->next;
		}
	}
}

void printRL() {
	if(tail == NULL)
		std::cout << "Empty List" << std::endl;
	else {
		Lista* aux = tail;
		while(aux != NULL) {
			std::cout << aux->data << " ";
			aux = aux->prev;
		}
	}
}

void deleteE() {
	if(head == NULL)
		std::cout << "\nEmpty" << std::endl;
	else {
		int numero;
		std::cout << "\nType the number: ";
		std::cin >> numero;
		Lista* aux = head;
		bool achou = false;
		while(aux != NULL) {
			if(aux->data == numero) {
				achou = true;
				if(aux == head) {
					head = aux->next;
					if(head != NULL)
						head->prev = NULL;
					delete(aux);
					aux = head;
				}
				else if(aux == tail) {
					tail = aux->prev;
					tail->next = NULL;
					delete(aux);
					aux = NULL;
				}
				else {
					//aux = aux->next;
					//aux = aux->prev;
					Lista* aux2;
					aux2 = aux->next;
					delete(aux);
					aux = aux2;
				}
			} else {
				aux = aux->next;
			}
		}

		if(achou)
			std::cout << "\nDeleted" << std::endl;
		else
			std::cout << "\n404" << std::endl;
	}
}

void clearL() {
	return;
}

int main() {
	int opt;
	do {
		chooseOption(&opt);
		if(opt < 1 || opt > 7)
			std::cout << "\nInvalid";
		if(opt == 1) addToStart();
		if(opt == 2) addToEnd();
		if(opt == 3) printL();
		if(opt == 4) printRL();
		if(opt == 5) deleteE();
		if(opt == 6) clearL();
	} while(opt != 7);
	return 0;
}
