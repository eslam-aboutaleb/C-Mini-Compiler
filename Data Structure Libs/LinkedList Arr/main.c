#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "LinkedList_interface.h"

int main(void)
{
	
	Node *Head = NULL;
	if(List_xAddNodeFirst(&Head,"Eslam")==lIST_HEAP_SIZEOUT_ERROR)
	{
		printf("NO Storage");
	}if(List_xAddNodeFirst(&Head,"Ali")==lIST_HEAP_SIZEOUT_ERROR)
	{
		printf("NO Storage");
	}if(List_xAddNodeFirst(&Head,"al")==lIST_HEAP_SIZEOUT_ERROR)
	{
		printf("NO Storage");
	}if(List_xAddNodeFirst(&Head,"sad")==lIST_HEAP_SIZEOUT_ERROR)
	{
		printf("NO Storage");
	}
	printf("Hu");
	
	List_xInsertNodeNth(&Head,"aa",3);

	List_xPrint(Head);
	List_xDeleteNode(&Head,1);
	List_xPrint(Head);
	List_xReverse(&Head);
	

	List_xPrint(Head);


	return 0;
}
