#include <stdio.h>
#include "stack.h"

void display(void *data)
{
  unsigned int *nbr = (int *)(data);
  printf("data: %d\n", *nbr);
}

int main()
{
	int tab[] = { 10, 15, 20, 25, 30, 1, 2 };
	Stack		*newStack;

	newStack = NewStack();

	newStack->push(newStack, &tab[0]);
	newStack->push(newStack, &tab[1]);
	newStack->push(newStack, &tab[2]);
	newStack->push(newStack, &tab[3]);
	newStack->push(newStack, &tab[4]);

	newStack->view(newStack, &display);
	printf("---------- Size: %d\n", newStack->size(newStack));

	newStack->push(newStack, &tab[5]);
	newStack->push(newStack, &tab[6]);

	newStack->view(newStack, &display);
	printf("---------- Size: %d\n", newStack->size(newStack));

	newStack->pop(newStack);
	newStack->pop(newStack);
	newStack->pop(newStack);
	newStack->pop(newStack);
	newStack->pop(newStack);
	newStack->pop(newStack);
	newStack->pop(newStack);
	newStack->pop(newStack);
	newStack->pop(newStack);
	newStack->pop(newStack);
	newStack->pop(newStack);
	newStack->pop(newStack);
	newStack->pop(newStack);
	newStack->pop(newStack);

	newStack->view(newStack, &display);
	printf("---------- Size: %d\n", newStack->size(newStack));

	StackDestroy(newStack);

	newStack->view(newStack, &display);
	printf("---------- Size: %d\n", newStack->size(newStack));

	newStack->push(newStack, &tab[0]);
	newStack->push(newStack, &tab[1]);
	newStack->push(newStack, &tab[2]);
	newStack->push(newStack, &tab[3]);
	newStack->push(newStack, &tab[4]);

	newStack->view(newStack, &display);
	printf("---------- Size: %d\n", newStack->size(newStack));

	newStack->clear(newStack);
	newStack->clear(newStack);
	newStack->clear(newStack);
	newStack->clear(newStack);
	newStack->clear(newStack);

	newStack->view(newStack, &display);
	printf("---------- Size: %d\n", newStack->size(newStack));

#ifdef _WIN32
	system("PAUSE");  /* Pour la console Windows. */
#endif

	return 0;
}
