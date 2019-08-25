#include <iostream>

 int main()
 {

  int k,l,m,n,d,i,casualities(0);

  std::cin >>k >>l >>m >>n >>d;

  for(i=1;i<=d;i++)
  {
    if(i%k==0)
	  casualities++;
	 else if(i%l==0)
	  casualities++;
	 else if(i%m==0)
     casualities++;
	 else if(i%n==0)
	  casualities++;
  }

  std::cout << casualities << '\n';
 
  return 0;
 }
