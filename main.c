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
    const char hello_world[13+1] = "Hello, World!";
    const char hello_world_base64[18+1] = "SGVsbG8sIFdvcmxkIQ";
    char hello_world_base64_out[512] = { 0 };
    char hello_world_out[512] = { 0 };

    // Encode the string in base64
    base64_encode(hello_world, strlen(hello_world), hello_world_base64_out);

    // Print the encoded string
    printf("\"%s\" encoded in base64 is \"%s\"\n", hello_world, hello_world_base64_out);

    // Decode the base64 to a string
    base64_decode(hello_world_base64, strlen(hello_world_base64), hello_world_out);

    // Print the decoded string
    printf("\"%s\" decoded from base64 is \"%s\"\n", hello_world_base64, hello_world_out);

    // Success
    return EXIT_SUCCESS;
}
