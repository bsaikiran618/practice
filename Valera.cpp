#include <iostream>

 int main()
 {
  
   unsigned long int nums[4],temp;
	short i,j,shoes(0);


	std::cin >> nums[0] >> nums[1] >> nums[2] >> nums[3];

	for(i=1;i<4;i++)
	{
	  j=i-1;
	  temp=nums[i];

	  while(nums[j]>temp && j>=0)
	  {
		 nums[j+1] = nums[j];
		 j--;
	  }
	  nums[j+1] = temp;
	}

	for(i=1;i<4;i++)
	{
	  if(nums[i]==nums[i-1])
	  {
	    shoes++;
	  }
	}

	std::cout << shoes << '\n';

 
   return 0;
 }
