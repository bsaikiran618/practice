#include <stdio.h>


 void get_directions(int x1,int y1, int x2, int y2, char dirs[])
 {
   int x_diff = ((x2-x1)<0)?(x1-x2):(x2-x1);
	int y_diff = ((y2-y1)<0)?(y1-y2):(y2-y1);
	
	char c = (x2-x1)<0?'W':'E';
	int i;

	for(i=0;i<x_diff;i++)
	dirs[i] = c;
	
	c = (y2-y1)<0?'S':'N';

	for(;i<y_diff;i++)
	dirs[i] = c;
 }


 int main()
 {
 	unsigned long int start_x,start_y;
	unsigned long int end_y,end_y;
	unsigned long int total_time;
	char *target_directions,*given_directions;

	scanf("%lu",&total_time);
	scanf("%lu%lu%lu%lu",&start_x,&start_y,&end_x,&end_y);

	given_directions = (char *)malloc(sizeof(char) * total_time);

	scanf("%s",given_directions);

	unsigned int x_diff = (start_x - end_x)<0?(-1*(start_x-end_x)):start_x-end_x;

	unsigned int y_diff = (start_y - end_y)<0?(-1*(start_y-end_y)):start_y-end_y;

	unsigned int min_time = x_diff+y_diff;

	if(min_time > strlen(given_directions))
	{
		puts("-1\n");
		return 0;
	}

   
	
	return 0;
 
 }
