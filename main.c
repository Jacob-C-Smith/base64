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
    const char hello_world            [13+1] = "Hello, World!";
    char       hello_world_base64_out [512]  = { 0 };
    char       hello_world_out        [512]  = { 0 };

    // Encode the string in base64
    if ( base64_encode(hello_world, strlen(hello_world), hello_world_base64_out) == 0 ) goto failed_to_encode;

    // Print the encoded string
    (void)printf("\"%s\" encoded in base64 is \"%s\"\n", hello_world, hello_world_base64_out);

    // Decode the base64 to a string
    if ( base64_decode(hello_world_base64_out, strlen(hello_world_base64_out), hello_world_out) == 0 ) goto failed_to_decode;

    // Print the decoded string
    (void)printf("\"%s\" decoded from base64 is \"%s\"\n", hello_world_base64_out, hello_world_out);

    // Success
    return EXIT_SUCCESS;

    // Error handling
    {
        failed_to_encode:

            // Print an error message to standard out
            printf("Failed to encode data!\n");

            // Error
            return EXIT_FAILURE;

        failed_to_decode:
        
            // Print an error message to standard out
            printf("Failed to decode data!\n");

            // Error
            return EXIT_FAILURE;
    }
}
