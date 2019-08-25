#include <iostream>
#include <vector>

 int main()
 {
 	unsigned int n;
	unsigned long long int x,min,max,min_n(0),max_n(0);

	std::vector <unsigned long long int> beautyIndex;

	std::cin >> n; // no_of_flowers

	for(unsigned int i=0;i<n;i++)
	{
		std::cin >> x;
		beautyIndex.push_back(x);
	}

	max = beautyIndex[0];
	max_n = 1;
	min = beautyIndex[0];
	min_n = 1;
	
	for(unsigned int i=1;i<n;i++)
	{
		if(beautyIndex[i] == max)
		{
			max_n++;
		}
		if(beautyIndex[i] > max)
		{
			max_n =1;
			max = beautyIndex[i];
		}
		if(beautyIndex[i] == min)
		{
			min_n++;
		}
		else if(beautyIndex[i] < min)
		{
			min_n =1;
			min = beautyIndex[i];
		}
	}

	std::cout << max - min << ' ';

	if(max == min)
	{
		std::cout <<((max_n * (max_n -1))/2);
	}
	else
	{
		std::cout << max_n*min_n << '\n';
	}


	return 0;
 }
