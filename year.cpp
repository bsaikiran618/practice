#include <iostream>
#include <stdlib.h>
#include <stdio.h>

int nextYear(int y);

 int main()
 {
   int y;

	std::cin >> y;
	y=nextYear(y);
   std::cout << y;

	return 0;
	
 }

 int nextYear(int y)
 {
  int temp,i,j,k;
  int digits[4];
  bool repeats =false;


  for(k=y+1;;k++)
  {
   repeats =false;
	temp=k;
	i=3;

	while(temp>0 && i>=0)
	{
	  digits[i--] = temp%10;
	  temp/=10;
	}


	for(i=1;i<4;i++)
	{
	 temp=digits[i];
	 j=i-1;

	  while(digits[j]>temp && j>=0)
	  {
	    digits[j+1] = digits[j];
		 j--;
	  }
	 
	 digits[j+1]=temp;
	}


	for(i=1;i<4;i++)
	{
	  if(digits[i-1] == digits[i])
	  {
	    repeats =true;
		 break;
	  }
	}
   
   if(repeats == false)
    return k;
  }
  return y;
 }
