#include <stdio.h>
#include <stdlib.h>

 int main()
 {
	int n,i,j,temp;
	int *arr;
	int *sorted;
	int *diffs;
	int count = 0;
	scanf("%d",&n);
	
	arr = (int *)calloc(1,n * sizeof(int));
	sorted=(int*)calloc(1,n*sizeof(int));
	diffs = (int*)calloc(1,n*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}

	// perform insertion sort
	i=0;
	while(i<n)
	{
		if(arr[i] == 0) // ill be using 0 to indicate that the number
							 // has been checked.
		{
		  i++;
		  continue;
		}
		
		int diff = 0;
		int prevdiff = diff;
		int isAP = 1;
		int prevpos = i;

		//find first repetition of arr[i]

		for(j=i+1;j<n;j++)
		{
			if(arr[j] == arr[i])
			{
			 diff = j-i;
			 prevpos = j;
			 arr[j] = 0;
			 break;
			}
		}
		
		prevdiff = diff;

		// now check if difference is maintained.

		for(j=prevpos+1;j<n;j++)
		{
			if(arr[j] == arr[i])
			{
				diff = j-prevpos;
				if(diff!=prevdiff)
				{
					arr[j]=0; // kill the number
					
					for(int k=j+1;k<n;k++) // kill all occurences of the number.
					if(arr[k] == arr[i])
					arr[k] = 0;

					isAP = 0;
					break;
				}
				prevdiff = diff;
				prevpos = j;
				arr[j] = 0;
			}
		}
		
			if(isAP)
			{
				count++;
				//insert the element into the sorted group using insertion sort
				
				j=count-2;
				temp = arr[i];

				while(j>=0 && sorted[j]>temp)
				{
					sorted[j+1] = sorted[j];
					diffs[j+1] = diffs[j];

					j--;
				}
				 sorted[j+1] = temp;
				 diffs[j+1] = diff;
			}

		arr[i] = 0;	// mark the element as checked.
		i++;
	}

	printf("%d\n",count);

	for(i=0;i<count;i++)
	{
		if(sorted[i]!=0)
		printf("%d %d\n",sorted[i],diffs[i]);
	}

 	return 0;
 }
