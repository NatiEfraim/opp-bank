//////////////////// Course - OPP EX2
////////////////////Name - Nati Efraim
//////////////////// id - 315552810
#include "Account.h"
/// /////////////////////constrctor and destructor.
Account::Account()
	:m_accountNumber(0), m_balance(0), m_numberOfTransaction(0), m_transactionList(nullptr), m_persons(nullptr), m_totalPersons(0)
{
	//////////constructor deffule.
}
Account::Account(Person** persons, int count, double balance)
	:m_accountNumber(0), m_balance(balance), m_numberOfTransaction(0), m_transactionList(nullptr), m_totalPersons(count), m_persons(nullptr)
{
	this->SetPersons(persons, this->GetTotalPersons());
	/////set the account number
	for (int i = 0; i < this->m_totalPersons; i++)
	{
		this->m_accountNumber += this->m_persons[i]->GetId();///add the id of the persons for the account number.
	}
	///  /////////alocation for arr persons!
	////////////this->m_persons = new Person * [this->m_totalPersons];
	////////////for (int i = 0; i < this->m_totalPersons; i++)
	////////////{
	////////////	this->m_persons[i] = new Person(*(persons[i]));////////go to copy constructor of Person
	////////////	this->m_accountNumber += this->m_persons[i]->GetId();////for the seal number.
	////////////}
}
Account::Account(const Person& person, double balance)
	:m_balance(balance), m_accountNumber(0), m_numberOfTransaction(0), m_transactionList(nullptr), m_totalPersons(1), m_persons(nullptr)
{

	// //////////alocation arr for the arr persons
	this->m_persons = new Person * [this->m_totalPersons];
	this->m_persons[0] = new Person(person);///go to copy constructor of Person.
	this->m_accountNumber += this->m_persons[0]->GetId();/////for the seal number code.
	///////this->m_totalPersons += 1;

}
Account::Account(const Account& other)
	:m_accountNumber(other.m_accountNumber), m_balance(other.m_balance), m_totalPersons(other.m_totalPersons), m_persons(nullptr), m_transactionList(nullptr), m_numberOfTransaction(other.m_numberOfTransaction)
{
	// ////////set the transaction list and the persons list.
	this->SetPersons(other.GetPersons(), other.GetTotalPersons());
	this->SetTransactions(other.m_transactionList, other.m_numberOfTransaction);
	
	////////// ////////alocation of arr transaction
	////////if (other.m_numberOfTransaction>0)
	////////{
	////////	this->m_transactionList = new Transaction * [this->m_numberOfTransaction];
	////////	for (int i = 0; i < this->m_numberOfTransaction; i++)
	////////	{
	////////		this->m_transactionList[i] = new Transaction(*other.m_transactionList[i]);////go th the constructor of transaction.
	////////	}
	////////}
	////////// ///////////// alocation of arr of persons
	////////if (other.m_totalPersons>0)
	////////{
	////////	this->m_persons = new Person * [this->m_totalPersons];
	////////	for (int i = 0; i < this->m_totalPersons; i++)
	////////	{
	////////		this->m_persons[i] = new Person(*(other.m_persons[i]));///////////go to the constructor of Person
	////////	}
	////////}
	/////////deep copy!!!!
}
Account::~Account()///////destructor.
{
	//////////delete the Arr of persons!!!!
	this->clearPersons();//////clear arr of the persosns.
	//////////////if (this->m_persons != nullptr)
	//////////////{
	//////////////	for (int i = 0; i < this->m_totalPersons; i++)
	//////////////	{
	//////////////		delete this->m_persons[i];//////go to the Person destructor.
	//////////////		this->m_persons[i] = nullptr;
	//////////////	}
	//////////////	delete[]this->m_persons;
	//////////////	this->m_persons = nullptr;//////verey importent.
	//////////////}
	/////////////////////delete the Arr of Transaction!!!!
	this->clearTransactions();//////clear arr of transaction.
	//////////if (this->m_transactionList!=nullptr)
	//////////{
	//////////	for (int i = 0; i < this->m_numberOfTransaction; i++)
	//////////	{
	//////////		delete this->m_transactionList[i];////go to destructor of trascation.(Not initilaized)
	//////////		this->m_transactionList[i] = nullptr;
	//////////	}
	//////////	delete[]this->m_transactionList;////delete the arr it self.
	//////////	this->m_transactionList = nullptr;//////verey importent.
	//////////}

}
//////////////////////////////////////acesess function.
void Account::SetPersons(Person** persons, int count)
{
	//////////////////if (this->m_persons != nullptr)
	//////////////////{
	//////////////////	for (int i = 0; i < this->m_totalPersons; i++)
	//////////////////	{
	//////////////////		delete this->m_persons[i];////go to the desturctor of Persons
	//////////////////		this->m_persons[i] = nullptr;
	//////////////////	}
	//////////////////	delete[]this->m_persons;////////destructor of Person
	//////////////////	this->m_persons = nullptr;
	//////////////////}
	this->clearPersons();/////clear arr of persons.
	if (count<=0 || persons==nullptr)
	{
		this->m_totalPersons = 0;
		this->m_persons = nullptr;
		return;/////there is nothing to do.
	}
	// ////////re alocation!!!
	this->m_totalPersons = count;
	this->m_persons = new Person * [this->m_totalPersons];
	for (int i = 0; i < this->m_totalPersons; i++)
	{
		this->m_persons[i] = new Person(*(persons[i]));//////go to copy consturctor.
	}

}
void Account::SetAccountNumber(int number)
{
	this->m_accountNumber = number;
}
void Account::SetBalance(double balance)
{
	this->m_balance = balance;
}
void Account::SetTransactions(Transaction** newTransaction, int count)
{
	////////////////if (this->m_transactionList != NULL)
	////////////////{
	////////////////	for (int i = 0; i < this->m_numberOfTransaction; i++)
	////////////////	{
	////////////////		delete this->m_transactionList[i];//////go to the desturtor of trazcation.
	////////////////		this->m_transactionList[i] = nullptr;
	////////////////	}
	////////////////	delete[] this->m_transactionList;/////destructor of trunsaction
	////////////////	this->m_transactionList = nullptr;
	////////////////}
	this->clearTransactions();//////clear arr of transaction.
	if (count<=0 || newTransaction==nullptr)
	{
		this->m_numberOfTransaction = 0;
		this->m_transactionList = nullptr;
		return;////there is nothing to do.
	}
	//////////re-alocation for the arr tansaction
	this->m_numberOfTransaction = count;
	this->m_transactionList = new Transaction * [this->m_numberOfTransaction];
	for (int i = 0; i < this->m_numberOfTransaction; i++)
	{
		this->m_transactionList[i] = new Transaction(*(newTransaction[i]));////////go to the copy constructor of transaction
	}
}
Transaction** Account::GetTransactions()
{
	return this->m_transactionList;
}
int	Account::GetNumOfTransactions()
{
	return this->m_numberOfTransaction;
}
Person** Account::GetPersons() const
{
	return this->m_persons;
}
int	Account::GetTotalPersons()const
{
	return this->m_totalPersons;
}
int	Account::GetAccountNumber() const
{
	return this->m_accountNumber;
}
double Account::GetBalance() const
{
	return this->m_balance;
}
///////////////////////////Other Functction
void Account::clearTransactions()
{
	if (this->m_transactionList != nullptr)
	{
		for (int i = 0; i < this->m_numberOfTransaction; i++)
		{
			delete this->m_transactionList[i];/////go to the desturction of transaction
			this->m_transactionList[i] = nullptr;
		}
		delete[]this->m_transactionList;/////go to the destructor of transaction
		this->m_transactionList = nullptr;
	}
}
void Account::clearPersons()
{
	if (this->m_persons != nullptr)
	{
		for (int i = 0; i < this->m_totalPersons; i++)
		{
			delete this->m_persons[i];//////go to the destructor of Person
			this->m_persons[i] = nullptr;
		}
		delete[]this->m_persons;//////go to the destrctor of Person.
		this->m_persons = nullptr;
	}
}
void Account::AddPerson(const Person& newPerson, double	amount)
{
	// ///////////addPersons to the Arr persons.
	int found = 0;

	for (int i = 0; i < this->m_totalPersons; i++)
	{
		/////search person.
		if ((this->m_persons[i]->GetId() == newPerson.GetId()))
		{
			//////the persons has found.
			found = -1;
			break;

		}
	}
	if (found == -1)
	{
		////not todo nothing
		//////////the person is allready exsist.
		return;

	}
	Person** tempArr = new Person * [this->m_totalPersons + 1];
	for (int i = 0; i < this->m_totalPersons; i++)
	{
		tempArr[i] = this->m_persons[i];///////shalow copy!!!save all persons in the arr befor to delete.
	}
	if (this->m_persons!=nullptr)
	{
		delete[]this->m_persons;//////delete the arr only!!
		this->m_persons = nullptr;
	}
	this->m_persons = tempArr;////new assitment!
	/////////////////////////tempArr[this->m_totalPersons] = new Person(newPerson);//////go to the copy constructor.
	this->m_totalPersons += 1;////////increase the size of persons in the arr.
	this->m_persons[this->m_totalPersons - 1] = new Person(newPerson);//////go to the copy constructor of persons
	this->m_balance += amount;//////add the balance of the account
	return;
}
void Account::DeletePerson(const Person& oldPerson)
{
	//////////delete persons from Arr of persons.
	int found = -1;
	for (int i = 0; i < this->m_totalPersons; i++)
	{
		if ((this->m_persons[i]->GetId() == oldPerson.GetId()))
		{
			//////the persons has found.
			found = i;///save the index person need to delete
			break;

		}
	}
	if (found==-1)
	{
		////the old person has not exsist.
		return;
	}
	delete this->m_persons[found];////delete the persons
	if (found==0)
	{
		this->m_totalPersons = 0;////up date the total num of persons.
		if (this->m_persons!=nullptr)
		{
			////that mean this persons was the only persons in the r arr of persons
			delete[] this->m_persons;/////go tot the destrctor of person.
			this->m_persons = nullptr;
		}
		return;
	}
	this->m_persons[found] = this->m_persons[this->m_totalPersons - 1];////assitment the last persons
	/////alocate temp arr of persons.
	this->m_totalPersons -= 1;////decrease the size of the arr.
	Person** tempArr = new Person * [this->m_totalPersons];
	for (int i = 0; i < this->m_totalPersons; i++)
	{
		tempArr[i] = this->m_persons[i];//////shalow copy.
	}
	////delete the old arr.
	if (this->m_persons!=nullptr)
	{
		delete[]this->m_persons;/////go to the destructor.
		this->m_persons = nullptr;
	}
	this->m_persons = tempArr;//////re assitment!!!
	return;
}
void Account::AddTransaction(const Transaction& newTransaction)
{
	if (newTransaction.GetSource()->GetAccountNumber()==newTransaction.GetDes()->GetAccountNumber())
	{
		////////same account. up date one of them!
		// ////////////////the depsit function or the withdraw function 
		// ///// alocate new transaction and up-Date the balance of bank account
		newTransaction.GetSource()->Withdraw(newTransaction.GetAmount(), newTransaction.GetDate());
	}
	else
	{
		/////////diffrent account
		////////up -date the balance - both of them
		//////////////////Handel with the source!!!!
		///////////////newTransaction.GetSource()->SetBalance(newTransaction.GetSource()->GetBalance() - newTransaction.GetAmount());/////reduce from the source
		newTransaction.GetSource()->Withdraw(newTransaction.GetAmount(), newTransaction.GetDate());/////set new transaction for the source
		//////////////////Handel with the dest!!!!
		///////////////newTransaction.GetDes()->SetBalance(newTransaction.GetDes()->GetBalance() + newTransaction.GetAmount());////add for the dest.
		newTransaction.GetDes()->Deposit(newTransaction.GetAmount(), newTransaction.GetDate());//////set new deposit for the dest.
	}
}
void Account::Withdraw(double amount, const char* date)
{
	///////////need to do withdraw at the same account!!!
	Transaction transaction(this, this, amount, date);////new transaction
	/////alocate new arr of transaction
	Transaction** tempArr = new Transaction * [this->m_numberOfTransaction + 1];
	for (int i = 0; i < this->m_numberOfTransaction; i++)
	{
		tempArr[i] = this->m_transactionList[i];////save all transactions in the arr transaction.
	}
	if (this->m_transactionList!=nullptr)
	{
		delete[]this->m_transactionList;/////delete the arr it self
		this->m_transactionList = nullptr;
	}
	this->m_numberOfTransaction += 1;//////increase the size of transaction
	this->m_transactionList = tempArr;/////////new assitment.
	this->m_transactionList[this->m_numberOfTransaction - 1] = new Transaction(transaction);////go to the constructor of transaction
	this->m_balance -= amount;////up-date the balance.

}
void Account::Deposit(double amount, const char* date)
{
	//////////deposit the same account!!!
	////diffine new transaction
	Transaction transaction(this, this, amount, date);
	//////alocation temp arr of transaction.
	Transaction** tempArr = new Transaction * [this->m_numberOfTransaction + 1];
	for (int i = 0; i < this->m_numberOfTransaction; i++)
	{
		tempArr[i] = this->m_transactionList[i];///////shallow copy.
	}
	if (this->m_transactionList!=nullptr)
	{
		delete[]this->m_transactionList;
		this->m_transactionList = nullptr;
	}
	this->m_transactionList = tempArr;/////new assitment.
	this->m_numberOfTransaction += 1;/////increase the size of transaction
	this->m_transactionList[this->m_numberOfTransaction - 1] = new Transaction(transaction);///go to the copy constructor.
	this->m_balance += amount;/////up-date the balance!!

}