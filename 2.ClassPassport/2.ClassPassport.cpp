/*Створіть клас Passport (паспорт), який буде містити
паспортну інформацію про громадянина України.
За допомогою механізму успадкування, реалізуйте
клас ForeignPassport (закордонний паспорт) похідний
від Passport.
Нагадаємо, що закордонний паспорт містить крім
паспортних даних, також дані про візи, номер закордонного паспорта*/

#include <iostream>
#include <string>
using namespace std;

class Passport {		//Клас Паспорт 
private:
	int numOfPas;		
	string name;
	string surname;			
	string streetHome;
	int numHome;
public:
	void setNumPas(int numOfPas) {this->numOfPas = numOfPas;}		
	virtual void getNumPas() {cout << "Num Of Passport: " << this->numOfPas << endl;}	
	void setName(string name) {this->name = name;}
	void getName() {cout << "Name : " << this->name << endl;}
	void setSurName(string surname) {this->surname = surname;}				//Сеттери і Геттери для інформації 
	void getSurName() {cout << "Surname : " << this->surname << endl;}
	void setStreetHome(string streetHome) {this->streetHome = streetHome;}
	void getStreetHome() {cout << "Street : " << this->streetHome;}
	void setNumHome(int numHome) {this->numHome = numHome;}
	void getNumHome() {cout << "Num : " << this->numHome << endl;}
};

class ZakordPass :public Passport			//Дочірній клас Закордонний паспорт який наслідується від базового класа паспорт 
{
private:
	int numZakPas;
	string visa;
public:
	void getName(Passport* JohnnyDepp) { JohnnyDepp->getName(); }
	void getSurName(Passport* JohnnyDepp) { JohnnyDepp->getSurName(); }			//Геттери і сетери для закородоного паспорта 
	void setNumPasZak(int numZakPas) { this->numZakPas = numZakPas; }	
	void getNumPas() override { cout << "Num Of Zakordoniy Passport: " << this->numZakPas << endl; } 
	void setVisa(string visa) { this->visa = visa; }
	void getVisa() {cout << "Visa in : " << this->visa;}
};

int main()
{
	Passport JohnnyDepp;
	cout << "\tPassport" << endl;
	JohnnyDepp.setNumPas(888258);
	JohnnyDepp.getNumPas();
	JohnnyDepp.setName("Johnny");
	JohnnyDepp.getName();
	JohnnyDepp.setSurName("Depp");					//Використовуючи гетери і сетери вводимо та виводимо інйормацію по класу паспорт
	JohnnyDepp.getSurName();
	JohnnyDepp.setStreetHome("Soborna ");
	JohnnyDepp.getStreetHome();
	JohnnyDepp.setNumHome(34);
	JohnnyDepp.getNumHome();
	cout << endl;

	cout << "zakordon" << endl;
	ZakordPass JohnnyDepp2;
	JohnnyDepp2.getName(&JohnnyDepp);
	JohnnyDepp2.getSurName(&JohnnyDepp);
	JohnnyDepp2.setNumPasZak(333666);				//Використовуючи гетери і сетери вводимо та виводимо інформацію по закордонному паспорту
	JohnnyDepp2.getNumPas();
	JohnnyDepp2.setVisa("Ukraine, Greece, Amber Heard");
	JohnnyDepp2.getVisa();
	cout << endl;
}
