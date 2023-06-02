#include "prog.h"
#include <math.h>

// Convert string to int in any base
int string_to_int(char *string, int base) {
    int result = 0;

    for (int i = 0; i < strlen(string); i++) {
        int digit;
        if (string[i] >= '0' && string[i] <= '9') {
            digit = string[i] - '0';
        } else if (string[i] >= 'a' && string[i] <= 'f') {
            digit = string[i] - 'a' + 10;
        } else if (string[i] >= 'A' && string[i] <= 'F') {
            digit = string[i] - 'A' + 10;
        } else {
            printf("Invalid character.\n");
            exit(-1);
        }

        if (digit >= base) {
            printf("Invalid character.\n");
            exit(-1);
        }

        result += digit * pow(base, strlen(string)-i-1);
    }
    return result;
}

// Helper function that reverses string for base conversion
void reverse_str(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len/2; i++)
    {
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

// Convert decimal to given base from argument
char* dec_to_base(char* dest, int src, int base, int width) {
    if (base == 16) {
       int i = 0;
       dest[width] = '\0';

       for (int j = width - 4; j >= 0; j -= 4) {
           int digit = (src >> j) & 0xF;
           if (digit < 10)
               dest[i] = '0' + digit;
           else
               dest[i] = 'A' + (digit - 10);
           i++;
       }

        return dest;
    }
	
    char digits[] = "0123456789ABCDEF";

    if (src < 0) {
   	    src += (1 << width); // add 2^32 to make the value unsigned
    }
    
    int i = 0;
    while (src > 0) {
        dest[i] = digits[src % base];
        src /= base;
        i++;
    }
    
    dest[i] = '\0';

    int padding = 0;
  	if (width != 32) {
	  if (i < width) 
      	padding = width - i;
	} else if (width == 32) {
		if (base == 2) 
	      padding = 32 - i;
	   	else if (base == 16)
	      padding = 8 - i;
	}

    for (int j = 0; j < padding; j++) {
        dest[i + j] = '0';
    }
    
    dest[i + padding] = '\0';

    reverse_str(dest);
    return dest; 

}

