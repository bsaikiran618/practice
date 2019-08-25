#include <iostream>
#include <vector>
#include <string>



enum class muns
{
	jan =1,
	feb,
	mar,
	apr,
	may,
	jun,
	jul,
	aug,
	sep,
	oct,
	nov,
	dec
};

class Date
{
  private:
	 muns month{muns::jan};
	 unsigned int day{1};
	 unsigned int year{1900};
  public:
  	 muns Month(){return month;}
	 unsigned int Day(){return day;}
	 unsigned int Year(){return year;}
	 static int X;
	 class Invalid
	 {
	 	// Invalid Object.
	 };
	 Date(int d, muns m, int y);
	 Date(int y);

};


 Date::Date(int d, muns m, int y)
 :day(d),month(m),year(y)
{
	if(m == muns::feb)
	{
	if(d < 1|| d > 28)
		{
		 throw Invalid{};
		}
	}
	else
	{
		if(m >muns::dec || m < muns::jan)
		{
			throw Invalid{};
		}
		if((int(m)%2==0)&&(d > 30 || d < 1))
		{
			throw Invalid{};
		}
		if((int(m)%2!=0)&&(d > 31 ||d < 1))
		{
			throw Invalid{};	
		}
	}
}
Date::Date(int y)
:year{y}
{
	if(y < 1000 || y > 3000)
	throw Invalid{};
}

int main(int argc, char*argv[])
{

	try
	{
		Date newDate(1,muns::jul,2019);
		Date x{2017};


	std::cout << newDate.Day() << '/';
	std::cout << int(newDate.Month()) << '/';
	std::cout << newDate.Year() << '\n';

	std::cout << x.Day() << '/';
	std::cout << int(x.Month()) <<'/';
	std::cout << x.Year() << '\n';
	}
	catch(Date::Invalid& invalid)
	{
		std::cout << "Found invalid date\n";
		return 1;
	}
	return 0;
}
