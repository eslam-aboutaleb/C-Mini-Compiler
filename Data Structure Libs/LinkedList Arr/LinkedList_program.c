/* ************************************************************ */
/* Author: Eslam Ehab Aboutaleb									*/
/* Date	 : 6/10/2020
/* ************************************************************ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STD_TYPES.h"
#include "LinkedList_interface.h"

/* Local functions prototypes */
static ERROR_STATUS List_xCreateNode(Node **Copy_ppNode);
static HeadState_t List_xIsEmpty(Node *Copy_ppNode);

static ERROR_STATUS List_xCreateNode(Node **Copy_ppNode)
{
	/* Create temp node */
	Node *TempNode = (Node *)malloc(sizeof(Node));
	/*If there is space in heap return E_OK else return E_NOK */
	if(NULL == TempNode)
	{
		return E_NOK;
	}
	/* Assign TempNode to the argument node */
	*Copy_ppNode = TempNode;
	/* Free temp node */
	//free(TempNode);
	return E_OK;
}


static HeadState_t List_xIsEmpty(Node *Copy_ppNode)
{
	if(NULL == Copy_ppNode)
	{
		return LIST_IS_EMPTY;
	}
	else
	{
		return LIST_NOT_EMPTY;
	}
}

ERROR_STATUS List_xAddNodeFirst(Node **Copy_ppHead , ListType Copy_xData)
{
	Node *TempNode = NULL;
	/* Check if there is enough heap memory */
	if(E_NOK == List_xCreateNode(&TempNode))
	{
		return lIST_HEAP_SIZEOUT_ERROR;
	}

	/* Assign data to temp node */
	TempNode->Data = malloc(sizeof(Copy_xData));
	strcpy((TempNode->Data),Copy_xData);
	/* If the list is empty */
	if(LIST_IS_EMPTY == List_xIsEmpty(*Copy_ppHead))
	{
		/* Assign its link to null as it is the first node */
		TempNode->Next = NULL;
	}
	else
	{
		/* Assign its link to the old head */
		TempNode->Next = *Copy_ppHead;
	}
	/* Assign temp as the new list head */
	*Copy_ppHead = TempNode;

	//free(TempNode);
	return E_OK;
}

ERROR_STATUS List_xAddNodeEnd(Node **Copy_ppHead , ListType Copy_xData)
{
	if(LIST_IS_EMPTY == List_xIsEmpty(*Copy_ppHead))
	{
		List_xAddNodeFirst(Copy_ppHead,Copy_xData);
	}
	else
	{
		Node *TempNode = NULL;
		/* Check if there is enough heap memory */
		if(E_NOK == List_xCreateNode(&TempNode))
		{
			return lIST_HEAP_SIZEOUT_ERROR;
		}

		TempNode->Data = malloc(sizeof(Copy_xData));
		strcpy(TempNode->Data,Copy_xData);
		TempNode->Next    = NULL;

		Node *CurrentNode = *Copy_ppHead;
		while(NULL != CurrentNode->Next)
		{
			CurrentNode = CurrentNode->Next;
		}
		CurrentNode->Next = TempNode;
	}
}


ERROR_STATUS List_xInsertNodeNth(Node **Copy_ppHead , ListType Copy_xData , u32 Copy_u32Position)
{
	/* check if is it the first position */
	if( 1 == Copy_u32Position)
	{
		List_xAddNodeFirst(Copy_ppHead,Copy_xData);
	}
	else
	{
		if(List_u32Count(*Copy_ppHead) < Copy_u32Position - 1 )
		{
			return LIST_OUT_LIMIT_POS_ERROR;
		}
		else
		{
			/* No Action */
		}

		Node *TempNode = NULL;
		Node *CurrnetNode = *Copy_ppHead;
		if(E_NOK == List_xCreateNode(&TempNode))
		{
			return lIST_HEAP_SIZEOUT_ERROR;
		}
		else
		{
			/* No Action */
		}

		u32 Index = 0;
		TempNode->Data = malloc(sizeof(Copy_xData));
		strcpy(TempNode->Data,Copy_xData);
		TempNode->Next = NULL;
		for(Index = 0; Index < Copy_u32Position - 2;Index++)
		{
			/* Traverse the list until position - 2 to access the node before desired node */
			CurrnetNode = CurrnetNode->Next;
		}

        /* Assign link of the temp node as link of its previous node */
		TempNode->Next 	  = CurrnetNode->Next;
		CurrnetNode->Next = TempNode;
	}

	return E_OK;
}

