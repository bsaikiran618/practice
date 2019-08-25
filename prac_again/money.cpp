#include <iostream>
#include <string>


 enum
 {
 	KRONER
 }

 std::vector<double> conversion_rates = { 6.62 };
 std::vector<std::string> known_currencies {"USD","KRONER"};

 class Money
 {
 	private:
		unsigned long int total_cents {0};
		std::string currency{"USD"};
	public:

	class InvalidCurrency
	{
		private:
			std::string cur;
		public:
			InvalidCurrency(std::string s)
			:cur{s};
			{
			
			}
			std::string getCurrency(){return cur;}
	}
	 
	 // constructor
	 //Money(unsigned int dollars, unsigned int cents, std::string cur)
	 Money(double d,std::string cur)
	 :currency{cur}
	 {
		unsigned long int cents;
		unsigned long int dollars;

		dollars = int(d);
		cents = (d-dollars)*100;

	 	total_cents += cents;
		total_cents += dollars * 100;

		bool found = false;
		 for(int i=0;i < known_currencies;i++)
		 {
		 		if(known_currencies[i] == cur)
				{
					found = true;
					break;
				}
		 }
		 if(!found)
		 {
		 	throw InvalidCurrency{cur};
		 }

	 }
	 // member functions

	 double getAmount()
	 {
	 	 return  double(total_cents)/100;
	 }
	 unsigned int getDollars()
	 {
	 	return unsigned int(total_cents/100);
	 }
	 double getCents()
	 {
	 	return ((getAmount()-getDollars())*100);
	 }
 
 };

  int main()
  {
  		std::cout << "Enter the amount of money and currency:\n";
		double x;
		std::string currenc;
		std::cin >> x;
		std::cin >> currenc;

		Money m {x,currenc};

		std::cout << "Total Amount:" << m.getAmount() << '\n';
		

		return 0;
  }
