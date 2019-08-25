#include <iostream>
#include <vector>


 int main()
 {
 	int n,m,x,i,j,temp,min_diff;
	std::vector <unsigned int> pieces;

	std::cin >> n >> m;

	while(m--)
	{
	  std::cin >> x;
	  pieces.push_back(x);
	}

	for(i=1;i<pieces.size();i++)
	{
	  temp = pieces[i];
	  j	 = i-1;

	  while(j>=0 && temp < pieces[j])
	  {
	    pieces[j+1] = pieces[j];
		 j--;
	  }
	  pieces[j+1] = temp;
	}

	min_diff = pieces[n-1]-pieces[0];

	i=1;

	 while((i+n-1) < pieces.size())
	 {
	   if((pieces[i+n-1] - pieces[i])<min_diff)
			min_diff = pieces[i+n-1] - pieces[i];

			i++;
	 }

	std::cout << min_diff << '\n';
 
   return 0;
 }
