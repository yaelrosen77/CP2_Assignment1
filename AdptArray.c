#include "AdptArray.h"
#include <stdio.h>

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
    for(i, i< ipArr->ArrSize, i++){
        if (!PArr){
            return;
        }
        PArr->delFunc((PArr->pElemArr)[i]);
    }
    free(PArr->pElem);
    free(PArr);
}

