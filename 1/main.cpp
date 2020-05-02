
/*Vending machine simulator
Class Item - item object with name and price
Class Slot - label-what's inside a slot, num_items - number of items, is_empty - if slot is empty, num - for counting obects
Class CashMachine - coin handling mecganism. cent5...euro2 - number of coins, entry,return - is coin in input/return state,
entry1,return1 - value of input and change.

Edits:
2019/05/05........ created classes
2019/05/19.........test units/ asserts/ operators/ added to_string for all classes


*/


#include <iostream>
#include <string>
#include <cstdlib>
#include "CashBox.h"
#include "machine.h"


using namespace std;
using namespace Demo;


int main()
{

	Item s("cola", 3.5);
	cout << s.get_name() << s.get_price() << endl;
	Item d(s);
	cout << d.get_name() << d.get_price() << endl;
	Item r("play", 5.5);
	cout << r.to_string() << endl;
	r = s;
	cout << r.to_string() << endl;
	SlotItem a(r, "A4", 5);
	cout << a.to_string() << endl;
	Coin c(0.5);
	cout << c.get_coin() << endl;
	Coin f(c);
	cout << f.get_coin() << endl;
	SlotCoin cl(f, "0.5", 10);
	cout << cl.to_string() << endl;
	cout << a.to_string() << endl;
	CashBox m(cl, true, true);	
	m.put(5.0);
	cout << "cia" << endl;
	cout << m.get_coin(0.5) << endl;
	SlotCoin n(m.get_coin_slot(0.5));
	cout << n.to_string() << endl;
	//VendingMachine(m, a);   //must fix get_label from base class
	/*SlotBase s1("A3", 6);
	CashBox c1(12, 4, 9, 45);
	VendingMachine v1(c1);
	v1.set_slot(s1);*/
	//Slot class functionality
	/*try
	{
		Slot s1("A3", 6);
		Slot s2("B2", 4);
		//getters
		cout << "Info about object s1: " << s1.get_label() << " " << s1.get_numItems() << " status: " << s1.get_status() << endl;
		cout << "Info about object s2: " << s2.get_label() << " " << s2.get_numItems()<< " status: " << s2.get_status() << endl;

		//setters/getters
		s1.set_numItems(3);
		s1.set_label("B5");
		cout << "Info about object s1: " << s1.get_label() << " " << s1.get_numItems() << endl;

		//ID and total num (no setters)
		cout << "Total num of objects " << s1.get_lastNum() << endl;
		cout << "ID of s1 obj = " << s1.get_num() << "     ID of s2 obj = " << s2.get_num() << endl;

		// ++, --, +=, -=, == operators
		s1++;
		++s1;
		s2--;
		--s2;
		s1 -= 2;
		s2 += 1;
		//s1 and s2 num of items should be equal
		cout << s1.to_string() << endl;
		cout << s2.to_string() << endl;
		if (s1 == s2)
			cout << "Objects are equal." << endl;
		cout << "Enter info about slot " << endl;
		cin >> s1;
		cout << s1 << endl;
		s1.set_label("hello"); //exception
	}
	catch (string invalid_argument)
	{
		cout << "Slot class exception caught. "  << endl;
	}



	//Cashbox class functionality
	try
	{
		CashBox c1(12, 4, 9, 45);

		//getters
		cout << "Info about c1 obj: " << c1.get_5() << " " << c1.get_10() << " " << c1.get_20() << " " << c1.get_50() << " "
			<< c1.get_e1() << " " << c1.get_e2() << " " << endl;

		//setters
		c1.set_5(5);
		c1.set_10(10);
		c1.set_20(20);
		c1.set_50(50);
		c1.set_e1(1);
		c1.set_e2(2);
		cout << "Info about c1 obj: " << c1.to_string() << endl;

		//entry/return boxes
		c1.put(0.1);
		c1.put(0.5);   //input = 0.1 + 0.5;
		cout << "input: " << c1.get_input() << " status " << c1.get_entry_status() << endl;
		c1.put(0.15);
		cout << "return: " << c1.get_return() << " status " << c1.get_return_status() << endl;

		// ++, --, +=, -= operators
		CashBox c2(5, 5, 5, 5, 5, 5);
		c2++;
		++c2;
		c2--;
		--c2;
		c2 += 10;
		c2 -= 5;
		cout << "Info about object c2: " << c2.to_string() << endl;
		cout << "Enter nums of coins: " << endl;
		cin >> c2;
		cout << c2 << endl;
		c2.set_10(-9); //exception
	}
	catch (string invalid_argument)
	{
		cout << "Cashbox class exception caught."  << endl;
	}

	//Item class functionality

	try
	{
		Item *list[3];
		list[0] = new Item("Coca", 1.5);
		list[1] = new Item("Cola", 1.8);
		list[2] = new Item("Zero", 2.5);
		for (int i = 0; i < 3; ++i)
		{
			cout << list[i]->to_string() << endl;
		}

		//setters/getters
		list[0]->set_price(2.5);
		list[0]->set_name("cookie");
		cout << "Info about first obj in array " << list[0]->get_name() << " " << list[0]->get_price() << endl;
		for (int i = 0; i < 3; ++i)
		{
			delete list[i];
		}

		Item i1("Snickers", 0.5);
		cin >> i1;  //set price to 3.5 for equality check
		cout << "Enter info about an item: " << endl;
		cout << i1.to_string() << endl;
		Item i2("M&M's", 2.5);

		//+=, -=, == operators
		i2 += 1.0;
		if (i1 == i2)
			cout << "Price is equal" << endl;
		i1 -= 2.1;
		if (!(i1 == i2))
			cout << "Not equal" << endl;
		cout << i1 << endl;

		i1.set_price(-9); //throws exception
	}
	catch (string invalid_argument)
	{
		cout << "Item class exception caught."  << endl;
	}*/
	system("pause");
	return 0;
}

