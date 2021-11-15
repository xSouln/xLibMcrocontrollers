//=================================================================================================================================
#include <string.h>
#include "xList.h"
//=================================================================================================================================
xListElementT* xListAdd(xListT *list, xObject object){
  xListElementT *element = calloc(1, sizeof(xListElementT));
  if(element){
    element->Value = object;
    
    if(!list->Head) { list->Head = element; }
    else { list->Tail->Next = element; }
    
    list->Tail = element;    
    list->Count++;
  }
  return element;
}
//=================================================================================================================================
xListElementT* xListInsert(xListT *list, uint16_t index, xObject object){
  xListElementT *element = 0;
  if(index < list->Count){
    xListElementT *request = calloc(1, sizeof(xListElementT));
    
    request->Value = object;
    request->Next = list->Head;
    
    while(index){
      element = request->Next;
      index--;
    }
    
    if(element){ element->Next = request; }
    if(request->Next == list->Head){ list->Head = request; }
    if(request->Next == 0){ list->Tail = request; }
    
    list->Count++;
  }
  return element;
}
//=================================================================================================================================
xListElementT* xListRemoveAt(xListT *list, uint16_t index){
  if(index < list->Count){
    xListElementT *previous = 0;
    xListElementT *total = list->Head;
    
    while(index)
    {
      previous = total;
      total = total->Next;
      index--;
    }
    
    if(!previous) { list->Head = total->Next; }
    else { previous->Next = total->Next; }
    
    if(total->Next == 0){ list->Tail = previous; }
    
    result = total->Value;
    
    free(total);    
    list->Count--;
  }
  return result;
}
//=================================================================================================================================
xListElementT* xListRemoveElement(xListT *list, xListElementT *element)
{
  if(!list->Count){ return 0; }
  
  //xListElementT* total = list->Head;
  //xListElementT* previous = 0;
  xListElementT** ptr = &list->Head;
  
  while(*ptr && *ptr != element)
  //while(total && total != element)
  {    
    ptr = (xListElementT**)&(*ptr)->Next;
    //previous = total;
    //total = total->Next;
  }
  
  //if(!total) { return 0; }
  if(!*ptr) { return 0; }
  
  //if(!previous) { list->Head = total->Next; }
  //else { previous->Next = total->Next; }  
  
  if(element->Next == 0){ list->Tail = element->Next; }
  (*ptr) = (*ptr)->Next;
  
  free(element);  
  list->Count--;
    
  return (*ptr)->Next;
}
//=================================================================================================================================
xListElementT* xListGetElement(xListT *list, uint16_t index){
  xListElementT *element;
  if(index < list->Count){
    element = list->Head;
    while(index){ element = element->Next; index--; }
  }
  return element;
}
//=================================================================================================================================
