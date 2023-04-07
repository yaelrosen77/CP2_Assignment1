#include "AdptArray.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FAIL -1
#define SUCCESS 1

typedef struct AdptArray_
{
    int ArraySize;
    PElement* Pelem;
    DEL_FUNC delFunc;
	COPY_FUNC copyFunc;
    PRINT_FUNC printFunc;

}AdptArray, *PAdptArray;

PAdptArray CreateAdptArray(COPY_FUNC CopyFunc, DEL_FUNC DelFunc, PRINT_FUNC printi){
    PAdptArray NewArray = (PAdptArray)malloc(sizeof(AdptArray));
    if (!NewArray)
        return NewArray;
    NewArray->ArraySize = 0;
    NewArray->Pelem = NULL;
    NewArray->delFunc = DelFunc;
    NewArray->copyFunc = CopyFunc; 
    NewArray->printFunc = printi;
    return NewArray;
}

void DeleteAdptArray(PAdptArray PArr){
    if (PArr == NULL)
        return;
    
    for(int i=0; i< (PArr->ArraySize); i++){
        if (!PArr)
            return;
        PArr->delFunc((PArr->Pelem)[i]);
    }
    free(PArr->Pelem);
    free(PArr);
}

int GetAdptArraySize(PAdptArray PArr){
    if (!PArr)
        return FAIL;
    return PArr->ArraySize;
}

Result SetAdptArray(PAdptArray PArr, int ndx, PElement Pelem){
    if (!PArr)
        return FAIL;
    PElement* newElem;
    
    if (ndx >= PArr->ArraySize){
        newElem = (PElement*)calloc((ndx+1), sizeof(PElement));
        if (!newElem)
            return FAIL;
        memcpy(newElem, PArr->Pelem, (PArr->ArraySize)*sizeof(PElement));
        free(PArr->Pelem);
		PArr->Pelem = newElem;
    }
    PArr->ArraySize = (ndx >= PArr->ArraySize) ? (ndx + 1) : PArr->ArraySize;
    return SUCCESS;
}

PElement GetAdptArrayAt(PAdptArray PArr, int ndx){
    if (PArr == NULL)
        return FAIL;
    if (ndx >= PArr->ArraySize)
        return FAIL;
    PElement temp = (PArr->Pelem)[ndx];
    return temp;
}

void PrintDB(PAdptArray PArr){
    if (PArr==NULL)
        return;
    for (int i=0; i<PArr->ArraySize; i++)
        if ((PArr->Pelem)[i])
            PArr->printFunc((PArr->Pelem)[i]);
}