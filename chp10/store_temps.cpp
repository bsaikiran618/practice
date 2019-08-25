#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>

using namespace std;

 int main()
 {
	int hour;
	double temperature;
	char suffix;

	srand(time(0));

	ofstream outfile {"raw_temps.txt"};

	if(!outfile)
	{
		cout << "Couldnt write/create raw_temps.txt" << endl;
	}

	 for(int i=1;i<50;i++)
	 {
	    hour = (rand()%25);
		 temperature = (rand()%1000) /10.0;

		 suffix = (hour > 12)?'c':'f';
		 

		 outfile << hour << " " << temperature << suffix << endl;
	 }

	 return 0;
 }
