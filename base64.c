/** !
 * Base 64 encoding and decoding
 * 
 * @file base64.c 
 * 
 * @author Jacob Smith
 */

// Include 
#include <base64/base64.h>

// Constant data
const char base_64_characters[64] = {
                                      'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                                      'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                                      'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                                      'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                                      'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                                      'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                                      'w', 'x', 'y', 'z', '0', '1', '2', '3',
                                      '4', '5', '6', '7', '8', '9', '+', '/'
                                    };

int base64_encode ( const void *const p_data, size_t len, unsigned char *const p_output )
{

    // Argument errors
    if ( p_data   == (void *) 0 ) goto no_data;
    if ( p_output == (void *) 0 ) goto no_output;

    // Iterate through len bytes of p_data
    for (size_t i = 0, j = 0; i < len; i+=3, j+=4)
    {

        // Initialized data
        unsigned long part = (((i   < len) ? ((unsigned char*)p_data)[i]   : 0) << 0x10) | 
                             (((i+1 < len) ? ((unsigned char*)p_data)[i+1] : 0) << 0x08) |
                             ( (i+2 < len) ? ((unsigned char*)p_data)[i+2] : 0);

        // Write the part to the output
        p_output[j]   = base_64_characters[(part >> 3 * 6) & 0x3F];
        p_output[j+1] = base_64_characters[(part >> 2 * 6) & 0x3F];
        p_output[j+2] = base_64_characters[(part >> 1 * 6) & 0x3F];
        p_output[j+3] = base_64_characters[(part >> 0 * 6) & 0x3F];
    }
    
    // Success
    return 1;

    // Error handling
    {

        // Argument errors
        {
            no_data:
                #ifndef NDEBUG
                    printf("[base64] Null pointer provided for parameter \"p_data\" in call to function \"%s\"\n", __FUNCTION__);
                #endif

                // Error
                return 0;

            no_output:
                #ifndef NDEBUG
                    printf("[base64] Null pointer provided for parameter \"p_output\" in call to function \"%s\"\n", __FUNCTION__);
                #endif

                // Error
                return 0;
        }
    }
}