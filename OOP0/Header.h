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
};

//Грузовик
class truck : public transport {
	int cargo;//Грузоподъемность
	int engine;//Мощность двигателя
	int fuel_tank;//Объем топливного бака
public:
	void InData(ifstream& ifst);
	void Out(ofstream& ofst);
	truck()//Конструктор
	{
		cargo = 0;
		engine = 0;
		fuel_tank = 0;
	}
};

class bus : public transport {
	short int capacity;//Пассажировместимость
	int engine;//Мощность двигателя
	int fuel_tank;//Объем топливного бака
public:
	void InData(ifstream& ifst);
	void Out(ofstream& ofst);
	bus()//Конструктор
	{
		capacity = 0;
		engine = 0;
		fuel_tank = 0;
	}
};

class passenger_car : public transport {
	int max_speed;//Максимальная скорость
	int engine;//Мощность двигателя
public:
	void InData(ifstream& ifst);
	void Out(ofstream& ofst);
	passenger_car()//Конструктор
	{
		max_speed = 0;
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