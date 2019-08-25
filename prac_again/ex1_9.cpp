#include <iostream>
#include <vector>
#include <string>

class Name_pairs
{
	private:
		
		std::vector<std::string> names;
		std::vector<double> ages;
	public:

		class Invalid
		{
			
		};

		class InvalidAge
		{
			double bad_age;

			public:
			InvalidAge(double x) //constructor for InvalidAge
			:bad_age(x)
			{
			
			}
			public:
				double getAge() { return bad_age;}
		};

		void read_names(int n);
		std::string getName(int i) const;
		double getAge(int i) const;
		int getSize() const;
		void read_ages();
		void print_all();
		void sort_all();


};

	int Name_pairs::getSize() const
	{
		return names.size();
	}

	std::string Name_pairs::getName(int i) const
	{
		if(i<0 || i>=names.size())
		{
			throw Invalid{};
		}
		
		return names[i];
	}
	double Name_pairs::getAge(int i) const
	{
		if(i<0 || i>=ages.size())
		{
			throw Invalid{};
		}

		return ages[i];
	}

	std::ostream& operator<<(std::ostream& out, const Name_pairs& ns)
	{
		out << '\n';

		int i;

		for(i=0 ; i<ns.getSize()-1 ; i++)
		{
			out << ns.getName(i) << ',' << ns.getAge(i) << '\n';
		}


		return out << ns.getName(i) << ',' << ns.getAge(i) << '\n';
	}
	bool operator==(const Name_pairs& ns1,const Name_pairs& ns2)
	{
		if(ns1.getSize()!=ns2.getSize())
		{
			return false;
		}
		else
		{
			for(int i=0;i<ns1.getSize();i++)
			{
				if((ns1.getName(i)!=ns2.getName(i))||(ns1.getAge(i)!=ns2.getAge(i)))
				return false;
			}
		}
		return true;
	}

	bool operator!=(const Name_pairs& ns1,const Name_pairs& ns2)
	{
		return !(ns1 == ns2);
	}


	void Name_pairs::read_names(int n)
	{
		std::string s;

		for(int i=0;i<n;i++)
		{	
			std::cout << "Enter name:\n";
			std::cin >> s;
			names.push_back(s);
		}

		read_ages();
	}
	void Name_pairs::read_ages()
	{
		double x;

		for(int i = 0;i < names.size();i++)
		{
			std::cout << "enter age of " << names[i] << '\n';
			std::cin >> x;

			if( x > 0 && x < 115)
			{
				ages.push_back(x);
			}
			else
			{
				throw InvalidAge{x};
			}
		}
	}

	void Name_pairs::print_all()
	{
		if(names.size() != ages.size())
		{
			std::cerr << "size mismatch of ages and names\n";
			return;
		}
		for(int i = 0;i < names.size();i++)
		{
			std::cout << '[' << names[i] << ',' << ages[i] << ']' <<'\n';
		}
	}
	void Name_pairs::sort_all()
	{
		if(names.size() != ages.size())
		{
			std::cerr << "size mismatch of ages and names\n";
			return;
		}
		for(int i=1;i<names.size();i++)
		{
			std::string temp = names[i];
			double tempAge = ages[i];
			int j = i-1;

			while(j>=0 && temp < names[j])
			{
				names[j+1] = names[j];
				ages[j+1] = ages[j];
				j--;
			}

			names[j+1] = temp;
			ages[j+1] = tempAge;
		}
	}


	 int main(int argc, char *argv[])
	 {
	 	Name_pairs ns;

		try
		{
			ns.read_names(5);
			ns.sort_all();
			std::cout << ns;
		}
		catch( ... )
		{
			std::cout << "error occured!\n";
			return 1;
		}

	  return 0;
	 }
