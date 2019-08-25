#include <iostream>
#include <vector>

enum class months
{
	jan =1,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec
	
};
enum  weekday
{
	sunday,monday,tuesday,wednesday,thursday,friday,saturday
};
const std::vector<unsigned int>monthday
{
	31,28,31,30,31,30,31,31,30,31,30,31
};
bool isLeapYear(unsigned int y)
{
	return (((y%4==0)&&(y%100!=0))||((y%400==0)));
}

class Year
{

	static const int min = 1800; // lowest year possible
	static const int max = 3200; // highest year possible
	
	private:
		unsigned int y{2001};

	public:
	unsigned int val() const { return y;}

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
		unsigned int n{1};
		weekday wd;
		void setNoOfDays();
		void setWeekday();

	public:
		unsigned int d()const{return day;}
		months m()const {return month;}
		unsigned int y()const {return year.val();}
		std::string wday()const {
		
			switch(int(wd))
			{
				case 0: return "SUNDAY";
				case 1: return "MONDAY";
				case 2: return "TUESDAY";
				case 3: return "WEDNESDAY";
				case 4: return "THURSDAY";
				case 5: return "FRIDAY";
				case 6: return "SATURDAY";
			}
			std::cout << "REMAINDER:" << int(wd);
			return "INVALIDDAY";
		}


		Date (unsigned int,months,Year); //last arg is of type Year.
		void add_day();
		Date nextWorkday();
		unsigned int WeekNo();

		class Invalid
		{
		  //exception
		};
};


	std::ostream& operator<<(std::ostream& out, const Date& date)
	{
		return  (out << '(' << date.d() << '/'<<int(date.m()) << '/' << date.y() <<"DAY:" << date.wday() << ')' << '\n');
	}

	Date::Date(unsigned int nd,months mon,Year yea)
	:day(nd),month(mon),year(yea)
	{
			if(int(m()) < 1 || int(m()) > 12)
			throw Invalid{};

			if(m() == months::feb)
		{
			if(isLeapYear(yea.val()))
			{
				if(d()<1 || d()>29)
					throw Date::Invalid{};
			}
			else
			{
				if(d()<1 || d()>28)
					throw Date::Invalid{};
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
			if(d()<1 ||d() >31)
			throw Date::Invalid{};
		}
		else
		{
			if(d() < 1||d() >30)
			throw Date::Invalid{};
		}


		
		if(d() == 1 && m()==months::jan)
		 {
		 	n = 0;
			setWeekday();
		 }
		else
		 setNoOfDays();

	}

	void Date::add_day()
	{

		if(m() == months::feb)
		{

			// its feb, has 28 days.

			if(d()==28 && !isLeapYear(y()))
			{
				 //return Date{1,months::mar,Year{y()}};
					day = 1;
					month = months::mar;
			}
			if(d()==28 && isLeapYear(y()))
			{
				//return Date{d()+1,months::feb,Year{y()}};

					day = day + 1;
					month = months::feb;
			}
			else
			{
				//return Date{d()+1,months::feb,Year{y()}};
					day = day + 1;
					month = months::feb;
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
						//return Date{1,months::jan,Year{y()+1}};

						day = 1;
						month = months::jan;
						year = Year{y()+1};
					}
					else
					{
						//return Date{1,months(int(m())+1),Year{y()}};
						day = 1;
						month = months(int(m())+1);
					}
				 }
				 else
				 {
					//return Date{d()+1,m(),Year{y()}};
					day = day+1;
				 }
			}

		else
		{
			// has 30 days.

				if(day == 30)
			{
				//return Date{1,months(int(m())+1),Year{y()}};
				day = 1;
				month = months(int(m())+1);
			}
			else
			{
				//return Date{d()+1,m(),Year{y()}};
				day = day +1;
			}
		}
		
		n++;
		setWeekday();
	}

	void Date::setNoOfDays()
	{
		int number=0;
		
		for(int i=0;i<int(m())-1;i++)
		{
			if(m()==months::feb && isLeapYear(y()))
			number+=29;
			else
			number+=monthday[i];
		}

		number+=d();

		n = number-1;

		setWeekday();
	}
	void Date::setWeekday()
	{
		wd = weekday((n%7));
	}

  bool operator==(Date& d1,Date& d2)
  {
  		return ((d1.d()==d2.d()) && (int(d1.m())==int(d2.m())) && (d1.y()==d2.y()));
  }

	unsigned int Date::WeekNo()
	{
		return int(n/7)+1;
	}

 Date nextWorkday(const Date& d)
 {
 	Date now = d;
	now.add_day();

	 while(now.wday()=="SUNDAY" || now.wday() == "SATURDAY")
	 {
	 	now.add_day();
	 }
	 return now;
 }


//////////////////////////////MAIN/////////////////////////////////////////
 int main( int argc, char *argv[])
 {
	unsigned int d,m,y;	
	std::cin >> d >> m  >> y;
	
	try{
			Date today{d,months(m),Year{y}};
			Date tomorrow { today };

			tomorrow.add_day();

			std::cout << "Today:";
			std::cout << today;
			std::cout << "WEEK:" << today.WeekNo() << '\n';
			std::cout << "Tomorrow:";
			std::cout << tomorrow;

			std::cout << "Next working day is :" << '\n' << nextWorkday(tomorrow);

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
