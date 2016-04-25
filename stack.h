#ifndef _STACK_H_
# define _STACK_H_

typedef struct		Node
{
  void			*data;
  struct Node		*prev;
}			Node;

typedef struct		Stack
{
  // Properties
  unsigned int		len;
  struct Node		*head;

  // Member functions
  unsigned int		(*push)(struct Stack *th, void *data);
  void *		(*pop)(struct Stack *th);
  void			(*clear)(struct Stack *th);
  unsigned int		(*size)(struct Stack *th);
  char			(*isEmpty)(struct Stack *th);
  void			(*view)(struct Stack *, void(*display)(void *data));
}			Stack;

void			StackInit(struct Stack *th);
struct Stack *		NewStack(void);
void			StackDestroy(struct Stack *th);

#endif // _STACK_H_
