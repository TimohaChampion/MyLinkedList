#pragma once
#include <iostream>

using namespace std;

template <typename T1>
struct Node {
	T1 value;
	Node<T1>* next = nullptr;
};

template <typename T>
class LinkedList {
	Node<T>* head = nullptr;
	//int counter = 0;

public:
	LinkedList() {};
	~LinkedList() {
		clear();
	}

	void pushToHead(T& value) {
		Node<T>* buff = new Node<T>[] { value, head };
		head = buff;
		//counter++;
	}

	void pushToHead(T&& value) {
		Node<T>* buff = new Node<T>[] { value, head };
		head = buff;
		//counter++;
	}

	void pushToTail(T& value) {
		Node<T>* buff = head;
		while (buff->next != nullptr)
			buff = buff->next;
		buff->next = new Node<T>{ value, nullptr };
	}

	void pushToTail(T&& value) {
		Node<T>* buff = head;
		while (buff->next != nullptr)
			buff = buff->next;
		buff->next = new Node<T>{ value, nullptr };
	}

	void pushToPos(T&& value, int pos) {
		if (pos == 0) {
			pushToHead(value);
			return;
		}
		Node<T>* buff = head;
		int counter = 0;
		while (buff->next != nullptr && pos != counter + 1) {
			buff = buff->next;
			counter++;
		}
		buff->next = new Node<T>{ value, buff->next };
	}

	void pushToPos(T& value, int pos) {
		if (pos == 0) {
			pushToHead(value);
			return;
		}
		Node<T>* buff = head;
		int counter = 0;
		while (buff->next != nullptr && pos != counter + 1) {
			buff = buff->next;
			counter++;
		}
		buff->next = new Node<T>{ value, buff->next };
	}

	void replaceToPos(T&& value, int pos) {
		if (pos == 0) {
			head->value = value;
			return;
		}
		Node<T>* buff = head;
		int counter = 0;
		while (buff->next != nullptr && pos != counter + 1) {
			buff = buff->next;
			counter++;
		}
		buff->next->value = value;
	}

	void replaceToPos(T& value, int pos) {
		if (pos == 0) {
			head->value = value;
			return;
		}
		Node<T>* buff = head;
		int counter = 0;
		while (buff->next != nullptr && pos != counter + 1) {
			buff = buff->next;
			counter++;
		}
		buff->next->value = value;
	}


	void removeFromHead() {
		if (head != nullptr) {
			Node<T>* buff = head;
			head = head->next;
			delete buff;
		}
	}

	void removeFromTail() {
		Node<T>* buff = head;
		while (buff->next->next != nullptr) {
			buff = buff->next;
		}
		delete buff->next;
		buff->next = nullptr;
	}

	void removeFromPos(int pos) {
		if (pos == 0) {
			removeFromHead();
			return;
		}
		Node<T>* buff = head;
		int counter = 0;
		while (buff->next != nullptr && pos != counter + 1) {
			buff = buff->next;
			counter++;
		}
		Node<T>* buff2 = buff->next->next;
		delete buff->next;
		buff->next = buff2;
	}

	void clear() {
		while (head != nullptr) {
			removeFromHead();
		}
	}

	void show() const {
		if (head != nullptr) {
			Node<T>* buff = head;
			while (buff != nullptr) {
				cout << buff->value << " ";
				buff = buff->next;
			}
			cout << endl;
		}
	}

	int size() const {
		if (head != nullptr) {
			int res = 0;
			Node<T>* buff = head;
			while (buff != nullptr) {
				buff = buff->next;
				res++;
			}
			return res;
		}
		return 0;
	}

};
