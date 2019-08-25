#include <iostream>
#include <cstdlib>

 int main()
 {
   int n,i,j;
	int *xs,*ys;
	int left(0),right(0),above(0),below(0);
	int central(0);

	std::cin >> n;

	xs = (int*) malloc(n*sizeof(int));
	ys = (int*) malloc(n*sizeof(int));

	for(i=0;i<n;i++)
	{
	  std::cin >> xs[i] >> ys[i] ;
	}
   
	for(i=0;i<n;i++)
	{
		left=right=above=below=0;

		for(j=0;j<n;j++)
		{
		  if(j==i)
		  continue;

		  if(xs[j]<xs[i] && ys[j]==ys[i])  //point left
		   left++;
		  if(xs[j]>xs[i] && ys[j]==ys[i])  //point right
		   right++;
		  if(xs[j]==xs[i] && ys[j]>ys[i])  //point above
		   above++;
		  if(xs[j]==xs[i] && ys[j]<ys[i])  //point below
		   below++;
		}
		
		if(left>=1 && right>=1 && above>=1 && below>=1)
		 central++;

	}

	std::cout << central << '\n';

	return 0;
 }
