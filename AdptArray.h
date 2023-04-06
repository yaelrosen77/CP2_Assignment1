#include "AdptArray.c"

/*
This struct creates a generic element to be later on assigned to our adptarray
*/

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

