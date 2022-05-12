#include <stdio.h>
#include <stdlib.h>

#include "menu.h"

typedef struct {
	int length;
	float* value;
} Vector;

Vector* create(int length) {
	Vector* vector = (Vector*)malloc(sizeof(Vector));
	
	vector->length = length;
	vector->value = (float*)malloc(sizeof(float));

	return vector;
}

float access(Vector* vector, int index) {
	if (index < 0 || index >= vector->length) {
		printf("Hmmmm... I dont think this index exists on this array.\n");
		exit(2);
	}

	return vector->value[index];
}

void set(Vector* vector, int index, float value) {
	if (index < 0 || index >= vector->length) {
		printf("Hey mate, you shouldn't be accessing this index, since it is not allocated\n");
		exit(2);
	}

	vector->value[index] = value;
}

void handle_menu(Vector* vector, int current_step) {
	int CREATE_STEP     = 0;
	int SET_VALUE_STEP  = 1;
	int READ_VALUE_STEP = 2;
	int EXIT_STEP       = 3;
	
	int option;	

	if (current_step == CREATE_STEP) {
		int vector_length;

		print_creation_menu();
		scanf("%d", &vector_length);
		vector = create(vector_length);
		
		print_successfully_created();

		handle_menu(vector, SET_VALUE_STEP);
	}
	
	if (current_step == SET_VALUE_STEP) {
		int vector_index = 0;
		float index_value = 0;

		print_set_menu();
		
		printf("\n - Index to be setted: ");
		scanf("%d", &vector_index);

		printf("\n - Value to be setted: ");
		scanf("%f", &index_value);

		set(vector, vector_index, index_value);

		option = get_main_menu_option();

		handle_menu(vector, option);
	}

	if (current_step == READ_VALUE_STEP) {
		int vector_index = 0;
		float value = 0;

		print_read_menu();

		printf("\n - Index to be read: ");
		scanf("%d", &vector_index);

		value = access(vector, vector_index);

		display_value(value, vector_index);

		option = get_main_menu_option();

		handle_menu(vector, option);
	}

	if (current_step == EXIT_STEP) {
		display_exit_message();

		return;
	}
}

int main() {
	Vector* vector;

	handle_menu(vector, 0);

	return 0;
}

