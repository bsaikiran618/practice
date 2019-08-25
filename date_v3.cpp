#include <iostream>


enum months
{
	jan =1,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec
	
};

class Date
{
	private:
		unsigned int day;
		unsigned int month;
		unsigned int year;
	public:
		unsigned int d(){return day;}
		unsigned int m(){return month;}
		unsigned int y(){return year;}

		Date (unsigned int n,unsigned int m,unsigned int d);
		void print_Date();
		Date add_day();
		class Invalid
		{
		  //exception
		};
};

	Date::Date(unsigned int n,unsigned int mon,unsigned int yea)
	:day(n),month(mon),year(yea)
	{
			if(m() == 2)
		{
			if(d()<1 || d()>28)
			throw Date::Invalid{};
		}
		else if(m() == jan||
				  m() == mar||
				  m() == may||
				  m() == jun||
				  m() == jul||
				  m() == sep||
				  m() == oct||
				  m() == dec
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
	 	std::cout << d() << '/' << m() << '/' << y() << '\n';
	 }

	Date Date::add_day()
	{
		if(m() == 2)
		{

			// its feb, has 28 days.

			if(d() == 28)
			{
				return Date{1,3,y()};
			}
			else
			{
				return Date{2,d()+1,y()};
			}

		}
		else if(m() == jan||
				  m() == mar||
				  m() == may||
				  m() == jun||
				  m() == jul||
				  m() == sep||
				  m() == oct||
				  m() == dec
		       )
				 {
				 
				 if(d() ==31)
				 {
				 	if(m() == 12)
					{
						return Date{1,1,y()+1};
					}
					else
					{
						return Date{1,m()+1,y()};
					}
				 }
				 else
				 {
					return Date{d()+1,m(),y()};
				 }
			}

		else
		{
			// has 30 days.

			if(day == 30)
			{
				return Date{1,m()+1,y()};
			}
			else
			{
				return Date{d()+1,m(),y()};
			}
		}

	}


 int main( int argc, char *argv[])
 {
	unsigned int d,m,y;	
	std::cin >> d >> m  >> y;
	
	try{
			Date today{d,m,y};
			Date tomorrow{today.add_day()};
			today.print_Date();
			tomorrow.print_Date();

			std::cout << '\n';
		}
	catch(Date::Invalid& e)
	{
		std::cout << "Invalid date \n";
	}

	return 0;
 }
