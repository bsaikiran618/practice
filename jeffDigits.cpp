#include <iostream>
#include <cstdlib>

 int main()
 {

  int *arr,n,i,fives(0),zeroes(0);

  std::cin >> n;
	
	arr = (int * ) malloc(n * sizeof(int));

	for(i=0;i<n;i++)
	 std::cin >> arr[i];

	for(i=0;i<n;i++)
	{
	  
	  if(arr[i]==5)
	  fives++;
	  else if(arr[i]==0)
	  zeroes++;
	}

   
	while(fives%9!=0)
	fives--;

  if(zeroes>=1 && fives%9==0)
  {
    for(i=0;i<fives;i++)
	 {
	   std::cout << '5';
	 }
	  
	  
	   std::cout << '0';
		zeroes--;
	   
		if(fives>=1)
		for(i=0;i<zeroes;i++)
		{
		 std::cout << '0';
		}

	 std::cout << '\n';

	 return 0;
  }

	std::cout << -1 << '\n';
 
  return 0;
 }
