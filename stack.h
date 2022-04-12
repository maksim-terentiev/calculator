#ifndef __stack_h__
#define __stack_h__

#define STACK_TYPE double

// char get_stack(); // no side effect
STACK_TYPE pop_stack();
int put_stack(STACK_TYPE elem);
int is_stack_empty();

#endif

