#include <vector>
#include <iostream>

 int main()
 {
   int n,m,x,i,j,temp,max,min;
	std::vector <int> planes,planes2;

	std::cin >> n >> m;

	while(m--)
	 {
	 	std::cin >> x;
		planes.push_back(x);
	 }

	 for(i=1;i<planes.size();i++)
	 {
	 	temp = planes[i];
		j = i-1;

			while(j>=0 &&  temp < planes[j])
			{
			  planes[j+1] = planes[j];
			  j--;
			}
			planes[j+1] = temp;
	 }

	 for(i=0;i<planes.size();i++)
	 	planes2.push_back(planes[i]);

	x=0;
	temp = n;

	x+= planes[planes.size()-1];
	planes[planes.size()-1]--;

	temp--; //one seat occupied.

	while(temp--)
	{
		i=planes.size()-1;
		max = i;

		for(i=planes.size()-1;i>=0;i--)
		{
		  if(planes[i]>planes[max])
		   max = i;
		}
		
		x+=planes[max];
		planes[max]--;
	}

	std::cout << x << ' ';

	x=0;
	temp = n;

	while(temp--)
	{
		for(i=0;i<planes2.size() && planes2[i]<1;i++);
		min = i;

		for(i=min+1;i<planes2.size();i++)
		 if((planes2[i]>0) && (planes2[i]<planes2[min]))
		 	min = i;

		x+=planes2[min];
		planes2[min]--;
	}

	std::cout << x << '\n';

	return 0;
 }
