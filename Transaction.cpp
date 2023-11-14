//////////////////// Course - OPP EX2
////////////////////Name - Nati Efraim
//////////////////// id - 315552810
#include "Transaction.h"
Transaction::Transaction(Account* s, Account* d, double amount, const char* date)
	:m_amount(amount), m_date(nullptr), m_source(s), m_destination(d)
{
	if (this->m_date != nullptr)
	{
		delete this->m_date;
		this->m_date = nullptr;
	}
	////this->m_date = new char[strlen(date) + 1];
	////strcpy_s(this->m_date, strlen(date) + 1, date);
	this->SetDate(date);

	//////this->m_source = s;
	//////this->m_destination = d;


}
Transaction::Transaction(const Transaction& other)
	:m_amount(other.m_amount), m_date(nullptr), m_source(other.m_source), m_destination(other.m_destination)
{
	if (this->m_date!=nullptr)
	{
		delete this->m_date;
		this->m_date = nullptr;
	}
	this->SetDate(other.m_date);
	////////this->m_date = new char[strlen(other.m_date) + 1];
	////////strcpy_s(this->m_date, strlen(other.m_date) + 1, other.m_date);
	////////////////this->m_source = other.m_source;
	////////////////this->m_destination = other.m_destination;
}
/////////////////////////////////////////////Accesess function.
void Transaction::SetSource(Account* src)
{
	this->m_source = src;//////shallow copy.
}
void Transaction::SetDes(Account* dst)
{
	this->m_destination = dst;////shallow copy.
}
void Transaction::SetAmount(double amount)
{
	this->m_amount = amount;
}
void Transaction::SetDate(const char* date)
{
	if (this->m_date!=nullptr)
	{
		delete this->m_date;
		this->m_date = nullptr;
	}
	//////////this->m_date = new char[strlen(date) + 1];
	//////////strcpy_s(this->m_date, strlen(date) + 1, date);
	this->m_date = strdup(date);
}
Account* Transaction::GetSource() const
{
	return this->m_source;
}
Account* Transaction::GetDes() const
{
	return this->m_destination;
}
double	Transaction::GetAmount() const
{
	return this->m_amount;
}
char* Transaction::GetDate() const
{
	return this->m_date;
}