/** @file Inventario.hh
 * @brief Especificacion de la clase Inventario
 */

#ifndef _SISTEMA_HH_
#define _SISTEMA_HH_

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <map>
using namespace std;
#endif

/** @class Inventario
 * @brief Representa el conjunto de características y
    operaciones del inventario.

    Ofrece la operación de lectura y escritura.Controla los productos 
    que hay dentro del almacen. Se puede consultar si hay algún producto, 
    se puede añadir y también se puede eliminar.
 */

class Inventario{
    
private:
/** @brief Inventario, definido como un map donde el identificador es 
     un string que seria el id del producto y un int que representa la 
     cantidad de productos con ese mismo item hat en la sala o almacen*/
    map<string,int> inv;
    
    
public:
    
    
    /*Constructoras*/
    
    /** @brief Creadora per defecte.
        \pre Cierto
        \post Crea un sistema vacío
     */
    Inventario();
    
    
    /* Destructoras */
    
    /** @brief Destructora por defecto.
        \pre Existe un sistema
        \post Destruye el sistema
     */
    ~Inventario();
    
    
    /* Consultoras */
    
    /** @brief Consultora de las unidades de un producto.
        \pre Cierto
        \post Si el producto existe devuelve sus unidades, sino devuelve -1 que indica el error
     */
    int consultar_prod_inv(string& idprod);
    
    /** @brief Para cada producto se escribe su identificador y la cantidad total que hay en el almacén de él
        \pre Cierto
        \post Se escribe cada producto con su identificador y la cantidad total que hay en el almacén de él, ordenado por idprod
     */
    void escribir_inventario();
    
    /** @brief En cada estanteria hay un numero de items de un producto
        \pre Cierto
        \post devuelve el numero total de items que hay en la estanteria
     */
    int items_en_inventario();
    
    
    /* Modificadoras */
    
    /** @brief Modificadora que añade un producto no existente dentro del sistema con cero unidades, dando error si ya existe.
        \pre Pasa por parámetro el identificador del producto
        \post Se introduce en el sistema el producto sin ninguna unidad si no existe, sino devuelve error
     */
    bool poner_prod_inv(string& idprod);
    
    /** @brief Modificadora que da de baja un producto del sistema si éste existe y no quedan unidades. Si no existe o le quedan unidades, da error.
        \pre Pasa por parámetro el identificador del producto
        \post Se da de baja el producto con el identificador proporcionado, si éste no existe o le quedan unidades, devolverá un error
     */
    bool quitar_prod_inv(string& idprod);
    
        
    /** @brief Se introducen "cant" unidades del producto al inventario
        \pre Cierto
        \post Se han colocado "cant" unidades del producto en el inventario
     */
    void poner_items_inv(string& idprod, int& cant);
    
        
    /** @brief Se eliminan "cant" unidades del producto del inventario
        \pre Cierto
        \post Se han quitado "cant" productos del inventario
     */
    void quitar_items_inv(string& idprod, int& cant);
};
#endif

   
