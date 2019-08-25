#include <stdio.h>
#include <stdlib.h>

 int main(int argc, char*argv[])
 {
 		int n,i,j;

		scanf("%d",&n); // get the no of  numbers.

		// now create an array of n numbers.

		int *unsorted = malloc( n*sizeof(int));
		
		// also allocate space for sorted array.

		int *sorted = malloc(n * sizeof(int));

		// read all the integers.

		for(int i=0;i < n;i++)
		{
			scanf("%d",&unsorted[i]);
			// copy content of unsorted into sorted.
			sorted[i] = unsorted[i];
		}
		
		// perform sort.

		for(int i=1;i<n;i++)
		{
			int j=i-1;
			int temp = sorted[i];

			 while(j>=0 && sorted[j]>temp)
			 {
			 	sorted[j+1] = sorted[j];
				j--;
			 }
			 sorted[j+1] = temp;
		}

		int index = 0;
		
		while(index <= n-1)
		{
			int number = 1;
				for(i=index+1;i<n;i++)
				{
					if(sorted[i-1] == sorted[i])
					number++;
				}

			// the number we are checking for is sorted[index].

			int first_index;

			 for(i = 0;i<n;i++)
			 {
			 	if(unsorted[i] == sorted[index])
				 {
				 	first_index = i;
					break;
				 }
			 }
			
			 int difference = 0;

			 	while(difference <= n-1)
				{
					int isAP = 0;
					j=number;

					for(i = first_index;i<n && j>0; i+=difference)
					{
						if(unsorted[i]!=sorted[index])
						{
							isAP = 0;
							break;
						}
						else
						{
							isAP = 1;
							j--;
						}
					}

					if(isAP)
					{
						printf("%d %d\n",sorted[index], difference);
					}

					difference++;
				}
			
			index+=number;

		}
		
		return 0;
 }
