
# ROADMAP.MD: CrackMe Tersine Mühendislik Analizi

## Proje Özeti
Bu proje, C diliyle geliştirilen bir CrackMe uygulamasının, tersine mühendislik yöntemleriyle analiz edilmesini amaçlamaktadır. Derlenmiş `.exe` dosyası, Ghidra ve x64dbg kullanılarak statik ve dinamik analiz teknikleriyle incelenecek; şifre kontrol mekanizması ortaya çıkarılacak ve tüm süreç raporlanacaktır. Proje bireysel olarak yürütülmektedir.

**Toplam Süre:** 3 gün  
**Sorumlu:** Zeynep Rabia Alkoç  
**Kapsam:** Kod yazımı → Derleme → Ghidra Analizi → x64dbg Analizi → Raporlama

---

## 📁 Proje Dosya Yapısı (Beklenen)

```
CrackMe-Analysis/
├── src/
│   └── crackme_pro.c
├── bin/
│   └── crackme_pro.exe
├── analysis/
│   ├── ghidra/
│   │   └── screenshots/
│   ├── x64dbg/
│   │   └── screenshots/
├── docs/
│   ├── ghidra-analysis.md
│   ├── x64dbg-analysis.md
│   └── references.md
├── reports/
│   ├── analysis_report.md
│   └── analysis_report.pdf
├── README.md
└── ROADMAP.md
```

---

## ⏱️ Zaman Planı ve Görevler

### 🟦 Gün 1 – Uygulama Yazımı ve Derleme

- [ ] `crackme_pro.c` oluşturulur
  - XOR, pozisyon tabanlı modifikasyon, hash algoritması eklenir
- [ ] Derleme işlemi:
  ```bash
  gcc src/crackme_pro.c -o bin/crackme_pro.exe
  ```
- [ ] `Access Denied` ve `Access Granted` mantığı test edilir
- [ ] README.md dosyasında proje tanımı ve kullanım bilgisi yazılır

---

### 🟩 Gün 2 – Ghidra ile Statik Analiz

- [ ] Ghidra'da yeni proje oluşturulur
- [ ] `crackme_pro.exe` dosyası içe aktarılır
- [ ] `main()`, `check_password()`, `custom_hash()` fonksiyonları analiz edilir
- [ ] Fonksiyon içi kontrol akışı ve string sabitleri incelenir
- [ ] `analysis/ghidra/screenshots/` klasörüne görüntüler alınır
- [ ] `docs/ghidra-analysis.md` içerisine analiz adımları not alınır

---

### 🟨 Gün 3 – x64dbg ile Dinamik Analiz & Raporlama

- [ ] `crackme_pro.exe` x64dbg ile çalıştırılır
- [ ] `printf("Access Granted")` satırına breakpoint eklenir
- [ ] Bellek takibi ile şifre dizisi izlenir
- [ ] Giriş şifresinin çözülmesi için gerekli hex analiz yapılır
- [ ] `analysis/x64dbg/screenshots/` içerisine adım adım ekran görüntüsü eklenir
- [ ] `docs/x64dbg-analysis.md` içerisine yorumlu analiz yazılır
- [ ] `reports/analysis_report.md` ve `analysis_report.pdf` oluşturulur

---

## 📌 Ek Görevler

- [ ] `references.md` içerisine kullanılan kaynaklar, araç sürümleri ve linkler yazılır
- [ ] `README.md` içerisine “Nasıl çalıştırılır?” ve “Araç kurulumu” bilgisi eklenir
- [ ] Ghidra ve x64dbg kurulum adımları belgelenir
- [ ] Projenin PDF versiyonu oluşturulur ve teslim formatına getirilir

---

## ✅ Test Planı

| Aşama              | Test İçeriği                                   | Beklenen Sonuç                     |
|--------------------|-------------------------------------------------|------------------------------------|
| Derleme            | `gcc` ile derlenebilir mi?                     | `.exe` oluşmalı                    |
| Terminal testi     | Hatalı ve doğru şifre girildiğinde tepkiler    | Uygun mesajlar dönmeli             |
| Ghidra             | Fonksiyonlar tanımlanabilir mi?                | Yapı tam ayrıştırılmalı            |
| x64dbg             | Bellek ve break point izleme yapılabiliyor mu? | Şifre dizisi takip edilebilmeli    |

---

## 🧪 Kullanılan Araçlar ve Versiyonlar

| Araç         | Versiyon / Kaynak                            |
|--------------|-----------------------------------------------|
| GCC (MinGW)  | 12.2.0                                        |
| Ghidra       | 10.4 (https://ghidra-sre.org)                 |
| x64dbg       | May 2025 Snapshot (https://x64dbg.com)       |
| Windows      | 10 x64 test ortamı                            |

---

## 📚 Notlar

- Tüm analiz çıktıları görsellerle desteklenmelidir.
- Rapor dili teknik ve akademik düzeye uygun yazılacaktır.
- Kaynakça bölümü APA veya IEEE standardına uygun hazırlanacaktır.
