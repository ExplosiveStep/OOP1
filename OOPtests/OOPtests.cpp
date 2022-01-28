#include "pch.h"
#include "CppUnitTest.h"
#include "..\OOP0\Header.h"
#include <fstream>
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace OOPtests
{
	TEST_CLASS(OOPtests)
	{
	public:
		
		TEST_METHOD(In_Truck_Test) //Тест проверки ввода информации о грузовике
		{
			ifstream ifst("../OOP0/InTruck.txt");

			truck t;

			t.InData(ifst);

			Assert::AreEqual(t.Getcargo(), 3000);
		}
		TEST_METHOD(In_Bus_Test) //Тест проверки ввода информации об автобусе
		{
			ifstream ifst("../OOP0/InBus.txt");

			bus b;

			b.InData(ifst);

			Assert::AreEqual(b.Getcapacity(), (short int )30);
		}
		TEST_METHOD(In_Passenger_Test) //Тест проверки ввода информации о легковом автомобиле
		{
			ifstream ifst("../OOP0/InPassenger_car.txt");

			passenger_car p;

			p.InData(ifst);

			Assert::AreEqual(p.Getmax_speed(), 300);
		}
		TEST_METHOD(In_Transport) //Тест проверки ввода информации о машине
		{
			ifstream ifst("../OOP0/InTransport.txt");
			transport* ptr;
			ptr = ptr->In(ifst);
			Assert::AreEqual((int)ptr->getk(), (int)0);
		}
		TEST_METHOD(Out_truck_test)// Тест проверки вывода информации о грузовике
		{
			truck t;
			t.Setcargo(3000);
			t.Setengine(140);
			t.Setfuel_tank(50);
			ofstream ofst("../OOP0/OutTruck.txt");
			t.Out(ofst);
			ifstream ifst1("../OOP0/OutTruck.txt");
			ifstream ifst2("../OOP0/OutTruck2.txt");
			string test1;
			string test2;
			getline(ifst1, test1, '\0');
			getline(ifst2, test2, '\0');
			Assert::AreEqual(test1, test2);
		}
		TEST_METHOD(Out_bus_test)// Тест проверки вывода информации об автобусе
		{
			bus b;
			b.Setcapacity((short int)30);
			b.Setengine(140);
			b.Setfuel_tank(50);
			ofstream ofst("../OOP0/Outbus.txt");
			b.Out(ofst);
			ifstream ifst1("../OOP0/Outbus.txt");
			ifstream ifst2("../OOP0/Outbus2.txt");
			string test1;
			string test2;
			getline(ifst1, test1, '\0');
			getline(ifst2, test2, '\0');
			Assert::AreEqual(test1, test2);
		}
		TEST_METHOD(Out_passenger_car_test)// Тест проверки вывода информации о грузовике
		{
			passenger_car p;
			p.Setmax_speed(3000);
			p.Setengine(140);
			p.Setfuel_tank(50);
			ofstream ofst("../OOP0/OutPassenger_car.txt");
			p.Out(ofst);
			ifstream ifst1("../OOP0/OutPassenger_car.txt");
			ifstream ifst2("../OOP0/OutPassenger_car2.txt");
			string test1;
			string test2;
			getline(ifst1, test1, '\0');
			getline(ifst2, test2, '\0');
			Assert::AreEqual(test1, test2);
		}
		TEST_METHOD(Out_transport_test)// Тест проверки вывода информации о машине
		{
			ifstream ifst("../OOP0/OutTransport3.txt");
			transport* ptr;
			ptr = ptr->In(ifst);
			ofstream ofst("../OOP0/OutTransport.txt");
			ptr->Out(ofst);
			ifstream ifst1("../OOP0/OutTransport.txt");
			ifstream ifst2("../OOP0/OutTransport2.txt");
			string test1;
			string test2;
			getline(ifst1, test1, '\0');
			getline(ifst2, test2, '\0');
			Assert::AreEqual(test1, test2);
		}
		TEST_METHOD(Incontainer_test)// Тест проверки ввода содержимого контейнера
		{
			ifstream ifst("../OOP0/Incontainer.txt");
			container* head = new container;
			container* tail = new container;
			head->In(ifst, head, tail);
			Assert::AreEqual(head->Getlen(), 3);
			Assert::AreEqual(tail->Getlen(), 3);
			truck* test1 = (truck*)head->Getcont();
			Assert::AreEqual(test1->Getcargo(), 1400);
			Assert::AreEqual(test1->Getengine(), 120);
			Assert::AreEqual(test1->Getfuel_tank(), 50);
			head = head->Getnext();
			bus* test2 = (bus*)head->Getcont();
			Assert::AreEqual(test2->Getcapacity(), (short int)30);
			Assert::AreEqual(test2->Getengine(), 130);
			Assert::AreEqual(test2->Getfuel_tank(), 60);
			head = head->Getnext();
			passenger_car* test3 = (passenger_car*)head->Getcont();
			Assert::AreEqual(test3->Getmax_speed(), 200);
			Assert::AreEqual(test3->Getengine(), 150);
			Assert::AreEqual(test3->Getfuel_tank(), 45);
		}
		TEST_METHOD(Outcontainer_test)// Тест проверки вывода содержимого контейнера
		{
			ifstream ifst("../OOP0/Outcontainer3.txt");
			container* head = new container;
			container* tail = new container;
			head->In(ifst, head, tail);
			ofstream ofst("../OOP0/Outcontainer.txt");
			head->Out(ofst, head);
			ifstream ofst1("../OOP0/Outcontainer.txt");
			ifstream ofst2("../OOP0/Outcontainer2.txt");
			string test1;
			string test2;
			getline(ofst1, test1, '\0');
			getline(ofst2, test2, '\0');
			Assert::AreEqual(test1, test2);

		}
		TEST_METHOD(Sort_test)// Тест проверки сортировки
		{
			ifstream ifst("../OOP0/Sort.txt");
			container* head = new container;
			container* tail = new container;
			head->In(ifst, head, tail);
			head->Sort(head);
			truck* test1 = (truck*)head->Getcont();
			Assert::AreEqual(test1->Getengine(), 150);
			head = head->Getnext();
			bus* test2 = (bus*)head->Getcont();
			Assert::AreEqual(test2->Getengine(), 130);
			head = head->Getnext();
			passenger_car* test3 = (passenger_car*)head->Getcont();
			Assert::AreEqual(test3->Getengine(), 120);
		}
		TEST_METHOD(Limitedout_test)// Тест проверки ограниченного вывода
		{
			ifstream ifst("../OOP0/Limitedout3.txt");
			container* head = new container;
			container* tail = new container;
			head->In(ifst, head, tail);
			ofstream ofst("../OOP0/Limitedout.txt");
			head->Limited_out(head, ofst);
			ifstream ofst1("../OOP0/Limitedout.txt");
			ifstream ofst2("../OOP0/Limitedout2.txt");
			string test1;
			string test2;
			getline(ofst1, test1, '\0');
			getline(ofst2, test2, '\0');
			Assert::AreEqual(test1, test2);

		}
	};
}