#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEN 64

// Girişleri hashleyen fonksiyon (XOR + pozisyon + ASCII kaydırma)
void hash_input(const char* input, char* output) {
    int key = 0x5A;
    for (int i = 0; i < strlen(input); i++) {
        output[i] = ((input[i] ^ key) + i) % 126;
        if (output[i] < 33) output[i] += 33;
    }
    output[strlen(input)] = '\0';
}

// Kullanıcı adını doğrular: ters yazılmış hali dosyadakiyle eşleşmeli
int validate_username(const char* input) {
    FILE* file = fopen("required/user.txt", "r");
    if (!file) {
        printf("Hata: required/user.txt bulunamadı!\n");
        return 0;
    }

    char expected[MAX_LEN];
    fgets(expected, MAX_LEN, file);
    expected[strcspn(expected, "\n")] = '\0'; // \n sil
    fclose(file);

    int len = strlen(input);
    if (len != strlen(expected)) return 0;

    for (int i = 0; i < len; i++) {
        if (input[i] != expected[len - 1 - i])
            return 0;
    }
    return 1;
}

// Şifre doğrulama: hash eşleşmeli
int validate_password(const char* input) {
    FILE* file = fopen("required/pass.hash", "r");
    if (!file) {
        printf("Hata: required/pass.hash bulunamadı!\n");
        return 0;
    }

    char expected[MAX_LEN], hashed[MAX_LEN];
    fgets(expected, MAX_LEN, file);
    expected[strcspn(expected, "\n")] = '\0';
    fclose(file);

    hash_input(input, hashed);
    return strcmp(hashed, expected) == 0;
}

// Lisans doğrulama: gün ve şifre hash'e göre işlem yapar
int validate_license(const char* username, const char* password, const char* license) {
    char combined[MAX_LEN * 2];
    snprintf(combined, sizeof(combined), "%s:%s", username, password);

    char generated[MAX_LEN];
    hash_input(combined, generated);
    return strcmp(generated, license) == 0;
}

int main() {
    char username[MAX_LEN], password[MAX_LEN], license[MAX_LEN];

    printf("Kullanıcı Adı: ");
    fgets(username, MAX_LEN, stdin);
    username[strcspn(username, "\n")] = '\0';

    printf("Şifre: ");
    fgets(password, MAX_LEN, stdin);
    password[strcspn(password, "\n")] = '\0';

    printf("Lisans Kodu: ");
    fgets(license, MAX_LEN, stdin);
    license[strcspn(license, "\n")] = '\0';

    if (!validate_username(username)) {
        printf("Kullanıcı adı geçersiz!\n");
        return 1;
    }

    if (!validate_password(password)) {
        printf("Şifre geçersiz!\n");
        return 1;
    }

    if (!validate_license(username, password, license)) {
        printf("Lisans kodu geçersiz!\n");
        return 1;
    }

    printf("✔ Doğrulama başarılı! Lisanslı kullanıcı hoş geldin, %s 🎉\n", username);
    return 0;
}
