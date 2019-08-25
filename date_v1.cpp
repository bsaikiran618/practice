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
};

	 void print_Date(Date& date)
	 {
	 	std::cout << date.day << '/' << date.month << '/' << date.year << '\n';
	 }

	Date add_day(Date &current)
	{
		Date next;

		if(current.month == 2)
		{

			// its feb, has 28 days.

			if(current.day == 28)
			{
				next.day = 1;
				next.month = 3;
				next.year = current.year;
			}
			else
			{
			next.month = 2;
			next.day = current.day+1;
			next.year = current.year;
			}

			return next;

		}
		else if(current.month == jan||
				  current.month == mar||
				  current.month == may||
				  current.month == jun||
				  current.month == jul||
				  current.month == sep||
				  current.month == oct||
				  current.month == dec
		       )
				 {
				 
				 if(current.day ==31)
				 {
				 	if(current.month == 12)
					{
						next.day = 1;
						next.month = 1;
						next.year = current.year +1;
					}
					else
					{
						next.day = 1;
						next.month = current.month + 1;
						next.year = current.year;
					}
				 }
				 else
				 {
				 	next.day = current.day+1;
					next.month = current.month;
					next.year = current.year;
				 }
				 

				 return next;
			}

		else
		{
			// has 30 days.

			if(current.day == 30)
			{
				next.day =1;
				next.month = current.month+1;
				next.year = current.year;
			}
			else
			{
				next.day = current.day +1;
				next.month = current.month;
				next.year = current.year;
			}
		}

		return next;
	}

	bool isvalidDate(Date &d)
	{
		if(d.month == 2)
		{
			if(d.day<1 || d.day>28)
			return false;
			return true;
		}
		else if(d.month == jan||
				  d.month == mar||
				  d.month == may||
				  d.month == jun||
				  d.month == jul||
				  d.month == sep||
				  d.month == oct||
				  d.month == dec
		       )
		{
			if(d.day<1 ||d.day >31)
			return false;
		}
		else
		{
			if(d.day < 1||d.day >30)
			return false;
		}


		return true;
	}

 int main( int argc, char *argv[])
 {
   Date today;
	Date tomorrow;
	
	std::cin >> today.day >> today.month >> today.year;

	tomorrow = add_day(today);


	if(isvalidDate(today))
	print_Date(today);
	else
	{
		std::cout << "Invalid Date\n";
	}
	std::cout << '\n';
	if(isvalidDate(tomorrow))
	print_Date(tomorrow);
	else
	{
		std::cout << "Invalid Date\n";
	}
	std::cout << '\n';

	return 0;
 }
