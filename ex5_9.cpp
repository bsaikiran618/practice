#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

enum class Genre
{
	FIC,
	NON_FIC,
	BIO,
	PERD,
	CHLD
};

bool isPending(double fees);

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

 	out << "----------------------------------------------\n";
 	out << "Name of Patron:" << p.getName() << '\n';
	out << "Lib. Card No. :" << p.getLibCardNo() << '\n';
   out << "Fees Pending: " << p.getFees() << '\n';
	return out << "----------------------------------------------\n";
 }

 bool isPending(double fee)
 {
 	if(fee>0)
	return true;

	//else

	return false;
 }

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


 int main(int argc, char *argv[])
 {
 	try
	{
 		Book myBook  {"How to Die on Mars","Elon Musk","123-456-789-A",Genre::BIO,false,"1-01-2019"};
		Patron myPatron  {"Saikiran B.",12347L,100.25};

		myPatron.setFees(-564);

		std::cout << myBook;
		std::cout << myPatron;
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
	catch( ... )
	{
		std::cout << "unknown error occured!\n";
		return 1;
	}

 	return 0;
 }
