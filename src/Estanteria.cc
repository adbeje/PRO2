/** @file Estanteria.cc
    @brief Código de la clase Estanteria
*/

#include "Estanteria.hh"
#include <algorithm>

Estanteria::Estanteria() {}

Estanteria::Estanteria(int f, int c){
    filas = f;
    columnas = c;
    est = vector<string>(f*c, "");
    invest = Inventario();
}

Estanteria::~Estanteria(){}

void Estanteria::poner_items_invest(string& idprod, int& cant){
    if (cant != 0) 
        invest.poner_items_inv(idprod,cant);
}

void Estanteria::quitar_items_invest(string& idprod, int& cant){
    int items;
    items = invest.consultar_prod_inv(idprod);
    if (items < 0)
        cant = items;
    else {
        invest.quitar_items_inv(idprod,cant);
        items = invest.consultar_prod_inv(idprod);
        if (items == 0)
            invest.quitar_prod_inv(idprod);
    }
}

int Estanteria::anadir_items_est(string& idprod, int cant){
    int i = 0, rest = cant;
    while (i < filas*columnas and rest > 0) {
        if (est[i] == "") {
            est[i] = idprod;
            --rest;
        }
        ++i;
    }
    cant = cant - rest;
    poner_items_invest(idprod,cant);
    
    return rest;
}

int Estanteria::eliminar_items_est(string& idprod, int cant){
    int b = invest.consultar_prod_inv(idprod);
    int i = 0, rest = cant;
    if (b >= 0) {
        while (i < filas*columnas and rest > 0) {
            if(est[i] == idprod) {
                est[i] = "";
                --rest;
            }
            ++i;
        }
        
    }
    else 
        return b;
    
    cant = cant - rest;
    quitar_items_invest(idprod,cant);
    return rest;
}


void Estanteria::compactar_estanteria(){
    if (invest.items_en_inventario() > 0) {
        int poscanvi;
        bool canvi = false;
        for (int i = 0; i < filas*columnas; ++i) {
            if(est[i] == "" and not canvi){
                canvi = true;
                poscanvi = i;
            }
            else if(est[i] != "" and canvi){
                swap(est[i],est[poscanvi]);
                canvi = false;
                i = poscanvi;
            }
        }
    }
}

bool cmp(string a, string b) {
    if (a != "" and b == "") 
        return true;
    else if (a == "" and b != "") 
        return false;
    else if (a < b) 
        return true;
    return false;
}

void Estanteria::reorganizar_estanteria(){
    if (invest.items_en_inventario() > 0) 
        sort(est.begin(),est.end(),cmp);
}

bool Estanteria::estanteria_redimensionada(int f, int c){
    int items = invest.items_en_inventario();
    if (items <= f*c) {
        compactar_estanteria();
        est.resize(f*c,"");
        filas = f;
        columnas = c;
    }
    else 
        return false;
    
    return true;

}

int Estanteria::consultar_f(){
    return filas;
}

int Estanteria::consultar_c(){
    return columnas;
}

string Estanteria::consultar_pos_estanteria(int i, int j){
    int pos = (filas*columnas) - 1 - (columnas*(i-1) + (j-1));
    return est[pos];
}

void Estanteria::escribir_estanteria(){
    int x = filas*columnas - columnas, j = 0, i = 0;
    while (x >= 0 and i <= filas) {
        if (j == 0) {
            if (est[x] == "") cout << "  " << "NULL";
            else cout << "  " << est[x];
        }
        else{
            if (est[x] == "") cout << " " << "NULL";
            else cout << " " << est[x];
            
        }
        ++x;
        ++j;
        if (j == columnas) {
            x = x -(2*columnas);
            j = 0;
            ++i;
            cout << endl;
        }
    }
    
    cout << "  " << invest.items_en_inventario() << endl;
    invest.escribir_inventario();
}

int Estanteria::items_en_estanteria() {
    return invest.items_en_inventario();
}
