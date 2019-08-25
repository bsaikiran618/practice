#include <iostream>
#include <vector>


 int main()
 {
 	int s,n,i,x,j,temp,temp2;
	std::vector <int> dragons;
	std::vector <int> power_up;

	std::cin >> s >> n;

	while(n--)
	{
	  std::cin >> x;
	  dragons.push_back(x);
	  std::cin >> x;
	  power_up.push_back(x);
	}

	for(i=1;i<dragons.size();i++)
	{ 
	   j = i-1;
		temp = dragons[i];
		temp2 = power_up[i];

		 while(j>=0 && temp<dragons[j])
		 {
		   dragons[j+1]=dragons[j];
			power_up[j+1]=power_up[j];
			j--;
		 }
	  dragons[j+1] = temp;
	  power_up[j+1]=temp2;
	}

	for(i=0;i<dragons.size();i++)
	{
		if(dragons[i]>=s)
		{
		  std::cout << "NO\n";
		  return 0;
		}
		else
		{
		  s+=power_up[i];
		}
	}

	std::cout << "YES\n";
 
   return 0;
 }
