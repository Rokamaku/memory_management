#include <stdbool.h>
#include <stdlib.h>

struct memory_node {
	char* memory_variable;
	struct memory_node *next;
	struct memory_node *prev;
};

static struct memory_node *head = NULL;
static int nMemory = 0;


static struct memory_node* createNode(char* );
static bool AddNode(char* );
static void DelNode(char* );
static void DelAll();


char* my_malloc(int );
void my_free(char* );
void clean_all();
void signal_handler();