/** @file Almacen.cc
    @brief Código de la clase Almacen
*/


#include "Almacen.hh"

Almacen::Almacen() {}

Almacen::Almacen(int n) {
    leer_almacen(n);
    vsal = vector<Estanteria>(n);
    leer_salas(n);
    invalm = Inventario();
}

Almacen::~Almacen() {}

void Almacen::consultar_pos(int idsala, int i, int j) {
    string idprod;
    idprod = vsal[idsala-1].consultar_pos_estanteria(i, j);
    if (idprod == "")
        cout << "  "<< "NULL" << endl;
    else 
        cout << "  "<< idprod << endl;
}

int Almacen::consultar_prod(string idprod) {
    return invalm.consultar_prod_inv(idprod);
    
}

bool Almacen::poner_prod(string& idprod) {
    return invalm.poner_prod_inv(idprod);
    
}

bool Almacen::quitar_prod(string& idprod) {
    return invalm.quitar_prod_inv(idprod);
}

int Almacen::poner_items(int& idsala, string& idprod, int cant) {
    int entr = invalm.consultar_prod_inv(idprod);
    if (entr >= 0) {
        entr = vsal[idsala-1].anadir_items_est(idprod,cant);
        cant = cant - entr;
        invalm.poner_items_inv(idprod,cant);
    }
    else
        return -1;
    
    return entr;
}

int Almacen::quitar_items(int& idsala, string& idprod, int cant) {
    int esta = invalm.consultar_prod_inv(idprod);
    int sale;
    if (esta >= 0) {
         sale = vsal[idsala-1].eliminar_items_est(idprod, cant);
         if (sale >= 0){
            cant = cant - sale;
            invalm.quitar_items_inv(idprod,cant);
        }
        else 
            sale = cant;

    }
    else 
        return -1;
    return sale;
}

int Almacen::i_distribuir(BinTree<int> a, int cant, string idprod) {
    if (a.empty() or cant == 0) {
        return cant;
    }
    else {
        int node = a.value(), csl, csr;
        BinTree<int> l = a.left();
        BinTree<int> r = a.right();
        cant = poner_items(node, idprod, cant);
        csl = i_distribuir(l, (cant+1)/2, idprod);
        csr = i_distribuir(r, cant/2, idprod);
        return csl + csr;
    }
}
 
void Almacen::distribuir(string& idprod, int& cant) {
    int b = invalm.consultar_prod_inv(idprod);
    if (b < 0 )
        cant = -1;
    else 
        cant = i_distribuir(alm, cant, idprod);
}

void Almacen::compactar(int idsala) {
    vsal[idsala-1].compactar_estanteria();
}

void Almacen::reorganizar(int idsala) {
    vsal[idsala-1].reorganizar_estanteria();
}

bool Almacen::redimensionar(int idsala, int f, int c) {
    return vsal[idsala-1].estanteria_redimensionada(f, c);
}

void Almacen::leer_salas(int& n) {
    int f, c;
    for (int i = 0; i < n; ++i) {
        cin >> f >> c;
        Estanteria est(f, c);
        vsal[i] = est;
        
    }
}

void Almacen::i_leer_almacen(BinTree<int>& a,int& n) {
    int x;
    cin >> x;
    if (x != 0 and x <= n){
        BinTree<int> l;
        i_leer_almacen(l,n);
        BinTree<int> r;
        i_leer_almacen(r,n);
        a=BinTree<int>(x,l,r);
    } 
}

void Almacen::leer_almacen(int& n) {
    i_leer_almacen(alm,n);
}

void Almacen::escribir(int idsala) {
    vsal[idsala-1].escribir_estanteria();
}

void Almacen::inventario() {
    invalm.escribir_inventario();
}
