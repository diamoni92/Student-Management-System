#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    getchar(); // consume newline after number
    
    for (int i = 0; i < n; i++) {
        char input[205]; // max 100 chars * 2 for '\0' representation + extra
        char line[105];  // actual string buffer
        int len = 0;
        
        // Read the line
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }
        
        // Remove trailing newline if present
        int inputLen = strlen(input);
        if (inputLen > 0 && input[inputLen - 1] == '\n') {
            input[inputLen - 1] = '\0';
            inputLen--;
        }
        
        // Parse the input and convert \0 to actual null character
        int j = 0;
        for (int k = 0; k < inputLen; k++) {
            if (input[k] == '\\' && k + 1 < inputLen && input[k + 1] == '0') {
                // Found \0 sequence, add null character
                line[j++] = '\0';
                k++; // skip the '0'
            } else {
                // Regular character
                line[j++] = input[k];
            }
        }
        
        // Add final null terminator
        line[j] = '\0';
        
        // Calculate sizeof: total length including all characters and final null terminator
        int sizeofValue = j + 1;
        
        // Calculate strlen: length up to first null character (excluding it)
        int strlenValue = strlen(line);
        
        printf("%d %d\n", sizeofValue, strlenValue);
    }
    
    return 0;
}
