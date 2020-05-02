#include "CashBox.h"
#include <cassert>
#include <iostream>
#include <sstream>
#include <fstream>
#include <exception>
#include <stdexcept>
//#define assert(ignore) ((void) 0) //uncomment to turn off asserst
#define DEBUG //comment for constructor/destructor reports

namespace Demo {

	
	CashBox::CashBox(SlotCoin &sc, bool es = false ,bool rs = false)
	{
		
		#ifndef DEBUG
				std::cout << "Constructor was called for : cashbox " << std::endl;
		#endif
		
		init_box(sc);

		assert(this->entry_status == false);
		assert(this->return_status == false);
	}
	
	void CashBox::init_box(SlotCoin &sc)
	{
		entry1 = false;
		return1 = false;

		if (c.size() > NUM_COIN_SLOTS)
			throw std::invalid_argument("Number of slots is full.");
		set_coin(sc);
	}

	CashBox::~CashBox()
	{
#ifndef DEBUG
		std::cout << "Destructor was called for : "  << std::endl;
#endif
		c.clear();
	}

	CashBox::CashBox(const CashBox & s)
	{
		int size = s.c.size();
		for (int i = 0; i < size; ++i)
		{
			this->c.push_back(s.c[i]);
		}
		entry_status = s.get_entry_status();
		return_status = s.get_return_status();
		entry1 = s.get_input();
		return1 = s.get_return();
	}

	CashBox & CashBox::operator=(const CashBox & s)
	{
		entry_status = s.get_entry_status();
		return_status = s.get_return_status();
		entry1 = s.get_input();
		return1 = s.get_return();
		// check for self-assignment
		if (this == &s)
			return *this;

		// deallocating any value 
		c.clear();

		int size = s.c.size();

		if (size)
		{
			for (int i = 0; i < size; ++i)
			{
				this->c.push_back(s.c[i]);
			}
		}
		else
			throw std::invalid_argument("Assignment failed. Error in item name");

		return *this;
	}

	/*______________________GETTERS______________________*/
	double CashBox::get_input() const
	{
		return entry1;
	}
	double CashBox::get_return() const
	{
		return return1;
	}
	int CashBox::get_coin(double sk) const
	{
		int x = (int)(sk * 100);
		int size = c.size();
		for (int i = 0; i < size; ++i)
		{
			Coin temp = c[i].get_value();
			if (temp.get_coin() == x)
				return c[i].get_numItems();
		}
		return 0;
	}
	
	bool CashBox::get_return_status() const
	{
		return return_status;
	}
	bool CashBox::get_entry_status() const
	{
		return entry_status;
	}
	/*______________________SETTERS______________________*/

	void CashBox::set_coin(SlotCoin& sc)
	{
		Coin temp_x = sc.get_value();
		int x = temp_x.get_coin();
		int index = 0;
		switch (x)
		{
		case CENT5:
			break;
		case CENT10:
			break;
		case CENT20:
			break;
		case CENT50:
			break;
		case EURO1:
			break;
		case EURO2:
			break;
		default:
			throw std::invalid_argument("Invalid value of coin");
		}
		c.push_back(sc);
	}

	SlotCoin& CashBox::get_coin_slot(double m)
	{
		int size = c.size();
		int int_value = (int)(m * 100);
		for (int i = 0; i < size; ++i)
		{
			Coin temp = c[i].get_value();
			if (int_value == temp.get_coin())
			{
				SlotCoin& myObject = c[i];
				return myObject;
			}		
		}
		throw std::invalid_argument("This coin does not exist.");
	}


	void CashBox::set_entry_status(bool v)
	{
		entry_status = v;
	}

	void CashBox::set_return(double v)
	{
		if (v < 0)
			throw std::invalid_argument("exception");
		return1 = v;
	}

	void CashBox::set_entry(double v)
	{
		if (v < 0)
			throw std::invalid_argument("exception");

		entry1 = v;
	}

	void CashBox::set_return_status(bool v)
	{
		return_status = v;
	}

