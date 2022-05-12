int get_main_menu_option() {
	int option;

	char menu[] = "\n ========= ============ \n  Options               \n ========= ============ \n       1.   Set value   \n       2.   Read value  \n       3.   Exit :(     \n ========= ============ ";

	printf("%s", menu);
	printf("\n\n -> ");
	scanf("%d", &option);

	return option;
}

void print_creation_menu() {
	char menu[] = "\n =============== \n  Creation Step  \n ===============\n";
	
	printf("%s", menu);
	printf("\n - What is the vector length? ");
	printf("\n\n -> ");
}

void print_successfully_created() {
	printf("\n ============================== ");
	printf("\n  Vector successfully created!  ");
	printf("\n ============================== \n\n");
}

void print_set_menu() {
	printf("\n ================== ");
	printf("\n  Set vector value  ");
	printf("\n ================== \n\n");
}

void print_read_menu() {
    printf("\n =================== ");
    printf("\n  Read vector index  ");
	printf("\n =================== \n\n");
}

void display_value(float value, int index) {
	printf("\n -> Vector[%d] = %f\n", index, value);
}

void display_exit_message() {
    printf("\n  See you...  \n\n");
}
