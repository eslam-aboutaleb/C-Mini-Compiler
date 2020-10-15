#ifndef FUNCTIONS_LIB_H
#define FUNCTIONS_LIB_H


typedef unsigned char								ParameterType_t;
typedef unsigned char								ReturnType_t;

#define FUNCTION_NAME_LIMIT							100
#define PARAMETER_NAME_LIMIT						100
#define FUNCTIONS_PARAMETERS_LIMIT					100

typedef struct {
	u8 ParameterName[PARAMETER_NAME_LIMIT];
	ParameterType_t xArgumentType;
}FuncParameters_st;


typedef struct {
	u8  FunctionName[FUNCTION_NAME_LIMIT];
	ReturnType_t xReturnType;
	u32 u32DefLine;
	u8 u8N_Parameters;
	FuncParameters_st Parameters[FUNCTIONS_PARAMETERS_LIMIT];
}Function_st;






#endif /* FUNCTIONS_LIB_H */
