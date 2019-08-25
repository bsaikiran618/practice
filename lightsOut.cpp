#include <iostream>
#include <stdlib.h>
#include <stdio.h>

void changeState(int arr[][3] ,int x,int y);
void flip(int *num);

 int main()
 {
    int times_grid[3][3],lights_grid[3][3];
	 int i,j,t,k;

	for(i=0;i<3;i++)
	{
	  for(j=0;j<3;j++)
	  {
	    std::cin >> times_grid[i][j];
	    lights_grid[i][j] = 1;
		}
	}

	for(i=0;i<3;i++)
	{
	  for(j=0;j<3;j++)
	  {
	    t = times_grid[i][j];
        
		  for(k=0;k<t;k++)
		  {
		     changeState(lights_grid,i,j);
		  }
	  
	  }
	}

	for(i=0;i<3;i++)
	{
	 for(j=0;j<3;j++)
	 	  std::cout <<lights_grid[i][j];

		 std::cout << '\n';
    }
 }

 void changeState(int arr[][3],int x,int y)
 {
   
	 flip(&(arr[x][y]));

	 if((x-1) >= 0)
	 {
	   flip(&(arr[x-1][y]));
	 }
	 if((x+1) < 3)
	 {
		flip(&(arr[x+1][y]));
	 }
	 if((y-1) >= 0)
	 {
	   flip(&(arr[x][y-1]));
	 }
	 if((y+1) <3)
	 {
      flip(&(arr[x][y+1]));
     }
 }
 void flip(int *num)
 {
    if(*num==1)
	 *num = 0;
	 else 
	 *num = 1;
 }
