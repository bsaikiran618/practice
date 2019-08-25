#include <iostream>


 int main()
 {
	int k,months[12],i,j,temp,sum(0);


	std::cin >> k;

	for(i=0;i<12;i++)
	{
		std::cin >> months[i];
	}

	for(i=1;i<12;i++)
	{
	  temp =months[i];
	  j=i-1;

	  while(j>=0 && temp>months[j])
	  {
	    months[j+1] = months[j];
		 j--;
	  }

	  months[j+1] = temp;
	}



	i=0;

	while(i<12 && sum<k)
	{
		sum+=months[i];
		i++;
	}
	
	if(sum>=k)
	std::cout << i <<'\n';
	else
	std::cout << -1 << '\n';

	return 0;
 }
