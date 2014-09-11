#include <stdlib.h>
#include <stdio.h>
#include "arrayList.h"

//getSize not accessed outside of this file so declare it to be static
//static essentially makes it private to this file 
static int getSize(primitiveType type);

/*
 * Initializes a new arrayList with size of 4, number of elements is 0
 * and allocates space for the array.
 */
arrayList * initialize(primitiveType type)
{
    arrayList * list = malloc(sizeof(arrayList));
    list -> array = malloc(getSize(type)*4);
    list -> arraySize = 4;
    list -> numElements = 0;
    list -> type = type;
    
   return list;
}
/*
 * Returns the size of the array in bytes
 */
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
/*
 * Adds an element to the end of the array. If the arrayList is already full the
 * size will be doubled before the element is added.
 */
void addElement(arrayList * arylstP, void * element)
{
   if((arylstP -> arraySize) == (arylstP-> numElements)){
        void * listTwo = malloc((arylstP->arraySize) * (arylstP-> elementSize)*2);
        int i;
        for(i = 0; i < ((arylstP->numElements))*(arylstP->elementSize); i++){
            ((char *) listTwo)[i] = ((char *)(arylstP->array))[i];
        }
        free(arylstP->array);
        arylstP->array = listTwo;
        arylstP->arraySize *= 2;
        
   }
   int i;
   for(i =0;i < (arylstP->elementSize); i++){
       ((char *)(arylstP->array))[i + ((arylstP->numElements)*(arylstP->elementSize))] = ((char *)(element))[i];
   }
   (arylstP->numElements)++;
}

/*
 * Removes the element at the index given in the arrayList.
 */
void removeElement(arrayList * arylstP, int index)
{
   int i;
   if(arylstP->type == charType){
       for(i = index; i < (arylstP->numElements) -1;i++)
           ((char *)(arylstP->array))[i]= ((char *)(arylstP->array))[i+1];
   }
   else if (arylstP->type == shortType){
       for(i = index; i < (arylstP->numElements)-1;i++)
           ((short *)(arylstP->array))[i] = ((short *)(arylstP->array))[i+1];
   }
   else {
       for (i = index; i < (arylstP->numElements) - 1; i++)
           ((int *)(arylstP->array))[i] = ((int *)(arylstP->array))[i+1];
   }
}
/*
 * Prints the elements in the arrayList from start to end.
 */   
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

