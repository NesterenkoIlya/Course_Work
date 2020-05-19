//#include "DigitalCounter.h"
#include "ElectricityCounter.h"
#include "AccountBook.h"
#include <Windows.h>
string delimiter = "---------------------------------------------------------------\n";

using namespace std;

int main() {
	system("chcp 1251");
	int c;
	while (true) {
		cout << delimiter
			<< "1, создание цифрового счетчика\n"
			<< "2, создание счетчика электричества\n"
			<< "3, создание расчетной книжки\n"
			<< "4, демонстрация механизма позднего связывания\n"
			<< "5, очистка консоли\n"
			<< "0, завершить работу\n"
			<< delimiter;
		cout << "Введите число: "; Counter::input_check(c);
		while (c < 0 || c > 4) {
			cout << "Вы ввели неправильное число\n"
				 << "Оно должно быть в диапазаное от 0 до 4\n"
				 << "Повторите ввод: "; Counter::input_check(c);
		}
		switch (c) {    //Главное меню
			case 1: { //Интерфейс для работы с классом DigitalCounter
				int c1;
				ifstream fin("DigitalCounter_input.txt");
				ofstream fout("DigitalCounter_output.txt");
				DigitalCounter digital_counter, dc;
				while (true) {
					cout << delimiter
						<< "Class DigitalCounter\n"
						<< "1, ввод объекта DigitalCounter\n"
						<< "2, вывод объекта\n"
						<< "3, вывод счетчика\n"
						<< "4, увеличить счетчик на 1\n"             
						<< "5, проверка методов\n"
						<< "6, проверка перегрузок операторов\n"
						<< "7, ввод из файла\n"
						<< "8, вывод в файл\n"
						<< "0, главное меню\n"
						<< delimiter;
					cout << "Введите число: "; Counter::input_check(c1);
					while (c1 < 0 || c1 > 8) {
						cout << "Вы ввели неправильное число\n"
							 << "Оно должно быть в диапазаное от 0 до 8\n"
							 << "Повторите ввод: "; Counter::input_check(c1);
					}
					//Меню DigitalCounter
					switch(c1) {
						case 1: {
							dc.input();
							cout << dc;
							break;
						}
						case 2: {
							dc.output();
							break;
						}
						case 3: {
							dc.print_counter();
							break;
						}
						case 4: {
							cout << dc;
							dc.counter_increment();
							cout << dc;
							break;
						}
						case 5: {
							DigitalCounter dc(0, 99, 18);
							cout << dc;
							cout << "Метод counter_increment()\n"
								<< "dc.counter_increment()\n";
							dc.counter_increment();
							cout << dc;
							cout << "Метод input()\n"
								<< "dc.input()\n";
							dc.input();
							cout << "Метод output()\n"
								<< "dc.output\n";
							dc.output();
							cout << "Переопределенный метод print_counter()\n"
								<< "dc.print_counter()\n";
							dc.print_counter();
							break;
						}
						case 6: {
							cout << "Перегрузка оператора ()\n" << digital_counter 
								 << "digital_counter(0, 256, 12)\n";
							digital_counter(0, 256, 122);
							cout << digital_counter;
							
							cout << "Перегрузка оператора ++\ndigital_counter++\n";
							digital_counter++;
							cout << digital_counter;
							
							cout << "Перегрузка оператора +=\ndigital_counter += 12\n";
							digital_counter += 12;
							cout << digital_counter;
							
							cout << "Перегрузка оператора --\ndigital_counter--\n";
							digital_counter--;
							cout << digital_counter;
							
							cout << "Перегрузка оператора -=\ndigital_counter -= 3\n";
							digital_counter -= 3;
							cout << digital_counter;
							
							cout << "Перегрузка оператора =\ndigital_counter2 = digital_counter\n";
							DigitalCounter digital_counter2 = digital_counter;
							cout << "Перегрузка оператора >>\ncin >> digital_counter\n";
							cin >> digital_counter;
							
							cout << "digital_counter\n" << digital_counter;
							
							cout << "digital_counter2\n" << digital_counter2;
							break;
						}
						case 7: {
							fin >> dc;
							break;
						}
						case 8: {
							fout << dc;
							break;
						}
						case 0: {
							break;
						}
						default:
							break;
					}
					if (c1 == 0) break;
				}
				break;
			}
			case 2: { //Интерфейс для работы с классом ElectricityCounter
				ElectricityCounter ec, electricity_counter, electricity_counter1(4, 25, 12.34235, 4, 2), f_ec;
				ofstream outf("ElectricityCounter_output.txt");
				ifstream inf("ElectricityCounter_input.txt");
				while (true) {
					int c2;
					double n;
					cout << delimiter
						<< "Class ElectricityCounter\n"
						<< "1, ввод объекта\n"
						<< "2, вывод объекта\n"
						<< "3, вывод счетчика\n"
						<< "4, установка счетчика\n"
						<< "5, получить значение счетчика\n"
						<< "6, проверка перегрузок операторов\n"
						<< "7, чтение объекта из файла\n"
						<< "8, запись объекта в файл\n"
						<< "0, главное меню\n"
						<< delimiter;
					cout << "Введите число: "; Counter::input_check(c2);
					while (c2 < 0 || c2 > 8) {
						cout << "Вы ввели неправильное число\n"
							<< "Оно должно быть в диапазаное от 0 до 8\n"
							<< "Повторите ввод: "; Counter::input_check(c2);
					}
					switch (c2) {
						case 1: {
							cin >> ec;
							cout << ec;
							break;
						}
						case 2: {
							cout << ec;
							break;
						}
						case 3: {
							ec.print_counter();
							break;
						}
						case 4: {
							if (ec.get_max_value() == 0 && ec.get_min_value() == 0) {
								cout << "Чтобы установить значение счетчика введите объект\n";
							}
							else {
								cout << "Введите значение счетчика: "; Counter::input_check(n);
								ec = n;
							}
							break;
						}
						case 5: {
							cout << "Текущее значение счетчика: "; 
							cout << *ec << endl;
							break;
						}
						case 6: {
							cout << "Перегрузка оператора ввода\n"
								<< "cin >> electricity_counter\n";
							cin >> electricity_counter;
							cout << "Перегрузка оператора вывода\n"
								<< "cout << electricity_counter\n"
								<< electricity_counter;
							cout << "Перегрузка оператора присваивания для числа\n"
								<< "electricity_counter = 10\n"
								<< electricity_counter;
							electricity_counter = 10;
							cout << electricity_counter;
							cout << "Перегрузка оператора разименования\n"
								<< "cout << *electricity_counter\n"
								<< *electricity_counter;
							cout << "Перегрузка оператора присваивания для объектов\n"
								<< "electricity_counter_1:\n" << electricity_counter1
								<< "electricity_counter1 = electricity_counter\n";
							electricity_counter1 = electricity_counter;
							cout << "electricity_counter1:\n"
								<< electricity_counter1;
							break;
						}
						case 7: {
							inf >> ec;
							break;
						}
						case 8: {
							outf << ec;
							break;
						}
						case 0: {
							break;
						}
						default: {
							break;
						}
					}
					if (c2 == 0) break;
				}
				break;
			} 
			case 3: { //Интерфейс для работы с классом AccountBook
				int c3, n;
				cout << "Введите количество показаний счетчика: "; Counter::input_check(n);
				AccountBook accounts(n), acc_check(4, 8.75, 22, 5, 2020);
				ofstream fout("AccountBook_output.txt");
				ifstream fin("AccountBook_input.txt");
				cin >> accounts;
				while (true) {
					cout << delimiter
						<< "Class AccountBook\n"
						<< "1, добавить элемент по индексу\n"
						<< "2, добавить элемент в начало\n"
						<< "3, добавить элемент в конец\n"
						<< "4, удалить элемент по индексу\n"
						<< "5, изменить размер массива\n"
						<< "6, очистить массив\n"
						<< "7, общее количество потребленной электроэнергии\n"
						<< "8, общая стоимость\n"
						<< "9, ввод из файла\n"
						<< "10, вывод в файл\n"
						<< "0, главное меню\n"
						<< delimiter;
					cout << "Введите число: "; Counter::input_check(c3);
					while (c3 < 0 || c3 > 10) {
						cout << "Вы ввели неправильное число\n"
							<< "Оно должно быть в диапазаное от 0 до 10\n"
							<< "Повторите ввод: "; Counter::input_check(c3);
					}
					switch (c3) {    //Меню класса AccountBook
						case 1: {
							int index;
							ElectricityCounter element;
							cin >> element;
							cout << "Введите индекс: "; 
							Counter::input_check(index);
							accounts.add_element(element, accounts.begin() + index);
							cout << accounts;
							break;
						}
						case 2: {
							ElectricityCounter element;
							cin >> element;
							accounts.add_elem_begin(element);
							cout << accounts;
							break;
						}
						case 3: {
							ElectricityCounter element;
							cin >> element;
							accounts.add_elem_end(element);
							cout << accounts;
							break;
						}
						case 4: {
							int index;
							cout << "Введите индекс: "; 
							Counter::input_check(index);
							accounts.remove_element(accounts.begin() + index);
							cout << accounts;
							break;
						}
						case 5: {
							int new_length;
							cout << "Введите новый размер: ";
							Counter::input_check(new_length);
							accounts.resize(new_length);
							cout << accounts;
							break;
						}
						case 6: {
							bool check;
							cout << "Вы уверенны(1/0): ";
							Counter::input_check(check);
							if (check == 1) {
								accounts.erase();
								cout << accounts;
							}
							break;
						}
						case 7: {
							if (accounts.get_lenght() == 0) {
								cout << "Для начала введите объект\n";
								break;
							}
							cout << "Oбщее количество потребленной электроэнергии: "
								<< accounts.sum_accounts();
							break;
						}
						case 8: {
							if (accounts.get_lenght() == 0) {
								cout << "Для начала введите объект\n";
								break;
							}
							cout << "Oбщая стоимость потребленной электроенергии: "
								<< accounts.price_accounts();
							break;
						}
						case 9: {
							fin >> accounts;
							break;
						}
						case 10: {
							fout << accounts;
							break;
						}
						case 0: {
							break;
						}
						default:
							break;
					}
					if (c3 == 0)
						break;
				}
				break;
			} 
			case 4: {
				DigitalCounter b(15, 29, 28);
				Counter* counter1(&b);
				counter1->print_counter();
				ElectricityCounter a(0, 256, 234.124523, 4, 2);
				Counter* counter(&a);
				counter->print_counter();
				break;
			}
			case 5: { //Очистка консоли
				system("cls");
				break;
			} 
			case 0: { //Завершение работы программы
				return 0;
			} default:
				break;
		}
	}
}
