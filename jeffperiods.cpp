#include <iostream>
#include <vector>
using namespace std;


 int main()
 {
 	int n;
	short done = -1;
	 int *arr;
	 int *nums;
	 int *diffs;

	cin >> n;
	arr = new int[n];
	nums = new int[n];
	diffs = new int[n];

	for(int i=0;i<n;i++)
	cin >> arr[i];

	int count = 0;

	for(int i=0;i<n;i++)
	{
		
		if(arr[i] == done)
		continue;

	  int hasCopy = 0;
	  int diff = 0;
	  int prevpos=i;
	  int isAP = 1;
	  int j;
	   
		for(j=i+1;j<n;j++)
		{
			if(arr[j]  == arr[i])
				{
				  hasCopy = 1;
				  diff = j-i;
				  arr[j] = done;
				  prevpos = j;
				  break;
				}
		}

		if(hasCopy)
		for(j=j+1;j<n;j++)
		{
			if(arr[j] == arr[i])
			{
				if(diff != (j-prevpos))
				{
					isAP = 0;
					break;
				}
				arr[j] = done;
				prevpos = j;
			}
		}
			
			if(isAP)
			{
				count++;
				if(count == 1)
				{
					nums[count-1] = arr[i];
					diffs[count-1] = diff;
				}
				else
				{
					int x = count-1;
					while(x >=0 && nums[x]>arr[i])
					{
						nums[x+1] = nums[x];
						diffs[x+1] = diffs[x];
						x--;
					}
					if(i!=0)
					{
					nums[x+1] = arr[i];
					diffs[x+1] = diff;
				   }
				}
			}
			arr[i] = done;
	  }


	cout << count << endl;

	for(int i=0;i<count;i++)
	{
		cout << nums[i] << ' ' << diffs[i] << endl;
	}

	return 0;

 }
