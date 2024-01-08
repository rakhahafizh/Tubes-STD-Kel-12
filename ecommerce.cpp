#include "ecommerce.h"

void createListParent(listeCommerce &LE) {
  firstE(LE) = NULL;
 }

void createListChild(listCostumer &LC) {
  firstC(LC) = NULL;
 }

adreCommerce allocateChild(infotypeeCommerce A) {
  adreCommerce P = new elmeCommerce;
  infoE(P) = A;
  nextE(P) = NULL;
  return P;
}
adrCostumer allocateParent(infotypeCostumer B) {
  adrCostumer Q = new elmCostumer;
  infoC(Q) = B;
  nextC(Q) = NULL;
  child(Q) = NULL;
  return Q;
}
void insertLastChild(listeCommerce &LE, adreCommerce P) {
  adreCommerce A;
  if (firstE(LE) == NULL) {
    firstE(LE) = P;
  } else {
    A = firstE(LE);
    while (nextE(A) != NULL) {
      A = nextE(A);
    }
    nextE(A) = P;
  }
}
void insertLastParent(listCostumer &LC, adrCostumer Q) {
  adrCostumer B;
  if (firstC(LC) == NULL) {
    firstC(LC) = Q;
  } else {
    B = firstC(LC);
    while (nextC(B) != NULL) {
      B = nextC(B);
    }
    nextC(B) = Q;
  }
}

adreCommerce searchBarang(listeCommerce &LE, string kodeB) {
    adreCommerce A, P;
    A = firstE(LE);
    P = NULL;
    while (A != NULL) {
      if (infoE(A).kodeBarang == kodeB) {
        P = A;
      }
      A = nextE(A);
    }
    return P;
}

adrCostumer searchCostumer(listCostumer & LC, string kodeC) {
    adrCostumer B, Q;
    B = firstC(LC);
    Q = NULL;
    while (B != NULL) {
      if (infoC(B).kodeCostumer == kodeC) {
        Q = B;
      }
      B = nextC(B);
    }
    return Q;
}

void menambahkanBarang( listCostumer LC,listeCommerce LE, string kodepengguna, string kodebarang){
    adrCostumer P;
    adreCommerce Q;
    adrConnect R,C;

    P = searchCostumer(LC,kodepengguna);
    Q = searchBarang(LE,kodebarang);
    if (P!=NULL && Q != NULL){
        R = new elmConnect;
        next(R)=NULL;
        C=child(P);
        if(C==NULL){
            child(P)=R;
        }else{
            while(next(C)!=NULL){
                C = next(C);
            }
            next(C)=R;
        }
        nextE(R)=Q;
        cout << "Barang berhasil dipesan";
    }else{
        cout<< "Pengguna atau Barang tidak ditemukan";
    }
}

void showAllBarang(listeCommerce LE) {
    adreCommerce A;
    A = firstE(LE);
    while (A != NULL) {
      cout << "Nama Barang : " << infoE(A).namaBarang << endl;
      cout << "Kode Barang : " << infoE(A).kodeBarang << endl;
      cout << "Harga Barang : " << infoE(A).hargaBarang << endl;
      A = nextE(A);
    }
}
void showAllPengguna(listCostumer LC){
    adrCostumer B;
    B = firstC(LC);
    while(B!=NULL){
        cout << "Nama Pengguna : " << infoC(B).nama << endl;
        cout << "Kode Pengguna : " << infoC(B).kodeCostumer << endl;
        cout << "Alamat Pengguna :" << infoC(B).alamat << endl;
        cout << "Jumlah Barang dibeli : " << infoC(B).jumlahBarang << endl;
        B = nextC(B);
    }
}
void showAllPenggunaBarang(listCostumer LC, listeCommerce LE) {
  adrCostumer P = firstC(LC);

    while (P != NULL) {
        cout << "Nama Pengguna : " << infoC(P).nama << endl;
        cout << "Kode Pengguna : " << infoC(P).kodeCostumer << endl;

        adrConnect R = child(P);
        while (R != NULL) {
            adreCommerce Q = nextE(R);
            cout << "   Barang yang dibeli : " << infoE(Q).namaBarang << endl;
            R = next(R);
        }
        P = nextC(P);
    }

}
void deleteLastParent(listCostumer &LC, adrCostumer &P) {
    adrCostumer Prec = firstC(LC);
    if (nextC(Prec) == NULL) {
        firstC(LC) = NULL;
    } else {
        while (nextC(nextC(Prec)) != NULL) {
            Prec = nextC(Prec);
        }
        P = nextC(Prec);
        nextC(Prec) = NULL;
    }
}

