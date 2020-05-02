#include "Item.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <exception>
#include <stdexcept>
#include <cassert>
//#define assert(ignore) ((void) 0) //uncomment to turn off asserst
#define DEBUG //comment for constructor/destructor reports

namespace Demo {

	Item::Item(const char* n, double m)
	{
		set_name(n);
		set_price(m);
#ifndef DEBUG
		std::cout << "Constructor was called for : " << this->to_string() << std::endl;
#endif
		assert(price > 0 || name == NULL);
		assert(m == get_price()); //checking getter
	}


	Item::Item(const Item & i)
	{
		this->set_price(i.get_price());
		if (i.name)
		{
			int n_len = std::strlen(i.name) + 1;
			name = new char[n_len];

			for (int j = 0; j < n_len; ++j)
				name[j] = i.name[j];
		}
		else
			throw std::invalid_argument("Copying failed.");
	}

	Item & Item::operator=(const Item & i)
	{

		price = i.price;
		// check for self-assignment
		if (this == &i)
			return *this;

		// deallocating any value 
		delete[] name;

		int n_len = std::strlen(i.name) + 1;

		if (i.name)
		{
			name = new char[n_len];

			// do the copy 
			for (int j = 0; j < n_len; ++j)  //
			{
				name[j] = i.name[j];
			}
		}
		else
			throw std::invalid_argument("Assignment failed. Error in item name");

		return *this;
	}


	Item::~Item()
	{
#ifndef DEBUG
		std::cout << "Destructor was called for : " << this->to_string() << std::endl;
#endif
		delete[]name;

	}

	/*______________________GETTERS______________________*/
	double Item::get_price() const
	{
		return price;
	}

	char* Item::get_name() const
	{
		return name;
	}

	std::string Item::get_namestr() const
	{
		std::string temp(name);
		return temp;
	}
	/*______________________SETTERS______________________*/
	template<class T>
	void Item::set_price(T m)
	{
		int temp_m = m * 100;   //makes integer from floating point for easier validation
		if (temp_m % 5 != 0 || m <= 0 || m > MAX_PRICE)
		{
			throw std::invalid_argument("Invalid price!");
		}
		else
			this->price = m;
	}
	template void Item::set_price<double>(double m);

	void Item::set_name(const char* n)
	{
		if (*n == 0)
			throw std::invalid_argument("Name cannot be empty!");

		int n_len = std::strlen(n);

		if (n_len > MAX_CHAR)
			throw std::invalid_argument("Name is too long!");

		name = new char[n_len + 1]();  // \0 at the end

		for (int i = 0; i < n_len; ++i)
		{
			name[i] = n[i];
		}
	}


	/*_____________INFO ABOUT OBJ TO STRING______________*/

	std::string Item::to_string() const
	{
		std::stringstream s;
		std::string temp(name);
		s << temp << " " << price;
		return s.str();
	}


	/*_____________I/O OPERATOR OVERLOADING_______________*/

	std::ostream& operator<<(std::ostream &o, const Item &i)
	{
		o << i.to_string() << std::endl;
		return o;
	}

	std::istream& operator>>(std::istream &i, Item &s)
	{
		double price;
		std::string str;
		{
			i >> str;
			i >> price;
			if (i.fail())
			{
				i.clear();
				i.ignore(256, '\n');
				throw std::ios_base::failure("Input error");
			}
		}
		char *name_temp = new char[str.length() + 1]();
		strcpy_s(name_temp, str.length() + 1, str.c_str());
		s.set_price(price);
		s.set_name(name_temp);
		delete[] name_temp;
	}

	/*_____________OPERATOR OVERLOADING______________*/

	Item Item::operator+=(double n)
	{
		Item temp = *this;
		double temp_price = get_price();
		set_price(get_price() + n);
		assert(get_price() == (temp_price + n));
		return  temp;
	}

	Item Item::operator-=(double n)
	{
		Item temp = *this;
		set_price(get_price() - n);
		return  temp;
	}

	bool Item::operator==(const Item& a) const
	{
		if (this->price == a.price)
			return true;
		else
			return false;
	}
}