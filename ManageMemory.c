#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "ManageMemory.h"



static struct memory_node* createNode(char* node) {
	struct memory_node* newNode = (struct memory_node*)malloc(sizeof(struct memory_node));
	newNode->memory_variable = node;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}


static bool AddNode(char* node) {
	struct memory_node* newNode = createNode(node);
	if (newNode == NULL)
		return false;
	if (head == NULL) {
		head = newNode;
	}
	else {
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}
	nMemory++;
	return true;
}


static void DelNode(char* Node) {
	struct memory_node* curr = head;
	if (curr->memory_variable == Node) {
		curr->next->prev = NULL;
		head = curr->next;
		free(curr->memory_variable);
		free(curr);
		curr = head;
		return;
	}
	int indexCurr = 0;
	while (indexCurr < nMemory) {
		if (curr->memory_variable == Node) {
			if (indexCurr < nMemory - 1) {
				curr->prev->next = NULL;
				free(curr->memory_variable);
				free(curr);
				return;
			}
			curr->prev->next = curr->next;
			curr->next->prev = curr->prev;
			free(curr->memory_variable);
			free(curr);
			break;
		}
		indexCurr++;
	}
}


static void DelAll() {
	struct memory_node* curr = head;
	while (curr != NULL) {
		struct memory_node* p = curr;
		curr = curr->next;
		free(p->memory_variable);
		free(p);
	}
	head = NULL;
}


char* my_malloc(int size) {
	char* memory_Variable = (char*)malloc(size);
	if (memory_Variable == NULL)
		return NULL;
	AddNode(memory_Variable);
	return memory_Variable;
}
void my_free(char* ptr) {
	DelNode(ptr);
}
void clean_all() {
	DelAll();
}

void __attribute__ ((constructor)) premain() {
    signal(SIGINT, signal_handler);
}

void __attribute__ ((destructor))  endmain() { 
	clean_all();
}

void signal_handler() {
	clean_all();
	exit(0);
}