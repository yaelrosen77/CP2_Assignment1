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
    PRINT_FUNC printFunc;

}AdptArray, PAdptArray*;

PAdptArray CreateAdptArray(COPY_FUNC CopyFunc, DEL_FUNC DelFunc, PRINT_FUNC printi){
    PAdptArray NewArray = (PAdptArray)malloc(sizeof(AdptArray));
    if (!NewArray)
        return NewArray;
    NewArray.ArraySize = 0;
    NewArray.Pelem = NULL;
    NewArray.delFunc = DelFunc;
    NewArray.copyFunc = CopyFunc; 
    NewArray.printFunc = printi;
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

Result SetAdptArray(PAdptArray PArr, int ndx, Pelement Pelem){
    if (!PArr)
        return FAIL;
    Pelement* newElem;
    
    if (ndx >= PArr.ArraySize){
        newElem = (Pelem*)calloc((ndx+1), sizeof(Pelement));
        if (!newElem)
            return FAIL;
        memcpy(newElem, PArr.Pelem, (PArr.ArraySize)*sizeof(Pelement));
        free(PArr.Pelem);
		PArr->Pelem = newElem;
    }
    PArr.ArraySize = (ndx >= PArr.ArraySize) ? (ndx + 1) : PArr.ArraySize;
    return SUCCESS;
}

PElement GetAdptArrayAt(PAdptArray PArr, int ndx){
    if (PArr == NULL)
        return FAIL;
    if (ndx >= PArr.ArraySize)
        return FAIL;
    PElement temp = (PArr.Pelem)[ndx];
    return temp;
}

void PrintDB(PAdptArray PArr){
    if (PArr==NULL)
        return;
    for (int i=0; i<PArr.ArraySize; i++)
        if ((PArr.Pelem)[i])
            PArr.printFunc((PArr.Pelem)[i]);
}