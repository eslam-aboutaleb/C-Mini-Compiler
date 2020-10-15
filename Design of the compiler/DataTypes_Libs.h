typedef unsigned char								DataTypes_t
typedef unsigned char								VarScope_t

#define CHAR_TYPE									0
#define INT_TYPE									1
#define FLOAT_TYPE									2

#define VAR_GLOBAL									0
#define VAR_LOCAL									1


#define VAR_NAME_LIMIT								100

typedef struct{
	u8 u8VarName[VAR_NAME_LIMIT];
	u32 u32DefLine;
	DataTypes_t uxDataTybe;
	VarScope_t 	uxScope;
}DataTypes_st;