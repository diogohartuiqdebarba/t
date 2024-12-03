#ifndef T_H
#define T_H

#include <stdio.h>

int passed_tests = 0;

#define GREEN_TEXT "\033[0;32m" 
#define RED_TEXT "\033[1;31m"
#define RESET_TEXT "\033[0m"

#define assert(assertion) do { \
    if (!(assertion)) { \
        static char message[512]; \
        snprintf(message, sizeof(message), "%sError => %s: %s failed%s", RED_TEXT, __func__, #assertion, RESET_TEXT); \
        return message; \
    } \
} while (0)

#define run(tests...) ({ \
    void *result = NULL; \
    void *(*test_array[])() = {tests}; \
    int num_tests = sizeof(test_array) / sizeof(test_array[0]); \
    for (int i = 0; i < num_tests; i++) { \
        result = test_array[i](); \
        if (result != NULL) { \
            printf("%s\n", (char*)result); \
            break; \
        } \
        passed_tests++; \
    } \
    if (result == NULL) { \
        printf("%sALL TESTS PASSED%s\n", GREEN_TEXT, RESET_TEXT); \
    } \
    printf("Tests run: %d\n", passed_tests); \
})

#endif // T_H
