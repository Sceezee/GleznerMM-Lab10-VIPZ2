#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define LENGTH 40

typedef struct SInfoOfBook
{
    char chAuthorName[LENGTH];
    char chAuthorSurname[LENGTH];
    char BookName[LENGTH];
    int nYearOfPublishing;
    int nNumberOfPages;
    int nPrice;
} SInfo;

typedef struct SInfoTmp
{
    char chAuthorName[LENGTH];
    char chAuthorSurname[LENGTH];
    char chBookName[LENGTH];
    int nYearOfPublishing;
    int nNumberOfPages;
    int nPrice;
} SInfoTmp;

typedef struct SNode
{
    SInfo book;
    struct SNode* pNext;
} Snode;

Snode* ListInitReadWrite();

void AddElemToEndOfList(Snode** pHead, Snode* pNextNode);

void DeleteNeededElements(Snode** pListStart);

void PrintList(Snode** pHead);

void FreeList(Snode* pHead);

void PushList(Snode** pListStart, Snode* element);

#endif
