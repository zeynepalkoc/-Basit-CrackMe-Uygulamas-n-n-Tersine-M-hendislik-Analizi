# CrackMe Reverse Engineering Analyzer

## 🎯 Projenin Amacı ve Genel İşleyişi

Bu proje, tersine mühendislik tekniklerini kullanarak bir CrackMe (şifre çözme) uygulamasının analiz edilmesini amaçlamaktadır. Derlenmiş bir C programı, **Ghidra** ve **x64dbg** araçlarıyla analiz edilmiş; şifre kontrol algoritması çözülerek uygulamanın güvenlik mantığı ortaya çıkarılmıştır.

Projede amaçlanan temel hedefler:

- Derlenmiş `.exe` dosyasının iç yapısının analiz edilmesi  
- Şifre doğrulama algoritmasının ayrıştırılması  
- Statik ve dinamik analizlerle şifrenin tespit edilmesi  
- Tüm sürecin belgelenerek rapor haline getirilmesidir

---

## 👤 Proje Sahibi Bilgileri

| Bilgi              | İçerik                    |
|--------------------|---------------------------|
| **Ad Soyad**       | Zeynep Rabia Alkoç        |
| **Öğrenci Numarası** | 2320191065               |


---

## ⚙️ Kullanılan Araçlar ve Sürümler

| Araç / Teknoloji  | Sürüm / Açıklama                              |
|------------------|-----------------------------------------------|
| Ghidra           | 10.4 (Statik analiz aracı)                    |
| x64dbg           | 2025 Sürümü (Dinamik analiz aracı)            |
| GCC (MinGW)      | 12.2.0 (C derleyici)                           |
| Windows 11 x64    | Test ortamı                                   |
| Python (opsiyonel) | JSON çıktılar için yardımcı betikler         |

---

## 📁 Proje Dosya Yapısı

```plaintext
├── crackme_pro.c           # Kaynak C kodu
├── crackme_pro.exe         # Derlenmiş uygulama (analiz edilen)
├── docs/
│   ├── ghidra-analysis.md  # Ghidra analiz dokümanı
│   ├── x64dbg-analysis.md  # x64dbg analiz dokümanı
│   ├── report.pdf          # Nihai analiz raporu
├── screenshots/            # Ekran görüntüleri klasörü
└── README.md               # Proje tanıtım dosyası (bu belge)
