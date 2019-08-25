#include <iostream>
#include <string>
#include <vector>

struct X
{
	void f(int x) // function inside struct X
	{
		struct Y
		{
			int f() // function inside struct Y
			{
				return 1;
			}
			int m; // member of struct Y
		};

		int m; //member of function f
		m=x;
		Y m2;
		
		return f(m2.f()); // infinite recursion , causes Seg-fault.
	}

	int m; //member of struct X

	void g(int m)
	{
		if(m)
		f(m+2);
		else
		{
			g(m+2);
		}
	}

	X()
	{
		//empty constructor
	}

	void m3()
	{
		//empty function
	}
};

	int main() //this is a bug.
	{
		X a;
		a.f(2);
	}

