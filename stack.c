#include <stdlib.h>
#include "stack.h"

// Methods declaration
static unsigned int	push(struct stack *th, void *data);
static void *		pop(struct stack *th);
static void		clear(struct stack *th);
static unsigned int	size(struct stack *th);
static unsigned int	is_empty(struct stack *th);
static void		view(struct stack *th, void (*display)(void *data));

// Private functions declaration
static void		init_method_ptr(struct stack *th);
static void *		delete_node(struct stack *th);

// Constructor
struct stack *		new_stack(void)
{
  struct stack		*stack = NULL;

  if ((stack = (struct stack *)malloc(sizeof(struct stack))) != NULL)
    stack_init(stack);
  return (stack);
}

void			stack_init(struct stack *th)
{
  if (th != NULL)
    {
      th->len = 0;
      th->head = NULL;
      init_method_ptr(th);
    }
}

// Destructor
void			stack_destroy(struct stack *th)
{
  if (th != NULL)
    {
      th->clear(th);
      th->len = 0;
      th->head = NULL;
    }
}

// Member functions
static unsigned int	push(struct stack *th, void *data)
{
  struct node		*new_node;

  if (th != NULL)
    {
      if ((new_node = (struct node *)malloc(sizeof(struct node))) != NULL)
	{
	  new_node->data = data;
	  new_node->prev = th->head;
	  th->head = new_node;
	  th->len++;
	}
      return (th->len);
    }
  return (0);
}

static void *		pop(struct stack *th)
{
  if (th != NULL)
    return (delete_node(th));
  return (NULL);
}

static void		clear(struct stack *th)
{
  if (th != NULL)
    {
      while (th->head != NULL)
	delete_node(th);
    }
}

static unsigned int	size(struct stack *th)
{
  if (th != NULL)
    return (th->len);
  return (0);
}

static unsigned int	is_empty(struct stack *th)
{
  if (th != NULL && th->head != NULL && th->len > 0)
    return (0);
  return (1);
}

static void		view(struct stack *th, void (*display)(void *data))
{
  struct node		*node;

  if (th != NULL && display != NULL)
    {
      node = th->head;
      while (node != NULL)
	{
	  display(node->data);
	  node = node->prev;
	}
    }
}

// Private functions
static void		init_method_ptr(struct stack *th)
{
  if (th != NULL)
    {
      th->push = &push;
      th->pop = &pop;
      th->clear = &clear;
      th->size = &size;
      th->is_empty;
      th->view = &view;
    }
}

static void *		delete_node(struct stack *th)
{
  struct node		*tmp = NULL;
  void			*data = NULL;

  if (th != NULL && th->head != NULL)
    {
      tmp = th->head;
      data = th->head->data;
      th->head = th->head->prev;
      free(tmp);
      th->len--;
    }
  return (data);
}
