#include <iostream>
#include <stdint.h>

 int main()
 {	
 	uint64_t number(0),temp(0);
	int luckys(0);
	bool isLucky = true;
	short digit(0);
   
	std::cin >> number;
	
	temp=number;

	while(temp>0)
	{
	  digit = temp%10;
     if(digit==4 || digit==7)
	  {
	    luckys++;
	  }

	  temp/=10;
	}

  if(luckys==0)
  {
    isLucky = false;
	 goto end;
  }
	temp =luckys;
 
 

	while(temp>0)
	{
	 digit = temp%10;
	  if(digit!=4 && digit!=7)
	  {
	    isLucky =false;
		 break;
	  }
	 temp/=10;
	}

end:

   if(isLucky == false)
	{
	  std::cout << "NO";
	}
	else
	{
	  std::cout <<"YES";
	}
	std::cout << '\n';
 return 0;
 
 }
