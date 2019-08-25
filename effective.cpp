#include <iostream>
#include <cstdlib>

 int main()
 {
	int queries; 
   int *arr;
	unsigned int search,i,n;
	unsigned long long int v(0),p(0);                   // these can get quite big

	std::cin >> n;                            // get number of numbers.

	arr = (int*) calloc(1,n * sizeof(int));   // make array.

	for(i=0;i<n;i++)
	 std::cin >> arr[i];                      // get values of array.

	 std::cin >> queries;                     // get no of queries

	 while(queries--)
	 {
	   std::cin >> search;                    // get query

		for(i=0;(i<n && (arr[i]!=search));i++); //this loops through 
														   //the array until 'search' is found.
	  
	  v += i+1;                               // vasya's comparisons are going to be same as i+1
	  p += n-i;                               // petya's comparisons are going to be [n- vasya's_comparisons] ,because the 
	  			                                	// search value exists only once in the array since it is a permutation of all
				                               	// numbers from 1 to n.
	 }

	 std::cout << v << ' ' << p << '\n'; // print result.
 
   return 0;
 }
