#include <stdlib.h>
#include "stack.h"

// Member functions declaration
static unsigned int	push(struct Stack *th, void *data);
static void *		pop(struct Stack *th);
static void		clear(struct Stack *th);
static unsigned int	size(struct Stack *th);
static void		view(struct Stack *th, void (*display)(void *data));

// Static functions declaration
static void		initMethodPtr(struct Stack *th);
static void *		deleteNode(struct Stack *th);

// Constructor
void			StackInit(struct Stack *th)
{
  if (th != NULL)
    {
      th->len = 0;
      th->head = NULL;
      initMethodPtr(th);
    }
}

static void		initMethodPtr(struct Stack *th)
{
  th->push = &push;
  th->pop = &pop;
  th->clear = &clear;
  th->size = &size;
  th->view = &view;
}

struct Stack *		NewStack(void)
{
  struct Stack		*newStack;

  if ((newStack = (struct Stack *)malloc(sizeof(struct Stack))) != NULL)
    StackInit(newStack);
  return (newStack);
}

// Destructor
void			StackDestroy(struct Stack *th)
{
  if (th != NULL)
    {
      th->clear(th);
      th->len = 0;
      th->head = NULL;
    }
}

// Member functions
static unsigned int	push(struct Stack *th, void *data)
{
  struct Node		*newNode;

  if (th != NULL)
    {
      if ((newNode = (struct Node *)malloc(sizeof(struct Node))) != NULL)
	{
	  newNode->data = data;
	  newNode->prev = th->head;
	  th->head = newNode;
	  th->len++;
	}
      return (th->len);
    }
  return (0);
}

static void *		pop(struct Stack *th)
{
  if (th != NULL)
    return (deleteNode(th));
  return (NULL);
}

static void		clear(struct Stack *th)
{
  if (th != NULL)
    {
      while (th->head != NULL)
	deleteNode(th);
    }
}

static unsigned int	size(struct Stack *th)
{
  if (th != NULL)
    return (th->len);
  return (0);
}

static void		view(struct Stack *th, void (*display)(void *data))
{
  struct Node		*it;

  if (th != NULL && display != NULL)
    {
      it = th->head;
      while (it != NULL)
	{
	  display(it->data);
	  it = it->prev;
	}
    }
}

static void *		deleteNode(struct Stack *th)
{
  struct Node		*tmp;
  void			*data;

  data = NULL;
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
