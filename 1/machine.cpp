#include "machine.h"
#include <string>


using namespace std;

namespace Demo {
	
	void VendingMachine::set_is_init(bool status)
	{
		if (is_init == false)
		{
			for (int i = 0; i < NUM_ITEM_SLOTS; ++i)
			{
				items[i] = NULL;
			}
		}
		is_init = status;
	}

	VendingMachine::VendingMachine(CashBox& i, SlotItem& s)
	{
		set_is_init(true);
		box = new CashBox(i);
		set_item_slot(s);
	}

	VendingMachine::~VendingMachine()
	{
		for (int i = 0; i < NUM_ITEM_SLOTS; ++i)
		{
			delete items[i];
		}
	
	}
	void VendingMachine::set_item_slot(SlotItem & b)
	{
		if (is_open == false)
			throw std::invalid_argument("Vending machine is closed.");

		string slot_label = b.get_label();   //e.g. AP
		std::cout << slot_label << std::endl;
		int first_char = (int)slot_label[0] - (int)'A'; //'A' = 0; 'B' = 1....
		int second_char = (int)slot_label[1] - (int)'0';// 1 = 0, 2 = 1... 
		int index = first_char * NUM_LETTERS + second_char;
		SlotItem* temp = new SlotItem(b);
		items[index] = temp;
	}

	void VendingMachine::set_status(bool status)
	{
		is_open = status;
	}

	void VendingMachine::change_coin(SlotCoin& co)
	{
		if (is_open == false)
			throw std::invalid_argument("Vending machine is closed.");

		box->set_coin(co);
	}

	int VendingMachine::get_coinNum(double val) const
	{
		int num = (box->get_coin_slot(val)).get_numItems();
		return num;
	}

	SlotItem& VendingMachine::get_item_slot(const char* name) const
	{
		if (is_open == false)
			throw std::invalid_argument("Vending machine is closed.");

		for (int i = 0; i < NUM_ITEM_SLOTS; ++i)
		{
			if (items[i]->get_label() == name)
			{
				
				SlotItem temp(items[i]->get_item(), items[i]->get_label(), items[i]->get_numItems());
				return temp;
			}
		}
		throw std::invalid_argument("Item does not exist");
	}

	bool VendingMachine::get_status() const
	{
		return is_open;
	}

	void VendingMachine::add_coin(double add)
	{
		if (is_open == true)
			throw std::invalid_argument("Vending machine is open.");

		box->put(add);
	}

	double VendingMachine::return_money() const
	{
		if (is_open == true)
			throw std::invalid_argument("Vending machine is open.");

		double all = box->get_input() + box->get_return();

		box->set_entry(0);
		box->set_entry(0);

		return all;
	}

	void VendingMachine::choice(std::string & a)
	{
		if (is_open == true)
			throw std::invalid_argument("Vending machine is open.");

		if (a.length() != ITEM_LABEL)
			throw std::invalid_argument("Error in label");

		int first_char = (int)a[0] - (int)'A'; //'A' = 0; 'B' = 1....
		int second_char = (int)a[1] - (int)'0';// 1 = 0, 2 = 1... 
		int index = first_char * NUM_LETTERS + second_char;
		if (index >= 0 || index >= NUM_ITEM_SLOTS)
		{
			if (items[index] != NULL)
			{
				if (items[index]->get_numItems() > 0 || box->get_input() >= (items[index]->get_item()).get_price())
				{
					items[index]->set_numItems(items[index]->get_numItems() - 1);
					box->set_entry(box->get_input() - (items[index]->get_item()).get_price());
				}
			}
		}
		else
			throw std::invalid_argument("Wrong label");

		
	}

}