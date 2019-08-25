#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct point
{
  int x;
  int y;
};


 int main()
 {
  cout << "Us3r pl35s3 3nter s3v3n p5irs 0f p01nts\n";
	vector<struct point> original_points;

	ofstream output_file {"mydata.txt"};
	if(!output_file)
	{
	  cout << "Couldnt open the output file" << endl;
	}

   for(int i=0;i<7;i++)
	{
		struct point newPoint;
		cin >> newPoint.x >> newPoint.y ;
		if(cin)
		{
		 original_points.push_back(newPoint);
		}
		else
		{
			cout << "Cin not good." <<endl;
		}
	}

	for(struct point x: original_points)
	{
		output_file << x.x << ' ' << x.y << endl;
	}

   ifstream input {"mydata.txt"};

	if(!input)
	{
		cerr << "Coulnt open input file: mydate.txt\n";
	}

	vector<struct point> processed_points;
   int index = 0;
	  while(input.good())
	  {
	  		struct point newPoint;
	  	  input >> newPoint.x >> newPoint.y;
	  		if(input.good())
			{
				if(original_points[index].x!= newPoint.x || original_points[index].y!=newPoint.y)
				{
					cerr << "Data not same in both vectors!\n";
					break;
				}
				processed_points.push_back(newPoint);
				index++;
			}
	  }

		cout << "Elements of vector 1\n";

		for(struct point x:original_points)
		{
			cout << x.x << ' ' << x.y << endl;
		}
		cout << "Elements of vector 2\n";

		for(struct point x:processed_points)
		{
			cout << x.x << ' ' << x.y << endl;
		}

	if(original_points.size() != processed_points.size())
	{
		cout << "Number of datum different in both files\n";
	}


  return 0;
 }
