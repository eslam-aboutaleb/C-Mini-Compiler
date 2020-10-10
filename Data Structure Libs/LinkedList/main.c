#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "LinkedList_interface.h"

int main(void)
{
	Node *Head = NULL;
	if(List_xAddNodeFirst(&Head,5)==lIST_HEAP_SIZEOUT_ERROR)
	{
		printf("NO Storage");
	}if(List_xAddNodeFirst(&Head,6)==lIST_HEAP_SIZEOUT_ERROR)
	{
		printf("NO Storage");
	}if(List_xAddNodeFirst(&Head,20)==lIST_HEAP_SIZEOUT_ERROR)
	{
		printf("NO Storage");
	}if(List_xAddNodeFirst(&Head,10)==lIST_HEAP_SIZEOUT_ERROR)
	{
		printf("NO Storage");
	}
	
	List_xInsertNodeNth(&Head,200,3);

	List_xPrint(Head);
	List_xDeleteNode(&Head,1);
	List_xPrint(Head);
	List_xReverse(&Head);
	

	List_xPrint(Head);


	return 0;
}
