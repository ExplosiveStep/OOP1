#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>

using namespace std;

//Обобщение
class transport {
	enum key { TRUCK, BUS };
	int k;
public:
	static transport* In(ifstream& ifst);
	virtual void InData(ifstream& ifst) = 0;
	virtual void Out(ofstream& ofst) = 0;
	int getk();
	transport()
	{
		k = -1;
	}
};

//Грузовик
class truck : public transport {
	int cargo;//Грузоподъемность
	int engine;//Мощность двигателя
public:
	void InData(ifstream& ifst);
	void Out(ofstream& ofst);
	truck()//Конструктор
	{
		cargo = 0;
		engine = 0;
	}
};

class bus : public transport {
	short int capacity;//Пассажировместимость
	int engine;//Мощность двигателя
public:
	void InData(ifstream& ifst);
	void Out(ofstream& ofst);
	bus()//Конструктор
	{
		capacity = 0;
		engine = 0;
	}
};

//Контейнер
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
	void Limited_out(container* head, ofstream& ofst);
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