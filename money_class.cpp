#include <cmath>
#include <iostream>
#include <vector>
#include <string>

namespace CURRENCY
{

		std::vector<std::string> known;
		std::vector<double> conversion_rates;
		bool isValid(std::string curr);
		void addCurrency(std::string newCurr, double cr);
		void changeConversionRate(std::string curr, double cr);
		double getConversionRate(std::string curr); // to dollar

};



 
 bool CURRENCY::isValid(std::string curr)
 {
 	for(int i=0;i<CURRENCY::known.size();i++)
	{
		if(curr == CURRENCY::known[i])
		{
			return true;
		}
	}

	return false;
 }

 void CURRENCY::addCurrency(std::string newCurr, double cr)
 {
 	if(!CURRENCY::isValid(newCurr))
	{

		if(cr > 0)
		{
			CURRENCY::conversion_rates.push_back(cr);
			CURRENCY::known.push_back(newCurr);
		}
		else
		{
			std::cout << "NEGATIVE OR ZERO CONVERSION RATE!\n";
			std::cout << "CANNOT ADD CURRENCY\n";			
		}
	}
	else
	{
		std::cout << "Currency already exists\n";
	}
}


 void CURRENCY::changeConversionRate(std::string curr , double cr)
 {
 	if(CURRENCY::isValid(curr) && (cr > 0))
	{
		int index;
			
			for(int i=0;i<CURRENCY::known.size();i++)
			{
				if(CURRENCY::known[i] == curr)
				index = i;

				break;
			}
			CURRENCY::conversion_rates[index] = cr;
	}
	else
	{
		std::cout << "INVALID CONVERSION RATE OR UNKNOWN CURRENCY\n";
	}
 }

 double CURRENCY::getConversionRate(std::string str)
 {
 	for(int i=0;i<CURRENCY::known.size();i++)
	{
		if(CURRENCY::known[i] == str)
		{
			return CURRENCY::conversion_rates[i];
		}
	}

	std::cout << "Couldnt find conversion rate for " << str << '\n';
 }

//------------------------------------------______________________________________------------------------_______________________----------












//----------------------------------------------____________________________________---------------------_________--------_____-----____---------

class Money
{
	private:
		long int total_cents{0};
		std::string Currency{""};

	public:
		
		class InvalidMoney
		{
		
		};
		
		// constructors..

		Money(double amount, std::string cur)
		{
			int dollars = int(amount);
			int cents = int(amount * 100) %100;

			total_cents = cents + (dollars*100);
			
			if(CURRENCY::isValid(cur))
			Currency = cur;
			else
			{
				std::cout << "Invalid Currency :" << cur << '\n';
				throw InvalidMoney{};
			}
		
		}


		Money(long int cents, std::string cur)
		:total_cents{cents}
		{
			if(cents < 0 || cents > 2147483647)
			{
			 	throw InvalidMoney{};
			}
			if(CURRENCY::isValid(cur))
			Currency = cur;
			else
			{
				std::cout << "Invalid Currency :" << cur << '\n';
				throw InvalidMoney{};
			}

		}
		
		//member functions.

		// non-modifying
		long int getCents()const{return total_cents;} // small function		
		std::string getCurrency()const {return Currency;}		
		double getAmount()const
		{
		
			double x;
			x = total_cents/100.0;
			return x;
		}
		//modifying

		void convertTo(std::string curr)
		{
			if(CURRENCY::isValid(curr))
			{
				double amount = (((total_cents/100.000)* CURRENCY::getConversionRate(Currency))/CURRENCY::getConversionRate(curr));
				total_cents = amount*100.000;
				Currency = curr;
			}
			else
			{
				throw InvalidMoney{};
			}
		}

};

//defining an input operation for Money objects..
 std::ostream& operator<<(std::ostream& out, Money& m)
 {
 	return out << m.getAmount() <<  m.getCurrency();
 }
 std::istream& operator>>(std::istream& in, Money& m)
 {
	double amount;
	std::string curr;


 	in >> amount;
	in >> curr;
		
	m = Money{amount,curr}; // creating a object and assigning it to m

	return in;
 }

 // lets define operations for the money class..

 Money operator+(const Money& m1, const Money& m2)
 {
 	if(m1.getCurrency() == m2.getCurrency())
 	return Money{m1.getCents() + m2.getCents(), m1.getCurrency()};

		// convert money1 to money2 currency
		// return money with sum and currency as currency of money2

		Money temp1 = m1;
		
		temp1.convertTo(m2.getCurrency());

		return Money{temp1.getCents() + m2.getCents(), m2.getCurrency()};
 }
 
 Money operator-(const Money& m1, const Money& m2)
 {
 	if(m1.getCurrency() == m2.getCurrency())
 	return Money{m1.getCents() - m2.getCents(),m2.getCurrency()};


		Money temp1 = m1;
		
		temp1.convertTo(m2.getCurrency());

		return Money{temp1.getCents() - m2.getCents(), m2.getCurrency()};
 }

// Main starts here..
//______________________________-------------------_______-------_______------___-----___----___----___----___------___------___----____-------------
 int main()
 {

 	CURRENCY::addCurrency("USD",1.000);
	CURRENCY::addCurrency("RUP",0.014);

	Money m1{0.0, "USD"};
	std::cout << "Enter some amount in dollars\n";
	std::cin  >> m1;

	std::cout << m1 << " in rupees is";
	m1.convertTo("RUP");
	std::cout << m1 << std::endl;

	double x = 6176227/double(500000);

	std::cout << x << std::endl;

	return 0;
}
