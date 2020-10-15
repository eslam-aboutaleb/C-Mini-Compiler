#ifndef DATA_TYPES_LIB_H_
#define DATA_TYPES_LIB_H_

typedef unsigned char								DataTypes_t;
typedef unsigned char								VarScope_t;

/* Date types */
#define CHAR_TYPE									0
#define INT_TYPE									1
#define FLOAT_TYPE									2
#define VOID_TYPE									3

/* Scope of the variable */
#define VAR_GLOBAL									0
#define VAR_LOCAL									1

/* Pointer states */
#define VAR_NONPOINTER								0
#define VAR_POINTER									1

/* Name limit of the variable */
#define VAR_NAME_LIMIT								100


typedef struct{
	u8 u8VarName[VAR_NAME_LIMIT];
	DataTypes_t uxDataTybe;
	VarScope_t 	uxScope;
	u32 		u32DefLine;
}DataTypes_st;

#endif /* DATA_TYPES_LIB_H_ */
