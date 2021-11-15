//=================================================================================================================================
#include <string.h>
#include "xList.h"
//=================================================================================================================================
xObject xListAdd(xListT *list, xObject object){
  xListElementT *element = calloc(1, sizeof(xListElementT));
  if(element){
    element->Value = object;
    
    if(!list->FirstElement) { list->FirstElement = element; }
    else { list->LastElement->Next = element; }
    
    list->LastElement = element;    
    list->Count++;
  }
  return element;
}

xObject xListInsert(xListT *list, uint16_t index, xObject object){
  xListElementT *element = 0;
  if(index < list->Count){
    xListElementT *request = calloc(1, sizeof(xListElementT));
    
    request->Value = object;
    request->Next = list->FirstElement;
    
    for(uint16_t i = 0; i < index; i++){
      element = request->Next;
      request->Next = element->Next;
    }
    
    if(element){ element->Next = request; }
    if(request->Next == list->FirstElement){ list->FirstElement = request; }
    if(request->Next == 0){ list->LastElement = request; }
    
    list->Count++;
  }
  return element;
}

xObject xListRemoveAt(xListT *list, uint16_t index){
  xObject result = 0;
  if(index < list->Count){
    xListElementT *previous = 0;
    xListElementT *element = list->FirstElement;
    
    for(uint16_t i = 0; i < index; i++){
      previous = element;
      element = element->Next;
    }
    
    if(!previous){ list->FirstElement = element->Next; }
    else { previous->Next = element->Next; }
    
    if(previous->Next == 0){ list->LastElement = previous; }
    
    result = element->Value;    
    free(element);
    list->Count--;
  }
  return result;
}

void xListRemove(xListT *list, xObject object){
 
}

xObject xListGet(xListT *list, uint16_t index){
  if(index < list->Count){
    xListElementT *element = list->FirstElement;
    for(uint16_t i = 0; i < index; i++){ element = element->Next; }
    return element->Value;
  }
  return 0;
}
//=================================================================================================================================
