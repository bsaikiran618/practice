#include <iostream>

 int min(int x,int y,int z);

 int main()
 {
	int n,l,k,c,d,p,nl,np,toasts(0);
   unsigned int total_slices,total_drink;
   unsigned int no_of_salt;

	std::cin >>n >>k >>l >>c >>d >>p >> nl >> np;

	total_drink = (k * l)/nl;
	total_slices= c * d;
	no_of_salt  = p / np;

	toasts = min(total_drink,total_slices,no_of_salt);

	std::cout << (toasts/n) << '\n';

   return 0;
 }
  int min(int x,int y, int z)
  {
    return (x<y)?((x<z)?x:z):(y<z?y:z);
  }
