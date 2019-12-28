/**
 * @mainpage Laboratorio PRO2. Caso de estudio: Aplicacion para una cadena de tiendas de muebles, TreeKea. Documentación. 

Práctica TreeKea resuelta, con documentación completa (incluyendo elementos privados y código).

El programa principal se encuentra en el módulo program.cc. Atendiendo a los tipos de datos sugeridos en el enunciado, necesitaremos un módulo para representar el <em>Almacen</em> en el que se controlan todos los componentes de este, otra para el tipo <em>Estanteria</em> y otro para el tipo <em>Inventario<em/>.
*/

/** @file main.cc
    @brief Programa principal para la aplicacion TreeKEA.
*/
#ifndef NO_DIAGRAM
#include <iostream>
#endif
#include "Almacen.hh"


using namespace std;

/** @brief Programa principal para la cadena de tiendas de muebles.
*/

int main() {
    int nsalas;
    cin >> nsalas;
    Almacen a(nsalas);
    string com;
    cin >> com;
    while(com != "fin"){
        if(com == "poner_prod"){
            bool b;
            string idprod;
            cin >> idprod;
            b = a.poner_prod(idprod);
            cout << com << " " << idprod << endl;
            if (not b) 
                cout << "  " << "error" << endl;
        }
        else if(com == "quitar_prod"){
            bool b;
            string idprod;
            cin >> idprod;
            b = a.quitar_prod(idprod);
            cout << com << " " << idprod << endl;
            if (not b)
                cout << "  " << "error" << endl;
            
        }
        else if(com == "poner_items"){
            int idsala, cant;
            string idprod;
            cin >> idsala >> idprod >> cant;
            cout << com << " " << idsala << " " << idprod << " " << cant << endl;
            int entr = a.poner_items(idsala, idprod, cant);
            if (entr < 0) 
                cout << "  " << "error" << endl;
            else 
                cout << "  " << entr << endl;
        }
        else if(com == "quitar_items"){
            int idsala, cant;
            string idprod;
            cin >> idsala >> idprod >> cant;
            cout << com << " " << idsala << " " << idprod << " " << cant << endl;
            int sale = a.quitar_items(idsala, idprod, cant);
            if (sale < 0) 
                cout << "  " << "error" << endl;
            else 
                cout << "  " << sale << endl;
                
        }
        else if(com == "distribuir"){
            int cant;
            string idprod;
            cin >> idprod >> cant;
            cout << com << " " << idprod << " " << cant << endl;
            a.distribuir(idprod, cant);
            if (cant < 0)
                cout << "  " << "error" << endl;
            else 
                cout << "  " << cant << endl;
            
        }
        else if(com == "compactar"){
            int idsala;
            cin >> idsala;
            a.compactar(idsala);
            cout << com << " " << idsala << endl;
        }
        else if(com == "reorganizar"){
            int idsala;
            cin >> idsala;
            a.reorganizar(idsala);
            cout << com << " " << idsala << endl;
        }
        else if(com == "redimensionar"){
            int idsala, f, c;
            bool b;
            cin >> idsala >> f >> c;
            b = a.redimensionar(idsala, f, c);
            cout << com << " " << idsala << " " << f << " " << c << endl;
            if (not b) cout << "  " << "error" << endl;
            
        }
        else if(com == "escribir"){
            int idsala;
            cin >> idsala;
            cout << com << " " << idsala << endl;
            a.escribir(idsala);
        }
        else if(com == "consultar_pos"){
            int idsala, f, c;
            cin >> idsala >> f >> c;
            cout << com << " " << idsala << " " << f << " " << c << endl;
            a.consultar_pos(idsala, f, c);
        }
        else if(com == "consultar_prod"){
            string idprod;
            int b;
            cin >> idprod;
            b = a.consultar_prod(idprod);
            cout << com << " " << idprod <<endl;
            if (b < 0) 
                cout << "  " << "error" << endl;
            else 
                cout << "  " << b << endl;
                
            
        }
        else if(com == "inventario"){
            cout << com << endl;
            a.inventario();
            
        }
        cin >> com;
    }
    cout << "fin" << endl;
}
    
