#include <iostream>
#include <fstream>
using namespace std;

 int main()
 {
 	char str[512]; // name of input file.
	ifstream in;
	int sum = 0,x;


	 cout << "Enter the name of the file\n";
	 cin >> str;

	in.open(str);

	if(!in)
	{
		cout << "Couldnt open " << str << endl;
		return 1;
	}


	 while(in >> x)
	 {
	 	sum+=x;
	 }

	cout << "Sum is " << sum << endl;

	return 0;
 }
