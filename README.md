# Embedded-System-Memory-Management
## Latar Belakang
Dalam sistem embedded, memori adalah salah satu sumber daya yang paling berharga dan terbatas. Pengelolaan memori yang efisien sangat penting untuk memastikan stabilitas dan kinerja sistem yang optimal. Fragmentasi memori dapat menyebabkan sebagian besar memori tidak dapat digunakan secara efektif, meskipun masih ada banyak ruang yang tersisa. Fragmentasi adalah situasi di mana memori yang tersedia terpecah menjadi bagian-bagian kecil yang tidak dapat digunakan untuk alokasi memori baru, meskipun total memori yang tersedia cukup. Hal ini menyebabkan sistem gagal mengalokasikan memori, meskipun secara teknis masih ada ruang yang cukup. Untuk mengatasi fragmentasi dan memastikan penggunaan memori yang efisien, berbagai algoritma pengelolaan memori telah dikembangkan. Dalam eksperimen ini, kita akan mengeksplorasi tiga algoritma utama:
- First Fit: Mengalokasikan blok memori pertama yang cukup besar untuk memenuhi permintaan.
- Best Fit: Mencari blok memori terkecil yang cukup besar untuk memenuhi permintaan, dengan harapan meminimalkan sisa memori yang tidak terpakai.
- Worst Fit: Mencari blok memori terbesar yang tersedia, dengan harapan meminimalkan fragmentasi dengan membagi blok besar menjadi bagian yang lebih kecil.
## Tujuan Eksperimen
Eksperimen ini bertujuan untuk mengeksplorasi dan memahami perbedaan antara tiga algoritma pengelolaan memori yang sering digunakan dalam sistem embedded: First Fit, Best Fit, dan Worst Fit. Ketiga algoritma ini digunakan untuk mengalokasikan memori pada sistem dengan sumber daya terbatas, seperti pada sistem embedded. Dengan memahami bagaimana masing-masing algoritma bekerja dan pengaruhnya terhadap penggunaan memori, kita bisa menentukan metode mana yang paling efisien untuk situasi tertentu, terutama dalam hal meminimalkan fragmentasi memori dan memastikan alokasi yang optimal.
## Penjelasan Fragmentasi
- Fragmentasi Internal: Terjadi ketika ruang yang dialokasikan lebih besar dari yang dibutuhkan, sehingga sisa ruang dalam blok yang dialokasikan tidak digunakan.
- Fragmentasi Eksternal: Terjadi ketika blok memori bebas tidak dapat digunakan untuk alokasi baru karena blok-blok tersebut terlalu kecil atau tersebar.
## Pelaksanaan Eksperimen
### Persiapan Sistem:
- Kami mengalokasikan memori virtual sebesar 25 KB. Sistem memori ini akan digunakan untuk mensimulasikan pengelolaan memori dalam sistem embedded.
- Tiga algoritma pengelolaan memori (First Fit, Best Fit, dan Worst Fit) telah diimplementasikan dalam C untuk mengelola alokasi dan dealokasi memori.
### Eksperimen:
- Task 1: Melakukan alokasi memori dalam ukuran acak antara 1 hingga 4096 byte, menggunakan salah satu dari tiga algoritma yang disebutkan. Setelah sejumlah blok dialokasikan, sebagian dari blok-blok tersebut akan dibebaskan kembali untuk mensimulasikan skenario dunia nyata. Setelah sebagian blok memori dibebaskan, blok tersebut akan dialokasikan kembali agar perbedaan antara ketiga algoritma pengelolaan memori lebih terlihat.
- Monitoring: Setiap kali task selesai, kami mencatat jumlah memori yang digunakan dengan fungsi monitor_memory_usage, untuk melihat seberapa efektif masing-masing algoritma dalam mengelola memori yang ada.
### Analisis:
- Kami membandingkan jumlah memori yang digunakan oleh setiap algoritma untuk melihat bagaimana mereka menangani fragmentasi memori dan bagaimana efektivitas mereka dalam menggunakan ruang memori yang tersedia.
## Hasil Eksperimen
Hasil dari eksperimen ini menunjukkan bahwa setiap algoritma memiliki karakteristik dan performa yang berbeda dalam pengelolaan memori:
- First Fit mengalokasikan memori secara efisien pada awalnya, namun cenderung mengalami masalah fragmentasi seiring berjalannya waktu, yang mengurangi efisiensinya.
- Best Fit mencoba meminimalkan sisa memori yang tidak terpakai dengan mencari blok terkecil yang cukup besar untuk dialokasikan. Namun, ini juga bisa meningkatkan fragmentasi internal, di mana banyak ruang kecil yang tersisa dalam blok tidak bisa digunakan.
- Worst Fit mengalokasikan blok terbesar yang tersedia, yang cenderung mengurangi fragmentasi eksternal, tetapi bisa menyebabkan fragmentasi internal yang lebih besar jika blok besar tersebut dipecah menjadi bagian-bagian kecil yang sulit digunakan kembali.
## Kesimpulan
Dari eksperimen ini, dapat disimpulkan bahwa tidak ada satu pun algoritma yang secara universal lebih baik dari yang lain; masing-masing memiliki kelebihan dan kekurangannya sendiri tergantung pada skenario spesifik. Dalam sistem embedded dengan sumber daya terbatas, pemilihan algoritma pengelolaan memori harus disesuaikan dengan pola penggunaan memori yang diantisipasi untuk memaksimalkan efisiensi dan stabilitas sistem. Algoritma First Fit cenderung lebih cepat tetapi kurang efisien dalam jangka panjang karena fragmentasi, sementara Best Fit dan Worst Fit dapat lebih efektif dalam skenario tertentu, tetapi dengan biaya kinerja dan kompleksitas yang lebih tinggi. Oleh karena itu, pemahaman mendalam tentang pola alokasi dan kebutuhan sistem sangat penting dalam memilih algoritma yang tepat untuk pengelolaan memori.
