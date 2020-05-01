/*
 * Search this source code for a comment with XXX. You must
 * implement this missing functionality. When you run the program
 * input should look like any of the following:
 *    push hi
 *    push whoah
 *    pop
 *    print
 *    push tho
 *    print
 *
 * I will execute something like the following and check that valgrind
 * reports no errors.
 *
 * In my shell:
 * $ printf "push $RANDOM\npush $RANDOM\npush $RANDOM\npop\nprint\n" | valgrind --leak-check=full ./stack
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	char *value;
	struct node *next;
};

struct stack {
	struct node *root;
};

struct stack *
stack_create(void)
{
	struct stack *r;

	r = malloc(sizeof *r);
	if (r == NULL)
		return NULL;

	r->root = NULL;
	return r;	
}

/*
 * XXX: You must implement this function. It should remove
 * the top item on the stack and free the memory of both
 * the value and the node that was removed.
 */
void
stack_pop(struct stack *stack)
{
	struct node* old_root = stack->root;
	if(old_root != NULL)
	{
		free(old_root->value);
		stack->root = old_root->next;
	}
	//free(old_root->value);
	free(old_root);
}

bool
stack_push(struct stack *stack, const char *value)
{
	struct node *node;

	node = malloc(sizeof *node);
	if (node == NULL)
		return false;

	node->value = strndup(value, strlen(value) - 1);

	node->next = stack->root;
	stack->root = node;
	return true;
}

void
stack_print(struct stack *stack)
{
	struct node *cursor;
	size_t i = 0;

	for (cursor = stack->root; cursor != NULL; cursor = cursor->next)
		printf("[%zu] = %s\n", i++, cursor->value);

	return;
}

void
stack_destroy(struct stack *stack)
{
	struct node *cursor, *next;

	for (cursor = stack->root; cursor != NULL; cursor = next) {
		next = cursor->next;
		//free(cursor);
		stack_pop(stack);
	}

	free(stack);
	return;
}

int
main(void)
{
	struct stack *stack;

	stack = stack_create();

	for (;;) {
		char *token;
		char *line = NULL;
		size_t length = 0;
		ssize_t r;
		const size_t push_l = strlen("push ");

		r = getline(&line, &length, stdin);
		if (r == -1)
			break;

		if (strncmp(line, "push ", push_l) == 0) {
			line += push_l;

			if (stack_push(stack, line) == false)
				fprintf(stderr, "Stack push failed.\n");
		} else if (strcmp(line, "pop\n") == 0) {
			stack_pop(stack);
		} else if (strcmp(line, "print\n") == 0) {
			stack_print(stack);
		} else {
			fprintf(stderr, "Unknown command: must be one of push, pop and print.\n");
		}
		//free(line);
	}

	stack_print(stack);
	stack_destroy(stack);

	return 0;
}
