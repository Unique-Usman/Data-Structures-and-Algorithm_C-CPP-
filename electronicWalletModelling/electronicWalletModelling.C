#include <iostream>
#include <string>

using namespace std;

class Wallet {
  private:
    double balance;     // balance available in the account
    friend class Admin;
    static int count;   // keeps track of the count of wallets
  public:
    int id;     // the count number is assigned
    Wallet();
    Wallet(double);
    Wallet(Wallet &);
    double getBalance();        // fetches the balance in the account
    double topUp(double);       // adds to the account balance

    /* function to send money from self to another wallet; the other wallet object is taken as one of the arguments, as is the amount to be transferred */
    bool sendMoney( Wallet*, double/* parameters to be filled in here... */ );
};

class Admin {
  public:
/* function that takes the source and destination wallets as arguments, and also the amount to be transferred from the source to the destination */
    bool mediateTransfer( Wallet*, Wallet*, double/* parameters to be filled in here... */ );
};

// Member function definitions go here...


/* Member function for the Wallet */
int Wallet::count = 0;

Wallet::Wallet(){} //empty constructor

Wallet::Wallet(double bal):balance(bal)  //parameterised constructor
{
	count++;
	this->id = count;
}
//copy constructor 
Wallet::Wallet(Wallet &w) 
{
	this->balance = w.balance;
}

double Wallet::getBalance()
{
	return (this->balance);
}
double Wallet::topUp(double am)
{
	this->balance += am;
	return (this->balance);
}

bool Wallet::sendMoney(Wallet *w2, double am)
{
	Admin A;
	if (balance >= am)
	{
		A.mediateTransfer(w2, this, am);
		return (1);
	}
	else
	{
		cout << "Insufficient balance " << endl;
		return (0);
	}
}


/* Member function for the Admin*/

bool Admin::mediateTransfer(Wallet *wdest, Wallet *wsrc, double am)
{
	wdest->balance += am;
	wsrc->balance -= am;
	return (0);
}


// Driver code to be written inside main()...
int main()
{
	double amount;
	cout << "Enter the amount for the first wallet: " << endl;
	cin >> amount;
	Wallet *w1 = new Wallet(amount);
	cout << "Enter the amount for the second wallet: " << endl;
	cin >> amount;
	Wallet *w2 = new Wallet(amount);
	cout << "Enter the amount for the third wallet: " << endl;
	cin >> amount;
	Wallet *w3 = new Wallet(amount);
	//Transfering money
	cout << "Balance of the first wallet before transfer is :"  << w1->getBalance() << endl;
	cout << "Balance of the second wallet before  transfer is: " <<  w2->getBalance() << endl;
	double amountTransfer;
	cout << "Input the amount to be transfer: " << endl;	
	cin >>  amountTransfer;
	if (w1->sendMoney(w2, amountTransfer) != 0) 
	{ 
	cout << "Balance of the first wallet after transfer is :"  << w1->getBalance() << endl;
	cout << "Balance of the second wallet after  transfer is: " <<  w2->getBalance() << endl;
	}
	delete w1;
	delete w2;
	delete w3;
        return 0;
}
