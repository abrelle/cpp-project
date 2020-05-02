#include "Item.h"
#include "Slot.h"
#include "Coins.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <cstdlib>


using namespace std;
using namespace Demo;


 /*______________________ITEM CLASS TEST______________________*/
class ItemTest
{
	private:
		template <typename T>
		static void printTest(T number, bool res)
		{
			if (res)
				clog << "Item test " << number << " passed!" << endl;
			else
			{
				clog << "Item test " << number << " failed!" << endl;
			}
		}

	public:

	static void test1()
	{
		Item i("KitKat", 2.5);
		i.set_price(3.6);
		i.set_name("M&M's");
		printTest(1, true);
	}
	static void test2()
	{
		Item i("KitKat", 2.5);
		try
		{
			i.set_price(-3.5);
			throw 1;
		}
		catch (invalid_argument) //e.what()
		{
			printTest(2, true);
		}
		catch (int)
		{
			printTest(2, false);
		}
	}
	static void test3()
	{
		Item i("KitKat", 2.5);
		double before = i.get_price();
		try
		{
			i.set_price(-3.5);
			throw 1;
		}
		catch (...)
		{
			
		}
		double after = i.get_price();
		printTest(3, before == after);
	}
	static void test4()
	{
		Item i("KitKat", 2.5);
		string s1(i.to_string());
		try
		{
			stringstream ss;
			ss << i;
			ss >> i;
			string s2(i.to_string());
			printTest(4.1, s1.compare(s2) == 0);
		}
		catch (...)
		{
			printTest(4.2, false);
		}
	}

};


/*______________________SLOT CLASS TEST______________________*/

class SlotTest
{
	private:
		template <typename T>
		static void printTest(T number, bool res, const string& s = " ")
		{
			if (res)
			{
				clog << "Item test " << number << " passed! " << s << endl;
			}
			else
			{
				clog << "Item test " << number << " failed! " << s << endl;
			}
		}

	public:
		static void test1()
		{
			Slot s("A5", 6);
			s.set_label("A3");
			s.set_numItems(7);
			printTest(1,(s.get_label() == "A3" && s.get_numItems() == 7));
		}
		static void test2()
		{
			Slot s("B5", 6);
			try
			{
				s.set_numItems(-9);
				throw 1;
			}
			catch (const invalid_argument& a)
			{
				printTest(2.1, true, a.what());
			}
			catch (int)
			{
				printTest(2.1, false);
			}

			try
			{
				s.set_label("A78");
				throw 1;
			}
			catch (const invalid_argument& a)
			{
				string m = a.what();
				printTest(2.2, true, a.what());
			}
			catch (int)
			{
				printTest(2.2, false, "Didn't catch an exception!");
			}
		}
		static void test3()
		{
			Slot s("C5", 6);
			int temp = s.get_numItems();
			try
			{
				s.set_numItems(-9);
				throw 1;
			}
			catch (...)
			{

			}
			if (temp == s.get_numItems())
				printTest(3, true);
			else
				printTest(3, false);
		}
		static void test4()
		{
			Slot s("D5", 6);
			string s1(s.to_string());
			try
			{
				stringstream ss;
				ss << s;
				ss >> s;
				string s2(s.to_string());
				printTest(4.1, s1.compare(s2) == 0);
			}
			catch (...)
			{
				printTest(4.2, false);
			}
		}
};

/*______________________CASHBOX CLASS TEST______________________*/

class CashBoxTest
{
	private:
		template <typename T>
		static void printTest(T number, bool res, const string& s = " ")
		{
			if (res)
			{
				clog << "CashBox test " << number << " passed! " << s << endl;
			}
			else
			{
				clog << "CashBox test " << number << " failed! " << s << endl;
			}
		}
	public:
		static void test1()
		{
			CashBox b(1, 2, 3, 4, 5, 6);
			b.set_5(5);
			b.set_10(10);
			b.set_20(20);
			b.set_50(50);
			b.set_e1(10);
			b.set_e2(35);
			printTest(1, (b.get_10() == 10));
		}
		static void test2()
		{
			CashBox b(1, 2, 3, 4, 5, 6);
			try
			{
				b.set_5(5);
				b.set_10(10);
				b.set_20(20);
				b.set_50(50);
				b.set_e1(-49);
				b.set_e2(35);
				throw 1;
			}
			catch (const invalid_argument& e)
			{
				printTest(2.1, true, e.what());
			}
			catch (int)
			{
				printTest(2.2, false);
			}
		}
		static void test3()
		{
			CashBox b(1, 2, 3, 4, 5, 6);
			try
			{
				b += 8;
				if (b.get_10() != 10)
					throw invalid_argument("+= operator failed.");
				b -= 6;
				if (b.get_20() != 5)
					throw invalid_argument("-= operator failed.");
				b++;
				if (b.get_5() != 4)
					throw invalid_argument("++ increment operator failed.");
				++b;
				if (b.get_5() != 5)
					throw invalid_argument("++ increment operator failed.");
				b--;
				if (b.get_e1() != 8)
					throw invalid_argument("postfix decrement operator failed.");
				--b;
				if (b.get_e2() != 8)
					throw invalid_argument("prefix decrement operator failed.");

				printTest(3, true);
			}
			catch (const invalid_argument& e)
			{
				printTest(3, false, e.what());   
			}
		}
		static void test4()
		{
			CashBox b(1, 2, 3, 4, 5, 6);
			string b1(b.to_string());
			try
			{
				stringstream ss;
				ss << b;
				ss >> b;
				string b2(b.to_string());
				printTest(4.1, b1.compare(b2) == 0);
			}
			catch (...)
			{
				printTest(4.2, false);
			}
		}

};

int main(int argc, char* argv[])
{
	streambuf *clog_backup = clog.rdbuf();
	streambuf *cerr_backup = cerr.rdbuf();

	fstream logFile;
	streampos init_pos;
	logFile.open("log.txt", fstream::out);
	if (logFile.is_open())
	{
		clog.rdbuf(logFile.rdbuf());
		cerr.rdbuf(logFile.rdbuf());

		logFile << "class Item - testing started" << endl;
		ItemTest::test1();
		ItemTest::test2();
		ItemTest::test3();
		ItemTest::test4();
		logFile << "class Item - testing ended" << endl;
		logFile << '\n' << endl;

		logFile << "class Slot - testing started" << endl;
		SlotTest::test1();
		SlotTest::test2();
		SlotTest::test3();
		SlotTest::test4();
		logFile << "class Slot - testing ended" << endl;
		logFile << '\n' << endl;

		logFile << "class CashBox - testing started" << endl;
		CashBoxTest::test1();
		CashBoxTest::test2();
		CashBoxTest::test3();
		CashBoxTest::test4();
		logFile << "class CashBox - testing ended" << endl;


		logFile.close();
	}
	else
		cout << "file not opened" << endl;


	logFile.open("log.txt", fstream::in);
	if (logFile.is_open())
	{
		char line[80];
		while (logFile.good())
		{
			logFile.getline(line, 80);
			cout << line << endl;
		}
	}
	else
		cout << "file not opened" << endl;

	clog.rdbuf(clog_backup);
	cerr.rdbuf(cerr_backup);
	system("pause");
	return 0;
}
