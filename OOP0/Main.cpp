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

	if (!ifst.is_open()) {
		cout << "No input file found or could not open!" << endl;
		system("pause");
		exit(1);
	}
	ofstream ofst(argv[2]);
	if (!ofst.is_open()) {
		cout << "No output file found or could not open!" << endl;
		system("pause");
		exit(1);
	}
	cout << "Start" << endl;
	container* head = new container;// "������"
	container* tail = new container;// "�����"
	head->In(ifst, head, tail);// ���� ����������� ���������� �� ���������� ������
	int len = head->Getlen();// ���������� ��������� � ����������
	ofst << "Filled container. " << endl;
	head->Sort(head);// ����������
	head->Out(ofst, head);// ����� ���������� ���������� � ����
	//head->Limited_out(head, ofst);// ������������ �����
	ofst << "\n\nMULTIMETHOD. " << endl;
	head->MultiMethod(head, ofst);
	head->Clear(head);// ������� ����������
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