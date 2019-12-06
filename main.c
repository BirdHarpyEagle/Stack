#include "stack.h"

int main()
{
    int element = 0;
    int *elemAddr = &element;

    Stack <int> myStack = {};

    myStack.PushF(17);
    myStack.PushF(19);

    myStack.TopF(elemAddr);
    myStack.PopF();

    myStack.TopF(elemAddr);
    myStack.PopF();

    printf("\n\n");

    char letter = 0;

    Stack <char> anotherStack = {};

    anotherStack.PushF('a');
    anotherStack.PushF('b');
    anotherStack.PushF('c');
    anotherStack.PushF('d');
    anotherStack.PushF('e');
    anotherStack.PushF('f');
    anotherStack.PushF('g');
    anotherStack.PushF('h');
    anotherStack.PushF('i');
    anotherStack.PushF('j');
    anotherStack.PushF('k');
    anotherStack.PushF('l');
    anotherStack.PushF('m');

    for(int counterCounter = 0; counterCounter < 13; counterCounter++)
    {
        anotherStack.TopF(&letter);
        anotherStack.PopF();
    }

}
