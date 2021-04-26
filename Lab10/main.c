#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
    Snode* pHead;
    pHead = ListInitAndRead();

    printf("Before:\n");

    PrintList(&pHead);

    DeleteNeededElements(&pHead);

    printf("After:\n");

    PrintList(&pHead);

    FreeList(pHead);

    return 0;
}