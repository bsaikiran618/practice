#include <iostream>

 int main()
 {
 	int i,j,k,n;

	std::cin >> n;

	k=n;

	for(i=0;i<n+1;i++)
	{
	  for(j=0;j<2*k;j++)
	  std::cout << ' ';
	  for(j=0;j<i;j++)
	  std::cout << j << ' ';
	  for(j=i;j>=1;j--)
	  std::cout << j << ' ';
	  if(j==0)
	  std::cout << j ;

	  k--;

	  std::cout << '\n';
	}

	k=1;

	for(i=0;i<n;i++)
	{
	  for(j=0;j<2*k;j++)
	  std::cout << ' ';
	  for(j=0;j<(n-i-1);j++)
	  std::cout << j << ' ';
	  for(j=n-i-1;j>=1;j--)
	  std::cout << j << ' ';
	  if(j==0)
	  std::cout << j ;

	  k++;
	  std::cout << '\n';
	}

	return 0;
 }
