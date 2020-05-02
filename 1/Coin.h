#ifndef COIN_H
#define COIN_H
#include <string>
#include <sstream>

namespace Demo {
	class Coin
	{
	private:

		int value; //in cents
		enum Coins { CENT5 = 5, CENT10 = 10, CENT20 = 20, CENT50 = 50, EURO1 = 100, EURO2 = 200 };
		template<class T>
		void set_coin(T val);
	public:
		Coin(double val);
		Coin(int val);
		Coin(Coin &c);

		int get_coin() const;
		std::string to_string() const;
		~Coin();

		friend std::ostream& operator<<(std::ostream &o, const Coin &c);
		friend std::istream& operator>>(std::istream &i, Coin &c);
	};
	std::ostream& operator<<(std::ostream &i, const  Coin &c);
	std::istream& operator>>(std::istream &i, Coin &c);
}
#endif

