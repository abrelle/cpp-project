#include "Slot.h"
#include <cassert>
#include <sstream>
#include <iostream>
#include <exception>
#include <stdexcept>
//#include <stdexcept>
using namespace std;
//#define assert(ignore) ((void) 0) //uncomment to turn off asserst
#define DEBUG //comment for constructor/destructor reports

namespace Demo {

	/************************SlotBase class implementation******************************/


	void SlotBase::init_slot(std::string n, int i)
	{

		this->set_numItems(i);
		set_num(++last_num);
	}


	SlotBase::SlotBase(const SlotBase & s)
	{
		label = s.label;
		num_items = s.num_items;
		is_empty = s.is_empty;
		num = s.num;
		last_num = s.last_num;
	}

	SlotBase & SlotBase::operator=(const SlotBase & s)
	{
		if (this == &s)
			return *this;
		
	}

	SlotBase::SlotBase(std::string n, int i)
	{
		init_slot(n, i);
#ifndef DEBUG
		std::cout << "Constructor was called for : slotbasw" << std::endl;
#endif
	}

	SlotBase::~SlotBase()
	{
#ifndef DEBUG
		std::cout << "Destructor was called for : slotbase" << std::endl;
#endif
	}

	/*______________________SETTERS______________________*/

	int SlotBase::last_num = 0;  //!!!!!!!!!!


	void SlotBase::set_status(bool n)
	{
		is_empty = n;
	}


	void SlotBase::set_numItems(int i)
	{
		if (i > 0 && i <= MAX_ITEMS)
		{
			set_status(false);  //slot is not empty
			assert(this->is_empty == false);
			num_items = i;
		}
		else if (i == 0)
		{
			set_status(true);  //slot is empty
			assert(this->is_empty == true);
			num_items = 0;
		}
		else
		{
			set_status(true);
			assert(this->is_empty == true);
			throw std::invalid_argument("Invalid number of items in slot");
		}
	}


	void SlotBase::set_num(int n)
	{
		num = n;
	}

	/*______________________GETTERS______________________*/

	std::string SlotBase::get_label() const
	{
		return label;
	}


	bool SlotBase::get_status() const
	{
		return is_empty;
	}

	int SlotBase::get_numItems() const
	{
		return num_items;
	}

	int SlotBase::get_lastNum()
	{
		return last_num;
	}

	int SlotBase::get_num() const
	{
		return num;
	}

	/*****************************SlotItem class implementation**********************************/

	SlotItem::SlotItem(char* s, double p, const std::string & l, int num) : SlotBase(l, num), item(new Item(s,p))
	{

		if (item == NULL)
		{
			throw std::invalid_argument("Failed Item object");
		}
#ifndef DEBUG
		std::cout << "Constructor was called for item : " << this->to_string() << std::endl;
#endif
	}

	SlotItem::SlotItem(Item & i, std::string l, int num) : SlotBase(l, num)
	{
		item = NULL;
		item = new Item(i.get_name(), i.get_price()); //CHECK
		if (item == NULL)
		{
			throw std::invalid_argument("Failed Item (&) object");
		}
#ifndef DEBUG
		std::cout << "Constructor was called for item: " << this->to_string() << std::endl;
#endif
	}

	SlotItem::~SlotItem()
	{
#ifndef DEBUG
		std::cout << "DEsstructor was called for item : " << this->to_string() << std::endl;
#endif
		delete item;
	}

	/*__________________Setters______________________*/

	void SlotItem::set_label(std::string n)
	{
		if (n.empty() || n.length() != ITEM_LABEL)
		{
			throw std::invalid_argument("Invalid lenght of label.");
		}
		else if (n[0] < 65 || n[0] > 70)   //ascii values "A" = 65 ..... "F" = 70
		{
			throw std::invalid_argument("First character must be upper letter A...F.");
		}
		else if ((int)n[1] < 49 || (int)n[1] > 53)   //ascii values "1" = 49 .... "5" = 53
		{
			throw std::invalid_argument("Second character must be a number from 1-5.");
		}
		else
			label = n;
	}


	void SlotItem::set_item(Item & i)
	{
		item = NULL;
		item = new Item(i.get_name(), i.get_price()); //CHECK
		if (item == NULL)
		{
			throw std::invalid_argument("Failed Item (&) object");
		}

	}

	Item & SlotItem::get_item() const
	{
		return *item;
	}

