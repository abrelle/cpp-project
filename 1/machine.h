
#ifndef MACHINE_H
#define MACHINE_H

#include "CashBox.h"
#include<vector>

namespace Demo
{
	class VendingMachine
	{
	private:
		bool is_open; //if true - you can add items and change amount of coins, if false - you can buy stuff
		SlotItem* items[NUM_ITEM_SLOTS];
		CashBox* box;
		bool is_init = false;
		VendingMachine(const VendingMachine& vm);
		VendingMachine& operator =(const VendingMachine& vm);
		void set_is_init(bool);

	public:
		VendingMachine(CashBox& box1, SlotItem& s);
		~VendingMachine();
		void set_item_slot( SlotItem& slot);
		void set_status(bool);
		void change_coin(SlotCoin& co);
		int get_coinNum(double val) const;
		bool get_status() const;
		void add_coin(double add);
		double return_money() const;
		void choice( std::string& a);
		SlotItem& get_item_slot(const char* name) const;

	};
}

#endif
