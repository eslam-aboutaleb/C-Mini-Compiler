/* ************************************************************ */
/* Author: Eslam Ehab Aboutaleb									*/
/* Date	 : 8/10/2020											*/
/* ************************************************************ */

#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "Stack_interface.h"
static ERROR_STATUS Stack_xCreateNode(StackNode **Copy_ppNode)
{
	/* Create temp node */
	StackNode *TempNode = (StackNode *)malloc(sizeof(StackNode));
	/*If there is space in heap return E_OK else return E_NOK */
	if(NULL == TempNode)
	{
		return E_NOK;
	}
	/* Assign TempNode to the argument node */
	*Copy_ppNode = TempNode;
	/* Free temp node */
	return E_OK;
}

static StackState_t Stack_xIsEmpty(StackNode *Copy_ppNode)
{
	if(NULL == Copy_ppNode)
	{
		return STACK_IS_EMPTY;
	}
	else
	{
		return STACK_NOT_EMPTY;
	}
}



ERROR_STATUS Stack_xPush(StackNode **Copy_ppHead , StackType Copy_xData)
{
	StackNode *TempNode = NULL;
	/* Check if there is enough heap memory */
	if(E_NOK == Stack_xCreateNode(&TempNode))
	{
		return STACK_HEAP_SIZEOUT_ERROR;
	}
	/* Assign data to temp node */
	TempNode->Data = Copy_xData;
	/* If the list is empty */
	if(STACK_IS_EMPTY == Stack_xIsEmpty(*Copy_ppHead))
	{
		/* Assign its link to null as it is the first node */
		TempNode->Next = NULL;
	}
	else
	{
		/* Assign its link to the old head */
		TempNode->Next = *Copy_ppHead;
	}
	/* Assign temp as new head */
	*Copy_ppHead = TempNode;
	
	return E_OK;
}

ERROR_STATUS Stack_xPop(StackNode **Copy_ppHead , StackType *Copy_pxRecvData) 
{
	/* Check if there is an exisiting data first */
	if(STACK_IS_EMPTY == Stack_xIsEmpty(*Copy_ppHead))
	{
		return STACK_EMPTY_STACK_ERROR;
	}
	
	*Copy_pxRecvData = (*Copy_ppHead)->Data;
	StackNode *TempNode = *Copy_ppHead;
	*Copy_ppHead = (*Copy_ppHead)->Next;
	free(TempNode);
	TempNode = NULL;
	return E_OK;
}

ERROR_STATUS Stack_xPrint(StackNode * Copy_pHead)
{
	if( STACK_IS_EMPTY==Stack_xIsEmpty(Copy_pHead))
	{
		return STACK_EMPTY_STACK_ERROR;
	}
	printf("Stack is: ");
	/* Traverse the list until NULL */
	while( NULL != Copy_pHead)
	{
		printf("%d\t", Copy_pHead->Data);
		Copy_pHead = Copy_pHead->Next;
	}
	printf("\n");

	return E_OK;
}