ERROR_STATUS List_xModifyNodeNth(Node **Copy_ppHead , ListType Copy_xData , u32 Copy_u32Position)
{
   if(LIST_IS_EMPTY == List_xIsEmpty(*Copy_ppHead))
    {
        return LIST_ACCESS_EMPTYLIST_ERROR;
    }

	if(List_u32Count(*Copy_ppHead) < Copy_u32Position )
	{
		return LIST_OUT_LIMIT_POS_ERROR;
	}

	Node *CurrnetNode = *Copy_ppHead;
	u32 Index = 0;
	for(Index = 0; Index < Copy_u32Position - 1;Index++)
	{
		/* Traverse the list until position - 2 to access the node before desired node */
		CurrnetNode = CurrnetNode->Next;
	}
	CurrnetNode->Data = malloc(sizeof(Copy_xData));
	strcpy(CurrnetNode->Data,Copy_xData);

	return E_OK;
}


ERROR_STATUS List_xDeleteNode(Node **Copy_ppHead ,u32 Copy_u32Position)
{
    if(LIST_IS_EMPTY == List_xIsEmpty(*Copy_ppHead))
    {
        return LIST_ACCESS_EMPTYLIST_ERROR;
    }

	if(List_u32Count(*Copy_ppHead) < Copy_u32Position )
	{
		return LIST_OUT_LIMIT_POS_ERROR;
	}

	Node *TempNode 	  = NULL;
	Node *CurrentNode = *Copy_ppHead;

	if( 1 == Copy_u32Position)
    {
        *Copy_ppHead = (*Copy_ppHead)->Next;
        free(CurrentNode);
		CurrentNode = NULL;
		return E_OK;
    }

    if(E_NOK == List_xCreateNode(&TempNode))
	{
		return lIST_HEAP_SIZEOUT_ERROR;
	}

	u32 Index = 0;
	for(Index = 0; Index < Copy_u32Position - 2; Index++)
	{
		CurrentNode = CurrentNode->Next;
	}
	TempNode = CurrentNode->Next;
    CurrentNode->Next = TempNode->Next;
	free(TempNode);
	TempNode = NULL;

	return E_OK;
}

ERROR_STATUS List_xReverse(Node **Copy_ppHead )
{
	if(LIST_IS_EMPTY == List_xIsEmpty(*Copy_ppHead))
    {
        return LIST_ACCESS_EMPTYLIST_ERROR;
    }

	if(List_u32Count(*Copy_ppHead) < 2 )
	{
		return E_OK;
	}
	Node *CurrentNode  = *Copy_ppHead;
	Node *PreviousNode = NULL;
	Node *NextNode     = NULL;
	while(CurrentNode != NULL)
	{
		/* 1- Make the next node what the current points to */
		NextNode 			= CurrentNode->Next;
		/* 2- Update the current link and make it points to the previous node */
		CurrentNode->Next	= PreviousNode;
		/* 3- Update the previous node as the current node */
		PreviousNode		= CurrentNode;
		/* 4- Update the current node as the next node */
		CurrentNode			= NextNode;
	}
	*Copy_ppHead = PreviousNode;
}


u32 List_u32Count(Node * Copy_pHead)
{
	u32 Count = 0;
	/* Traverse the list until NULL */
	while( NULL != Copy_pHead)
	{
		Count++;
		Copy_pHead = Copy_pHead->Next;
	}

	return Count;
}

ERROR_STATUS List_xPrint(Node * Copy_pHead)
{
	if( LIST_IS_EMPTY==List_xIsEmpty(Copy_pHead))
	{
		return LIST_ACCESS_EMPTYLIST_ERROR;
	}
	printf("List is: ");
	/* Traverse the list until NULL */
	while( NULL != Copy_pHead)
	{
		printf("%s\t", Copy_pHead->Data);
		Copy_pHead = Copy_pHead->Next;
	}
	printf("\n");

	return E_OK;
}

