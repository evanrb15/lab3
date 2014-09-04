#include <stdlib.h>
#include <stdio.h>
#include "arrayList.h"

//getSize not accessed outside of this file so declare it to be static
//static essentially makes it private to this file 
static int getSize(primitiveType type);

arrayList * initialize(primitiveType type)
{
    arrayList * list = malloc(sizeof(arrayList));
    list -> array = malloc(getSize(type));
    list -> arraySize = 4;
    list -> numElements = 0;
    list -> type = type;
    
   return list;
}

int getSize(primitiveType type)
{
    if (type == charType)
        return sizeof(char);
    else if (type == intType)
        return sizeof(int);
    else if (type == shortType)
        return sizeof(short);

   return 0;
}

void addElement(arrayList * arylstP, void * element)
{
   if((arylstP -> arraySize) == (aryLst -> numElements)){
        arrayList * listTwo = malloc(sizeof(arrayList)) * (aryLst-> elementSize)*2;
        listTwo -> arraySize = (arylist-> arraySize*2);
        
   return;
}

void removeElement(arrayList * arylstP, int index)
{
   return;
}
      

void printArray(arrayList * arylstP)
{
   int i;
   printf("array size: %d, num elements: %d contents: ", 
          arylstP->arraySize, arylstP->numElements);
   for (i = 0; i < arylstP->numElements; i++)
   {
      if (arylstP->type == charType)
         //fill in the missing code that gets the element and &s it with 0xff
         printf("%02x ", 0xff);
      else if (arylstP->type == shortType)
         //fill in the missing code that gets the element and &s it with 0xffff
         printf("%04x ", 0xffff);
      else if (arylstP->type == intType)
         //fill in the missing code that gets the element and &s it with 0xffffffff
         printf("%08x ", 0xffffffff);
   }
   printf("\n");
}

