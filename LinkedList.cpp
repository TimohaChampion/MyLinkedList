#include "MyLinkedList.h"
#include<string>
#include<iostream>
using namespace std;



int main() {
	setlocale(0, "ru");
	LinkedList<string> list;
	string str[6] { "Moscow -13 C","Rostov +1 C","Omsk -23 C","Saratov -7 C","Krasnodar +2 C","Taganrog 0 C" };
	list.pushToHead(str[0]);
	list.pushToHead(str[1]);
	list.pushToHead(str[2]);
	list.pushToPos(str[3], 2);
	list.pushToTail(str[4]);
	list.pushToTail(str[5]);
	list.show();
	list.replaceToPos(str[5], 2);
	list.show();
	list.removeFromPos(3);
	list.removeFromHead();
	list.removeFromTail();
	list.show();
	list.size();
	list.show();
	list.clear();
	system("pause");
}

/*
Написать код который использует односвязанный список для
работы со строками (воспользуйтесь готовым шаблоном из MyLinkedList).

- Добавить строки:
 "Moscow -13 C", "Rostov +1 C", "Omsk -23 C", "Saratov -7 C", "Krasnodar +2 C", "Taganrog 0 C"

- Вывести на экран
- Убрать из списка строку Omsk ...
- Вывести элементы на экран.
*/
