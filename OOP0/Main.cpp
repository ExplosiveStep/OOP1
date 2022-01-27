#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "incorrect command line! "
			"Waited: command in_file out_file"
			<< endl;
		exit(1);
	}
	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);
	cout << "Start" << endl;
	container* head = new container;// "Голова"
	container* tail = new container;// "Хвост"
	head->In(ifst, head, tail);// Ввод содержимого контейнера из указанного потока
	int len = head->Getlen();// Количество элементов в контейнере
	ofst << "Filled container. " << endl;
	head->Sort(head);// Сортировка
	head->Out(ofst, head);// Вывод параметров транспорта в файл
	//head->Limited_out(head, ofst);// Ограниченный вывод
	head->Clear(head);// Очистка контейнера
	ofst << "Empty container. " << endl;
	cout << "Stop" << endl;
	if (len == 1) delete tail;
	if (len == 0)
	{
		delete head;
		delete tail;
	}
	_CrtDumpMemoryLeaks();
	return 0;
}