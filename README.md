<div align="center">

<h1>CrackMe Reverse Engineering Analyzer</h1>

<p><strong>final projesi- Tersine Mühendislik Uygulaması</strong></p>

<p>Derlenmiş bir CrackMe uygulamasının Ghidra ve x64dbg kullanılarak statik ve dinamik analiz yöntemleriyle çözülmesi.</p>

</div>

---

## 📁 Proje Hakkında

Bu proje, tersine mühendislik tekniklerini uygulamalı olarak göstermek amacıyla hazırlanmıştır.  
C dilinde yazılmış özel bir CrackMe uygulaması, doğrudan çözülmeyecek şekilde şifrelenmiş ve çeşitli algoritmalarla obfuscate edilmiştir. Projenin amacı, bu uygulamanın analiz araçları ile adım adım çözülmesidir.

---

## 🚀 Özellikler

- Özel bit manipülasyon ve hash algoritmaları
- Şifre gizleme teknikleri (XOR, transform, obfuscation)
- Anti-debug yapılar (zaman geciktirme, bellek karışıklığı)
- Ghidra ile statik analiz
- x64dbg ile dinamik çözümleme
- PDF rapor ve ekran görüntüleriyle belgeleme

---

## 🧑‍💻 Geliştirici

| Öğrenci No | Ad Soyad            | Rol                     |
|------------|----------------------|--------------------------|
| 2320191065 | Zeynep Rabia Alkoç   | Kodlama, analiz, rapor  |

---

## 📌 Yol Haritası

- [x] CrackMe uygulamasının geliştirilmesi  
- [x] Derlenmiş `.exe` dosyasının hazırlanması  
- [x] Statik analiz (Ghidra)  
- [x] Dinamik analiz (x64dbg)  
- [x] Şifre çözümünün belgelenmesi  
- [x] Final PDF raporunun hazırlanması  

---

## 🛠️ Kurulum

```bash
git clone https://github.com/zeynepalkoc/crackme-reverse.git
cd crackme-reverse
gcc crackme_pro.c -o crackme_pro.exe
