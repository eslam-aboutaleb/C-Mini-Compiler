#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "LinkedList_interface.h"

int main(void)
{
	
	Function_st Func = {
		"Eslam", 3
	};
	Function_st Func2 = {
		"ali", 3
	};
	Node *Head = NULL;
	if(List_xAddNodeFirst(&Head,&Func)==lIST_HEAP_SIZEOUT_ERROR)
	{
		printf("NO Storage");
	}if(List_xAddNodeFirst(&Head,&Func2)==lIST_HEAP_SIZEOUT_ERROR)
	{
		printf("NO Storage");
	}
	List_xPrint(Head);
	

	return 0;
}