	std::string SlotItem::to_string() 
	{
		std::stringstream s;
		s << item->get_name() << " " << item->get_price() << " " << label << " " << num_items;
		return s.str();
	}
	/*
	SlotItem SlotItem::operator+=(int a)
	{
		SlotItem temp = *this;
		int temp_num = this->get_numItems();
		SlotBase::set_numItems(temp_num + a);
		assert(SlotBase::get_numItems() == (temp_num + a));
		return  temp;
	}

	SlotItem SlotItem::operator-=(int a)
	{
		SlotItem temp = *this;
		int temp_num = this->get_numItems();
		SlotBase::set_numItems(temp_num - a);
		assert(SlotBase::get_numItems() == (temp_num - a));
		return  temp;
	}

	SlotItem SlotItem::operator++()
	{
		SlotItem temp = *this;
		int temp_num = this->get_numItems();
		SlotBase::set_numItems(temp_num + 1);
		assert(SlotBase::get_numItems() == (temp_num + 1));
		return  temp;
	}

	SlotItem SlotItem::operator--()
	{
		SlotItem temp = *this;
		int temp_num = this->get_numItems();
		SlotBase::set_numItems(temp_num - 1);
		assert(SlotBase::get_numItems() == (temp_num - 1));
		return  temp;
	}

	bool SlotItem::operator==(const SlotItem & a) const
	{
		if (this->num_items == a.get_numItems())
			return true;
		else
			return false;
	}

	std::ostream & operator<<(std::ostream & o, SlotItem & s)
	{
		o << s.to_string() << std::endl;
		return o;
	}

	std::istream & operator>>(std::istream & i, SlotItem & s)
	{
		int temp_num;
		double price;
		std::string temp_name;
		std::string temp_label;
		{
			i >> temp_name;
			i >> price;
			i >> temp_label;
			i >> temp_num;
			if (i.fail())
			{
				i.clear();
				i.ignore(256, '\n');
				throw std::ios_base::failure("Input error");
			}
		}
		Item t(temp_name, price);
		s.set_item(t);
		s.set_label(temp_label);
		s.set_numItems(temp_num);
	}
	*/


	/********************************CoinSlot implementation*************************************/

	SlotCoin::SlotCoin(double p, const std::string & l, int num) : SlotBase(l, num)
	{
		coin = NULL;
		coin = new Coin(p);
		if (coin == NULL)
			throw std::invalid_argument("Coin slot object failed");
#ifndef DEBUG
		std::cout << "Constructor was called for coin : " << this->to_string() << std::endl;
#endif
	}

	SlotCoin::SlotCoin(int p, const std::string & l, int num) : SlotBase(l, num)
	{
		coin = NULL;
		coin = new Coin(p);
		if (coin == NULL)
			throw std::invalid_argument("Cooin slot (int) failed.");
#ifndef DEBUG
		std::cout << "Constructor was called for coin: " << this->to_string() << std::endl;
#endif
	}

	SlotCoin::SlotCoin(Coin & c, const std::string l, int num) : SlotBase(l, num)
	{
		coin = NULL;
		coin = new Coin(c);
		if (coin == NULL)
			throw std::invalid_argument("Coin slot object (&) failed.");
#ifndef DEBUG
		std::cout << "Constructor was called for coin: " << this->to_string() << std::endl;
#endif
	}

	SlotCoin::~SlotCoin()
	{
#ifndef DEBUG
		std::cout << "Deastructor was called for : coin" << this->to_string() << std::endl;
#endif
		delete this->coin;
	}

	/*___________SETTERS_______________*/

	void SlotCoin::set_label(std::string n)
	{
		if (n.empty() || n.length() >= COIN_LABEL)
		{
			throw std::invalid_argument("Invalid lenght of label.");
		}
		else
			label = n;
	}

	void SlotCoin::set_coin(Coin & i)
	{
		coin = NULL;
		coin = new Coin(i);
		if (coin == NULL)
			throw std::invalid_argument("Setting coin slot object (&) failed.");
	}

	Coin & SlotCoin::get_value() const
	{
		return *coin;
	}

	std::string SlotCoin::to_string()
	{
		std::stringstream s;
		s << coin->get_coin() << " " << label << " " << num_items;
		return s.str();
	}

	/*____________________Operator overloading______________________*/

	/*SlotCoin SlotCoin::operator+=(int a)
	{
		SlotCoin temp = *this;
		int temp_num = this->get_numItems();
		temp.set_numItems(temp_num + a);
		cout << temp.get_numItems() << endl;
		return temp;
	}

	SlotCoin SlotCoin::operator-=(int a)
	{
		SlotCoin temp = *this;
		int temp_num = this->get_numItems();
		SlotBase::set_numItems(temp_num - a);
		assert(SlotBase::get_numItems() == (temp_num - a));
		return  temp;
	}

	SlotCoin SlotCoin::operator++()
	{
		SlotCoin temp = *this;
		int temp_num = this->get_numItems();
		temp.set_numItems(temp_num + 1);
		assert(temp.get_numItems() == (temp_num + 1));
		return temp;
	}

	SlotCoin SlotCoin::operator--()
	{
		SlotCoin temp = *this;
		int temp_num = this->get_numItems();
		SlotBase::set_numItems(temp_num - 1);
		assert(SlotBase::get_numItems() == (temp_num - 1));
		return  temp;
	}

	bool SlotCoin::operator==(const SlotCoin & a) const
	{
		if (this->num_items == a.get_numItems())
			return true;
		else
			return false;
	}

	std::ostream & operator<<(std::ostream & o,  SlotCoin & s)
	{
		o << s.to_string() << std::endl;
		return o;
	}

	std::istream & operator>>(std::istream & i, SlotCoin & s)
	{
		double val;
		int temp_num;
		std::string temp_label;
		{
			i >> val;
			i >> temp_label;
			i >> temp_num;
			if (i.fail())
			{
				i.clear();
				i.ignore(256, '\n');
				throw std::ios_base::failure("Input error");
			}
		}
		Coin t(val);
		s.set_coin(t);
		s.set_label(temp_label);
		s.set_numItems(temp_num);
	}
*/
}