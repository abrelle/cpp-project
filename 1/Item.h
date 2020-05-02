/*
Class Item:
	stores information about an item (name and price).
Attributes:
price - price of an item
name - name of an item

Methods:
get_price - returns price of an item
set_price - sets price of an item
get_name - returns name of an item
set_name - sets name of an item
to_string - info about object converted to string

operators +=, -= changes the price, == - for checking if price is the same
*/


#ifndef ITEM_H
#define ITEM_H
#define MAX_CHAR 50
#define MAX_PRICE 20
#include <string>

namespace Demo {

	class Item
	{
	private:

		double price;   //price of an item
		char *name;    //name of an item

	public:

		Item(const char *source, double d);
		Item(const Item& i);
		Item& operator= (const Item& i);    //checks if prices are equal
		~Item();

		//PRICE SETTER/GETTER
		double get_price() const;
		template<class T>
		void set_price(T m);

		//NAME SETTER/GETTER
		char* get_name() const;
		void set_name(const char* n);
		std::string get_namestr() const;

		//INFO ABOUT OBJ TO STRING
		std::string to_string() const;

		// I/O OPERATOR OVERLOADING
		friend std::ostream& operator<<(std::ostream &o, const Item &i);
		friend std::istream& operator>>(std::istream &o, Item &i);

		//OPERATOR OVERLOADING
		Item operator+=(double);
		Item operator-=(double);
		bool operator==(const Item& a) const;
	};

	std::ostream& operator<<(std::ostream &o, const Item &i);
	std::istream& operator>>(std::istream &o, Item &i);
}
#endif
