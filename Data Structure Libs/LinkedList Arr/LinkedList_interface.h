/* ************************************************************ */
/* Author: Eslam Ehab Aboutaleb									*/
/* Date	 : 6/10/2020
/* ************************************************************ */

#ifndef LINKEDLIST_INTERFACE_H
#define LINKEDLIST_INTERFACE_H

typedef u8* 						ListType;


typedef struct Node{
	ListType Data;
	struct Node* Next;
}Node;

typedef enum{
	LIST_IS_EMPTY = 0,
	LIST_NOT_EMPTY
}HeadState_t;

#define lIST_HEAP_SIZEOUT_ERROR															(10)
#define LIST_EMPTY_LIST_ERROR															(11)
#define LIST_OUT_LIMIT_POS_ERROR														(12)
#define LIST_ACCESS_EMPTYLIST_ERROR														(13)


ERROR_STATUS List_xAddNodeFirst(Node **Copy_ppHead , ListType Copy_xData);
ERROR_STATUS List_xAddNodeEnd(Node **Copy_ppHead , ListType Copy_xData);
ERROR_STATUS List_xInsertNodeNth(Node **Copy_ppHead , ListType Copy_xData , u32 Copy_u32Position);
ERROR_STATUS List_xModifyNodeNth(Node **Copy_ppHead , ListType Copy_xData , u32 Copy_u32Position);
ERROR_STATUS List_xDeleteNode(Node **Copy_ppHead ,u32 Copy_u32Position);
ERROR_STATUS List_xReverse(Node **Copy_ppHead );
ERROR_STATUS List_xPrint(Node * Copy_pHead);
u32 List_u32Count(Node * Copy_pHead);

#endif /* LINKEDLIST_INTERFACE_H */
