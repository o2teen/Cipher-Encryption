#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt text using Caesar Cipher
void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            // Encrypt uppercase letters
            text[i] = (text[i] - 'A' + shift) % 26 + 'A';
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            // Encrypt lowercase letters
            text[i] = (text[i] - 'a' + shift) % 26 + 'a';
        }
    }
}

// Function to decrypt text using Caesar Cipher
void decrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            // Decrypt uppercase letters
            text[i] = (text[i] - 'A' - shift + 26) % 26 + 'A';
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            // Decrypt lowercase letters
            text[i] = (text[i] - 'a' - shift + 26) % 26 + 'a';
        }
    }
}

int main() {
    char text[100];
    int shift;
    char choice;

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    
    // Remove the newline character that fgets adds
    text[strcspn(text, "\n")] = '\0';

    printf("Enter shift value: ");
    scanf("%d", &shift);
    getchar(); // To clear the newline character from the buffer

    printf("Enter 'e' to encrypt or 'd' to decrypt: ");
    scanf("%c", &choice);

    if (choice == 'e') {
        encrypt(text, shift);
        printf("Encrypted text: %s\n", text);
    } else if (choice == 'd') {
        decrypt(text, shift);
        printf("Decrypted text: %s\n", text);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
