#include "Header.h"
#include <iostream>
#include <fstream>

using namespace std;

//Очистка контейнера от элементов
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
	int k;
	ifst >> k;
	switch (k) {
	case 1:
		sp = new truck;
		break;
	case 2:
		sp = new bus;
		break;
    case 3:
        sp = new passenger_car;
        break;
	default:
		return 0;
	}
	sp->InData(ifst);
	return sp;
}

// Ввод параметров грузовика из файла
void truck::InData(ifstream& ifst) {
	ifst >> cargo >> engine;
}

// Ввод параметров автобуса из файла
void bus::InData(ifstream& ifst) {
	ifst >> capacity >> engine;
}

void passenger_car::InData(ifstream& ifst) {

    ifst >> max_speed >> engine;
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

// Вывод параметров грузовикав файл
void truck::Out(ofstream& ofst) {
    ofst << "It is truck: cargo = " << cargo << ", engine = " << engine << endl;
}

// Вывод параметров автобуса файл
void bus::Out(ofstream& ofst) {
    ofst << "It is bus: capacity = " << capacity << ", engine = " << engine << endl;
}

void passenger_car::Out(ofstream& ofst) {
    ofst << "It is passenger_car: max speed = " << max_speed << ", engine = " << engine << endl;
}

int container::Getlen()
{
    return len;
}