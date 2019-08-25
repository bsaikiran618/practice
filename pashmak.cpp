#include <iostream>
#include <cstdlib>

unsigned long int sum(unsigned long int n);

  int main()
  {	
  	unsigned long int n,temp,x,min,max,min_n(0),max_n(0);
	long long int i,j;
	unsigned long int *nums;


	std::cin >> n;

	nums = (unsigned long int *) malloc(n * sizeof(unsigned long int));
	i=0;

	for(i=0;i<n;i++){
	std::cin >> nums[i];
	}


	for(i=1;i<n;i++)
	{
	  j=i-1;
	  temp = nums[i];

	  while(j>=0 && temp<nums[j])
	  {
	  	 nums[j+1]=nums[j];
	    j--;
	  }
	  nums[j+1] = temp;
	}

	min = nums[0];
	max = nums[n-1];

	for(i=0;i<n;i++)
	{
		if(nums[i]==min)
		{
			min_n++;
		}
		else
		break;
	}
	for(i=n-1;i>=0;i--)
	{
		if(nums[i]==max)
		{
			max_n++;
		}
		else
		break;
	}

	if(max == min)
	{
		std::cout << 0 << ' ' << sum(max_n);
	}
	else
	{
		std::cout << max-min << ' ' << (max_n*min_n);
	}

  	return 0;
  }

unsigned long int sum(unsigned long int n)
{
  unsigned long int sumn(0);
	n--;

  while(n>=1)
  {
  sumn+=n;
  n--;
  }
  return sumn;
}
