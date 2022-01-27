#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>

using namespace std;

//���������
class transport {
public:
	static transport* In(ifstream& ifst);
	virtual void InData(ifstream& ifst) = 0;
	virtual void Out(ofstream& ofst) = 0;
};

//��������
class truck : public transport {
	int cargo;//����������������
	int engine;//�������� ���������
	int fuel_tank;//����� ���������� ����
public:
	void InData(ifstream& ifst);
	void Out(ofstream& ofst);
	truck()//�����������
	{
		cargo = 0;
		engine = 0;
		fuel_tank = 0;
	}
};

class bus : public transport {
	short int capacity;//��������������������
	int engine;//�������� ���������
	int fuel_tank;//����� ���������� ����
public:
	void InData(ifstream& ifst);
	void Out(ofstream& ofst);
	bus()//�����������
	{
		capacity = 0;
		engine = 0;
		fuel_tank = 0;
	}
};

class passenger_car : public transport {
	int max_speed;//������������ ��������
	int engine;//�������� ���������
public:
	void InData(ifstream& ifst);
	void Out(ofstream& ofst);
	passenger_car()//�����������
	{
		max_speed = 0;
		engine = 0;
	}
};

//���������
class container {
	container* next;
	container* prev;
	transport* cont;
	int len = 0;
public:
	void In(ifstream& ifst, container*, container*);
	void Out(ofstream& ofst, container*);
	void Clear(container*);
	int Getlen();
	container()
	{
		next = NULL;
		prev = NULL;
		cont = NULL;
		len = 0;
	}
	~container()
	{
	}
};
#endif