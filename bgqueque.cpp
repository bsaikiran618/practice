#include <stdlib.h>
#include <iostream>

 int main()
 {
    int n(0),t(0),i,j;
	 char temp;

	 std::cin >> n;
	 std::cin >> t;


    char *initial = (char *) malloc((n+1) * sizeof(char));
	 
	 for(i=0;i<n;i++)
	 {
	   std::cin >> temp;

		if(temp!='\n')
		 {
		   initial[i]=temp;
		 }
	 }

	  initial[n] ='\0';

	 for(i=0;i<t;i++)
	 {
	   
		for(j=0;j<n-1;j++)
		{
		  if(initial[j]=='B' && initial[j+1]=='G')
		  {
		    initial[j]='G';
			 initial[j+1]='B';

			 j=j+1;
		  }
		}
	 
	 }

  std::cout << initial << std::endl ; 
 return 0;
 }
