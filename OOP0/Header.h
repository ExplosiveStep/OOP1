#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// ���������
class transport {
	enum key { TRUCK, BUS , PASSENGER_CAR};
	int k;
public:
	static transport* In(ifstream& ifst);
	virtual void InData(ifstream& ifst) = 0;
	virtual void Out(ofstream& ofst) = 0;
	virtual double Gas_mil() = 0;
	virtual void MultiMethod(transport* other, ofstream& ofst) = 0;
	virtual void MMBus(ofstream& ofst) = 0;
	virtual void MMTruck(ofstream& ofst) = 0;
	virtual void MMPassenger_car(ofstream& ofst) = 0;
	int getk();
	transport()// �����������
	{
		k = -1;
	}
};

// ��������
class truck : public transport {
	int cargo;// ����������������
	int engine;// �������� ���������
	int fuel_tank;// ����� ���������� ����
public:
	void InData(ifstream& ifst);
	void Out(ofstream& ofst);
	double Gas_mil();
	int Getcargo();
	void Setcargo(int);
	int Getengine();
	void Setengine(int);
	int Getfuel_tank();
	void Setfuel_tank(int);
	void MultiMethod(transport* other, ofstream& ofst);
	void MMBus(ofstream& ofst);
	void MMTruck(ofstream& ofst);
	void MMPassenger_car(ofstream& ofst);
	truck()// �����������
	{
		cargo = 0;
		engine = 0;
		fuel_tank = 0;
	}
};

// �������
class bus : public transport {
	short int capacity;// ��������������������
	int engine;// �������� ���������
	int fuel_tank;// ����� ���������� ����
public:
	void InData(ifstream& ifst);
	void Out(ofstream& ofst);
	double Gas_mil();
	short int Getcapacity();
	void Setcapacity(short int);
	int Getengine();
	void Setengine(int);
	int Getfuel_tank();
	void Setfuel_tank(int);
	void MultiMethod(transport* other, ofstream& ofst);
	void MMBus(ofstream& ofst);
	void MMTruck(ofstream& ofst);
	void MMPassenger_car(ofstream& ofst);
	bus()// �����������
	{
		capacity = 0;
		engine = 0;
		fuel_tank = 0;
	}
};

// �������� ����������
class passenger_car : public transport {
	int max_speed;// ������������ ��������
	int engine;// �������� ���������
	int fuel_tank;// ����� ���������� ����
public:
	void InData(ifstream& ifst);
	void Out(ofstream& ofst);
	double Gas_mil();
	int Getmax_speed();
	void Setmax_speed(int);
	int Getengine();
	void Setengine(int);
	int Getfuel_tank();
	void Setfuel_tank(int);
	void MultiMethod(transport* other, ofstream& ofst);
	void MMBus(ofstream& ofst);
	void MMTruck(ofstream& ofst);
	void MMPassenger_car(ofstream& ofst);
	passenger_car()// �����������
	{
		max_speed = 0;
		engine = 0;
		fuel_tank = 0;
	}
};

// ���������
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
	void Sort(container*);
	void Limited_out(container* head, ofstream& ofst);
	void MultiMethod(container* head, ofstream& ofst);
	transport* Getcont();
	container* Getnext();
	container()// �����������
	{
		next = NULL;
		prev = NULL;
		cont = NULL;
		len = 0;
	}
	~container()// ����������
	{
	}
};
#endif