	void CashBox::put(double c)
	{
		if (c == 0.1 || c == 0.05 || c == 0.2 || c == 0.5 || c == 1 || c == 2)
		{
			entry1 += c;
			set_entry_status(true);
			set_return_status(false);
			assert(entry_status == true);
			assert(return_status == false);
		}
		else
		{
			return1 += c;
			set_entry_status(false);
			set_return_status(true);
			assert(entry_status == false);
			assert(return_status == true);
		}
	}
	/*std::string CashBox::to_string() const
	{
		std::stringstream s;
		s <
		return s.str();
	}


	std::ostream& operator<<(std::ostream &o, const CashBox &c)
	{
		o << c.to_string() << std::endl;
		return o;
	}

	std::istream& operator>>(std::istream &i, CashBox &c)
	{
		int cent5;
		int cent10;
		int cent20;
		int cent50;
		int euro1;
		int euro2;
		{
			i >> cent5;
			i >> cent10;
			i >> cent20;
			i >> cent50;
			i >> euro1;
			i >> euro2;
			if (i.fail())
			{
				i.clear();
				i.ignore(256, '\n');
				throw std::ios_base::failure("Input error");
			}
		}
		c.set_coin(cent5, 0.05);
		c.set_coin(cent10, 0.1);
		c.set_coin(cent20, 0.2);
		c.set_coin(cent50, 0.5);
		c.set_coin(euro1, 1.0);
		c.set_coin(euro2, 2.0);
	}

	CashBox& CashBox::operator++()
	{
		CashBox temp = *this;
		int temp2 = this->get_coin(0.2);
		set_coin(get_coin(0.05) + 1, 0.05);
		set_coin(get_coin(0.1) + 1, 0.1);
		set_coin(get_coin(0.2) + 1, 0.2);
		set_coin(get_coin(0.5) + 1, 0.5);
		set_coin(get_coin(1.0) + 1, 1.0);
		set_coin(get_coin(2.0) + 1, 2.0);
		;
		
		temp2++;
		assert(temp2 == this->get_coin(0.2));
		return *this;
	}

	CashBox CashBox::operator++(int)
	{
		CashBox temp = *this;
		int temp2 = this->get_coin(1.0);
		set_coin(get_coin(0.05) + 1, 0.05);
		set_coin(get_coin(0.1) + 1, 0.1);
		set_coin(get_coin(0.2) + 1, 0.2);
		set_coin(get_coin(0.5) + 1, 0.5);
		set_coin(get_coin(1.0) + 1, 1.0);
		set_coin(get_coin(2.0) + 1, 2.0);
		temp2++;
		assert(temp2 == this->get_coin(1.0));
		return temp;
	}

	CashBox& CashBox::operator--()
	{
		CashBox temp = *this;
		int temp2 = this->get_coin(2.0);
		set_coin(get_coin(0.05) - 1, 0.05);
		set_coin(get_coin(0.1) - 1, 0.1);
		set_coin(get_coin(0.2) - 1, 0.2);
		set_coin(get_coin(0.5) - 1, 0.5);
		set_coin(get_coin(1.0) - 1, 1.0);
		set_coin(get_coin(2.0) - 1, 2.0);
		temp2++;
		assert(temp2 == this->get_coin(2.0));
		return *this;
	}

	CashBox CashBox::operator--(int)
	{
		CashBox temp = *this;
		int temp2 = this->get_coin(0.5);
		set_coin(get_coin(0.05) - 1, 0.05);
		set_coin(get_coin(0.1) - 1, 0.1);
		set_coin(get_coin(0.2) - 1, 0.2);
		set_coin(get_coin(0.5) - 1, 0.5);
		set_coin(get_coin(1.0) - 1, 1.0);
		set_coin(get_coin(2.0) - 1, 2.0);
		temp2++;
		assert(temp2 == this->get_coin(0.5));
		return temp;
	}
	CashBox CashBox::operator+=(int n)
	{
		CashBox temp = *this;
		int temp2 = this->get_coin(0.5);
		set_coin(get_coin(0.05) + n, 0.05);
		set_coin(get_coin(0.1) + n, 0.1);
		set_coin(get_coin(0.2) + n, 0.2);
		set_coin(get_coin(0.5) + n, 0.5);
		set_coin(get_coin(1.0) + n, 1.0);
		set_coin(get_coin(2.0) + n, 2.0);
		temp2 += n;
		assert(temp2 == this->get_coin(0.5));
		return temp;
	}
	CashBox CashBox::operator-=(int n)
	{
		CashBox temp = *this;
		int temp2 = this->get_coin(0.1);
		set_coin(get_coin(0.05) - n, 0.05);
		set_coin(get_coin(0.1) - n, 0.1);
		set_coin(get_coin(0.2) - n, 0.2);
		set_coin(get_coin(0.5) - n, 0.5);
		set_coin(get_coin(1.0) - n, 1.0);
		set_coin(get_coin(2.0) - n, 2.0);
		temp2 -= n;
		assert(temp2 == this->get_coin(0.1));
		return temp;
	}*/
}
