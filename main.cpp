#include <iostream>
#include "ecommerce.h"

int main(){
    listCostumer LC;
    listeCommerce LE;
    createListChild(LC);
    createListParent(LE);

    inputmainmenu(LC,LE);
}
