#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[]) {
    stack_t *stack = NULL;
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int line_number = 1;

    if (argc != 2) {
        fprintf(stderr, "Error: Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (access(argv[1], R_OK) == -1) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    file = fopen(argv[1], "r");
    bus.file = file;
    if (file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    while ((read = getline(&line, &len, file)) != -1) {
        bus.content = line;
        int execute_result = execute(line, line_number, &stack, file);
        if (execute_result != 0)
        {
            fclose(file);
            free_stack(stack);
            free(line);
            exit(EXIT_FAILURE);
        }
        line_number++;
    }

    free(line);
    fclose(file);

    return (0);
}

