#include <iostream>

 int main()
 {
  int n,leftOpen(0),leftClose(0),rightOpen(0),rightClose(0);
  int i,x,total(0);

  std::cin >> n;

	for(i=0;i<n;i++)
	{
	  std::cin >>x;
	  if(x==0)
	   leftClose++;
	  else
	   leftOpen++;
	  
	  std::cin >>x;
	  if(x==0)
	   rightClose++;
	  else
	   rightOpen++;
	}
   
   
	if(leftClose >= leftOpen )
	{
	  total+=leftOpen;
	}
	if(leftClose < leftOpen)
	{
	  total+=leftClose;
	}
	if(rightClose >= rightOpen)
	{
	  total+= rightOpen;
	}
	if(rightOpen > rightClose)
	{
	  total+= rightClose;
	}
	
	
   std::cout << total <<std::endl;

 return 0;
 }
