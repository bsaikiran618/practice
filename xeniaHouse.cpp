#include <iostream>
#include <stdint.h>

 int main()
 {

   long int n,i,j,m,x,cur_pos(1);
   uint64_t time(0);


  std::cin >> n >> m;

  for(i=0;i<m;i++)
  {
    std::cin >> x;

	  if(x>cur_pos)
	  {
	    time+= (x-cur_pos);
	  }
	  else if(x<cur_pos)
	  {
	    time+= n-(cur_pos-x);
	  }
     
	  cur_pos = x;
  }
 
 std::cout << time << '\n';
 
  return 0;
 }
