// Версия 1.6.0: Более разумный realloc();
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

static const int CAPACITY = 13;

//const int STACK_BEGINNING_SIZE = 100;
const int STACK_STEP_SIZE = 5;

const int STACK_SUCCESS = 0;
const int STACK_OVERFLOW = 1;
const int STACK_EMPTY = 2;
const int STACK_NULLPTR = 3;

template <typename T>
struct Stack
{
    T * dataPointer;
    int size;
    int dataCells;

    Stack()
    {
        dataPointer = (T *) calloc(STACK_STEP_SIZE , sizeof(T));
        size = STACK_STEP_SIZE;
        dataCells = 0;
    }

    //Stack <T> * currentStack, 
    int Push(T element);
    int PushF(T element);

    int Top(T * element_addr);
    int TopF(T * element_addr);
    
    int Pop();
    int PopF();

    ~Stack()
    {
        free(dataPointer);
    }
};

template <typename T>
int Stack<T>::Push(T element)
{
    if(dataCells == CAPACITY)
        return STACK_OVERFLOW;

    if(dataCells == size)
    {
        if(CAPACITY - size >= STACK_STEP_SIZE)
        {
            dataPointer = (T *) realloc(dataPointer, size + STACK_STEP_SIZE);
            size += STACK_STEP_SIZE;
        }
        else //if(CAPACITY - size < STACK_STEP_SIZE)
        {
            dataPointer = (T *) realloc(dataPointer, CAPACITY);
            size = CAPACITY;
        }
    }
    
    *(dataPointer + dataCells++) = element;
    return STACK_SUCCESS;
}

template <typename T>
int Stack<T>::PushF(T element)
{
    int status = STACK_SUCCESS;

    if( (status = Push(element)) == STACK_OVERFLOW )
        printf("PushF: Стек переполнен\n");

    else if(status == STACK_SUCCESS)
        cout << "PushF: Удалось поместить элемент [" << element << "] в стек\n";

    if(dataPointer != NULL)
    {
        printf("\tАдрес нулевой ячейки: {%p}\n", dataPointer);
        if(dataCells != 0)
            printf("\tАдрес верхней ячейки: {%p}\n", dataPointer + dataCells - 1);
    }
    printf("\tРазмер стека: [%d]\n", size);
    return status;
}

template <typename T>
int Stack<T>::Top(T * element_addr)
{
    if(dataCells > 0)
    {
        *element_addr = *(dataPointer + dataCells - 1);
        return STACK_SUCCESS;
    }
    else
        return STACK_EMPTY;
}

template <typename T>
int Stack<T>::TopF(T * element_addr)
{
    int status = STACK_SUCCESS;

    if( (status = Top(element_addr)) == STACK_SUCCESS )
        cout << "TopF: Верхний элемент №" << size - 1 << " [" << *element_addr << "] получен\n";

    else if(status == STACK_EMPTY)
        printf("TopF: Стек пустой\n");

    if(dataPointer != NULL)
    {
        printf("\tАдрес нулевой ячейки: {%p}\n", dataPointer);
        if(dataCells != 0)
            printf("\tАдрес верхней ячейки: {%p}\n", dataPointer + dataCells - 1);
    }
    printf("\tРазмер стека: [%d]\n", size);
    return status;
}

template <typename T>
int Stack<T>::Pop()
{
    if(dataCells > 0)
        --dataCells;
    else //if(dataCells == 0)
        return STACK_EMPTY;
    
    if( (size - dataCells) > STACK_STEP_SIZE )
    {
        dataPointer = (T *) realloc(dataPointer, size - STACK_STEP_SIZE);
        size -= STACK_STEP_SIZE;
    }
        return STACK_SUCCESS;
}

template <typename T>
int Stack<T>::PopF()
{
    int status = STACK_SUCCESS;

    if( (status = Pop()) == STACK_SUCCESS)
        printf("PopF: Верхний элемент удалён\n");

    else if(status == STACK_EMPTY)
        printf("PopF: Стек уже пустой\n");

    if(dataPointer != NULL)
    {
        printf("\tАдрес нулевой ячейки: {%p}\n", dataPointer);
        if(dataCells != 0)
            printf("\tАдрес верхней ячейки: {%p}\n", dataPointer + dataCells - 1);
    }
    printf("\tРазмер стека: [%d]\n", size);
    return status;
}

