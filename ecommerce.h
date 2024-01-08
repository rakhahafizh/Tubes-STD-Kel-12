#ifndef ECOMMERCE_H_INCLUDED
#define ECOMMERCE_H_INCLUDED
using namespace std;

#include <iostream>
#define firstC(LC) (LC).firstC
#define firstE(LE) (LE).firstE
#define infoC(P) (P)->infoC
#define infoE(P) (P)->infoE
#define nextC(P) (P)->nextC
#define nextE(P) (P)->nextE
#define next(P) (P)->next
#define child(P) ((P)->child)

#define NIL NULL

/*
Alexader Descayodi Pasca Romadhona Sartono
Rakha Hafizh Hutomo Putra
*/

typedef struct elmeCommerce *adreCommerce;
typedef struct elmCostumer *adrCostumer;
typedef struct elmConnect *adrConnect;
typedef struct eCommerce infotypeeCommerce;
typedef struct Costumer infotypeCostumer;

struct eCommerce {
  int hargaBarang;
  string namaBarang, kodeBarang;
};

struct Costumer {
  string nama, kodeCostumer,alamat;
  int jumlahBarang;
};

struct elmeCommerce {
  infotypeeCommerce infoE;
  adreCommerce nextE;
};

struct elmCostumer {
  infotypeCostumer infoC;
  adrCostumer nextC;
  adrConnect child;
};

struct listeCommerce {
  adreCommerce firstE;
};

struct elmConnect {
  adrConnect next;
  adreCommerce nextE;
};

struct listCostumer {
  adrCostumer firstC;
};

#include "ecommerce.h"

void createListParent(listeCommerce &LE);
void createListChild(listCostumer &LC);
adreCommerce allocateChild(infotypeeCommerce A);
adrCostumer allocateParent(infotypeCostumer B);
void insertLastChild(listeCommerce &LE, adreCommerce P);
void insertLastParent(listCostumer &LC, adrCostumer Q);
adreCommerce searchBarang(listeCommerce &LE, string kodeB);
adrCostumer searchCostumer(listCostumer & LC, string kodeC);
void menambahkanBarang( listCostumer LC,listeCommerce LE);
void showAllBarang(listeCommerce LE);
void showAllPengguna(listCostumer LC);
void showAllPenggunaBarang(listCostumer LC, listeCommerce LE);
void deleteLastParent(listCostumer &LC, adrCostumer &P);
void deleteChildParent(listCostumer &LC, adrCostumer P);
void deleteFirstBarang(adrCostumer &P, adrConnect &R);
void deleteLastBarang(adrCostumer &P, adrConnect &R);
void deleteAfterBarang(adrCostumer &P, adrConnect target, adrConnect &R);
void deleteDesiredBarang(listCostumer &LC);
adrConnect searchBarangOnCostumer(adrCostumer P, string kode);
void cekCostumer(listCostumer LC, string kodePengguna);
void cekBarang(listeCommerce LE, string kodeBarang);
int menghitungBarang(listCostumer LC, string kodePengguna);
int menghitungHarga(listCostumer LC, string kodePengguna);
void mainmenu(listCostumer &LC, listeCommerce &LE);
void menu1(listCostumer &LC, listeCommerce &LE);
void menu2(listCostumer &LC, listeCommerce &LE);
void menu3(listCostumer &LC, listeCommerce &LE);
void menu4(listCostumer &LC, listeCommerce &LE);
void menu5(listCostumer &LC, listeCommerce &LE);
void menu6(listCostumer &LC, listeCommerce &LE);
void menu8(listCostumer &LC, listeCommerce &LE);
void menu10(listCostumer &LC, listeCommerce &LE);
void menu11(listCostumer &LC, listeCommerce &LE, string kodePengguna);
void menu12(listCostumer &LC, listeCommerce &LE,string kodeBarang);
void inputmainmenu(listCostumer &LC, listeCommerce &LE);


#endif // ECOMMERCE_H_INCLUDED
