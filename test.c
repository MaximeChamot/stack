#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void		display(void *data)
{
  unsigned int *nbr = (int *)(data);
  printf("data: %d\n", *nbr);
}

int		main()
{
  unsigned int	tmp[] = { 1, 2, 10, 15, 20, 25, 30 };
  stack		*stack;
  int		i;

  stack = new_stack();
  
  // test 1
  printf("test 1: Add 7 elements\n");

  for (i = 0; i < 7; ++i)
    stack->push(stack, &tmp[i]);

  stack->view(stack, &display);

  printf("Size:  [7]:[%d]\n", stack->size(stack));
  printf("----------\n\n");

  // test 2
  printf("test 2: pop 1 element and print the value\n");

  unsigned int *data = stack->top(stack);
  stack->pop(stack);

  printf("value [30]:[%d]\n", *data);
  printf("Size:  [6]:[%d]\n", stack->size(stack));
  printf("----------\n\n");

  // test 3
  printf("test 3: pop 20 elements and print the size of the stack\n");

  for (i = 0; i < 20; ++i)
    stack->pop(stack);

  printf("Size:  [0]:[%d]\n", stack->size(stack));
  printf("----------\n\n");
  
  // test 4
  printf("test 4: peek the top element of the list\n");

  for (i = 0; i < 7; ++i)
    stack->push(stack, &tmp[i]);

  data = stack->top(stack);
  printf("Top element: [30]:[%d]\n", *data);
  printf("Size:  [7]:[%d]\n", stack->size(stack));
  printf("----------\n\n");

  // test 5
  printf("Double clear\n");

  stack->clear(stack);
  stack->clear(stack);

  printf("Size:  [0]:[%d]\n", stack->size(stack));
  printf("----------\n\n");  

  stack_destroy(stack);

  free(stack);

  return 0;
}
