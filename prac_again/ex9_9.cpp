#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

constexpr double LIB_FEES = 100.00;

//----------------------------------------------------DATE-------------------------------------------------//
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
	public:
		unsigned int d()const{return day;}
		months m()const {return month;}
		unsigned int y()const {return year.val();}

		Date (unsigned int,months,Year); //last arg is of type Year.
		Date add_day();
		class Invalid
		{
		  //exception
		};
};

	std::ostream& operator<<(std::ostream& out, const Date& date)
	{
		return  (out << '(' << date.d() << '/'<<int(date.m()) << '/' << date.y() << ')' << '\n');
	}

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

//----------------------------------------------Book stuff---------------------------------------//

enum class Genre
{
	FIC,
	NON_FIC,
	BIO,
	PERD,
	CHLD
};

bool isPending(double fees);



//-------------------------------------------PATRON-----------------------------------------------//
class Patron
{
	private:
		std::string Name;
		unsigned long int LibCardNo;
		bool pending{false};	//default false
		double Fees{0.0}; 	//default 0.0 fees to be paid.
	public:
		std::string getName() const{return Name;}
		unsigned long int getLibCardNo() const{ return LibCardNo;}
		double getFees() const{return Fees;}
		bool getFeeStatus()const{return pending;}

		void setFees(double f);

		class InvalidFee
		{
			public:
				double Fee;

			InvalidFee(double d)
			:Fee{d}
			{
			
			}
		};

		Patron(std::string n,unsigned long int l)
		:Name{n},LibCardNo{l}
		{
	
		}
		Patron(std::string n, unsigned long int l,double f)
		:Name{n},LibCardNo{l},Fees{f}
		{
			pending = isPending(Fees); // Order of these two statements matters!!
		}
};

 void Patron::setFees(double f)
 {

	 if(f < 0)
	 {
	 	throw InvalidFee{f};
	 }
	 
		Fees = f;
		pending = isPending(getFees());
 }

 std::ostream& operator<<(std::ostream& out ,const Patron& p)
 {

 	out << "Name of Patron:" << p.getName() << '\n';
	out << "Lib. Card No. :" << p.getLibCardNo() << '\n';
   out << "Fees Pending: " << p.getFees() << '\n';
 }
 
 bool operator==(const Patron& p1, const Patron& p2)
 {
 	return (p1.getLibCardNo() == p2.getLibCardNo());
 }

 bool isPending(double fee)
 {
 	if(fee>0)
	return true;

	//else

	return false;
 }
//------------------------------------------BOOK-----------------------------------------------//
class Book
{
	private:
	std::string ISBN;
	bool is_checked_out{false};
	std::string Title;
	std::string Author;
	std::string cprt_date;
	Genre genre{ Genre::CHLD };
	bool isValidISBN(std::string isbn); // not inline

	public:
		std::string getAuthor()const {return Author;}
		std::string getTitle()const {return Title;}
		std::string getCprtDate()const {return cprt_date;}
		bool getStatus()const {return is_checked_out;}
		std::string getISBN()const {return ISBN;}
		void setCheckout(bool b){ is_checked_out = b; }
		
		std::string getGenre()const
		{
		
			switch(int(genre))
			{
				case int(Genre::FIC): return "Fiction";
				case int(Genre::NON_FIC): return "Non-Ficition";
				case int(Genre::BIO): return "Biography";
				case int(Genre::PERD): return "Periodical";
				case int(Genre::CHLD): return "Children";
			}
			
			return "Invalid";
		}

		class InvalidBook
		{
			std::string badisbn;

			public:
			
			std::string getISBN()const {return badisbn;}
			
			InvalidBook(std::string s)
			:badisbn{s}
			{
				
			}

		};

		Book(std::string t,std::string a,std::string i,Genre g,bool stat,std::string d)
		:Title{t},Author{a},ISBN{i},is_checked_out{stat},cprt_date{d},genre{g}
		{
			if(!isValidISBN(ISBN))
			{
				throw InvalidBook{ISBN};
			}
		}
};

 bool operator==(const Book& b1,const Book& b2)
	{
		if(b1.getISBN() != b2.getISBN())
		{
			return false;
		}
	}
 bool operator!=(const Book& b1,const Book& b2)
 {
 		return !(b1 == b2);
 }

 std::ostream& operator<<(std::ostream& out,const Book& b)
 {
 	out << "Title:" << b.getTitle() << '\n';
	out << "Author:" << b.getAuthor() << '\n';
	out << "ISBN:" << b.getISBN() << '\n';
	out << "Genre:" << b.getGenre() << '\n';
   out << "Cprt Date:" << b.getCprtDate() << '\n';
	out << "Availability: " << b.getStatus() << '\n';

	return out;
 }
 
 bool Book::isValidISBN(std::string s)
 {
 	int index = 0;

	for(int i=0;i<3;i++)
	{
	 	while((index < s.length()) && (s[index]!='-'))
	   {
			if(s[index]<48 || s[index] >57) //123-123-123-A
			{
				return false;
			}
			index++;
		}
		index++;
		if(index >= s.length())
		{	
			return false;
		}
	}

	if((!isdigit(s[index]))&&(!isalpha(s[index])))
	{
		return false;
	}

	return true;
 }
