#include <iostream>
#include <cstdlib>

 int main()
 {
   int *children;
	int m,n,i, children_satisfied(0),child_no;

	std::cin >> n >> m;

	children = (int *) malloc(n * sizeof(int));

	for(i=0;i<n;i++)
	std::cin >> children[i];

	while(children_satisfied < n)
	{
	  for(i=0;i<n;i++)
	  {
	    if(children[i] != -1)
	    {
			 if((children[i]-m) <= 0)
			 {
			 	child_no = i+1;
			   children_satisfied++;
				children[i] = -1; //go home.
			 }
			 else
			 {
			   children[i]-=m;
			 }
		 }
	  }
	}

	std::cout << child_no << '\n';

	return 0;
 }
