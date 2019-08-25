#include <iostream>
#include <cstdlib>

 int main()
 {

  int n,i,j,k,len(0),diff(0), *count;
  char str[1001], *diff_letters;

  std::cin >> n;

  std::cin >> str;

  while(str[len++]!='\0');
  len--;

  diff_letters = (char*) malloc((len/n) * sizeof(char));
  count = (int*) calloc(1,(len/n) * sizeof(int));


	for(i=0;i<len;i++)
	{
	  if(str[i]!='\t')
	  {
	    diff_letters[diff] = str[i];
		 count[diff]++;

		 for(j=i+1;j<len;j++)
		 {
		   if(str[j]==str[i])
			  {
				  count[diff]++;
				  str[j] = '\t';
			  }
		 }

		 diff++;
	  }
	}


	for(i=0;i<diff;i++)
	{
	  if((count[i]%n)!=0)
	  {
	    std::cout << -1 << '\n';
		 return 0;
	  }
	}



	for(i=0;i<n;i++)
	{
		for(j=0;j<diff;j++)
		{
		  for(k=0;k<(count[j]/n);k++)
		    std::cout << diff_letters[j];
		}
	
	}

	std::cout << '\n';
 
   return 0;
 }
