#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include "ManageMemory.h"

int main() {
	char* first_malloc = my_malloc(100);
	//char* first_malloc = malloc(100);
	char* second_malloc = my_malloc(200);
	//char* second_malloc = malloc(200);
	char* third_malloc = my_malloc(300);
	//char* third_malloc = malloc(300);
	printf("Malloc\n");
	//free(first_malloc);
	//free(second_malloc);
	//free(third_malloc);
	return 0;
}