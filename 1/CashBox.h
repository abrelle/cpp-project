/*
Class CashBox:
	stores coins and has mechanism of input/return values.
Attributes:
coins[0] - ..
return1 = 0 - for return
entry_status - if coin is entered
return_status - changes status if there is change or wrong coin


Methods:
set_entry - sets input
get_entry - returns input
set_return - sets return
get_return - returns change
set_entry_status - sets entry status
get_entry_status - gets entry status
set_return_status - sets return status
get_return_status - gets return status
init_coins - for adding coins/validation

to_string - info about object converted to string 

get_5...get_e2 - returs amount of certain coins
set_5...set_e2 - sets amount of certain coins

put - validation of input - users input for buying
operators +=, -= , ++, -- changes the amount of all coins
*/

#ifndef CASHBOX_H
#define CASHBOX_H
#include <string>
#include <vector>
#include "Slot.h"

namespace Demo {
	enum Coins {CENT5 = 5, CENT10 = 10, CENT20 = 20, CENT50 = 50, EURO1 = 100, EURO2 = 200};
	enum CoinIndex {INDEX5, INDEX10, INDEX20, INDEX50, INDEX1, INDEX2};
	class CashBox
	{
	private:

		std::vector<SlotCoin> c;
		double entry1 = 0;   //what input
		double return1 = 0;    //what return

		bool entry_status;      //if coin is entered      status cannot be set by user
		bool return_status;       // if wrong coin

		void set_entry_status(bool v);
		void set_return_status(bool v);

		void init_box(SlotCoin &sc);

	public:
		CashBox(SlotCoin &sc, bool es, bool rs);
		~CashBox();
		CashBox(const CashBox& s);
		CashBox & operator=(const CashBox & s);
		void put(double p);  //what kind of coins entered/validation/setters for entry/return inside... 10 cents = 0.1, 1 euro = 1 
		//std::string to_string() const;

		void set_entry(double v);
		void set_return(double v);

		double get_input() const;
		double get_return() const;
		bool get_return_status() const;
		bool get_entry_status() const;

		int get_coin(double m) const;
		void set_coin(SlotCoin& sc);
		SlotCoin& get_coin_slot(double m);

		/*friend std::ostream& operator<<(std::ostream &o, const CashBox &c);
		friend std::istream& operator>>(std::istream &o, CashBox &c);*/

		//OPERATOR OVERLOADING
		/*CashBox& operator++();   // Prefix increment operator
		CashBox operator++(int);     // Postfix increment operator
		CashBox& operator--();    // Prefix decrement operator.
		CashBox operator--(int);    // Postfix decrement operator.
		CashBox operator+=(int);
		CashBox operator-=(int);*/
	};

	/*std::ostream& operator<<(std::ostream &o, const CashBox &c);
	std::istream& operator>>(std::istream &o, CashBox &c);*/
}
#endif

