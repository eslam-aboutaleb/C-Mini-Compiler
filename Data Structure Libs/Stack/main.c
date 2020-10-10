#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "Stack_interface.h"
int main(void)
{
	StackNode *  Stack_p = NULL;
	int data;
	Stack_xPush(&Stack_p,50);
	Stack_xPush(&Stack_p,10);
	Stack_xPush(&Stack_p,20);
	Stack_xPush(&Stack_p,30);
	Stack_xPop(&Stack_p,&data);
	Stack_xPrint(Stack_p);
	printf("Data = %d",data);
	
	return 0;
}