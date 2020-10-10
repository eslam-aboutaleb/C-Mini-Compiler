/* ************************************************************ */
/* Author: Eslam Ehab Aboutaleb									*/
/* Date	 : 8/10/2020											*/
/* ************************************************************ */

#ifndef STACK_INTERFACE_H
#define STACK_INTERFACE_H

typedef uint32 						StackType;


typedef struct StackNode{
	StackType Data;
	struct StackNode* Next;
}StackNode;

typedef enum{
	STACK_IS_EMPTY = 0,
	STACK_NOT_EMPTY
}StackState_t;

#define STACK_HEAP_SIZEOUT_ERROR														(15)
#define STACK_EMPTY_STACK_ERROR															(16)

ERROR_STATUS Stack_xPush(StackNode **Copy_ppHead , StackType Copy_xData);
ERROR_STATUS Stack_xPop(StackNode **Copy_ppHead , StackType *Copy_pxRecvData);
ERROR_STATUS Stack_xPrint(StackNode * Copy_pHead);

#endif
