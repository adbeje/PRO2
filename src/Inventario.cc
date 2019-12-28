/** @file Inventario.cc
    @brief Código de la clase Inventario
*/


#include "Inventario.hh"

Inventario::Inventario() {
    map<string,int>inv;
}

Inventario::~Inventario() {}

int Inventario::consultar_prod_inv(string& idprod) {
    map<string,int>::iterator it = inv.find(idprod);
    if (it != inv.end()) 
        return it->second;
    else 
        return -1;
}

void Inventario::escribir_inventario() {
    map<string,int>::iterator it = inv.begin();
    while (it != inv.end()) {
        cout << "  " << it->first << " " << it->second << endl;
        ++it;
    }
}

int Inventario::items_en_inventario() {
    map<string,int>::iterator it = inv.begin();
    int sumitems = 0;
    while (it != inv.end()) {
        sumitems += it->second;
        ++it;
    }
    return sumitems;
}

bool Inventario::poner_prod_inv(string& idprod) {
    bool entra = false;
    map<string,int>::iterator it = inv.find(idprod);
    if (it == inv.end()) {
        inv.insert(pair<string,int>(idprod,0));
        entra = true;
    }
    return entra;
}

bool Inventario::quitar_prod_inv(string& idprod) {
    bool sale = false;
    map<string,int>::iterator it = inv.find(idprod);
    if(it != inv.end() and it->second == 0){
        inv.erase(it);
        sale = true;
    }
    return sale;
}

void Inventario::poner_items_inv(string& idprod,int& cant) {
    map<string,int>::iterator it = inv.find(idprod);
    if (it != inv.end()) {
        it->second += cant;
    }
    else 
        inv.insert(pair<string,int>(idprod,cant));
}

void Inventario::quitar_items_inv(string& idprod, int& cant) {
    map<string,int>::iterator it = inv.find(idprod);
    it->second = it->second - cant;
}
