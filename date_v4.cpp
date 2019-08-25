#include <iostream>


enum class months
{
	jan =1,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec
	
};
class Year
{

	static const int min = 1800; // lowest year possible
	static const int max = 3200; // highest year possible
	
	private:
		unsigned int y{2001};

	public:
	unsigned int val(){ return y;}

	class InvalidYear
	{
		private:
		unsigned int b;

		public:
		InvalidYear(unsigned int x)
		:b{x}
		{}
		unsigned int bad(){return b;}
	};


	Year(unsigned int x)
	{
		if(x < min || x > max)
		{
			throw InvalidYear{x};
		}
		else
		{
			y = x;
		}
	}

};
class Date
{
	private:
		unsigned int day;
		months month;
		Year year;
	public:
		unsigned int d(){return day;}
		months m(){return month;}
		unsigned int y(){return year.val();}

		Date (unsigned int,months,Year); //last arg is of type Year.
		void print_Date();
		Date add_day();
		class Invalid
		{
		  //exception
		};
};

	Date::Date(unsigned int n,months mon,Year yea)
	:day(n),month(mon),year(yea)
	{
			if(int(m()) < 1 || int(m()) > 12)
			throw Invalid{};

			if(m() == months::feb)
		{
			if(d()<1 || d()>28)
			throw Date::Invalid{};
		}
		else if(m() == months::jan||
				  m() == months::mar||
				  m() == months::may||
				  m() == months::jun||
				  m() == months::jul||
				  m() == months::sep||
				  m() == months::oct||
				  m() == months::dec
		       )
		{
			if(d()<1 ||d() >31)
			throw Date::Invalid{};
		}
		else
		{
			if(d() < 1||d() >30)
			throw Date::Invalid{};
		}

	}

	 void Date::print_Date()
	 {
	 	std::cout << d() << '/' << int(m()) << '/' << y() << '\n';
	 }

	Date Date::add_day()
	{
		if(m() == months::feb)
		{

			// its feb, has 28 days.

			if(d() == 28)
			{
				return Date{1,months::mar,Year{y()}};
			}
			else
			{
				return Date{2,months(int(m())+1),Year{y()}};
			}

		}
		else if(m() == months::jan||
				  m() == months::mar||
				  m() == months::may||
				  m() == months::jun||
				  m() == months::jul||
				  m() == months::sep||
				  m() == months::oct||
				  m() == months::dec
		       )
				 {
				 
				 if(d() ==31)
				 {
				 	if(m() == months::dec)
					{
						return Date{1,months::jan,Year{y()+1}};
					}
					else
					{
						return Date{1,months(int(m())+1),Year{y()}};
					}
				 }
				 else
				 {
					return Date{d()+1,m(),Year{y()}};
				 }
			}

		else
		{
			// has 30 days.

			if(day == 30)
			{
				return Date{1,months(int(m())+1),Year{y()}};
			}
			else
			{
				return Date{d()+1,m(),Year{y()}};
			}
		}

	}


 int main( int argc, char *argv[])
 {
	unsigned int d,m,y;	
	std::cin >> d >> m  >> y;
	
	try{
			Date today{d,months(m),Year{y}};
			Date tomorrow{today.add_day()};
			today.print_Date();
			tomorrow.print_Date();

			std::cout << '\n';
		}
	catch(Date::Invalid& e)
	{
		std::cout << "Invalid date \n";
		return 1;
	}
	catch(Year::InvalidYear& e)
	{
		std::cout << "Invalid Year:" << e.bad() << '\n';
		return 1;
	}

	return 0;
 }