void deleteChildParent(listCostumer &LC, adrCostumer P) {
    adrConnect R = child(P);
    while (R != NULL) {
        adrConnect temp = R;
        R = next(R);
        delete temp;
    }
}
void deleteFirstBarang(adrCostumer &P, adrConnect &R){
    R = child(P);
    child(P) = next(R);
    next(R) = NULL;
    nextE(R) = NULL;
}

 void deleteLastBarang(adrCostumer &P, adrConnect &R){
    R = child(P);
    adrConnect lastRelasi = child(P);
    adrConnect beforeLast = child(P);

    while(next(lastRelasi)!=NULL){
        lastRelasi = next(lastRelasi);
    }
    while(next(beforeLast)!= lastRelasi){
        beforeLast = next(beforeLast);
    }
    R = lastRelasi;
    nextE(lastRelasi) = NULL;
    next(beforeLast) = NULL;
}

void deleteAfterBarang(adrCostumer &P, adrConnect target, adrConnect &R){
    adrConnect Q = child(P);

    while(next(Q)!=target){
        Q = next(Q);
    }

    R = next(Q);
    next(Q) = next(R);
    next(R) = NULL;
    nextE(R) = NULL;
}

void deleteDesiredBarang(listCostumer &LC){
    string kodePengguna, kodeBarang;
    adrCostumer P;
    adrConnect target, R, lastRelasi;
    cout << "Masukkan Kode Pengguna : ";
    cin >> kodePengguna;
    P = searchCostumer(LC, kodePengguna);
    cout << "Masukkan Kode Barang : ";
    cin >> kodeBarang;
    target = searchBarangOnCostumer(P, kodeBarang);
    lastRelasi = child(P);
    while(next(lastRelasi)!=NULL){
        lastRelasi = next(lastRelasi);
    }

    if (child(P)==NULL){
        cout << "Pengguna belum memilih barang"<<endl;
    } else if(infoE(nextE(target)).kodeBarang == infoE(nextE(child(P))).kodeBarang){
        deleteFirstBarang(P, R);
        cout << "Kode Barang " << kodeBarang << " Berhasil dihapus."<<endl;
    } else if (infoE(nextE(target)).kodeBarang == infoE(nextE(lastRelasi)).kodeBarang){
        deleteLastBarang(P, R);
        cout << "Kode Barang " << kodeBarang << " Berhasil dihapus."<<endl;
    } else{
        deleteAfterBarang(P, target, R);
        cout << "Kode Barang " << kodeBarang << " Berhasil dihapus."<<endl;
    }

}

adrConnect searchBarangOnCostumer(adrCostumer P, string kode){
    adrConnect Q = child(P);

    while(infoE(nextE(Q)).kodeBarang!=kode){
        Q = next(Q);
    }

    return Q;
}
void cekCostumer(listCostumer LC, string kodePengguna){
    adrCostumer p = searchCostumer(LC, kodePengguna);
    if (p!=NULL){
        cout << "Costumer dengan kode " << kodePengguna << " ditemukan."<< endl;
    } else{
        cout << "Costumer dengan kode " << kodePengguna << " tidak ditemukan."<< endl;
    }
}
void cekBarang(listeCommerce LE, string kodeBarang) {
    adreCommerce P = searchBarang(LE, kodeBarang);
    if (P != NULL) {
        cout << "Barang dengan kode " << kodeBarang << " ditemukan." << endl;
    } else {
        cout << "Barang dengan kode " << kodeBarang << " tidak ditemukan." << endl;
    }
}

int menghitungBarang(listCostumer LC, string kodePengguna) {
    adrCostumer P = searchCostumer(LC, kodePengguna);
    if (P != NULL) {
        int jumlahBarang = 0;
        adrConnect C = child(P);
        while (C != NULL) {
            jumlahBarang++;
            C = next(C);
        }
        cout << "Jumlah barang yang dibeli oleh pengguna dengan kode pengguna " << kodePengguna << ": " << jumlahBarang << endl;
        return jumlahBarang;
    } else {
        cout << "Data pengguna dengan kode " << kodePengguna << " tidak ditemukan." << endl;
        return 0;
    }
}

