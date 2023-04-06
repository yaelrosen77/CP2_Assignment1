#include "AdptArray.h"
#include <stdio.h>
#include <stdlib.h>
#define FAIL -1
#define SUCCESS 1

typedef struct Element
{
    void* data;
}Element, Pelement*;

typedef struct AdptArray
{
    int ArraySize;
    Element* Pelem;
    DEL_FUNC delFunc;
	COPY_FUNC copyFunc;

}AdptArray, PAdptArray*;

PAdptArray CreateAdptArray(COPY_FUNC CopyFunc, DEL_FUNC DelFunc){
    PAdptArray NewArray = (PAdptArray)malloc(sizeof(AdptArray));
    if (!NewArray)
        return NewArray;
    NewArray-> ArraySize = 0;
    NewArray-> Pelem = Null;
    NewArray-> delFunc = DelFunc;
    NewArray-> copyFunc = CopyFunc; 
    return NewArray;
}

void DeleteAdptArray(PAdptArray PArr){
    int i=0;
    if (PArr == NULL)
    {
        return;
    }
    for(i, i< PArr->ArrSize, i++){
        if (!PArr){
            return;
        }
        PArr->delFunc((PArr->Pelem)[i]);
    }
    free(PArr->Pelem);
    free(PArr);
}

int SetAdptArray(PAdptArray PArr, int ndx, Pelement Pelem){
    if (!PArr)
        return FAIL;
    Pelement* newElem;
    
    if (ndx >= PArr.ArraySize){
        newElem = (Pelem*)calloc((ndx+1), sizeof(Pelement));
        if (!newElem)
            return FAIL;
        memcpy(newElem, PArr->Pelem, (PArr->ArraySize)*sizeof(Pelement));
        free(PArr->Pelem);
		PArr->Pelem = newElem;
    }
    PArr->ArraySize = (idx >= pArr->ArrSize) ? (idx + 1) : pArr->ArrSize;
    return 1;

}
