// Include
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// base64 submodule
#include <base64/base64.h>

// Entry point
int main ( int argc, const char *argv[] )
{

    // Supress compiler warnings
    (void) argc;
    (void) argv;

    // Initialized data
    const char hello_world[14] = "Hello, World!";
    char hello_world_base64[512] = { 0 };

    // Encode the string in base64
    base64_encode(hello_world, strlen(hello_world), hello_world_base64);

    // Print the encoded string
    printf("\"%s\" encoded in base64 is \"%s\"\n", hello_world, hello_world_base64);

    // Success
    return EXIT_SUCCESS;
}
