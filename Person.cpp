//////////////////// Course - OPP EX2
////////////////////Name - Nati Efraim
//////////////////// id - 315552810
#include "Person.h"
// ///////////////////////////constructor and destructor
Person::Person() :m_name(nullptr), m_id(0)
{

}
Person::Person(const char* name, int id) :m_id(id), m_name(nullptr)
{
	if (name!=nullptr)
	{
		//////////this->m_name = new char[strlen(name) + 1];
		//////////strcpy_s(this->m_name, strlen(name) + 1, name);
		//////this->m_name = _strdup(name);
		this->SetName(name);
	}
}
Person::Person(const Person& other) :m_id(other.m_id), m_name(nullptr)
{
	if (other.m_name!=nullptr)
	{
		//////////////this->m_name = new char[strlen(other.m_name) + 1];
		//////////////strcpy_s(this->m_name, strlen(other.m_name) + 1, other.m_name);
		//////this->m_name = _strdup(other.m_name);
		this->SetName(other.m_name);
	}
}
Person::~Person()
{
	if (this->m_name != nullptr)
	{
		delete this->m_name;
		this->m_name = nullptr;
	}
}
// //////////////////////acesess function
void Person::SetName(const char* newName)
{
	if (this->m_name!=nullptr)
	{
		delete this->m_name;
		this->m_name = nullptr;
	}
	////////this->m_name = new char[strlen(newName) + 1];
	////////strcpy_s(this->m_name, strlen(newName) + 1, newName);
	this->m_name = strdup(newName);
}
void Person::SetId(int newId)
{
	this->m_id = newId;
}
char* Person::GetName() const
{
	return this->m_name;
}
int	Person::GetId() const
{
	return this->m_id;
}