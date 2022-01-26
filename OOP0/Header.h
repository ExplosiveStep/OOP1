#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>

using namespace std;

//Обобщение
class transport {
public:
	static transport* In(ifstream& ifst);
	virtual void InData(ifstream& ifst) = 0;
	virtual void Out(ofstream& ofst) = 0;
	virtual double gas_mil() = 0;
};

//Грузовик
class truck : public transport {
	int cargo;//Грузоподъемность
	int engine;//Мощность двигателя
public:
	void InData(ifstream& ifst);
	void Out(ofstream& ofst);
	double gas_mil();
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
	double gas_mil();
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