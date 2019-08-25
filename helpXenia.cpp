#include <iostream>
#include <stdlib.h>


 int main()
 {
  char *str = (char *) malloc(100 * sizeof(char));
  int len(0),i(0),temp,j,n,*nums;

  std::cin >> str ;

  while(str[len++]!='\0');
  len--;

  n = (len+1)/2;

  nums = (int *) malloc(n * sizeof(int));
  j=0;

  for(i=0;i<len;i++)
  { 
    if(str[i]>=48 && str[i]<=57)
	 {
	   nums[j]=0;

		while(str[i]>=48 && str[i]<=57)
		{
		  nums[j] = (nums[j] * 10)+(str[i]-48);
		  i++;
		}
		
		j++;
	 }
  }

  for(i=0;i<n-1;i++)
  {
    for(j=0;j<n-1-i;j++)
	 {
	   if(nums[j+1] < nums[j])
		 {
		   nums[j+1] = nums[j+1] + nums[j];
			nums[j] = nums[j+1] -nums[j];
			nums[j+1] = nums[j+1] - nums[j];
		 }
	 }
  }

  for(i=0;i<n-1;i++)
  {
    std::cout << nums[i] <<'+';
  }

	std::cout << nums[i] << '\n';

	return 0;

 }
