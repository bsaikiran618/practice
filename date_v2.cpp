#include <iostream>


enum months
{
	jan =1,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec
	
};

struct Date
{
		unsigned int day;
		unsigned int month;
		unsigned int year;
		Date (int n, int m, int d);
		void print_Date();
		Date add_day();
	   bool isvalidDate();
};

	Date::Date(int n, int m, int d)
	{
		day = n;
		month = m;
		year = d;
	}

	 void Date::print_Date()
	 {
	 	std::cout << day << '/' << month << '/' << year << '\n';
	 }

	Date Date::add_day()
	{
		Date next{1,1,1};
		if(month == 2)
		{

			// its feb, has 28 days.

			if(day == 28)
			{
				next.day = 1;
				next.month = 3;
				next.year =year;
			}
			else
			{
			next.month = 2;
			next.day = day+1;
			next.year = year;
			}

			return next;

		}
		else if(month == jan||
				  month == mar||
				  month == may||
				  month == jun||
				  month == jul||
				  month == sep||
				  month == oct||
				  month == dec
		       )
				 {
				 
				 if(day ==31)
				 {
				 	if(month == 12)
					{
						next.day = 1;
						next.month = 1;
						next.year = year +1;
					}
					else
					{
						next.day = 1;
						next.month =month + 1;
						next.year = year;
					}
				 }
				 else
				 {
				 	next.day = day+1;
					next.month = month;
					next.year = year;
				 }
				 

				 return next;
			}

		else
		{
			// has 30 days.

			if(day == 30)
			{
				next.day =1;
				next.month =month+1;
				next.year = year;
			}
			else
			{
				next.day = day +1;
				next.month =month;
				next.year =year;
			}
		}

		return next;
	}

	bool Date::isvalidDate()
	{
		if(month == 2)
		{
			if(day<1 || day>28)
			return false;
			return true;
		}
		else if(month == jan||
				  month == mar||
				  month == may||
				  month == jun||
				  month == jul||
				  month == sep||
				  month == oct||
				  month == dec
		       )
		{
			if(day<1 ||day >31)
			return false;
		}
		else
		{
			if(day < 1||day >30)
			return false;
		}


		return true;
	}

 int main( int argc, char *argv[])
 {
   Date today{1,1,1};
	Date tomorrow{1,1,1};
	
	std::cin >> today.day >> today.month >> today.year;

	tomorrow = today.add_day();


	if(today.isvalidDate())
	today.print_Date();
	else
	{
		std::cout << "Invalid Date\n";
	}
	std::cout << '\n';
	if(tomorrow.isvalidDate())
	tomorrow.print_Date();
	else
	{
		std::cout << "Invalid Date\n";
	}
	std::cout << '\n';

	return 0;
 }
