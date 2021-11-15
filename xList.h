//=================================================================================================================================
#ifndef X_LIST_H
#define X_LIST_H
//=================================================================================================================================
#include <stdlib.h>
#include "xType.h"
//=================================================================================================================================
typedef struct{
  xObject Value;
  xObject Next;
}xListElementT;

typedef struct{
  xListElementT* FirstElement;
  xListElementT* LastElement; 
  uint16_t Count;
}xListT;

xObject xListAdd(xListT *list, xObject object);
xObject xListRemoveAt(xListT *list, uint16_t index);
xObject xListInsert(xListT *list, uint16_t index, xObject object);

xObject xListGet(xListT *list, uint16_t index);
//=================================================================================================================================
#endif
