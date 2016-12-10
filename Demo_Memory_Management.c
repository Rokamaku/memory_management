#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include "ManageMemory.h"

int main() {
	char* first_malloc = my_malloc(100);
	//char* first_malloc = malloc(100);
	printf("My first malloc allocated at %p\n", first_malloc);
	char* second_malloc = my_malloc(200);
	//char* second_malloc = malloc(200);
	printf("My second malloc allocated at %p\n", second_malloc);
	char* third_malloc = my_malloc(300);
	//char* third_malloc = malloc(300);
	printf("My third malloc allocated at %p\n", third_malloc);
	
	my_free(third_malloc);
	//free(third_malloc);
	printf("My third malloc deallocated\n");
	//while (1) {}
	//free(first_malloc);
	//free(second_malloc);
	//free(third_malloc);
	return 0;
}