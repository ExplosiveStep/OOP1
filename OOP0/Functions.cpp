#include "Header.h"
#include <iostream>
#include <fstream>

#define KEY 0

using namespace std;

// Очистка контейнера от элементов
void container::Clear(container* head) {
    int len = head->len;
    container* temp = head;
    for (int i = 0; i < len; i++) {
        delete temp->cont;
        temp->len = 0;
        temp = temp->next;
    }
    for (int i = 0; i < len; i++) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// Ввод содержимого контейнера из указанного потока
void container::In(ifstream& ifst, container* head, container* tail) {
    container* temp;
    int Len = 0;
    while (!ifst.eof()) {
        switch (Len)
        {
        case 0:
            if ((head->cont = transport::In(ifst))) {
                Len++;
            }
            break;
        case 1:
            if ((tail->cont = transport::In(ifst))) {
                head->next = tail;
                head->prev = tail;
                tail->next = head;
                tail->prev = head;
                Len++;
            }
            break;
        default:
            temp = new container;
            temp->next = NULL;
            temp->prev = NULL;
            if ((temp->cont = transport::In(ifst))) {
                tail->next = temp;
                head->prev = temp;
                temp->next = head;
                temp->prev = tail;
                tail = temp;
                Len++;
            }
            else { delete temp; }
            break;
        }
        temp = head;
        for (int i = 0; i < Len; i++) {
            temp->len = Len;
            temp = temp->next;
        }
    }
}
// Ввод параметров из файла
transport* transport::In(ifstream& ifst) {
	transport* sp;
    string str = "";
    getline(ifst, str);
    if ((str != "1") && (str != "2") && (str != "3")) {// Если символ не 1,2,3
       
        if (ifst.peek() == EOF) {// Если конец файла
            return 0;
        }
        else {
            cout << "Input data is incomplete or incorrect!";
            system("pause");
            exit(1);
        }
    }
    int k = atoi(str.c_str());
	switch (k)
    {
    case 1:
		sp = new truck;
        sp->k = TRUCK;
		break;
	case 2:
		sp = new bus;
        sp->k = BUS;
		break;
    case 3:
        sp = new passenger_car;
        sp->k = PASSENGER_CAR;
        break;
	default:
        cout << "Incorrect transport!" << endl;
        exit(1);
	}
	sp->InData(ifst);
	return sp;
}

// Ввод параметров грузовика из файла
void truck::InData(ifstream& ifst) {
    string str = "";
    string numbers = "0123456789";
    int flag = 0;// Вспомогательная переменная/количество циклов
    while (flag != 3) {
        getline(ifst, str);
        if (str == "") {// Если пустая строка
            cout << "Input data is incomplete!";
            system("pause");
            exit(1);
        }
        if (str[0] == '0') {// Если строка начинается с символа '0'
            cout << "Input data is incorrect!";
            system("pause");
            exit(1);
        }
        for (int i = 0; i < str.length(); i++) {// Если в строке есть символы помимо цифр
           
            if (numbers.find(str[i]) == -1) {
                cout << "Input data is incorrect!";
                system("pause");
                exit(1);
            }
        }
        switch (flag)
        {
        case 0:
            cargo = atoi(str.c_str());
            break;
        case 1:
            engine = atoi(str.c_str());
            break;
        case 2:
            fuel_tank = atoi(str.c_str());
            break;
        }
        flag++;
    }
}

// Ввод параметров автобуса из файла
void bus::InData(ifstream& ifst) {
    string str = "";
    string numbers = "0123456789";
    int flag = 0;// Вспомогательная переменная/количество циклов
    while (flag != 3) {
        getline(ifst, str);
        if (str == "") {// Если пустая строка
            cout << "Input data is incomplete!";
            system("pause");
            exit(1);
        }
        if (str[0] == '0') {// Если строка начинается с символа '0'
            cout << "Input data is incorrect!";
            system("pause");
            exit(1);
        }
        for (int i = 0; i < str.length(); i++) {// Если в строке есть символы помимо цифр
            
            if (numbers.find(str[i]) == -1) {
                cout << "Input data is incorrect!";
                system("pause");
                exit(1);
            }
        }
        switch (flag)
        {
        case 0:
            capacity = atoi(str.c_str());
            break;
        case 1:
            engine = atoi(str.c_str());
            break;
        case 2:
            fuel_tank = atoi(str.c_str());
            break;
        }
        flag++;
    }
}

// Ввод параметров легкового автомобиля из файла
void passenger_car::InData(ifstream& ifst) {

    string str = "";
    string numbers = "0123456789";
    int flag = 0;// Вспомогательная переменная/количество циклов
    while (flag != 3) {
        getline(ifst, str);
        if (str == "") {// Если пустая строка
            cout << "Input data is incomplete!";
            system("pause");
            exit(1);
        }
        if (str[0] == '0') {// Если строка начинается с символа '0'
            cout << "Input data is incorrect!";
            system("pause");
            exit(1);
        }
        for (int i = 0; i < str.length(); i++) {// Если в строке есть символы помимо цифр
            
            if (numbers.find(str[i]) == -1) {
                cout << "Input data is incorrect!";
                system("pause");
                exit(1);
            }
        }
        switch (flag)
        {
        case 0:
            max_speed = atoi(str.c_str());
            break;
        case 1:
            engine = atoi(str.c_str());
            break;
        case 2:
            fuel_tank = atoi(str.c_str());
            break;
        }
        flag++;
    }
}

// Вывод параметров в файл
void container::Out(ofstream& ofst, container* head) {

    int len = head->len;
    container* temp = head;
    ofst << "Container contains " << head->len
        << " elements." << endl;
    for (int i = 0; i < len; i++) {
        ofst << i << ": ";
        temp->cont->Out(ofst);
        temp = temp->next;
    }
}

// Вывод параметров грузовикав в файл
void truck::Out(ofstream& ofst) {
    ofst << "It is truck: cargo = " << cargo << ", engine = " << engine
        << ",fuel_tank = " << fuel_tank << endl;
}

// Вывод параметров автобуса в файл
void bus::Out(ofstream& ofst) {
    ofst << "It is bus: capacity = " << capacity << ", engine = " << engine
        << ", fuel_tank = " << fuel_tank << endl;
}

// Вывод параметров легкового автомобился в файл
void passenger_car::Out(ofstream& ofst) {
    ofst << "It is passenger_car: max speed = " << max_speed << ", engine = "
        << engine << ", fuel_tank = " << fuel_tank << endl;
}

int container::Getlen()
{
    return len;
}

// Метод, возвращающий параметр, который определяет сортировку
double truck::Gas_mil()
{
    return engine * 2;
}

double bus::Gas_mil()
{
    return engine * 2;
}

double passenger_car::Gas_mil()
{
    return engine * 2;
}

// Сортировка
void container::Sort(container* head)
{
    if (head->Getlen() > 1) {
        container* First = head;
        container* Second = head->next;
        container* Temp = new container;
        int len = head->len;
        for (int i = 0; i < len - 1; i++) {

            for (int j = 0; j < len - i - 1; j++) {

                if (First->cont->Gas_mil() < Second->cont->Gas_mil()) {
                    Temp->cont = First->cont;
                    First->cont = Second->cont;
                    Second->cont = Temp->cont;
                }

                Second = Second->next;
            }

            First = First->next;
            Second = First->next;
        }
        delete Temp;
    }
}

// Ограниченный вывод
void container::Limited_out(container* head, ofstream& ofst)
{
    int len = head->len;
    container* temp = head;
    for (int i = 0; i < len; i++) {

        if ((temp->cont->getk() == KEY) && (temp->cont->getk() == 0)) {
            temp->cont->Out(ofst);
        }

        if ((temp->cont->getk() == KEY) && (temp->cont->getk() == 1)) {
            temp->cont->Out(ofst);
        }

        if ((temp->cont->getk() == KEY) && (temp->cont->getk() == 2)) {
            temp->cont->Out(ofst);
        }
        temp = temp->next;
    }
}



transport* container::Getcont()
{
    return cont;
}
container* container::Getnext()
{
    return next;
}


int transport::getk()
{
    return k;
}



int truck::Getcargo()
{
    return cargo;
}
void truck::Setcargo(int a)
{
    cargo = a;
}
int truck::Getengine()
{
    return engine;
}
void truck::Setengine(int a)
{
    engine = a;
}
int truck::Getfuel_tank()
{
    return fuel_tank;
}
void truck::Setfuel_tank(int a)
{
    fuel_tank = a;
}



short int bus::Getcapacity()
{
    return capacity;
}
void bus::Setcapacity(short int a)
{
    capacity = a;
}
int bus::Getengine()
{
    return engine;
}
void bus::Setengine(int a)
{
    engine = a;
}
int bus::Getfuel_tank()
{
    return fuel_tank;
}
void bus::Setfuel_tank(int a)
{
    fuel_tank = a;
}



int passenger_car::Getmax_speed()
{
    return max_speed;
}
void passenger_car::Setmax_speed(int a)
{
    max_speed = a;
}
int passenger_car::Getengine()
{
    return engine;
}
void passenger_car::Setengine(int a)
{
    engine = a;
}
int passenger_car::Getfuel_tank()
{
    return fuel_tank;
}
void passenger_car::Setfuel_tank(int a)
{
    fuel_tank = a;
}