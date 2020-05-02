/*
Class Slot:
	stores information about slot: number of items, label (what Item)
Attributes:
label- name of slot
num_items - num of items in slot
is_empty - is slot empty
num - ID of an object
last_num - keeps the number of slots (filled)

Methods:
init_slot - slot validation
set_status - sets if slot is empty
get_status - returns if slot is empty
set_num - changes ID
get_num - returns ID
get_label - returns label of slot
set_label - sets label of slot
get_numItems - returns num of items
set_numItems - sets num of items

to_string - info about object converted to string

operators +=, -=, ++, -- changes the number of items, == - for checking if amount is the same
*/



#ifndef SLOT_H
#define SLOT_H
#define MAX_ITEMS 20
#define NUM_LETTERS 6
#define NUM_NUMBERS 5
#define NUM_ITEM_SLOTS 30 //num_letters * num_numbers
#define ITEM_LABEL 2
#define COIN_LABEL 20
#define NUM_COIN_SLOTS 6
#include <string>
#include <iostream>
#include <fstream>
#include "Item.h"
#include "Coin.h"


//      label:
//rows A, B, ... , F (6)
//columns 1, ... , 5

namespace Demo {

	class SlotBase
	{
	protected:

		std::string label;   //name of slot
		int num_items;     //num of items in slot
		bool is_empty;     //is slot empty
		int num;          //ID of an object
		static int last_num;
		void init_slot(std::string n, int i = 0);
		void set_status(bool s);//to ensure that user could not change status
		void set_num(int n);
		SlotBase(const SlotBase& s);
		SlotBase & operator=(const SlotBase & s);

	public:
		SlotBase(std::string n, int i);
		
		virtual ~SlotBase();

		//GETTERS
		std::string get_label() const;
		bool get_status() const;
		int get_numItems() const;
		int get_num() const;
		static int get_lastNum();

		//SETTERS
		virtual void set_label(std::string n) = 0;
		void set_numItems(int n);

		// OBJ INFO TO STRING
		virtual std::string to_string() = 0;


	};


	class SlotItem : public SlotBase
	{
	private:
		Item* item;

	public:
		SlotItem(char* s, double p, const std::string &l, int num);
		SlotItem(Item& i, std::string l, int num);
		virtual ~SlotItem();
		void set_label(std::string n);
		void set_item(Item& i);
		Item& get_item() const;
		std::string to_string();

		//OPERATOR OVERLOADING
		/*SlotItem operator+=(int);
		SlotItem operator-=(int);
		SlotItem operator++();
		SlotItem operator--();
		bool operator==(const SlotItem& a) const;

		// I/O OPERATOR OVERLOADING
		friend std::ostream& operator<<(std::ostream &o, const SlotItem &s);
		friend std::istream& operator>>(std::istream &i, SlotItem &s);*/
	};
	/*std::ostream& operator<<(std::ostream &o, const SlotItem &s);
	std::istream& operator>>(std::istream &i, SlotItem &s);*/



	class SlotCoin : public SlotBase
	{
	private:
		Coin* coin;
	public:
		SlotCoin(double p, const std::string &l, int num);
		SlotCoin(int p, const std::string &l, int num);
		SlotCoin(Coin& c,const std::string l, int num);
		virtual ~SlotCoin();
		void set_label(std::string n);
		void set_coin(Coin& i);
		Coin& get_value() const;
		std::string to_string();

		//OPERATOR OVERLOADING
		/*SlotCoin operator+=(int);
		SlotCoin operator-=(int);
		SlotCoin operator++();
		SlotCoin operator--();
		bool operator==(const SlotCoin& a) const;

		// I/O OPERATOR OVERLOADING
		friend std::ostream& operator<<(std::ostream &o, const SlotCoin &s);
		friend std::istream& operator>>(std::istream &i, SlotCoin &s);*/
	};
	/*std::ostream& operator<<(std::ostream &o, const SlotCoin &s);
	std::istream& operator>>(std::istream &i, SlotCoin &s);*/
}
#endif


