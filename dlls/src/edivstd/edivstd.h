#ifndef __EDIV_EDIVSTD_H_
#define __EDIV_EDIVSTD_H_

struct _regions regions[32] ;

/* Prototipos */
int eDIV_Exit(FUNCTION_PARAMS);
int eDiv_GetId(FUNCTION_PARAMS) ;
int eDiv_DefineRegion(FUNCTION_PARAMS) ;
int eDIV_Signal(FUNCTION_PARAMS);
int eDIV_Let_Me_Alone(FUNCTION_PARAMS);

#endif