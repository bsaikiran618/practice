#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


 int main(int argc, char *argv[])
 {
    if(argc!=2)
	 {
	 		std::cout << "Usage : temp_stats <filename>" << std::endl;
			return 1;
	 }
    const char *filename = argv[1];
    ifstream input_file{filename};

	 if(!input_file)
	 {
	 	std::cout << "Couldnt open file " << filename << std::endl;
	 }

	 double mean,median,x;
	 double sum = 0;
	 int number = 50;

	 std::vector<double> temps;

	   while(input_file >> x >> x)
		{
			temps.push_back(x);
			sum+=x;
		}
		int i,j,tempor;

		for( i=1;i<temps.size();i++)
		{
			 j = i-1;
			 tempor = temps[i];

			  while(j>=0 && tempor<temps[j])
			  {
			    temps[j+1] = temps[j];
				 j--;
			  }
 			temps[j+1] = tempor;
		}

		mean = sum/temps.size();
		
		  if(temps.size()%2 == 0)
		  {
		    median = (temps[temps.size()/2]+temps[(temps.size()/2) +1])/2;
		  }
		  else
		  {
		    median = temps[temps.size()/2];
		  }

		  cout << "mean temp: "  << mean << endl;
		  cout << "median temp : "<< median << endl; 

		return 0; 
 }