int menghitungHarga(listCostumer LC, string kodePengguna) {
    adrCostumer P = searchCostumer(LC, kodePengguna);
    if (P != NULL) {
        int jumlahHarga = 0;
        adrConnect C = child(P);
        while (C != NULL) {
            jumlahHarga = jumlahHarga + infoE(nextE(C)).hargaBarang;
            C = next(C);
        }
        cout << "Jumlah Harga yang harus dibayar oleh pengguna dengan kode " << kodePengguna << ": " << jumlahHarga << endl;
        return jumlahHarga;
    } else {
        cout << "Data pengguna dengan kode " << kodePengguna << " tidak ditemukan." << endl;
        return 0;
    }
}

void mainmenu(listCostumer &LC, listeCommerce &LE) {
  cout << "===============MENU=================" << endl;
  cout << "1. Tambah Data Pengguna" << endl;
  cout << "2. Tambah Data barang eCommerce" << endl;
  cout << "3. Tambah barang pada pesanan Pengguna" << endl;
  cout << "4. Tampilkan Semua Data Barang eCommerce" << endl;
  cout << "5. Tampilkan Semua Data Pengguna" << endl;
  cout << "6. Tampilkan Semua Data Pengguna beserta barang yang dibeli" << endl;
  cout << "7. Hapus barang pemesanan pengguna " << endl;
  cout << "8. Hapus data pengguna " << endl;
  cout << "9. Jumlah barang yang dibeli pengguna " << endl;
  cout << "10. Jumlah harga barang yang harus dibayar pengguna " << endl;
  cout << "11. Cek data Pengguna pada list" << endl;
  cout << "12. Cek data barang pada list" << endl;
  cout << "0. Exit" << endl;
}
void menu1(listCostumer &LC, listeCommerce &LE) {
  adrCostumer Q;
  string alamat, nama, kodeCostumer;
  Costumer C;

  cout << "=============== Tambah Data Pengguna ===============" << endl;

  cout << " nama : ";
  cin >> nama;


  cout << " kodeCostumer : ";
  cin >> kodeCostumer;


  cout << " alamat : ";
  cin >> alamat;

  cout << "jumlah barang : 0" <<endl;

  C.alamat = alamat;
  C.jumlahBarang = 0;
  C.kodeCostumer = kodeCostumer;
  C.nama = nama;


  Q = allocateParent(C);
  insertLastParent(LC, Q);

  cout << "Data Berhasil Ditambahkan" << endl;
  cout << "                         " << endl;
  inputmainmenu(LC,LE);
}
void menu2(listCostumer &LC, listeCommerce &LE) {
  adreCommerce P;
  eCommerce X;
  int hargaBarang;
  string namaBarang, kodeBarang;

  cout << "=============== Tambah Data eCommerce ===============" << endl;

  cout << "Nama Barang : ";
  cin >> namaBarang;


  cout << "Kode Barang : ";
  cin >> kodeBarang;

  cout << "harga Barang : ";
  cin >> hargaBarang;

  X.hargaBarang = hargaBarang;
  X.namaBarang = namaBarang;
  X.kodeBarang = kodeBarang;

  P = allocateChild(X);
  insertLastChild(LE,P);

  cout << "Data Berhasil Ditambahkan" << endl;
  cout << "                         " << endl;
  inputmainmenu(LC,LE);
}
void menu3(listCostumer &LC, listeCommerce &LE) {
    cout << "==============Tambah Barang Pesanan=============" << endl;
    string kodePengguna,kodeBarang;
    cout << "Masukkan kode pengguna yang ingin memesan : ";
    cin >> kodePengguna;
    cout << "Masukkan kode barang yang ingin dipesan : ";
    cin >> kodeBarang;
    menambahkanBarang(LC,LE,kodePengguna,kodeBarang);
    cout <<  ""<<endl;
    inputmainmenu(LC,LE);
}
void menu4(listCostumer &LC, listeCommerce &LE) {
  cout << "==============Tampilkan Data Barang=============" << endl;
  showAllBarang(LE);
  inputmainmenu(LC,LE);
}
void menu5(listCostumer &LC, listeCommerce &LE) {
  cout << "==============Tampilkan Data Pengguna=============" << endl;
  showAllPengguna(LC);
  inputmainmenu(LC,LE);
}
void menu6(listCostumer &LC, listeCommerce &LE) {
  cout << "==============Tampilkan Data Pengguna beserta barang yang dibeli=============" << endl;
  showAllPenggunaBarang(LC, LE);
  inputmainmenu(LC,LE);
}
void menu7(listCostumer &LC, listeCommerce &LE){
    cout << "==============Hapus Barang Pesanan yang Diinginkan=============" << endl;
    deleteDesiredBarang(LC);
    inputmainmenu(LC,LE);
}
void menu8(listCostumer &LC, listeCommerce &LE) {
    cout << "==============Pencarian Data Pengguna=============" << endl;
    string kodePengguna;
    cout << "Masukkan kode pengguna : ";
    cin >> kodePengguna;
    adrCostumer P;
    P = searchCostumer(LC, kodePengguna);
    if (P != NULL) {
        deleteLastParent(LC,P);
        deleteChildParent(LC,P);
        cout << "Data pengguna dengan kode " << kodePengguna << " berhasil dihapus." << endl;
    } else {
        cout << "Data pengguna dengan kode " << kodePengguna << " tidak ditemukan." << endl;
    }
    inputmainmenu(LC,LE);
}
void menu9(listCostumer &LC, listeCommerce &LE) {
    cout << "==============Total Barang Pembelian Pengguna=============" << endl;
    string kodePengguna;
    cout << "Masukkan kode pengguna : ";
    cin >> kodePengguna;
    menghitungBarang(LC, kodePengguna);
    inputmainmenu(LC,LE);
}
void menu10(listCostumer &LC, listeCommerce &LE) {
    cout << "==============Total Biaya Pembelian Pengguna=============" << endl;
    string kodePengguna;
    cout << "Masukkan kode pengguna : ";
    cin >> kodePengguna;
    adrCostumer P;
    P = searchCostumer(LC, kodePengguna);
    if (P != NULL) {
        int totalHarga = 0;
        adrConnect C = child(P);
        while (C != NULL) {
            adreCommerce E = nextE(C);
            totalHarga += infoE(E).hargaBarang;
            C = next(C);
        }
        cout << "Jumlah harga barang yang harus dibayar oleh pengguna dengan kode pengguna " << kodePengguna << " adalah : " << totalHarga << endl;
    } else {
        cout << "Data pengguna dengan kode " << kodePengguna << " tidak ditemukan." << endl;
    }
    inputmainmenu(LC,LE);
}
void menu11(listCostumer &LC, listeCommerce &LE, string kodePengguna) {
    cout << "==============Cek Costumer=============" << endl;
    cout << "Masukkan kode pengguna yang akan di cek : ";
    cin >> kodePengguna;
    cekCostumer(LC, kodePengguna);
    inputmainmenu(LC,LE);
}
void menu12(listCostumer &LC, listeCommerce &LE, string kodeBarang) {
    cout << "==============Cek Barang=============" << endl;
    cout << "Masukkan kode barang yang akan di cek : ";
    cin >> kodeBarang;
    cekBarang(LE, kodeBarang);
    inputmainmenu(LC,LE);
}

void inputmainmenu(listCostumer &LC, listeCommerce &LE) {
  int input;
  string kodePengguna,kodeBarang;

  mainmenu(LC,LE);
  cout << "Masukkan Pilihan : ";
  cin >> input;
  cout << endl;

  if (input == 1) {
    menu1(LC, LE);

  } else if (input == 2) {
    menu2(LC, LE);

  } else if (input == 3) {
    menu3(LC, LE);

  } else if (input == 4) {
    menu4(LC,LE);

  } else if (input == 5) {
    menu5(LC,LE);

  } else if (input == 6) {
    menu6(LC,LE);

  } else if (input == 7) {
    menu7(LC,LE);

  } else if (input == 8) {
    menu8(LC,LE);

  } else if (input == 9) {
    menu9(LC,LE);

  } else if (input == 10) {
    menu10(LC,LE);

  } else if (input == 11) {
    menu11(LC,LE,kodePengguna);

  } else if (input == 12) {
    menu12(LC,LE,kodeBarang);

  } else if (input == 0) {
    cout << "Bye~";
  } else {
    cout << "Inputan Salah" << endl;
    inputmainmenu(LC, LE);
  }
}
