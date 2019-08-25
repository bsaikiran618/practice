#include <iostream>

 int main()
 {

  char s[128];
  char c;
  int len(0);

  std::cin >> s;

  while(s[len++]!='\0');
  len--;

  while(len--)
  {
    std::cin >> c;

	 if(c!=s[len])
	 {
	   std::cout << "NO\n";
		return 0;
	 }
  }
  std::cout << "YES\n";

   return 0;
 }
