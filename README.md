# t

A simple test runner in C language.

### How to use

```c
#include "t.h"

void* test_something() {
    assert(1 + 1 == 2);
    return NULL;
}

void* test_something2() {
    assert(1 + 2 == 3);
    return NULL;
}

void* test_something3() {
    assert(2 * 2 == 1);
    return NULL;
}

int main(int argc, char **argv) {
    run(
        test_something, 
        test_something2, 
        test_something3
    );
    return 0;
}
```
