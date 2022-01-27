#include "Header.h"
#include <iostream>
#include <fstream>

#define KEY 0

using namespace std;

//������� ���������� �� ���������
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

// ���� ����������� ���������� �� ���������� ������
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
// ���� ���������� �� �����
transport* transport::In(ifstream& ifst) {
	transport* sp;
	int k;
	ifst >> k;
	switch (k) {
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

// ���� ���������� ��������� �� �����
void truck::InData(ifstream& ifst) {
	ifst >> cargo >> engine >> fuel_tank;
}

// ���� ���������� �������� �� �����
void bus::InData(ifstream& ifst) {
	ifst >> capacity >> engine >> fuel_tank;
}

void passenger_car::InData(ifstream& ifst) {

    ifst >> max_speed >> engine >> fuel_tank;
}

// ����� ���������� � ����
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

// ����� ���������� ���������� ����
void truck::Out(ofstream& ofst) {
    ofst << "It is truck: cargo = " << cargo << ", engine = " << engine << ",fuel_tank = " << fuel_tank << endl;
}

// ����� ���������� �������� ����
void bus::Out(ofstream& ofst) {
    ofst << "It is bus: capacity = " << capacity << ", engine = " << engine << ", fuel_tank = " << fuel_tank << endl;
}

void passenger_car::Out(ofstream& ofst) {
    ofst << "It is passenger_car: max speed = " << max_speed << ", engine = " << engine << ", fuel_tank = " << fuel_tank << endl;
}

int container::Getlen()
{
    return len;
}

double truck::gas_mil()
{
    return engine / 25;
}

double bus::gas_mil()
{
    return engine / 25;
}


double passenger_car::gas_mil()
{
    return engine / 25;
}

void container::Sort(container* head)
{
    if (head->Getlen() > 1)
    {
        container* First = head;
        container* Second = head->next;
        container* Temp = new container;
        int len = head->len;

        for (int i = 0; i < len - 1; i++) {
            for (int j = 0; j < len - i - 1; j++) {
                if (First->cont->gas_mil() < Second->cont->gas_mil()) {
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

void container::Limited_out(container* head, ofstream& ofst)
{
    int len = head->len;
    container* temp = head;

    for (int i = 0; i < len; i++)
    {
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

int transport::getk()
{
    return k;
}