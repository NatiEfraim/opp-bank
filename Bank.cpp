//////////////////// Course - OPP EX2
////////////////////Name - Nati Efraim
//////////////////// id - 315552810
#include "Bank.h"
/////////////////////////constructor and destructor
Bank::Bank()
	:m_account(nullptr), m_bankCode(0), m_name(nullptr), m_numbeOfAccounts(0), m_totalBalance(0)
{

}
Bank::Bank(const char* name, int code)
	:m_account(nullptr), m_name(nullptr), m_numbeOfAccounts(0), m_bankCode(code), m_totalBalance(0)
{
	if (this->m_name!=nullptr)
	{
		delete this->m_name;
		this->m_name = nullptr;
	}
	this->SetBankName(name);
	////////this->m_name = new char[strlen(name) + 1];
	////////strcpy_s(this->m_name, strlen(name) + 1, name);
}
Bank::~Bank()
{
	if (this->m_name!=nullptr)
	{
		delete this->m_name;
		this->m_name = nullptr;
	}
	if (this->m_account!=nullptr)
	{
		for (int i = 0; i < this->m_numbeOfAccounts; i++)
		{
			delete this->m_account[i];/////go to destructor of account.
			this->m_account[i] = nullptr;
		}
		delete[]this->m_account;/////destructor of arr.
		this->m_account = nullptr;
	}
}
///////////////////////////////////////accesess function
void Bank::SetBankName(const char* name)
{
	if (this->m_name!=nullptr)
	{
		delete this->m_name;
		this->m_name = nullptr;
	}
	this->m_name = strdup(name);
	////////this->m_name = new char[strlen(name) + 1];
	////////strcpy_s(this->m_name, strlen(name) + 1, name);
}
void Bank::SetAccount(Account** account, int numbeOfAccounts)
{
	if (this->m_account!=nullptr)
	{
		for (int i = 0; i < this->m_numbeOfAccounts; i++)
		{
			delete this->m_account[i];/////go to destructor of account.
			this->m_account[i] = nullptr;
		}
		delete[]this->m_account;////delete the arr.
		this->m_account = nullptr;
	}
	this->m_numbeOfAccounts = numbeOfAccounts;/////set new size.
	if (numbeOfAccounts>0 && account!=nullptr)
	{
		// ////////re alocate the arr of account
		this->m_account = new Account * [this->m_numbeOfAccounts];
		for (int i = 0; i < this->m_numbeOfAccounts; i++)
		{
			this->m_account[i] = new Account(*(account[i]));/////////go to copy constructor of Account.
		}
	}
	else
	{
		this->m_account = nullptr;
	}
	return;
}
void Bank::SetTotal(double total)
{
	this->m_totalBalance = total;
}
void Bank::SetCode(int code)
{
	this->m_bankCode = code;
}
const char* Bank::GetBankName() const
{
	return this->m_name;
}
Account** Bank::GetAccounts() const
{
	return this->m_account;
}
int	Bank::GetNumberOfAccounts() const
{
	return this->m_numbeOfAccounts;
}
double Bank::GetTotal() const
{
	return this->m_totalBalance;
}
int	Bank::GetCode() const
{
	return this->m_bankCode;
}
///////////////////////////////////Other Function
void Bank::AddAccount(const Account& account)
{
	//////At first search the account in the bank.
	for (int i = 0; i < this->m_numbeOfAccounts; i++)
	{
		if (this->m_account[i]->GetAccountNumber()==account.GetAccountNumber())
		{
			//////the account has found in the arr of the bank.
			return;
		}
	}
	//////the account has not found.
	/////alocate new temp arr
	Account** tempArr = new Account * [this->m_numbeOfAccounts + 1];
	for (int i = 0; i < this->m_numbeOfAccounts; i++)
	{
		tempArr[i] = this->m_account[i];//////assitmnet - save account only.
	}
	if (this->m_account!=nullptr)
	{
		delete[]this->m_account;////delete the arr it self
		this->m_account = nullptr;

	}
	this->m_numbeOfAccounts += 1;////increase the size.
	this->m_account = tempArr;/////new assitment
	this->m_account[this->m_numbeOfAccounts - 1] = new Account(account);///go to copy consturctor.
	this->m_totalBalance += account.GetBalance();////add the amount of the account to the total balance.
}
void Bank::AddAccount(const Person& per, double amount)
{
	//////at first create new account - by send person
	Account account(per, amount);////go to constructor of account.
	/////add to the arr of the bank
	/////At first diffine new arr.
	Account** tempArr = new Account * [this->m_numbeOfAccounts + 1];
	for (int i = 0; i < this->m_numbeOfAccounts; i++)
	{
		tempArr[i] = this->m_account[i];/////assitment - save account only
	}
	if (this->m_account!=nullptr)
	{
		delete[]this->m_account;/////delete the arr it selef
		this->m_account = nullptr;
	}
	this->m_account = tempArr;///////new assitmnet.
	this->m_numbeOfAccounts += 1;////increase the size
	this->m_account[this->m_numbeOfAccounts - 1] = new Account(account);////go to copy constructor of Account.
	this->m_totalBalance += amount;////add the amount of this account to the bank.
}
void Bank::AddPerson(const Person& newPerson, const Account& account, double amount)
{
	///////at first looking for the account in the bank
	for (int i = 0; i < this->m_numbeOfAccounts; i++)
	{
		if (this->m_account[i]->GetAccountNumber()==account.GetAccountNumber())
		{
			///////account has been found.
			///////the account is alredy in the bank - no need to add new account.
			/////send the function of AddPerson to handle of all from here!!
			double tempBalance = this->m_account[i]->GetBalance();////save the old balance
			this->m_account[i]->AddPerson(newPerson, amount);/////send the add persons to handel it.
			if (tempBalance!=this->m_account[i]->GetBalance())
			{
				///////the persons has been added.
				this->m_totalBalance += amount;/////up-date the total balance in all the bank.
			}
			return;
		}
	}
	this->AddAccount(newPerson, amount);//////send to the add cound function.
	//////the account has not found.
	//////diffine new one
	////////////Account tempAccount(newPerson, amount);/////go to the constructor of account.
	/////////////////diffine temp arr.
	////////////Account** TempArr = new Account * [this->m_numbeOfAccounts + 1];
	////////////for (int i = 0; i < this->m_numbeOfAccounts; i++)
	////////////{
	////////////	TempArr[i] = this->m_account[i];/////assitment - save the accounts in the bank.
	////////////}
	////////////if (this->m_account!=nullptr)
	////////////{
	////////////	delete[]this->m_account;/////delete the arr it selef
	////////////}
	////////////this->m_numbeOfAccounts += 1;////increase the size of the arr count
	////////////this->m_account = TempArr;/////new assitment.
	////////////this->m_account[this->m_numbeOfAccounts - 1] = new Account(account);/////go to copy constructor of the account.
	////////////this->m_totalBalance += amount;////up-date the total balance in the bank.

}
void Bank::DeleteAccount(const Account& account)
{
	//////////delete account on the bank
	////////At first looking for the accoumnt
	int found = -1;
	for (int i = 0; i < this->m_numbeOfAccounts; i++)
	{
		if (this->m_account[i]->GetAccountNumber()==account.GetAccountNumber())
		{
			//////the account has been found.
			found = i;
			break;
		}
	}
	if (found==-1)
	{
		/////the accound has not found
		return;
	}
	delete this->m_account[found];/////delete account.
	if (found==0)
	{
		/////this account was the only account
		this->m_numbeOfAccounts = 0;
		delete[]this->m_account;/////delete the all arr of account.
		this->m_account = nullptr;
		this->m_totalBalance -= account.GetBalance();/////reduse the total balance in the bank
		return;
	}
	this->m_account[found] = this->m_account[this->m_numbeOfAccounts - 1];////save the last account insted.
	/////diffine new arr for the account
	this->m_numbeOfAccounts -= 1;//////reduce the size of the accounts.
	Account** TempArr = new Account * [this->m_numbeOfAccounts];
	for (int i = 0; i < this->m_numbeOfAccounts; i++)
	{
		TempArr[i] = this->m_account[i];//////assitment - save the accounts.
	}
	if (this->m_account!=nullptr)
	{
		delete[]this->m_account;/////go to the destructor of account.
		this->m_account = nullptr;
	}
	this->m_account = TempArr;//////new assitment.
	this->m_totalBalance -= account.GetBalance();/////reduce the total balance in the bank
	return;
}
void Bank::DeletePerson(const Person& p)
{
	///////delete person from the bank
	double sumBalanceAccount = 0;
	for (int i = 0; i < this->m_numbeOfAccounts; i++)
	{
		this->m_account[i]->DeletePerson(p);/////send the function to delete person.
		if (this->m_account[i]->GetTotalPersons()==0)
		{
			//////need to the delete the account with the arr trasaction
			sumBalanceAccount += this->m_account[i]->GetBalance();////save the many.
			////////delete this->m_account[i];////go to the destructor of Account.
			this->DeleteAccount(*this->m_account[i]);//////delete the account!!!!

		}
	}
	this->m_totalBalance -= sumBalanceAccount;/////reduce of all balances we added!!.
}
