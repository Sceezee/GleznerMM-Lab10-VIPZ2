#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
//--------------------------------------------------------------------------------

Snode* ListInitReadWrite()
{
    FILE* outputList;
    outputList = fopen("C:\\Users\\Max Gll\\source\\repos\\Lab08_Task\\Lab08_Task\\outputList.bin", "rb");

    if (!(outputList))
    {
        printf("Can`t open the file");
        return 1;
    }

    Snode* pHead = NULL;
    pHead = (Snode*)malloc(sizeof(Snode));
    pHead->pNext = NULL;

    SInfo* book = (SInfo*)malloc(sizeof(SInfo));
    SInfoTmp* pTemp = (SInfoTmp*)malloc(sizeof(SInfoTmp));

    fread(pTemp, sizeof(SInfoTmp), 1, outputList);
    strcpy(book->chAuthorName, pTemp->chAuthorName);
    strcpy(book->chAuthorSurname, pTemp->chAuthorSurname);
    strcpy(book->BookName, pTemp->chBookName);

    book->nYearOfPublishing = pTemp->nYearOfPublishing;
    book->nNumberOfPages = pTemp->nNumberOfPages;
    book->nPrice = pTemp->nPrice;
    pHead->book = *book;
    fread(pTemp, sizeof(SInfoTmp), 1, outputList);

    while (!(feof(outputList)))
    {
        Snode* pnext = (Snode*)malloc(sizeof(Snode));
        pnext->pNext = NULL;

        strcpy(book->chAuthorName, pTemp->chAuthorName);
        strcpy(book->chAuthorSurname, pTemp->chAuthorSurname);
        strcpy(book->BookName, pTemp->chBookName);
        book->nYearOfPublishing = pTemp->nYearOfPublishing;
        book->nNumberOfPages = pTemp->nNumberOfPages;
        book->nPrice = pTemp->nPrice;
        pnext->book = *book;
        PushList(&pHead, pnext);
        fread(pTemp, sizeof(SInfoTmp), 1, outputList);
    }

    fclose(outputList);
    return pHead;
}
//--------------------------------------------------------------------------------

void AddElemToEndOfList(Snode** pHead, Snode* nextNode)
{
    Snode* pTmp = *pHead;
    do
    {
        if (pTmp->pNext == NULL)
        {
            pTmp->pNext = nextNode;
        }
        pTmp = pTmp->pNext;
    } while (pTmp != NULL);
}
//--------------------------------------------------------------------------------

void DeleteNeededElements(Snode** pListStart)
{
    if (*pListStart == NULL)
    {
        return;
    }

    char isDeleted = 0;

    if ((*pListStart)->book.nYearOfPublishing < 2000 && (*pListStart)->book.nNumberOfPages < 150)
    {
        Snode* pTmp = *pListStart;
        *pListStart = (*pListStart)->pNext;
        free(pTmp);
        isDeleted = 1;
    }

    if (isDeleted)
    {
        DeleteNeededElements(&(*pListStart));
    }
    else
    {
        DeleteNeededElements(&((*pListStart)->pNext));
    }
}
//--------------------------------------------------------------------------------

void PrintList(Snode** pHead)
{
    Snode* pTmp = *pHead;
    printf("        ------------------------------------------------------------\n");
    do
    {
        printf("\t| %10s | %12s | %10s | %4d | %4d | %3d |\n", pTmp->book.chAuthorName, pTmp->book.chAuthorSurname, pTmp->book.BookName, pTmp->book.nYearOfPublishing, pTmp->book.nNumberOfPages, pTmp->book.nPrice);
        printf("        ------------------------------------------------------------\n");
        pTmp = pTmp->pNext;
    } while (pTmp != NULL);
}
//--------------------------------------------------------------------------------

void FreeList(Snode* pHead)
{
    Snode* pNode = pHead, * pNext;

    while (NULL != pNode)
    {
        pNext = pNode->pNext;
        free(pNode);
        pNode = pNext;
    }
}
//--------------------------------------------------------------------------------

//Adds new element to the end of the list
void PushList(Snode** pListStart, Snode* element)
{

    if (*pListStart == NULL)
    {
        *pListStart = element;
        return;
    }

    if ((*pListStart)->pNext == NULL)
    {
        (*pListStart)->pNext = element;
        return;
    }
    else
    {
        PushList(&((*pListStart)->pNext), element);
    }
}
//--------------------------------------------------------------------------------