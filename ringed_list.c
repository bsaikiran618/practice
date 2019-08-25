// ringed list.

// going back by going forward



#include <stdio.h>

typedef struct NODE
{
 char c;

 struct NODE *next;
} node;

 int main(int argc, char *argv[])
 {
	node n1,n2,n3,*current;

	n1.c = 'A';
	n2.c = 'B';
	n3.c = 'C';

	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n1;
	
	current = &n1;

		for(int i = 0;i<10;i++)
		{
			printf("%c\n",current->c);
			current = current->next;
		}
 	
 
 	return 0;
 }
