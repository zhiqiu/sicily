// c++ Polymorphism

class Bank
{
public:
	Bank(string _name)
	{
		name = _name;
	}
	string getName() const
	{
		return name;
	}
	virtual void printMessage() const = 0;
	virtual void deposit(double m) = 0;
	virtual void withdraw(double m) = 0;
	virtual double getMoney() const = 0;
protected:
	string name;
};

class ICBC : public Bank
{
public:
	ICBC(double _money = 0) :Bank("ICBC")
	{
		money = _money;
	}
	void printMessage() const
	{
		cout << "Welcome to Industrial and Commercial Bank of China" << endl;
	}
	void deposit(double m)
	{
		money += m;
	}
	void withdraw(double m)
	{
		if (money > m) money -= m;
		else money = 0;
	}
	double getMoney() const
	{
		return money;
	}
private:
	double money;
};


class ABC : public Bank
{
public:
	ABC(double _money = 0) :Bank("ABC")
	{
		money = _money;
	}
	void printMessage() const
	{
		cout << "Welcome to Agricultural Bank of China" << endl;
	}
	void deposit(double m)
	{
		money += m;
	}
	void withdraw(double m)
	{
		if (money > m) money -= m;
		else money = 0;
	}
	double getMoney() const
	{
		return money;
	}
private:
	double money;
};

class AccountManager
{
public:
	AccountManager(int _size){
		size = _size;
		bankList = new Bank*[size];
	}
	~AccountManager(){
		delete[]bankList;
	}
	void setBank(int i, Bank *bank)
	{
		bankList[i] = bank;
	}
	Bank* getBank(int i)
	{
		return bankList[i];
	}
	void deposit(Bank *bank, double money)
	{
		bank->deposit(money);
	}
	void withdraw(Bank *bank, double money)
	{
		bank->withdraw(money);
	}
	void transfer(Bank *bank1, Bank *bank2, double money)
	{
		// Bank* B;
		double temp = bank1->getMoney();
		bank1->withdraw(bank1->getMoney());
		bank2->deposit(temp);

	}
	void printAccount() const
	{
		for (int i = 0; i<size; i++)
		{
			bankList[i]->printMessage();
			cout << bankList[i]->getName() << ends << bankList[i]->getMoney() << endl;;
		}

	}	//print the welcome message, bank name and money for each array element
private:
	Bank* *bankList;	//bank array, where each element is a (Bank*) type
	int size;	//the length of the bank array
};