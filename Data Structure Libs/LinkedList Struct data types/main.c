#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "LinkedList_interface.h"
#include "DataTypes_Libs.h"
int main(void)
{
	
	DataTypes_st Func = {
		"Eslam", 3
	};
	DataTypes_st Func2 = {
		"func", 3
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
