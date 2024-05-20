/** !
 * Include header for base64 library
 * 
 * @file base64/base64.h 
 * 
 * @author Jacob Smith 
 */

// Include guard
#pragma once

// Standard library
#include <stdio.h>
#include <stdbool.h>

// log module
#include <log/log.h>

// sync module
#include <sync/sync.h>

// Platform dependent macros
#ifdef _WIN64
#define DLLEXPORT extern __declspec(dllexport)
#else
#define DLLEXPORT
#endif


// Initializer
/** !
 * This gets called at runtime before main. 
 * 
 * @param void
 * 
 * @return void
 */
DLLEXPORT void base64_init ( void ) __attribute__((constructor));

// Encode
/** !
 * Encode len bytes of data in base 64, and store in p_output
 * 
 * @param p_data   the data to be encoded
 * @param len      the quantity of bytes to be encoded
 * @param p_output the output, encoded in base 64
 * 
 * @sa base64_decode
 * 
 * @return 1 on success, 0 on error
 */
DLLEXPORT int base64_encode ( const void *const p_data, size_t len, char *const p_output );

// Decode
/** !
 * Decode len bytes of base 64 data, and store in p_output
 * 
 * @param p_data   the data to be decoded
 * @param len      the quantity of bytes to be decoded
 * @param p_output the output, decoded from base 64
 * 
 * @sa base64_encode
 * 
 * @return 1 on success, 0 on error
 */
DLLEXPORT int base64_decode ( const char *const p_data, size_t len, void *const p_output );

// Cleanup
/** !
 * This gets called at runtime after main
 * 
 * @param void
 * 
 * @return void
 */
DLLEXPORT void base64_exit ( void ) __attribute__((destructor));
