#include "Coin.h"
#include <exception>
#include <stdexcept>
#include <iostream>


namespace Demo {
	template<class T>
	void Coin::set_coin(T val)
	{
		int x = 0;
		if (val >= 5)
			x = val;
		else if (val > 0.05 && val < 2)
			x = (int)(val * 100);
		else
			throw std::invalid_argument("Invalid value of coin");

		switch (x)
		{
		case CENT5:
			value = CENT5;
			break;
		case CENT10:
			value = CENT10;
			break;
		case CENT20:
			value = CENT20;
			break;
		case CENT50:
			value = CENT50;
			break;
		case EURO1:
			value = EURO1;
			break;
		case EURO2:
			value = EURO2;
			break;
		default:
			throw std::invalid_argument("Invalid value of coin");
		}
	}
	template void Coin::set_coin<double>(double val);
	template void Coin::set_coin<int>(int val);

	Coin::Coin(double val)
	{
		this->set_coin(val);
	}

	Coin::Coin(int val)
	{
		this->set_coin(val);
	}

	Coin::~Coin()
	{

	}

	Coin::Coin(Coin & c)
	{
		this->set_coin(c.get_coin());
	}

	int Coin::get_coin() const
	{
		return value;
	}

	std::string Coin::to_string() const
	{
		std::stringstream s;
		s << value;
		return s.str();
	}

	std::ostream& operator<<(std::ostream &o, const Coin &c)
	{
		o << c.to_string() << std::endl;
		return o;
	}

	std::istream& operator>>(std::istream &i, Coin &c)  //works only with ints
	{
		int val;
		{
			i >> val;

			if (i.fail())
			{
				i.clear();
				i.ignore(256, '\n');
				throw std::ios_base::failure("Input error");
			}
		}
		c.set_coin(val);
	}
}
