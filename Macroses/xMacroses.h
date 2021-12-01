/*
 * xMacroses.h
 *
 * Created: 16.05.2019 14:29:38
 *  Author: rekuts
 */ 
//=================================================================================================================================
#ifndef XMACROSES_H_
#define XMACROSES_H_
//=================================================================================================================================
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
//=================================================================================================================================
#define VA_ARGS_SHIFT(P1,P2,P3,P4,P5,P6,P7,P8,P9,P10,PN,...) PN
#define VA_ARGS_COUNT(...) VA_ARGS_SHIFT(-1,##__VA_ARGS__,9,8,7,6,5,4,3,2,1,0)
//=================================================================================================================================
#define COPY_MEMORY(memory, object, size) memcpy((uint8_t*)memory, (uint8_t*)object, size)
  
#define COPY_OBJECT(memory, object) memcpy((uint8_t*)memory, (uint8_t*)&object, sizeof(object))
/*
inline static int COPY_OBJECTS(uint8_t* memory, ...)
{
  uint16_t size = 0;
  uint8_t objects_count = VA_ARGS_COUNT(__VA_ARGS__);
  while(objects_count)
  {
    objects_count--;
  }
  return size;
}
*/
//=================================================================================================================================
#endif /* XTYPE_H_ */
