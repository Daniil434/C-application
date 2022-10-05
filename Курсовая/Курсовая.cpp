#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <time.h>
#include "игра.h"
using namespace std;

ifstream fin;
ofstream fout;
struct Medb0x {
	int id;
	char name[20];
	char value[32];
	double price;
	int number;
	int SIZE = 0;
	char last_date[32];
	char kabinet[20];
	char naznach[100];
	char about_user[100];
	void setparol_admin(int a) {
		this->parol_admin = a;
	}
	int getparol_admin() {
		return this->parol_admin;
	}
private:
	int parol_admin;
};
struct  Medb0xs {
	Medb0x P;
	Medb0xs* next;
};
//прототипы всех используемых функций
void lang() {
	char lang;
	setlocale(LC_ALL, "ru");
	bool vibor = true;
	do {
		cout << "<+********************************************************************************************************************+>" << endl;
		cout << "||\t\t\t\t\t Выберите язык консоли                                                        ||\n";
		cout << "||\t\t\t\t\t                                                                              ||" << endl;
		cout << "||\t\t\t\t\t 1.Русский-Rushen                                                             ||\n";
		cout << "||\t\t\t\t\t                                                                              ||" << endl;
		cout << "||\t\t\t\t\t 2.Англисский-Englesh                                                         ||\n";
		cout << "<+********************************************************************************************************************+>" << endl;
		lang = _getch();
		switch (lang)
		{
		case '1':
			setlocale(LC_ALL, "ru");
			vibor = false;
			break;
		case '2':
			setlocale(LC_ALL, "eng");
			vibor = false;
			break;
		default:
			system("cls");
			cout << "Выбран несуществующий пункт меню" << endl;
		}
	} while (vibor);
	system("cls");
}
void input_Medb0x(Medb0x&);
void print_Medb0xs(Medb0xs*);
void print_Medb0x(Medb0x);
void add_element_struct(Medb0xs**, Medb0x&);
void insert_element_struct(Medb0xs**, Medb0x&);
void save_struct(Medb0xs*, int);
void clear_struct(Medb0xs**);
void read_database(Medb0xs**);
void search_Medb0x(Medb0xs*);
void delete_Medb0x(Medb0xs**, int);
void buy_uslug(Medb0xs*, Medb0xs**);
void add_element_buy_struct(Medb0xs**, Medb0x&);
void print_buy_uslugMedb0x(Medb0x);
void print_buy_uslugMedb0xs(Medb0xs*);
void see_chet_Medb0x(Medb0xs**, Medb0x&);
void clear_buy_uslugstruct(Medb0xs**);
void delete_buy_uslug(Medb0xs**, Medb0x&, int);
void save_buy_uslugstruct(Medb0xs*);
void change_console_color();
int main()
{
	lang();
	Medb0x D;
	Medb0xs* Ps = NULL;
	Medb0xs* BPs = NULL;
	int zena;
	fin.open("admin.txt");
	if (!fin.is_open()) {
		cout << "Файл не открыт.\n";
	}
	else
	{
		int input_parol_admin1;
		fin >> input_parol_admin1;
		D.setparol_admin(input_parol_admin1);
		fin.close();
	};
	char user;
	do {
		bool pravda = false;
		do {
			pravda = true;;
			cout << "<+********************************************************************************************************************+>" << endl;
			cout << "||\t\t\t\t\tВыберите пользователя:                                                        ||\n";
			cout << "||\t\t\t\t\t                                                                              ||"<<endl;
			cout << "<+********************************************************************************************************************+>" << endl;
			cout << "||\t\t\t\t\t 1.Адмирнистратор                                                             ||\n";
			cout << "||\t\t\t\t\t                                                                              ||" << endl;
			cout << "||\t\t\t\t\t 2.Посетитель                                                                 ||\n";
			cout << "||\t\t\t\t\t                                                                              ||" << endl;
			cout << "||\t\t\t\t\t 0.Выход                                                                      ||\n";
			cout << "||\t\t\t\t\t                                                                              ||" << endl;
			cout << "||\t\t\t\t\t * Введите номер пункта                                                       ||\n";
			cout << "<+********************************************************************************************************************+>" << endl;
			user = _getch();
			system("cls");
			switch (user)
			{
			case '1':
				cout << "\t\t\t\t\tВведите пароль администратора" << endl;
				int prob_parol;
				cin >> prob_parol;
				if (prob_parol == D.getparol_admin()) {
					system("cls");
					cout << "\t\t\t\t\tДобро пожаловать администратор" << endl;
					pravda = false;
					char menu_admin;
					do {
						cout << "<+********************************************************************************************************************+>" << endl;
						cout << "||\t\t\t\t\t МЕНИ АДМИНА:                                                                 ||\n";
						cout << "||							                                                              ||"<<endl;
						cout << "<+********************************************************************************************************************+>" << endl;
						cout << "||\t\t\t\t 1.Просмотр списка медицинского оборудования                                          ||\n";
						cout << "||\t\t\t\t                                                                                      ||" << endl;
						cout << "||\t\t\t\t 2.Добавление нового медицинского оборудования                                        ||\n";
						cout << "||\t\t\t\t                                                                                      ||" << endl;
						cout << "||\t\t\t\t 3.Добавление нового медицинского оборудования в произв.место                         ||\n";
						cout << "||\t\t\t\t                                                                                      ||" << endl;
						cout << "||\t\t\t\t 4.Сохранение медицинского оборудования в базу данных (Продолжение записи)            ||\n";
						cout << "||\t\t\t\t                                                                                      ||" << endl;
						cout << "||\t\t\t\t 5.Сохранение медицинского оборудования в базу данных (Новая запись)                  ||\n";
						cout << "||\t\t\t\t                                                                                      ||" << endl;
						cout << "||\t\t\t\t 6.Чтение базы медицинского оборудования с файла                                      ||\n";
						cout << "||\t\t\t\t                                                                                      ||" << endl;
						cout << "||\t\t\t\t 7.Поиск  медицинского оборудования                                                   ||\n";
						cout << "||\t\t\t\t                                                                                      ||" << endl;
						cout << "||\t\t\t\t 8.Удаление медицинского оборудования по id                                           ||\n";
						cout << "||\t\t\t\t                                                                                      ||" << endl;
						cout << "||\t\t\t\t 9.Очистка списка                                                                     ||\n";
						cout << "||\t\t\t\t                                                                                      ||" << endl;
						cout << "||\t\t\t\t c.Помениять цвет консоли                                                            ||\n";
						cout << "||\t\t\t\t                                                                                      ||" << endl;
						cout << "||\t\t\t\t 0.Выход                                                                              ||\n";
						cout << "||\t\t\t\t                                                                                      ||" << endl;
						cout << "||\t\t\t\t * Введите номер пункта                                                               ||\n";
						cout << "<+********************************************************************************************************************+>" << endl;
						menu_admin = _getch();
						system("cls");
						switch (menu_admin) {
							// Просмотр списка товаров
						case '1':
							print_Medb0xs(Ps);
							system("pause");
							system("cls");
							break;
							// Добавление товара в список
						case '2':
							input_Medb0x(D);
							add_element_struct(&Ps, D);
							system("cls");
							break;
							// Вставка в произвол.место
						case '3':
							input_Medb0x(D);
							insert_element_struct(&Ps, D);
							system("cls");
							break;
							// Сохранение в файл списка
						case '4':
							save_struct(Ps, 1);
							system("cls");
							cout << "-------------------------------" << endl;
							cout << "Список мед оборудования сохранен" << endl;
							cout << "-------------------------------" << endl;
							break;
							// Сохранение в файл (перезапись)
						case '5':
							save_struct(Ps, 0);
							system("cls");
							cout << "-------------------------------" << endl;
							cout << "Список медицинского оборудования сохранен" << endl;
							cout << "-------------------------------" << endl;

							break;
							// Чтение с файла
						case '6':
							clear_struct(&Ps);
							read_database(&Ps);
							break;
							// Поиск товара
						case '7':
							search_Medb0x(Ps);
							system("pause");
							system("cls");
							break;
							// Удаление товара по номеру
						case '8':
							delete_Medb0x(&Ps, 0);
							break;
							// Очистка
						case '9':
							clear_struct(&Ps);
							cout << "-------------------------------" << endl;
							cout << "Список очищен" << endl;
							cout << "-------------------------------" << endl;
							break;
							// Выход
						case 'c':
							change_console_color();
						case '0':

							break;
						default: cout << "Выбран несуществующий пункт меню" << endl;
						}
					} while (menu_admin != '0');
				}
				else {
					cout << "Неверный пароль.Попробуйте еще раз" << endl;
				}
				break;
			case '2':
				char menu_user;
				do {
					cout << "<+********************************************************************************************************************+>" << endl;
					cout << "||\t\t\t\t\t МЕНИ ПОЛЬЗОВАТЕЛЯ:                                                           ||\n";
					cout << "||							                                                              ||" << endl;
					cout << "<+********************************************************************************************************************+>" << endl;
					cout << "||\t\t\t\t 1.Заказать услуги данного медицинского оборудования                                  ||\n";
					cout << "||\t\t\t\t                                                                                      ||" << endl;
					cout << "||\t\t\t\t 2.Просмотр заказаных услуг                                                           ||\n";
					cout << "||\t\t\t\t                                                                                      ||" << endl;
					cout << "||\t\t\t\t 3.Сохранение купленных услуг в файл                                                  ||\n";
					cout << "||\t\t\t\t                                                                                      ||" << endl;
					cout << "||\t\t\t\t 4.Чтение купленных услуг с файла                                                     ||\n";
					cout << "||\t\t\t\t                                                                                      ||" << endl;
					cout << "||\t\t\t\t 5.Выписка счета                                                                      ||\n";
					cout << "||\t\t\t\t                                                                                      ||" << endl;
					cout << "||\t\t\t\t 6.Удаление услуги из заказа                                                          ||\n";
					cout << "||\t\t\t\t                                                                                      ||" << endl;
					cout << "||\t\t\t\t 7.Очистка всех заказаных услуг                                                       ||\n";
					cout << "||\t\t\t\t                                                                                      ||" << endl;
					cout << "||\t\t\t\t 8.Просмотр списка медицинского оборудования и их усдуг                               ||\n";
					cout << "||\t\t\t\t                                                                                      ||" << endl;
					cout << "||\t\t\t\t 9.Можете раслабится сыграв в крестики нолики                                         ||\n";
					cout << "||\t\t\t\t                                                                                      ||" << endl;
					cout << "||\t\t\t\t 0.Выход                                                                              ||\n";
					cout << "||\t\t\t\t                                                                                      ||" << endl;
					cout << "||\t\t\t\t * Введите номер пункта                                                               ||\n";
					cout << "<+********************************************************************************************************************+>" << endl;
					// Покупка товара
					menu_user = _getch();
					system("cls");
					switch (menu_user) {
					case '1':
						buy_uslug(Ps, &BPs);
						break;
						// Просмотр корзины
					case '2':
						print_buy_uslugMedb0xs(BPs);
						break;
						// Сохранение в файл купленных товаров
					case '3':
						save_buy_uslugstruct(BPs);
						cout << "-------------------------------" << endl;
						cout << "Список купленных услуг мед оборудования сохранен" << endl;
						cout << "-------------------------------" << endl;
						break;
						// Сохранение в файл купленных товаров
					case '4':

						break;
						// Выписка счета
					case '5':
						see_chet_Medb0x(&BPs, D);
						break;
						// Удаление товара из корзины
					case '6':
						delete_buy_uslug(&BPs, D, 0);
						break;
						// Очистка корзины
					case '7':
						clear_buy_uslugstruct(&BPs);
						cout << "-------------------------------" << endl;
						cout << "Список купленных услуг мед оборудования очищен" << endl;
						cout << "-------------------------------" << endl;
						break;
					case '8':
						print_Medb0xs(Ps);
						system("pause");
						system("cls");
						break;
					case '9':
					igra();
					break;
			case '0':
				break;
			default: cout << "\t\t\t\tВыбран несуществующий пункт меню" << endl;
				}
			} while (menu_user != '0');
			pravda = false;
			break;
		case '0':
			pravda = false;
			break;
		default: cout << "\t\t\t\tВыбран несуществующий пункт меню" << endl;
		}
	} while (pravda);
} while (user != '0');

}
void print_Medb0xs(Medb0xs* Ps) {
	Medb0xs* S = Ps;
	if (!S) {
		cout << "\t\t\t\tСписок пуст" << endl;
		return;
	}
	cout << "<+********************************************************************************************************************+>";
	cout << "||\t\t\t\t\t СПИСОК МЕД ОБОРУДОВАНИЯ:                                                     ||\n";
	cout << "||\t\t\t\t		                                                                      ||" << endl;
	cout << "||\t\t\t\t\t--------- Товар (ID) " << S->P.id << " ----------                                          ||" << endl;
	while (S)
	{
		print_Medb0x(S->P);
		S = S->next;
	}
}
void print_Medb0x(Medb0x P) {
	cout << "<+********************************************************************************************************************+>";
	cout << "||\t\t\t\tID:  " << P.id << "                                                                             \n";
	cout << "||\t\t\t\t                                                                                      " << endl;
	cout << "||\t\t\t\tНазвание медицинского оборудования:  " << P.name <<"                                              \n";
	cout << "||\t\t\t\t                                                                                      " << endl;
	cout << "||\t\t\t\tЕдиница измерения(Валюта):  " << P.value << "                                                  \n";
	cout << "||\t\t\t\t                                                                                      " << endl;
	cout << "||\t\t\t\tЦена услуги данного медицинского оборудования:  " << P.price << "                              \n";
	cout << "||\t\t\t\t                                                                                      " << endl;
	cout << "||\t\t\t\tКоличество услуг данного оборудования в медицинской колледже:  " << P.number << "              \n";
	cout << "||\t\t\t\t                                                                                         " << endl;
	cout << "||\t\t\t\tДата установки оборудования:  " << P.last_date << "                                       \n";
	cout << "||\t\t\t\t                                                                                          " << endl;
	cout << "||\t\t\t\tкабинет в котором будет данное медицинское оборудование:  " << P.kabinet << "             \n";
	cout << "||\t\t\t\t                                                                                          " << endl;
	cout << "||\t\t\t\tдля чего будет использоваться данное оборудование:  " << P.naznach << "                   \n";
	cout << "||\t\t\t\t                                                                                  " << endl;
	cout << "||\t\t\t\tчто надо взять с собой поциенту на прием:  " << P.about_user << "\n";
	cout << "<+********************************************************************************************************************+>";
}
void add_element_struct(Medb0xs** Ps, Medb0x& D) {
	Medb0xs* Inc = new Medb0xs;
	Inc->P.id = D.id;
	strcpy_s(Inc->P.name, D.name);
	strcpy_s(Inc->P.value, D.value);
	Inc->P.price = D.price;
	Inc->P.number = D.number;
	Inc->P.SIZE = D.SIZE;
	strcpy_s(Inc->P.last_date, D.last_date);
	strcpy_s(Inc->P.kabinet, D.kabinet);
	strcpy_s(Inc->P.naznach, D.naznach);
	strcpy_s(Inc->P.about_user, D.about_user);
	Inc->next = *Ps;
	*Ps = Inc;
}
void input_Medb0x(Medb0x& D) {
	cout << endl;
	cout << "************************************************************************************************************************";
	char val[64];
	bool valid = false;
	do {
		cout << "Введите ID оборудования" << endl;
		cin >> val;
		for (int i = 0; i < strlen(val); i++) {
			if (val[i] < '0' || val[i]>'9') {
				valid = false;
				break;
			}
			valid = true;
		}
		if (valid) {
			D.id = atoi(val);
		}
		else {
			cout << "\t Неверный тип (только целые числа)" << endl;
		}
	} while (!valid);
	bool valid22 = false;
	do {
		cout << "Введите название медицинского оборудования" << endl;
		cin >> D.name;
		for (int i = 0; i < strlen(D.name); i++) {
			if (D.name[i] >= 'A' && D.name[i] <= 'Z' || D.name[i] >= 'a' && D.name[i] <= 'z') {
				valid22 = true;
				break;
			}
			valid22 = false;
		}
		if (valid22) {
			break;
		}
		else {
			cout << "\t Неверный тип(только буквы)" << endl;
		}
	} while (!valid22);
	bool valid23 = false;
	do {
		cout << "Введите единицу измерения(Валюту)" << endl;
		cin >> D.value;
		for (int i = 0; i < strlen(D.value); i++) {
			if (D.value[i] >= 'A' && D.value[i] <= 'Z' || D.value[i] >= 'a' && D.value[i] <= 'z') {
				valid23 = true;
			}
			else {
				valid23 = false;
			}
		}
		if (valid23) {
			break;
		}
		else {
			cout << "\t Неверный тип(только буквы)" << endl;
		}
	} while (!valid23);
	char val2[64];
	bool valid2 = true;
	bool valid27 = true;
	do {
		cout << "Введите цену усдуги данного медицинского оборудования" << endl;
		cin >> val2;
		for (int i = 0; i < strlen(val2); i++) {
			if (val2[i] == '.') {
				valid2 = false;
				continue;
			}
			else if (val2[i] < '0' || val2[i]>'9') {
				valid2 = false;
				break;
			}
			if (val2[i] >= 'A' && val2[i] <= 'Z' || val2[i] >= 'a' && val2[i] <= 'z') {
				valid27 = true;
			}
			else {
				valid27 = false;
			}
		}
		if (valid2 == false && valid27 == false) {
			D.price = atoi(val2);
		}
		else {
			cout << "\t Неверный тип (только дробные числа числа)" << endl;
		}
	} while (valid2 == true || valid27 == true);
	bool valid4 = true;
	bool valid26 = true;
	do {
		cout << "Введите кабинет в котором будет данное медицинское оборудование" << endl;
		cin >> D.kabinet;
		for (int i = 0; i < strlen(D.kabinet); i++) {
			if (D.kabinet[i] == '.') {
				valid26 = false;
				continue;
			}
		}
		for (int i = 0; i < 2; i++) {
			if (D.kabinet[i] >= 'A' && D.kabinet[i] <= 'Z' || D.kabinet[i] >= 'a' && D.kabinet[i] <= 'z') {
				valid4 = false;
			}
			else {
				valid4 = true;
			}
		}
		if (valid4 == true || valid26 == true) {
			cout << "\t Неверный тип (формат- кб.номер кабинета)" << endl;
		}
	} while (valid4 == true || valid26 == true);
	char val3[64];
	bool valid3 = false;
	do {
		cout << "Введите количество услуг данного оборудования в медицинской колледже" << endl;
		cin >> val3;
		for (int i = 0; i < strlen(val3); i++) {
			if (val3[i] < '0' || val3[i]>'9') {
				valid3 = false;
				break;
			}
			valid3 = true;
		}
		if (valid3) {
			D.number = atoi(val3);
		}
		else {
			cout << "\t Неверный тип (только целые числа)" << endl;
		}
	} while (!valid3);
	bool valid24 = false;
	bool valid25 = false;
	do {
		cout << "Введите дату установки оборудования" << endl;
		cin >> D.last_date;
		for (int i = 0; i < strlen(D.last_date); i++) {
			if (D.kabinet[i] == '.') {
				valid24 = true;
			}
			if (valid24) {
				if (D.last_date[i] >= 'A' && D.last_date[i] <= 'Z' || D.last_date[i] >= 'a' && D.last_date[i] <= 'z') {
					valid25 = false;
				}
				else {
					valid25 = true;
				}
			}
		}
		if (!valid24 || !valid25) {
			cout << "\t Неверный тип (формат - дата.месяц.год)" << endl;
		}
	} while (!valid24 || !valid25);
	bool valid30 = true;
	do {
		cout << "Напишите для чего будет использоваться данное оборудование" << endl;
		cin >> D.naznach;
		for (int i = 0; i < strlen(D.naznach); i++) {
			if (D.naznach[i] >= 'A' && D.naznach[i] <= 'Z' || D.naznach[i] >= 'a' && D.naznach[i] <= 'z') {
				valid30 = false;
			}
		}
		if (valid30) {
			cout << "\t Неверный тип (только буквы)" << endl;
		}
	} while (valid30);
	bool valid31 = true;
	do {
		cout << "Напишите что надо взять с собой поциенту на прием" << endl;
		cin >> D.about_user;
		for (int i = 0; i < strlen(D.about_user); i++) {
			if (D.about_user[i] >= 'A' && D.about_user[i] <= 'Z' || D.about_user[i] >= 'a' && D.about_user[i] <= 'z') {
				valid31 = false;
			}
		}
		if (valid31) {
			cout << "\t Неверный тип (только буквы)" << endl;
		}
	} while (valid31);
	D.SIZE++;
}
void insert_element_struct(Medb0xs** Ps, Medb0x& D) {
	Medb0xs* Inc = new Medb0xs;
	Inc->P.id = D.id;
	strcpy_s(Inc->P.name, D.name);
	strcpy_s(Inc->P.value, D.value);
	Inc->P.price = D.price;
	Inc->P.number = D.number;
	strcpy_s(Inc->P.last_date, D.last_date);
	strcpy_s(Inc->P.kabinet, D.kabinet);
	strcpy_s(Inc->P.naznach, D.naznach);
	strcpy_s(Inc->P.about_user, D.about_user);
	if (*Ps == NULL) {
		Inc->next = NULL;
		*Ps = Inc;
		return;
	}
	Medb0xs* S = *Ps;
	if (S->P.id >= Inc->P.id) {
		Inc->next = S;
		*Ps = Inc;
		return;
	}
	Medb0xs* S1 = S->next;
	while (S1) {
		if (S->P.id < Inc->P.id && S->P.id <= S1->P.id) {
			S->next = Inc;
			Inc->next = S1;
			return;
		}
		S = S->next;
		S1 = S1->next;
	}
	S->next = Inc;
	Inc->next = NULL;
}
void save_struct(Medb0xs* Ps, int act) {
	ofstream fout;
	if (!act) {
		remove("admin.txt");
	}
	fout.open("admin.txt");
	if (!fout) {
		cout << "\t\t\t\tБаза данных не доступна";
		return;
	}
	while (Ps) {
		for (int i = 0; i < Ps->P.SIZE; i++)
		{
			fout << "<+********************************************************************************************************************+>";
			fout << "||\t\t\t\t\t СПИСОК МЕД ОБОРУДОВАНИЯ:                                                     \n";
			fout << "||\t\t\t\t		                                                                      " << endl;
			fout << "||\t\t\t\t\t--------- Товар (ID) " << Ps->P.id << " ----------                                         " << endl;
			fout << endl;
			fout << "************************************************************************************************************************";
			fout << "||\t\t\t\tID:  " << Ps->P.id << "                                                                    \n";
			fout << "||\t\t\t\t                                                                                         " << endl;
			fout << "||\t\t\t\tНазвание медицинского оборудования:  " << Ps->P.name << "                                  \n";
			fout << "||\t\t\t\t                                                                                         " << endl;
			fout << "||\t\t\t\tЕдиница измерения(Валюта):  " << Ps->P.value << "                                          \n";
			fout << "||\t\t\t\t                                                                                         " << endl;
			fout << "||\t\t\t\tЦена услуги данного медицинского оборудования:  " << Ps->P.price << "                      \n";
			fout << "||\t\t\t\t                                                                                         " << endl;
			fout << "||\t\t\t\tКоличество услуг данного оборудования в медицинской колледже:  " << Ps->P.number << "      \n";
			fout << "||\t\t\t\t                                                                                         " << endl;
			fout << "||\t\t\t\tДата установки оборудования:  " << Ps->P.last_date << "                                    \n";
			fout << "||\t\t\t\t                                                                                         " << endl;
			fout << "||\t\t\t\tкабинет в котором будет данное медицинское оборудование:  " << Ps->P.kabinet << "          \n";
			fout << "||\t\t\t\t                                                                                         " << endl;
			fout << "||\t\t\t\tдля чего будет использоваться данное оборудование:  " << Ps->P.naznach << "                \n";
			fout << "||\t\t\t\t                                                                                         " << endl;
			fout << "||\t\t\t\tчто надо взять с собой поциенту на прием:  " << Ps->P.about_user << "                      \n";
			fout << "************************************************************************************************************************";
		}
		Ps = Ps->next;
	}
}
void read_database(Medb0xs** Ps) {
	Medb0xs* Inc = new Medb0xs;
	Medb0x S;
	fin.open("admin.txt");
	if (!fin) {
		cout << "База данных не доступна";
		return;
	}
	long file_size;
	fin.seekg(0, ios::end);
	file_size = fin.tellg();
	if (!file_size) {
		cout << "База данных пуста";
		return;
	}
	char input_id[100];
	fin.getline(input_id, 100);
	Inc->P.id = atoi(input_id);
	strcpy_s(Inc->P.name, S.name);
	strcpy_s(Inc->P.value, S.value);
	Inc->P.price = S.price;
	Inc->P.number = S.number;
	strcpy_s(Inc->P.last_date, S.last_date);
	Inc->next = NULL;
	*Ps = Inc;
	while (!fin.eof()) {
		Inc->next = new Medb0xs;
		Inc = Inc->next;
		Inc->P.id = S.id;
		strcpy_s(Inc->P.name, S.name);
		strcpy_s(Inc->P.value, S.value);
		Inc->P.price = S.price;
		Inc->P.number = S.number;
		strcpy_s(Inc->P.last_date, S.last_date);
		Inc->next = NULL;
	}
	fin.close();
	cout << "-------------------------------" << endl;
	cout << "Список медицинского облрудования получен из файла" << endl;
	cout << "-------------------------------" << endl;
}
void clear_struct(Medb0xs** Ps) {
	if (!*Ps) {
		cout << "\t\t\t\tСписок пуст" << endl;
		return;
	}
	Medb0xs* S = *Ps;
	Medb0xs* D;
	while (S)
	{
		D = S;
		S = S->next;
		delete D;
	}
	*Ps = NULL;
}
void search_Medb0x(Medb0xs* Ps) {
	if (!Ps) {
		cout << "\t\t\t\tСписок пуст" << endl;
		return;
	}
	char name[64];
	cout << "\t\t\t\tВведите имя продукта" << endl;
	cin >> name;
	system("Cls");
	Medb0xs* S = Ps;
	while (S) {
		if (!strcmp(S->P.name, name)) {
			cout << "\t\t\t\t По запросу найден" << endl;
			print_Medb0x(S->P);
			return;
		}
		S = S->next;
	}
	cout << "\t\t\t\t Данного товара нет" << endl;
}
void delete_Medb0x(Medb0xs** Ps, int delete_id) {
	if (!*Ps) {
		cout << "\t\t\t\tСписок пуст" << endl;
		return;
	}
	int id;
	cout << "************************************************************************************************************************";
	if (!delete_id) {
		char val[64];
		bool valid = false;
		do {
			cout << "Введите ID удаляемого медицинского оборудования и его услуг" << endl;
			cin >> val;
			system("cls");
			for (int i = 0; i < strlen(val); i++) {
				if (val[i] < '0' || val[i]>'9') {
					valid = false;
					break;
				}
				valid = true;
			}
			if (valid) {
				id = atoi(val);
			}
			else {
				cout << "\t Неверный тип (только целые числа)" << endl;
			}
		} while (!valid);
	}
	else {
		id = delete_id;
	}
	Medb0xs* T = *Ps;
	if (T->P.id == id) {
		*Ps = T->next;
		delete T;
		cout << "-------------------------------" << endl;
		cout << "Оборудование и услуги удалены" << endl;
		cout << "-------------------------------" << endl;
		return;
	}
	Medb0xs* T1 = T->next;
	while (T1) {
		if (T1->P.id >= id && id >= T1->P.id) {
			T->next = T1->next;
			delete T1;
			if (!delete_id) {
				cout << "-------------------------------" << endl;
				cout << "Оборудование и услуги удалены" << endl;
				cout << "-------------------------------" << endl;
			}
			return;
		}
		T = T1;
		T1 = T1->next;
	}
}
void buy_uslug(Medb0xs* Ps, Medb0xs** BPs) {
	if (!Ps) {
		cout << "\t\t\t\tСписок пуст" << endl;
		return;
	}
	Medb0x D;
	char val[64];
	bool valid = false;
	cout << "<+********************************************************************************************************************+>";
	do {
		cout << "Введите ID мед оборудования" << endl;
		cin >> val;
		for (int i = 0; i < strlen(val); i++) {
			if (val[i] < '0' || val[i]>'9') {
				valid = false;
				break;
			}
			valid = true;
		}
		if (valid) {
			D.id = atoi(val);
		}
		else {
			cout << "\t Неверный тип (только целые числа)" << endl;
		}
	} while (!valid);
	Medb0xs* S = Ps;
	bool result = false;
	while (S) {
		if (S->P.id == D.id) {
			result = true;
			cout << "\t\t\t\t По запросу найден" << endl;
			print_Medb0x(S->P);
			cout << "\nВведите количество покупаемых услуг на даннон медицинское оборудование" << endl;
			cin >> D.number;
			if (S->P.number < D.number) {
				cout << "На данный момент нет такого количества услуг" << endl;
				cout << "Сейчас в ассортименте(услуг): " << D.number << endl;
				D.number = D.number - (D.number - S->P.number);
				cout << "Купить: " << D.number << endl;
				cout << "количество услуг?" << endl;
			}
			int act;
			cout << "\n\t\t\t\tПродолжить покупку (1 - да,0 - нет" << endl;
			cin >> act;
			system("cls");
			if (act) {
				cout << "-------------------------------" << endl;
				cout << "Услуги добавлены в корзину" << endl;
				cout << "-------------------------------" << endl;
				strcpy_s(D.name, S->P.name);
				strcpy_s(D.value, S->P.value);
				D.price = S->P.price;
				strcpy_s(D.last_date, S->P.last_date);
				strcpy_s(D.about_user, S->P.about_user);
				strcpy_s(D.naznach, S->P.naznach);
				strcpy_s(D.kabinet, S->P.kabinet);
				add_element_buy_struct(BPs, D);
				S->P.number = S->P.number - D.number;
				if (!S->P.number) {
					delete_Medb0x(&Ps, D.id);
				}
				save_struct(Ps, 0);
			}
			return;
		}
		S = S->next;
	}
	if (!result) {
		cout << "\t\t\t\tМед облрудование с данным ID не найден" << endl;
	}
}
void add_element_buy_struct(Medb0xs** BPs, Medb0x& D) {
	Medb0xs* BInc = new Medb0xs;
	BInc->P.id = D.id;
	strcpy_s(BInc->P.name, D.name);
	strcpy_s(BInc->P.value, D.value);
	BInc->P.price = D.price;
	BInc->P.number = D.number;
	BInc->P.SIZE = D.SIZE;
	strcpy_s(BInc->P.last_date, D.last_date);
	strcpy_s(BInc->P.about_user, D.about_user);
	strcpy_s(BInc->P.naznach, D.naznach);
	strcpy_s(BInc->P.kabinet, D.kabinet);
	BInc->next = *BPs;
	*BPs = BInc;
}
void print_buy_uslugMedb0x(Medb0x P) {
	cout << "<+********************************************************************************************************************+>";
	cout << "||\t\t\t\tID:  " << P.id << "                                                                             \n";
	cout << "||\t\t\t\t                                                                                      " << endl;
	cout << "||\t\t\t\tНазвание медицинского оборудования:  " << P.name << "                                              \n";
	cout << "||\t\t\t\t                                                                                      " << endl;
	cout << "||\t\t\t\tЕдиница измерения(Валюта):  " << P.value << "                                                  \n";
	cout << "||\t\t\t\t                                                                                      " << endl;
	cout << "||\t\t\t\tЦена услуги данного медицинского оборудования:  " << P.price << "                              \n";
	cout << "||\t\t\t\t                                                                                      " << endl;
	cout << "||\t\t\t\tКоличество услуг данного оборудования в медицинской колледже:  " << P.number << "              \n";
	cout << "||\t\t\t\t                                                                                         " << endl;
	cout << "||\t\t\t\tДата установки оборудования:  " << P.last_date << "                                       \n";
	cout << "||\t\t\t\t                                                                                          " << endl;
	cout << "||\t\t\t\tкабинет в котором будет данное медицинское оборудование:  " << P.kabinet << "             \n";
	cout << "||\t\t\t\t                                                                                          " << endl;
	cout << "||\t\t\t\tдля чего будет использоваться данное оборудование:  " << P.naznach << "                   \n";
	cout << "||\t\t\t\t                                                                                  " << endl;
	cout << "||\t\t\t\tчто надо взять с собой поциенту на прием:  " << P.about_user << "\n";
	cout << "<+********************************************************************************************************************+>";
}
void print_buy_uslugMedb0xs(Medb0xs* BPs) {
	Medb0xs* BS = BPs;
	if (!BS) {
		cout << "\t\t\t\t	Список пуст" << endl;
		return;
	}
	while (BS)
	{
		cout << "<+********************************************************************************************************************+>";
		cout << "||\t\t\t\t\t Корзина (купленные услуг):                                                     ||\n";
		cout << "||\t\t\t\t		                                                                      ||" << endl;
		cout << "||\t\t\t\t\t--------- Товар (ID) " << BS->P.id << " ----------                                          ||" << endl;
		print_buy_uslugMedb0x(BS->P);
		system("pause");
		system("cls");
		BS = BS->next;
	}
}
void see_chet_Medb0x(Medb0xs** BPs, Medb0x& D) {
	Medb0xs* BS = *BPs;
	if (!BS) {
		cout << "\t\t\t\tСписок пуст" << endl;
		return;
	}
	int price = 0;
	cout << "\t\t\t\t************ Счет - фактура **************" << endl;
	while (BS)
	{
		cout << "\t\t\t\t--------- Товар (ID) " << BS->P.id << " ----------" << endl;
		print_buy_uslugMedb0x(BS->P);
		price += BS->P.price * BS->P.number;
		BS = BS->next;
	}
	cout << endl;
	cout << "Итого: " << price << endl;
	int act;
	cout << "\nОплатить (1 - да,0 - нет" << endl;
	cin >> act;
	system("cls");
	if (act) {
		remove("buy_uslugdatabase.txt");
		clear_buy_uslugstruct(BPs);
		cout << "-------------------------------" << endl;
		cout << "Товары куплены." << endl;
		cout << "-------------------------------" << endl;
	}
}
void clear_buy_uslugstruct(Medb0xs** BPs) {
	if (!*BPs) {
		cout << "\t\t\t\tСписок пуст" << endl;
		return;
	}
	Medb0xs* S = *BPs;
	Medb0xs* D;
	while (S)
	{
		D = S;
		S = S->next;
		delete D;
	}
	*BPs = NULL;
}
void delete_buy_uslug(Medb0xs** BPs, Medb0x& D, int delete_id) {
	if (!*BPs) {
		cout << "\t\t\t\tСписок пуст" << endl;
		return;
	}
	int id;
	if (!delete_id) {
		char val[64];
		bool valid = false;
		do {
			cout << "\t\t\t\tВведите ID удаляемой услуги" << endl;
			cin >> val;
			system("cls");
			for (int i = 0; i < strlen(val); i++) {
				if (val[i] < '0' || val[i]>'9') {
					valid = false;
					break;
				}
				valid = true;
			}
			if (valid) {
				id = atoi(val);
			}
			else {
				cout << "\t\t\t\t Неверный тип (только целые числа)" << endl;
			}
		} while (!valid);
	}
	else {
		id = delete_id;
	}
	Medb0xs* T = *BPs;
	if (T->P.id == id) {
		*BPs = T->next;
		delete T;
		cout << "-------------------------------" << endl;
		cout << "Услуга удалена" << endl;
		cout << "-------------------------------" << endl;
		return;
	}
	Medb0xs* T1 = T->next;
	while (T1) {
		if (T1->P.id >= id && id >= T1->P.id) {
			T->next = T1->next;
			delete T1;
			if (!delete_id) {
				cout << "-------------------------------" << endl;
				cout << "Услуга удалена" << endl;
				cout << "-------------------------------" << endl;
			}
			return;
		}
		T = T1;
		T1 = T1->next;
	}
}
void save_buy_uslugstruct(Medb0xs* BPs) {
	ofstream fout;
	remove("buy_uslugdatabase.txt");
	fout.open("buy_uslugdatabase.txt");
	if (!fout) {
		cout << "База данных не доступна";
		return;
	}
	while (BPs) {
		fout << "<+********************************************************************************************************************+>\n";
		fout << "||\t\t\t\t\t СПИСОК ЗАКАЗАНЫХ УСЛУГ:                                                  \n";
		fout << "||\t\t\t\t		                                                                      " << endl;
		fout << "||\t\t\t\t\t--------- Товар (ID) " << BPs->P.id << " ----------                       " << endl;
		fout << endl;
		fout << "************************************************************************************************************************\n";
		fout << "||\t\t\t\tID:  " << BPs->P.id << "                                                                    \n";
		fout << "||\t\t\t\t                                                                                         " << endl;
		fout << "||\t\t\t\tНазвание медицинского оборудования:  " << BPs->P.name << "                                  \n";
		fout << "||\t\t\t\t                                                                                         " << endl;
		fout << "||\t\t\t\tЕдиница измерения(Валюта):  " << BPs->P.value << " " << BPs->P.price << "                   \n";
		fout << "||\t\t\t\t                                                                                         " << endl;
		fout << "||\t\t\t\tКоличество услуг данного оборудования в медицинской колледже:  " << BPs->P.number << "      \n";
		fout << "||\t\t\t\t                                                                                         " << endl;
		fout << "||\t\t\t\tДата установки оборудования:  " << BPs->P.last_date << "                                    \n";
		fout << "||\t\t\t\t                                                                                         " << endl;
		fout << "||\t\t\t\tкабинет в котором будет данное медицинское оборудование:  " << BPs->P.kabinet << "          \n";
		fout << "||\t\t\t\t                                                                                         " << endl;
		fout << "||\t\t\t\tдля чего будет использоваться данное оборудование:  " << BPs->P.naznach << "                \n";
		fout << "||\t\t\t\t                                                                                         " << endl;
		fout << "||\t\t\t\tчто надо взять с собой поциенту на прием:  " << BPs->P.about_user << "                      \n";
		fout << "************************************************************************************************************************";
		BPs = BPs->next;
	}
	fout.close();
}
void change_console_color() {
	system("cls");
	{
		vector<string> change_color = { "0 — черный", "1 — синий", "2 — зеленый", "3 — голубой", "4 — красный", "5 — лиловый", "6 — желтый", "7 — белый",

			"8 — серый", "9 — свело - синий", "A — светло - зеленый", "B — светло - голубой", "С — светло - красный", "E — светло - желтый", "F — ярко - белый" };

		cout << "\n\n\n\n";

		for (int i = 0; i < change_color.size(); i++)
			cout << "\t\t\t\t\t\t" << change_color[i] << ' ' << endl;

		char bg, tc;

		cout << "Выберите цвет фона окна:";
		cin >> bg;
		cout << "Выберите цвет текста:";
		cin >> tc;
		if (bg == tc) {
			cout << endl;
			cout << "Невозможно выбрать одинаковые цвета!";
			Sleep(2000);
		}
		else {
			if (bg >= 'a' && bg <= 'z') {
				bg -= 32;
			}
			if (tc >= 'a' && tc <= 'z') {
				tc -= 32;
			}
			string a = "color ";
			a.push_back(bg);
			a.push_back(tc);
			const char* c = a.c_str();
			system(c);
		}
	}
	system("cls");
}