//-----------------------------------------------TRANSACTION-----------------------------------------------//
struct Transaction
{
	  Book book;
	  Patron patron;
	  Date date;

		Transaction(Book b,Patron p,Date d)
		:book{b},patron{p},date{d} //copy initialization
		{
					
		}

};
 std::ostream& operator<<(std::ostream& out, const Transaction& t)
 {
 	out << t.book;
	out << t.patron;
	return out << t.date;
 }

//-------------------------------------------------LIBRARY-------------------------------------------------//

class Library
{
	private:
		std::vector<Book> books;
		std::vector<Patron> patrons;
		std::vector<Transaction> transactions;
	public:

		class InvalidTransaction
		{
			private:
			Transaction t;

			public:
			InvalidTransaction(Transaction tr)
			:t{tr}
			{
			
			}

			Transaction& getTransaction(){ return t;}
		};

		void addPatron(Patron& p);
		void addBook(Book& b);
		void addTransaction(Transaction& t);
		std::vector<Patron> getPendingPatronList();

};

 void Library::addPatron(Patron& p)
 {
 	patrons.push_back(p);
 }
 void Library::addBook(Book& b)
 {
 	books.push_back(b);
 }
 void Library::addTransaction(Transaction& t)
 {
	// check to see if book exists in the library.
	// check to see if the said patron exists
	// check to see if patron owes any fees
	// if fees owed is zero then add transaction.
	// else report error.

	for(int i=0;i<books.size();i++)
	{
		if(books[i] == t.book && books[i].getStatus()==false)
		{
			for(int j=0;j<patrons.size();j++)
			{
				if(patrons[j] == t.patron)
				{
					if(patrons[j].getFees()!=0)
					{
						std::cerr << "Patron has already borrowed! Transaction not allowed.\n";
						throw InvalidTransaction{t};
					}


					patrons[j].setFees(LIB_FEES);
					books[i].setCheckout(true);
					transactions.push_back(t);
					return ;
				}
			}
		}
	}

	throw InvalidTransaction{t};
 }	
 
 std::vector<Patron> Library::getPendingPatronList()
 {
 	std::vector<Patron> p;

	 for(int i=0;i<patrons.size();i++)
	 {
	 	if(patrons[i].getFeeStatus() == true)
		{
			p.push_back(patrons[i]);
		}
	 }

	 return p;
 }

//--------------------------------------------------MAIN---------------------------------------------------//

 int main(int argc, char *argv[])
 {
 	try
	{
		Library myLibrary;

 		Book b1  {"How to Die on Mars","Elon Musk","123-456-789-A",Genre::BIO,false,"1-01-2019"};
		Book b2 {"High Hacking","George Hotz","124-489-789-X",Genre::NON_FIC,false,"2-01-2019"};
		Patron p1  {"Saikiran B.",12347,0};
		Patron p2 {"Samy Kamkar",12354,0};

		myLibrary.addBook(b1);
		myLibrary.addBook(b2);
		myLibrary.addPatron(p1);
		myLibrary.addPatron(p2);

		Transaction t1 {b2,p1,Date{11,months::jan,Year{2019}}};

		myLibrary.addTransaction(t1);
		
		Transaction t2 {b2,p2,Date{12,months::jan,Year{2019}}}; // this should give an error. b2 is already taken.

		myLibrary.addTransaction(t2);

		
	}



	catch( Book::InvalidBook& e )
	{

		std::cout << "Invalid Book: ";
		std::cout << e.getISBN();
		std::cout << '\n';
	}
	catch(Patron::InvalidFee& f)
	{
		std::cout << "Setting invalid fee:"<<f.Fee << '\n';
		return 1;
	}
	catch (Library::InvalidTransaction& e)
	{
		std::cout << "Transaction Cancelled:";
		std::cout << e.getTransaction();
	}
	catch( ... )
	{
		std::cout << "unknown error occured!\n";
		return 1;
	}

 	return 0;
 }
