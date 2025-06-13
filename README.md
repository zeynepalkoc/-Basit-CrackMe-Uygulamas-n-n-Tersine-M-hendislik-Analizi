
#  Vulnerability Analysis via Reverse Engineering

[![C](https://img.shields.io/badge/C-Language-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))  
[![Ghidra](https://img.shields.io/badge/Ghidra-Tool-red.svg)](https://ghidra-sre.org/)  
[![x64dbg](https://img.shields.io/badge/x64dbg-Debugger-yellow.svg)](https://x64dbg.com/)  
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)

---

## 📑 İçerik Tablosu  
## 📑 Table of Contents

1. [Giriş ve Amaç](#1-giriş-ve-amaç) / Introduction and Purpose  
2. [Özellikler](#2-özellikler) / Features  
3. [Dosya Yapısı](#3-dosya-yapısı) / File Structure  
4. [Kurulum ve Derleme](#4-kurulum-ve-derleme) / Installation and Compilation  
5. [Analiz Süreci](#5-analiz-süreci) / Analysis Process  
6. [Gelecek Geliştirmeler](#6-gelecek-geliştirmeler) / Future Improvements  
7. [Katkıda Bulunma](#7-katkıda-bulunma) / Contributing  
8. [Lisans](#8-lisans) / License

---

## 1. Giriş ve Amaç  
## 1. Introduction and Purpose

(TR) Bu proje, C dili ile yazılmış bir CrackMe uygulamasını analiz ederek güvenlik açıklarını belirlemeyi, şifre kontrol mekanizmasını anlamayı ve tersine mühendislik tekniklerini kullanarak iç işleyişi çözmeyi hedefler.

(EN) This project aims to analyze a CrackMe application written in C to identify security weaknesses, understand the password checking mechanism, and reverse engineer its logic using professional tools.

---

## 2. Özellikler  
## 2. Features

- C ile yazılmış CrackMe uygulaması  
- Gelişmiş şifreleme (XOR, pozisyon, karakter kaydırma)  
- Ghidra ile statik analiz  
- x64dbg ile dinamik analiz  
- Belgeleme ve raporlama (Markdown + PDF)  
- Lisans doğrulama kontrolü  
- Manuel veri girişi / Dosyadan veri alma desteği  

---

## 3. Dosya Yapısı  
## 3. File Structure

```
Reverse-Engineering-Analysis/
├── analysis/
│   ├── ghidra/
│   └── x64dbg/
├── assets/
├── bin/
├── docs/
├── reports/
├── required/
├── researches/
├── src/
│   └── crackme_advanced.c
├── README.md
├── ROADMAP.md
└── LICENSE
```

---

## 4. Kurulum ve Derleme  
## 4. Installation and Compilation

**Gereksinimler / Requirements:**

- GCC (MinGW)  
- Ghidra  
- x64dbg  
- Windows ortamı önerilir

**Derleme / Compilation:**

```bash
gcc src/crackme_advanced.c -o bin/crackme_advanced.exe
```

**Çalıştırma / Run:**

```bash
bin/crackme_advanced.exe
```

---

## 5. Analiz Süreci  
## 5. Analysis Process

- [x] Ghidra ile .exe dosyasının disassembly ve dekompilasyonu  
- [x] x64dbg ile break point ve register izlemesi  
- [x] Hardcoded veri kontrolü (yok!)  
- [x] Dinamik veri analizi: kullanıcı girişi veya dosyadan okuma  
- [x] Lisans kontrol algoritması çözümü  
- [x] Tersine mühendislik raporu oluşturma  

---

## 6. Gelecek Geliştirmeler  
## 6. Future Improvements

- Dosyadan anahtar okuma mekanizması  
- Dinamik log kayıt sistemi  
- Hata yönetimi ve şifrelemeye zorluk ekleme  
- GUI arayüz prototipi (opsiyonel)  

---

## Acknowledgements / *Teşekkürler*

Thanks to:  
- Keyvan Arasteh (keyvan.arasteh@istinye.edu.tr)
- Istinye University

*Teşekkürler: Harika kütüphaneler ve ilham kaynakları için.*

---

## 8. Lisans  
## 8. License

Bu proje MIT lisansı ile korunmaktadır. Detaylar için `LICENSE` dosyasına bakınız.  
This project is licensed under the MIT License. See the `LICENSE` file for details.

---

🧑‍💻 **Geliştirici / Developer**: Zeynep  Alkoç  
🔗 **GitHub**: [github.com/zeynepalkoc](https://github.com/zeynepalkoc)
