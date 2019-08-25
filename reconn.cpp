//this program has intentionally 
//been complicated to save memory
// in case of higher values of n.

// no matter what the value of n is,
// the code only uses 9 integers
// to generate the output.

// Yes this could be a case
// of unnecessary optimization.

// whatever.


#include <iostream>

 int main()
 {

 int n,diff;
 int i,min,fg,lg,x,pos1,pos2;
	
	std::cin >> n;

	std::cin >> fg;
	std::cin >> lg;

	pos1=0;
	pos2=1;

	min = ((lg-fg)<0)?(fg-lg):(lg-fg);

	for(i=2;i<n;i++)
	{
	  std::cin >> x;
		
	  diff = ((x-lg)<0)?(lg-x):(x-lg);

	  if(diff<min)
	  {
	    min =diff;
		 pos2=i;
		 pos1=i-1;
	  }
		
		lg=x;
	}

	diff = ((x-fg)<0)?(fg-x):(x-fg);
	if(diff<min)
	 {
	  pos1=0;
	  pos2=n-1;
	 }

	 std::cout << pos1+1 << ' ' << pos2+1 << '\n';

 return 0;
 }
