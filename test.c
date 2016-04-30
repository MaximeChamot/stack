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
  unsigned int	tab[] = { 10, 15, 20, 25, 30, 1, 2 };
  stack		*stack;
  int		i;

  stack = new_stack();

  for (i = 0; i < 7; ++i)
    stack->push(stack, &tab[i]);
  stack->view(stack, &display);
  printf("Size: 7:%d\n", stack->size(stack));

  stack_destroy(stack);
  free(stack);

  return 0;
}
