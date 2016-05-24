#ifndef _STACK_H_
# define _STACK_H_

typedef struct		node
{
  void			*data;
  struct node		*prev;
}			node;

typedef struct		stack
{
  // Properties
  unsigned int		len;
  struct node		*head;

  // Methods
  unsigned int		(*push)(struct stack *th, void *data);
  void *		(*pop)(struct stack *th);
  void			(*clear)(struct stack *th);
  unsigned int		(*size)(struct stack *th);
  unsigned int		(*is_empty)(struct stack *th);
  void *		(*peek)(struct stack *th);
  void			(*view)(struct stack *, void(*display)(void *data));
}			stack;

void			stack_init(struct stack *th);
struct stack *		new_stack(void);
void			stack_destroy(struct stack *th);

#endif // _STACK_H_
