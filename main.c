#include <stdio.h>
#include <assert.h>
#include <stdint.h>

uint8_t hex_to_byte(unsigned char h1, unsigned char h2) {
    // Convert ASCII hex characters to their integer value
    uint8_t byte_value;
    // Convert first character (h1)
    if (h1 >= '0' && h1 <= '9') {
        byte_value = (h1 - '0') *16; //  (multiply by 16)
    } else if (h1 >= 'a' && h1 <= 'f') {
        byte_value = (h1 - 'a' + 10) *16; //(multiply by 16) and add 10 for a-f
    } else if (h1 >= 'A' && h1 <= 'F') {
        byte_value = (h1 - 'A' + 10) *16;
    }
    else {
        return 0; 
    }
    // Convert second character (h2)
    if (h2 >= '0' && h2 <= '9') {
        byte_value |= (h2 - '0'); // Add value of h2
    } else if (h2 >= 'a' && h2 <= 'f') {
        byte_value |= (h2 - 'a' + 10); // Add value of h2 for a-f
    } else {
        return 0; // Invalid input, return 0 or handle error appropriately
    }

    return byte_value; // Return the combined byte value
}

void hexstr_to_hash(char hexstr[], unsigned char hash[32]) {
    for (int i = 0; i < 32; i++) {
        // Each byte consists of two hex characters
        hash[i] = hex_to_byte(hexstr[i * 2], hexstr[i * 2 + 1]);
    }
}
int main() {
    // Test cases for hex_to_byte
    assert(hex_to_byte('c', '8') == 200);
    assert(hex_to_byte('0', '3') == 3);
    assert(hex_to_byte('0', 'a') == 10);
    assert(hex_to_byte('1', '0') == 16);

    // Example usage of hexstr_to_hash
    char hex_input[] = "a2c3b02cb22af83d6d1ead1d4e18d916599be7c2ef2f017169327df1f7c844fd"; // 64 hex characters
    unsigned char hash[32];
    
    hexstr_to_hash(hex_input, hash);

    // Print the resulting hash array
    printf("Hash values:\n");
    for (int i = 0; i < 32; i++) {
        printf("%02x ", hash[i]);
    }
    printf("\n");

    return 0;
}