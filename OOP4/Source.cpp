#include<iostream>
#include<assert.h>
using namespace std;


//class : Debtor(debtor - borclu)
//	fields : objectId, name, surname, workAddress, salary, phoneNumber
//	fields : hasLatePayment(bool), liveAddress, debt, Id(static)
//	methods : showDebtor
//
//
//	class : Bank
//	fields : name, debtors(array)
//	method : showAllDebtors,
//	method : borcu 1000 den yuxari olanlari gostermek
//	method : gecikmesi olanlari gostermek
//
//
//	QEYD : Kechdiymiz her shey istifade olunsun.
//	static field, copy constructor ve s

class Debtor {

	int myID;
	char* name;
	char* surname;
	char* workAdress;
	int salary;
	char* phoneNumber;
	bool HasLatePayment = false;
	char* liveAdress;
	int debt;

public:
	static int ID;
	static int MAX;

	Debtor() = default;



	Debtor(const Debtor& other) {


		SetId(other.myID);
		SetName(other.name);
		SetSurname(other.surname);
		SetWorkAdress(other.workAdress);
		SetPhoneNumber(other.phoneNumber);
		SetSalary(other.salary);
		SetLiveAdress(other.liveAdress);
		SetDebt(other.debt);
		SetLatePayment(other.HasLatePayment);

	}
	Debtor(const char* name, const char* surname, const char* workAdress, int salary, const char* phoneNumber, bool HasLatePayment, const char* liveAdress, int debt) {
		SetName(name);
		SetSurname(surname);
		SetWorkAdress(workAdress);
		SetSalary(salary);
		SetPhoneNumber(phoneNumber);
		SetLatePayment(HasLatePayment);
		SetLiveAdress(liveAdress);
		SetDebt(debt);
		assert(ID < MAX && "Our garage is full");
		myID = ID++;


	}
	int GetCurrentId() { return ID; }
	int GetObjectId() { return myID; }
	char* GetName() { return name; }
	char* GetSurname() { return surname; }
	char* GetWorkAdress() { return workAdress; }
	int getSalary() { return salary; }
	char* GetPhoneNumber() { return phoneNumber; }
	bool GetLatePayment() { return HasLatePayment; }
	char* GetLiveAdress() { return liveAdress; }
	int GetDebt() { return debt; }



	void SetId(const int myID) {
		this->myID = myID;
	}
	void SetName(const char* name) {
		assert(name != nullptr && "Name should not be null");
		int l = strlen(name);
		this->name = new char[l + 1]{};
		strcpy_s(this->name, l + 1, name);
	}
	void SetSurname(const char* surname) {
		assert(surname != nullptr && "surname should not be null");
		int l = strlen(surname);
		this->surname = new char[l + 1]{};
		strcpy_s(this->surname, l + 1, surname);
	}
	void SetWorkAdress(const char* workAdress) {
		assert(workAdress != nullptr && "workAdress should not be null");
		int l = strlen(workAdress);
		this->workAdress = new char[l + 1]{};
		strcpy_s(this->workAdress, l + 1, workAdress);
	}
	void SetSalary(const int& salary) {
		assert(salary > 0 && "salary should be more than 0");
		this->salary = salary;
	}
	void SetPhoneNumber(const char* phoneNumber) {
		assert(phoneNumber != nullptr && "phoneNumber should not be null");
		int l = strlen(phoneNumber);
		this->phoneNumber = new char[l + 1]{};
		strcpy_s(this->phoneNumber, l + 1, phoneNumber);
	}

	void SetLatePayment(const bool HasLatePayment) {
		this->HasLatePayment = HasLatePayment;
	}


	void SetLiveAdress(const char* liveAdress) {
		assert(liveAdress != nullptr && "liveAdress should not be null");
		int l = strlen(liveAdress);
		this->liveAdress = new char[l + 1]{};
		strcpy_s(this->liveAdress, l + 1, liveAdress);
	}


	void SetDebt(const int& debt) {
		assert(debt > -1 && "debt should be more than 0");
		this->debt = debt;
	}



	void Show() {
		cout << "-----------------------" << endl;
		cout << "ID : " << myID << endl;
		cout << "Name : " << name << endl;
		cout << "Surname : " << surname << endl;
		cout << "Work adress : " << workAdress << endl;
		cout << "Phone number : " << phoneNumber << endl;
		cout << "Live Adress : " << liveAdress << endl;
		cout << "Salary : " << salary << endl;
		if (HasLatePayment == 1)
		{
			cout << "Late Payment : Yes" << endl;
		}
		else
		{
			cout << "Late Payment : No " << endl;
		}
		cout << "Debt : " << debt << endl;

	}

	~Debtor()
	{
		delete[]name;
		delete[]surname;
		delete[]workAdress;
		delete[]phoneNumber;
		delete[]liveAdress;

	}
};


int Debtor::ID = 1;
int Debtor::MAX = 5;

class Bank {

	char* bankName;
	Debtor* debtors;
	int count = 0;

public:
	Bank(Debtor* debtors, int count, const char* bankName) {
		this->count = count;
		this->debtors = debtors;
		this->debtors = debtors;
		SetBankName(bankName);
	}
	void SetBankName(const char* bankName) {
		if (bankName != nullptr)
		{
			int l = strlen(bankName);
			this->bankName = new char[l + 1]{};
			strcpy_s(this->bankName, l + 1, bankName);

		}
	}
	void Show() {
		cout << "==============" << bankName << "===========" << endl << endl;
		for (size_t i = 0; i < count; i++)
		{
			debtors[i].Show();
		}
	}
	~Bank()
	{
		delete[]debtors;
		delete[]bankName;
	}

};

void main() {
	Debtor d1("Elchin", "Guliyev", "StepIt", 800, "0507408448", true, "Akhmedli", 400);
	Debtor d2("Ilkin", "Aliyev", "261 school", 500, "0553452314", false, "Xalglar", 0);
	Debtor d3("Farid", "Mansimov", "Socar", 1500, "0502115676", true, "Nizami", 35);
	Debtor* debtors = new Debtor[3]
	{
		d1,d2,d3
	};



	Bank b(debtors, 3, "Kapital Bank");
	b.Show();



}





