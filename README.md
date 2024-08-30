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
```console
Starting task with First Fit allocation...
Phase 1
Memory Status:
Block 1: Address = 00000000, Size = 42, Used = No
Block 2: Address = 00408A60, Size = 2084, Used = Yes, Actual Size: 2084
Block 3: Address = 00000000, Size = 2239, Used = No
Block 4: Address = 00408B60, Size = 1925, Used = Yes, Actual Size: 1925
Block 5: Address = 00000000, Size = 2786, Used = No
Block 6: Address = 00408C60, Size = 3437, Used = Yes, Actual Size: 3437
Block 7: Address = 00000000, Size = 3287, Used = No
Block 8: Address = 00408D60, Size = 687, Used = Yes, Actual Size: 687
Block 9: Address = 00000000, Size = 2387, Used = No
Block 10: Address = 00408E60, Size = 3985, Used = Yes, Actual Size: 3985
Remaining memory: 13482
Memory used: 12118 bytes

Phase 2
1. Allocating 1610 bytes
Memory Status:
Block 1: Address = 00000000, Size = 42, Used = No
Block 2: Address = 00408A60, Size = 2084, Used = Yes, Actual Size: 2084
Block 3: Address = 00408AE0, Size = 2239, Used = Yes, Actual Size: 1610
Block 4: Address = 00408B60, Size = 1925, Used = Yes, Actual Size: 1925
Block 5: Address = 00000000, Size = 2786, Used = No
Block 6: Address = 00408C60, Size = 3437, Used = Yes, Actual Size: 3437
Block 7: Address = 00000000, Size = 3287, Used = No
Block 8: Address = 00408D60, Size = 687, Used = Yes, Actual Size: 687
Block 9: Address = 00000000, Size = 2387, Used = No
Block 10: Address = 00408E60, Size = 3985, Used = Yes, Actual Size: 3985
2. Allocating 3570 bytes
Memory Status:
Block 1: Address = 00000000, Size = 42, Used = No
Block 2: Address = 00408A60, Size = 2084, Used = Yes, Actual Size: 2084
Block 3: Address = 00408AE0, Size = 2239, Used = Yes, Actual Size: 1610
Block 4: Address = 00408B60, Size = 1925, Used = Yes, Actual Size: 1925
Block 5: Address = 00000000, Size = 2786, Used = No
Block 6: Address = 00408C60, Size = 3437, Used = Yes, Actual Size: 3437
Block 7: Address = 00000000, Size = 3287, Used = No
Block 8: Address = 00408D60, Size = 687, Used = Yes, Actual Size: 687
Block 9: Address = 00000000, Size = 2387, Used = No
Block 10: Address = 00408E60, Size = 3985, Used = Yes, Actual Size: 3985
Block 11: Address = 00408EE0, Size = 3570, Used = Yes, Actual Size: 3570
3. Allocating 2802 bytes
Memory Status:
Block 1: Address = 00000000, Size = 42, Used = No
Block 2: Address = 00408A60, Size = 2084, Used = Yes, Actual Size: 2084
Block 3: Address = 00408AE0, Size = 2239, Used = Yes, Actual Size: 1610
Block 4: Address = 00408B60, Size = 1925, Used = Yes, Actual Size: 1925
Block 5: Address = 00000000, Size = 2786, Used = No
Block 6: Address = 00408C60, Size = 3437, Used = Yes, Actual Size: 3437
Block 7: Address = 00408CE0, Size = 3287, Used = Yes, Actual Size: 2802
Block 8: Address = 00408D60, Size = 687, Used = Yes, Actual Size: 687
Block 9: Address = 00000000, Size = 2387, Used = No
Block 10: Address = 00408E60, Size = 3985, Used = Yes, Actual Size: 3985
Block 11: Address = 00408EE0, Size = 3570, Used = Yes, Actual Size: 3570
4. Allocating 444 bytes
Memory Status:
Block 1: Address = 00000000, Size = 42, Used = No
Block 2: Address = 00408A60, Size = 2084, Used = Yes, Actual Size: 2084
Block 3: Address = 00408AE0, Size = 2239, Used = Yes, Actual Size: 1610
Block 4: Address = 00408B60, Size = 1925, Used = Yes, Actual Size: 1925
Block 5: Address = 00408BE0, Size = 2786, Used = Yes, Actual Size: 444
Block 6: Address = 00408C60, Size = 3437, Used = Yes, Actual Size: 3437
Block 7: Address = 00408CE0, Size = 3287, Used = Yes, Actual Size: 2802
Block 8: Address = 00408D60, Size = 687, Used = Yes, Actual Size: 687
Block 9: Address = 00000000, Size = 2387, Used = No
Block 10: Address = 00408E60, Size = 3985, Used = Yes, Actual Size: 3985
Block 11: Address = 00408EE0, Size = 3570, Used = Yes, Actual Size: 3570
5. Allocating 1770 bytes
Memory Status:
Block 1: Address = 00000000, Size = 42, Used = No
Block 2: Address = 00408A60, Size = 2084, Used = Yes, Actual Size: 2084
Block 3: Address = 00408AE0, Size = 2239, Used = Yes, Actual Size: 1610
Block 4: Address = 00408B60, Size = 1925, Used = Yes, Actual Size: 1925
Block 5: Address = 00408BE0, Size = 2786, Used = Yes, Actual Size: 444
Block 6: Address = 00408C60, Size = 3437, Used = Yes, Actual Size: 3437
Block 7: Address = 00408CE0, Size = 3287, Used = Yes, Actual Size: 2802
Block 8: Address = 00408D60, Size = 687, Used = Yes, Actual Size: 687
Block 9: Address = 00408DE0, Size = 2387, Used = Yes, Actual Size: 1770
Block 10: Address = 00408E60, Size = 3985, Used = Yes, Actual Size: 3985
Block 11: Address = 00408EE0, Size = 3570, Used = Yes, Actual Size: 3570
6. Allocating 492 bytes
Memory Status:
Block 1: Address = 00000000, Size = 42, Used = No
Block 2: Address = 00408A60, Size = 2084, Used = Yes, Actual Size: 2084
Block 3: Address = 00408AE0, Size = 2239, Used = Yes, Actual Size: 1610
Block 4: Address = 00408B60, Size = 1925, Used = Yes, Actual Size: 1925
Block 5: Address = 00408BE0, Size = 2786, Used = Yes, Actual Size: 444
Block 6: Address = 00408C60, Size = 3437, Used = Yes, Actual Size: 3437
Block 7: Address = 00408CE0, Size = 3287, Used = Yes, Actual Size: 2802
Block 8: Address = 00408D60, Size = 687, Used = Yes, Actual Size: 687
Block 9: Address = 00408DE0, Size = 2387, Used = Yes, Actual Size: 1770
Block 10: Address = 00408E60, Size = 3985, Used = Yes, Actual Size: 3985
Block 11: Address = 00408EE0, Size = 3570, Used = Yes, Actual Size: 3570
Block 12: Address = 00408F60, Size = 492, Used = Yes, Actual Size: 492
7. Allocating 2996 bytes
Failed to allocate memory at iteration 7
Next allocation size: 2996
Remaining memory: 2794
Memory used: 22806 bytes

Starting task with Best Fit allocation...
Phase 1
Memory Status:
Block 1: Address = 00000000, Size = 3751, Used = No
Block 2: Address = 00408A60, Size = 732, Used = Yes, Actual Size: 732
Block 3: Address = 00000000, Size = 1341, Used = No
Block 4: Address = 00408B60, Size = 3720, Used = Yes, Actual Size: 3720
Block 5: Address = 00000000, Size = 2317, Used = No
Block 6: Address = 00408C60, Size = 3903, Used = Yes, Actual Size: 3903
Block 7: Address = 00000000, Size = 154, Used = No
Block 8: Address = 00408D60, Size = 293, Used = Yes, Actual Size: 293
Block 9: Address = 00000000, Size = 95, Used = No
Block 10: Address = 00408E60, Size = 1038, Used = Yes, Actual Size: 1038
Remaining memory: 15914
Memory used: 9686 bytes

Phase 2
1. Allocating 2333 bytes
Memory Status:
Block 1: Address = 004089E0, Size = 3751, Used = Yes, Actual Size: 2333
Block 2: Address = 00408A60, Size = 732, Used = Yes, Actual Size: 732
Block 3: Address = 00000000, Size = 1341, Used = No
Block 4: Address = 00408B60, Size = 3720, Used = Yes, Actual Size: 3720
Block 5: Address = 00000000, Size = 2317, Used = No
Block 6: Address = 00408C60, Size = 3903, Used = Yes, Actual Size: 3903
Block 7: Address = 00000000, Size = 154, Used = No
Block 8: Address = 00408D60, Size = 293, Used = Yes, Actual Size: 293
Block 9: Address = 00000000, Size = 95, Used = No
Block 10: Address = 00408E60, Size = 1038, Used = Yes, Actual Size: 1038
2. Allocating 3335 bytes
Memory Status:
Block 1: Address = 004089E0, Size = 3751, Used = Yes, Actual Size: 2333
Block 2: Address = 00408A60, Size = 732, Used = Yes, Actual Size: 732
Block 3: Address = 00000000, Size = 1341, Used = No
Block 4: Address = 00408B60, Size = 3720, Used = Yes, Actual Size: 3720
Block 5: Address = 00000000, Size = 2317, Used = No
Block 6: Address = 00408C60, Size = 3903, Used = Yes, Actual Size: 3903
Block 7: Address = 00000000, Size = 154, Used = No
Block 8: Address = 00408D60, Size = 293, Used = Yes, Actual Size: 293
Block 9: Address = 00000000, Size = 95, Used = No
Block 10: Address = 00408E60, Size = 1038, Used = Yes, Actual Size: 1038
Block 11: Address = 00408EE0, Size = 3335, Used = Yes, Actual Size: 3335
3. Allocating 3512 bytes
Memory Status:
Block 1: Address = 004089E0, Size = 3751, Used = Yes, Actual Size: 2333
Block 2: Address = 00408A60, Size = 732, Used = Yes, Actual Size: 732
Block 3: Address = 00000000, Size = 1341, Used = No
Block 4: Address = 00408B60, Size = 3720, Used = Yes, Actual Size: 3720
Block 5: Address = 00000000, Size = 2317, Used = No
Block 6: Address = 00408C60, Size = 3903, Used = Yes, Actual Size: 3903
Block 7: Address = 00000000, Size = 154, Used = No
Block 8: Address = 00408D60, Size = 293, Used = Yes, Actual Size: 293
Block 9: Address = 00000000, Size = 95, Used = No
Block 10: Address = 00408E60, Size = 1038, Used = Yes, Actual Size: 1038
Block 11: Address = 00408EE0, Size = 3335, Used = Yes, Actual Size: 3335
Block 12: Address = 00408F60, Size = 3512, Used = Yes, Actual Size: 3512
4. Allocating 1352 bytes
Memory Status:
Block 1: Address = 004089E0, Size = 3751, Used = Yes, Actual Size: 2333
Block 2: Address = 00408A60, Size = 732, Used = Yes, Actual Size: 732
Block 3: Address = 00000000, Size = 1341, Used = No
Block 4: Address = 00408B60, Size = 3720, Used = Yes, Actual Size: 3720
Block 5: Address = 00408BE0, Size = 2317, Used = Yes, Actual Size: 1352
Block 6: Address = 00408C60, Size = 3903, Used = Yes, Actual Size: 3903
Block 7: Address = 00000000, Size = 154, Used = No
Block 8: Address = 00408D60, Size = 293, Used = Yes, Actual Size: 293
Block 9: Address = 00000000, Size = 95, Used = No
Block 10: Address = 00408E60, Size = 1038, Used = Yes, Actual Size: 1038
Block 11: Address = 00408EE0, Size = 3335, Used = Yes, Actual Size: 3335
Block 12: Address = 00408F60, Size = 3512, Used = Yes, Actual Size: 3512
5. Allocating 1247 bytes
Memory Status:
Block 1: Address = 004089E0, Size = 3751, Used = Yes, Actual Size: 2333
Block 2: Address = 00408A60, Size = 732, Used = Yes, Actual Size: 732
Block 3: Address = 00408AE0, Size = 1341, Used = Yes, Actual Size: 1247
Block 4: Address = 00408B60, Size = 3720, Used = Yes, Actual Size: 3720
Block 5: Address = 00408BE0, Size = 2317, Used = Yes, Actual Size: 1352
Block 6: Address = 00408C60, Size = 3903, Used = Yes, Actual Size: 3903
Block 7: Address = 00000000, Size = 154, Used = No
Block 8: Address = 00408D60, Size = 293, Used = Yes, Actual Size: 293
Block 9: Address = 00000000, Size = 95, Used = No
Block 10: Address = 00408E60, Size = 1038, Used = Yes, Actual Size: 1038
Block 11: Address = 00408EE0, Size = 3335, Used = Yes, Actual Size: 3335
Block 12: Address = 00408F60, Size = 3512, Used = Yes, Actual Size: 3512
6. Allocating 2484 bytes
Memory Status:
Block 1: Address = 004089E0, Size = 3751, Used = Yes, Actual Size: 2333
Block 2: Address = 00408A60, Size = 732, Used = Yes, Actual Size: 732
Block 3: Address = 00408AE0, Size = 1341, Used = Yes, Actual Size: 1247
Block 4: Address = 00408B60, Size = 3720, Used = Yes, Actual Size: 3720
Block 5: Address = 00408BE0, Size = 2317, Used = Yes, Actual Size: 1352
Block 6: Address = 00408C60, Size = 3903, Used = Yes, Actual Size: 3903
Block 7: Address = 00000000, Size = 154, Used = No
Block 8: Address = 00408D60, Size = 293, Used = Yes, Actual Size: 293
Block 9: Address = 00000000, Size = 95, Used = No
Block 10: Address = 00408E60, Size = 1038, Used = Yes, Actual Size: 1038
Block 11: Address = 00408EE0, Size = 3335, Used = Yes, Actual Size: 3335
Block 12: Address = 00408F60, Size = 3512, Used = Yes, Actual Size: 3512
Block 13: Address = 00408FE0, Size = 2484, Used = Yes, Actual Size: 2484
7. Allocating 3347 bytes
Failed to allocate memory at iteration 7
Next allocation size: 3347
Remaining memory: 1651
Memory used: 23949 bytes

Starting task with Worst Fit allocation...
Phase 1
Memory Status:
Block 1: Address = 00000000, Size = 1870, Used = No
Block 2: Address = 00408A60, Size = 3529, Used = Yes, Actual Size: 3529
Block 3: Address = 00000000, Size = 1092, Used = No
Block 4: Address = 00408B60, Size = 1724, Used = Yes, Actual Size: 1724
Block 5: Address = 00000000, Size = 652, Used = No
Block 6: Address = 00408C60, Size = 1703, Used = Yes, Actual Size: 1703
Block 7: Address = 00000000, Size = 32, Used = No
Block 8: Address = 00408D60, Size = 3332, Used = Yes, Actual Size: 3332
Block 9: Address = 00000000, Size = 2651, Used = No
Block 10: Address = 00408E60, Size = 1662, Used = Yes, Actual Size: 1662
Remaining memory: 13650
Memory used: 11950 bytes

Phase 2
1. Allocating 1290 bytes
Memory Status:
Block 1: Address = 00000000, Size = 1870, Used = No
Block 2: Address = 00408A60, Size = 3529, Used = Yes, Actual Size: 3529
Block 3: Address = 00000000, Size = 1092, Used = No
Block 4: Address = 00408B60, Size = 1724, Used = Yes, Actual Size: 1724
Block 5: Address = 00000000, Size = 652, Used = No
Block 6: Address = 00408C60, Size = 1703, Used = Yes, Actual Size: 1703
Block 7: Address = 00000000, Size = 32, Used = No
Block 8: Address = 00408D60, Size = 3332, Used = Yes, Actual Size: 3332
Block 9: Address = 00408DE0, Size = 2651, Used = Yes, Actual Size: 1290
Block 10: Address = 00408E60, Size = 1662, Used = Yes, Actual Size: 1662
2. Allocating 569 bytes
Memory Status:
Block 1: Address = 004089E0, Size = 1870, Used = Yes, Actual Size: 569
Block 2: Address = 00408A60, Size = 3529, Used = Yes, Actual Size: 3529
Block 3: Address = 00000000, Size = 1092, Used = No
Block 4: Address = 00408B60, Size = 1724, Used = Yes, Actual Size: 1724
Block 5: Address = 00000000, Size = 652, Used = No
Block 6: Address = 00408C60, Size = 1703, Used = Yes, Actual Size: 1703
Block 7: Address = 00000000, Size = 32, Used = No
Block 8: Address = 00408D60, Size = 3332, Used = Yes, Actual Size: 3332
Block 9: Address = 00408DE0, Size = 2651, Used = Yes, Actual Size: 1290
Block 10: Address = 00408E60, Size = 1662, Used = Yes, Actual Size: 1662
3. Allocating 2854 bytes
Memory Status:
Block 1: Address = 004089E0, Size = 1870, Used = Yes, Actual Size: 569
Block 2: Address = 00408A60, Size = 3529, Used = Yes, Actual Size: 3529
Block 3: Address = 00000000, Size = 1092, Used = No
Block 4: Address = 00408B60, Size = 1724, Used = Yes, Actual Size: 1724
Block 5: Address = 00000000, Size = 652, Used = No
Block 6: Address = 00408C60, Size = 1703, Used = Yes, Actual Size: 1703
Block 7: Address = 00000000, Size = 32, Used = No
Block 8: Address = 00408D60, Size = 3332, Used = Yes, Actual Size: 3332
Block 9: Address = 00408DE0, Size = 2651, Used = Yes, Actual Size: 1290
Block 10: Address = 00408E60, Size = 1662, Used = Yes, Actual Size: 1662
Block 11: Address = 00408EE0, Size = 2854, Used = Yes, Actual Size: 2854
4. Allocating 3616 bytes
Memory Status:
Block 1: Address = 004089E0, Size = 1870, Used = Yes, Actual Size: 569
Block 2: Address = 00408A60, Size = 3529, Used = Yes, Actual Size: 3529
Block 3: Address = 00000000, Size = 1092, Used = No
Block 4: Address = 00408B60, Size = 1724, Used = Yes, Actual Size: 1724
Block 5: Address = 00000000, Size = 652, Used = No
Block 6: Address = 00408C60, Size = 1703, Used = Yes, Actual Size: 1703
Block 7: Address = 00000000, Size = 32, Used = No
Block 8: Address = 00408D60, Size = 3332, Used = Yes, Actual Size: 3332
Block 9: Address = 00408DE0, Size = 2651, Used = Yes, Actual Size: 1290
Block 10: Address = 00408E60, Size = 1662, Used = Yes, Actual Size: 1662
Block 11: Address = 00408EE0, Size = 2854, Used = Yes, Actual Size: 2854
Block 12: Address = 00408F60, Size = 3616, Used = Yes, Actual Size: 3616
5. Allocating 3678 bytes
Memory Status:
Block 1: Address = 004089E0, Size = 1870, Used = Yes, Actual Size: 569
Block 2: Address = 00408A60, Size = 3529, Used = Yes, Actual Size: 3529
Block 3: Address = 00000000, Size = 1092, Used = No
Block 4: Address = 00408B60, Size = 1724, Used = Yes, Actual Size: 1724
Block 5: Address = 00000000, Size = 652, Used = No
Block 6: Address = 00408C60, Size = 1703, Used = Yes, Actual Size: 1703
Block 7: Address = 00000000, Size = 32, Used = No
Block 8: Address = 00408D60, Size = 3332, Used = Yes, Actual Size: 3332
Block 9: Address = 00408DE0, Size = 2651, Used = Yes, Actual Size: 1290
Block 10: Address = 00408E60, Size = 1662, Used = Yes, Actual Size: 1662
Block 11: Address = 00408EE0, Size = 2854, Used = Yes, Actual Size: 2854
Block 12: Address = 00408F60, Size = 3616, Used = Yes, Actual Size: 3616
Block 13: Address = 00408FE0, Size = 3678, Used = Yes, Actual Size: 3678
6. Allocating 2773 bytes
Failed to allocate memory at iteration 6
Next allocation size: 2773
Remaining memory: 1643
Memory used: 23957 bytes
```
Hasil dari eksperimen ini menunjukkan bahwa setiap algoritma memiliki karakteristik dan performa yang berbeda dalam pengelolaan memori:
- First Fit mengalokasikan memori secara efisien pada awalnya, namun cenderung mengalami masalah fragmentasi seiring berjalannya waktu, yang mengurangi efisiensinya.
- Best Fit mencoba meminimalkan sisa memori yang tidak terpakai dengan mencari blok terkecil yang cukup besar untuk dialokasikan. Namun, ini juga bisa meningkatkan fragmentasi internal, di mana banyak ruang kecil yang tersisa dalam blok tidak bisa digunakan.
- Worst Fit mengalokasikan blok terbesar yang tersedia, yang cenderung mengurangi fragmentasi eksternal, tetapi bisa menyebabkan fragmentasi internal yang lebih besar jika blok besar tersebut dipecah menjadi bagian-bagian kecil yang sulit digunakan kembali.
## Kesimpulan
Dari eksperimen ini, dapat disimpulkan bahwa tidak ada satu pun algoritma yang secara universal lebih baik dari yang lain; masing-masing memiliki kelebihan dan kekurangannya sendiri tergantung pada skenario spesifik. Dalam sistem embedded dengan sumber daya terbatas, pemilihan algoritma pengelolaan memori harus disesuaikan dengan pola penggunaan memori yang diantisipasi untuk memaksimalkan efisiensi dan stabilitas sistem. Algoritma First Fit cenderung lebih cepat tetapi kurang efisien dalam jangka panjang karena fragmentasi, sementara Best Fit dan Worst Fit dapat lebih efektif dalam skenario tertentu, tetapi dengan biaya kinerja dan kompleksitas yang lebih tinggi. Oleh karena itu, pemahaman mendalam tentang pola alokasi dan kebutuhan sistem sangat penting dalam memilih algoritma yang tepat untuk pengelolaan memori.
