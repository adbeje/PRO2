/** @file Estanteria.hh
    @brief Especificación de la clase Estanteria
 */


#ifndef _ESTANTERIA_HH_
#define _ESTANTERIA_HH_
#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <vector>
#endif
#include "Inventario.hh"

/** @class Estanteria
    @brief Representa la información y las operaciones asociadas a
    una estanteria.

    Sus operaciones son las modificadoras que ponen o quitan productos, 
    tanto de la estanteria como de el inventario de esta. Las consultoras
    devuelven productos dada su posicion en la estanteria, numero de items 
    que contiene la estanteria, escribe la estanteria etc...
    
    Dado que vamos a necesitar leer almacenes, definimos el
    concepto de estanteria vacía para disponer de un formato de entrada
    parecido al de las anteriores sesiones de laboratorio, en las que
    se emplea una "marca" para indicar la lectura de un árbol vacío.
    
*/

class Estanteria{
    
private:
    /** @brief Indican las filas i las columnas que tiene la estanteria*/
    int filas, columnas;
    
    /** @brief Es la estructura de strings (productos) que representa la 
     *estanteria de la sala*/
    vector<string> est;
    
    /** @brief Inventario de la estanteria, donde se almacenaran los 
     *identificadores totales de la estanteria con su respectiva cantidad
     * de estos en la estanteria*/
    Inventario invest;
    
public:
    
    
     /*Constructoras*/

     /** @brief Constructora que crear matriz Estanteria vacia
        \pre Cierto
        \post Crea una estanteria de crear matriz Estanteria vacia
     */
    Estanteria();
    
    /** @brief Constructora que crear matriz Estanteria (f x c)
        \pre Cierto
        \post Crea una estanteria de crear matriz Estanteria (f x c) con productos nulos
     */
    Estanteria(int f, int c);
    
    
    /* Destructoras */
    /** @brief Destructora por defecte
        \pre Existe una estanteria
        \post Destruye la estantería
     */
    ~Estanteria();
    
    
    /* Modificadoras */
    /** @brief Coloca un producto dentro del primer lugar vacío que encuentre de la estantería no llena
        \pre Se pasa por referencia una estantería y al canal estandar de entrada hay preparado un producto
        \post Se devuelven los items que no han entrado en la estanteria
     */
    int anadir_items_est(string& idprod, int cant);
    
    /** @brief Eliminamos x productos con la misma idprod del parámetro implícito
        \pre El parametro implicito esta en la estantería, sino devuelve -1 para comprobar el error
        \post Se devuelven los items que no se han eliminado de la estanteria
     */
    int eliminar_items_est(string& idprod, int cant);
        
    /** @brief Se introducen "cant" unidades del producto al inventario de la estanteria
        \pre Cierto
        \post Se han colocado "cant" unidades del producto en el inventario de la estanteria
     */
    void poner_items_invest(string& idprod, int& cant);
        
    /** @brief Se eliminan "cant" unidades del producto del inventario de la estanteria
        \pre Cierto
        \post Se han quitado "cant" productos del inventario de la estanteria
     */
    void quitar_items_invest(string& idprod, int& cant);
    
    /** @brief Se realiza la compactación del parámetro implícito
        \pre Cierto
        \post Los productos quedan compactados hacia la izquierda y hacia abajo, no hay hueco entre dos productos
     */
    void compactar_estanteria();
    
    /** @brief Se realiza la reorganización del parámetro implícito
        \pre Cierto
        \post Los productos quedan reorganizados alfabéticamente hacia la izquierda y hacia abajo sin dejar espacios antes de ellos
     */
    void reorganizar_estanteria();
    
    /** @brief Devuelve la estantería redimensionada de tamaño (f x c)
        \pre Los productos del parámetro implícito < = nuevo tamaño
        \post Devuelve true si la estanteria ha quedado redimensionada de tamaño (f x c), si no entran en el nuevo tamaño devuelve false
     */
    bool estanteria_redimensionada(int f, int c);

    
    /* Consultoras */
    /** @brief Devuelve el número de filas del parámetro implícito
        \pre Cierto
        \post Devuelve i
     */
    int consultar_f();
    
    /** @brief Devuelve el número de columnas del parámetro implícito
        \pre Cierto
        \post Devuelve j
     */
    int consultar_c();
    
    /** @brief Indica qué producto hay en la posicion (i, j) del parámetro implícito
        \pre Pasa por parámetros la posicion del producto
        \post Si hay un producto devuelve su idprod, si no hay devuelve NULL
     */
    string consultar_pos_estanteria(int i, int j);
    
    /** @brief Escribe por pantalla el parámetro implícito
        \pre Cierto
        \post Se han escrito por canal estándar de salida los estudiantes del parámetro implícito
     */
    void escribir_estanteria();
    
    /** @brief En cada estanteria hay un numero de items de un producto
     * \pre Cierto
     * \post devuelve el numero total de items que hay en la estanteria
     */
    int items_en_estanteria();
    
};

#endif
    
