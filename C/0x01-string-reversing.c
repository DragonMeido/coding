/* Tried to get my hands on coding again. The following code reverses a string entered by user at runtime,
 * here i tried dynamically resize the input buffer */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INITAL_BUFFER_SIZE 10

char* getdastring() {
    char* buffer = malloc(INITAL_BUFFER_SIZE * sizeof(char));
    printf("gib string pls: ");
    if (buffer == NULL) {
        printf("failed to allocate memory\n");
        exit(1);
    }
    
    int capacity = INITAL_BUFFER_SIZE;
    int length = 0;
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {
        if (length == capacity - 1) {
            capacity *= 2;
            char* new_buffer = realloc(buffer, capacity * sizeof(char));
            if (new_buffer == NULL) {
                printf("failed to allocate memory for new_buffer\n");
                free(buffer);
                exit(1);
            }
            buffer = new_buffer;
        }
        buffer[length++] = c;
    }
    buffer[length] = '\0';
    return buffer;
}

int main() {
    int i = 0;
    char* input = getdastring();
    printf("\nInput string: \t%s\n", input);
    int inputlen = strlen(input) + 1;
    printf("\nOutput string: \t");
    for (i = 0; i <= inputlen; i++) {
        printf("%c", input[inputlen - i]);
    }
    free(input);
    return 0;
}

