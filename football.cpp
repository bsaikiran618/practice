#include <iostream>

 int strequal(char *str1,char *str2)
 {
   int i,len1(0),len2(0);

	 while(str1[len1++]!='\0');
	 len1--;
	 while(str2[len2++]!='\0');
	 len2--;
		
		if(len1==len2)
		{
			for(i=0;i<len1;i++)
			{
			  if(str1[i]!=str2[i])
			   return 0;
			}
			return 1;
		}
		
		
   return 0;
 }

 int main()
 {
   char name1[13],str[13],name2[13];
	int  score1(0),score2(0);
	int  n,i,j,len1(0),len2(0);

	std::cin >> n;

	std::cin >> str;

	while(str[len1++]!='\0');
	len1--;

	for(i=0;i<=len1;i++)
	{
		name1[i]=str[i];
	}

	score1++;

	n--;

	while(n--)
	{
	  std::cin >> str;
		
		if(strequal(str,name1))
		 score1++;
		else
	    {
		   score2++;
			while(str[len2++]!='\0');
			len2--;

			for(i=0;i<=len2;i++)
			{
			  name2[i]=str[i];
			}
			n--;
			break;
		 }
	  
	}

	while((n--)>=0)
	{
		std::cin >> str;

	  if(strequal(str,name1))
	  {
	    score1++;
	  }
	  else
	  {
	    score2++;
	  }
	}

	(score1>score2)?(std::cout << name1) :( std::cout << name2);
	
	std::cout << '\n';

	return 0;

 }


