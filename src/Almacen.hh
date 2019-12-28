/** @file Almacen.hh
    @brief Especificación de la clase Almacen
 */


#ifndef _ALMACEN_HH_
#define _ALMACEN_HH_
#ifndef NO_DIAGRAM
#include <iostream>
#include "BinTree.hh"
#endif
#include "Estanteria.hh"
#include "Inventario.hh"

/** @class Almacen
    @brief Engloba todos los elementos, representa el conjunto de salas donde en esta encontramos la Estanteria.
    
*/

class Almacen{
    
private:
    
    /** @brief A traves de este vector nos moveremos por las salas con mas eficiencia*/
    vector<Estanteria>vsal;
    /** @brief Representa la nueva clase Almacen, que la compone el indicador de la sala */
    BinTree<int> alm;
    /** @brief Representa un map, un diccionario, donde se almacenaran los identificadores totales de la almacen*/
    Inventario invalm;

    
public:
    
    
    /* Constructoras */
    /** @brief Creadora por defecto
        \pre Cierto
        \post El resultado es un sistema nuevo vacio sin almacen
     */
    Almacen();
    
    /** @brief Creada un Almacen con n salas
        \pre Cierto
        \post El resultado es el arbol con n salas
     */
    Almacen(int n);
    
    
    /* Destructura */
    /** @brief Destructora por defecto
        \pre Existe un sistema 
        \post Destruye el sistema
     */
    ~Almacen();
    
    
    /* Consultoras */
    /** @brief Consultora de la posició d'un producte a una sala
        \pre identificador de sala, i, j > 0
        \post Si hay un producto devuelve su idprod, si no NULL
     */
    void consultar_pos(int idsala, int i, int j);
    
    /** @brief Consultora de las unidades de un producto
        \pre Cierto
        \post Si el producto existe devuelve sus unidades, sino devuelve -1 para indicar error
     */
    int consultar_prod(string idprod);
    
    
    /* Modificadoras */
    /** @brief Añade un producto con cero unidades no existente dentro del almacen, dando error si ya existe
        \pre Pasa por parámetro el identificador del producto
        \post Se introduce en el sistema un producto nuevo, si existe devuelve false
     */
    bool poner_prod(string& idprod);
    
    /** @brief Da de baja un producto del sistema si existe y no quedan unidades. Si no existe/unidades, error
        \pre Pasa por parámetro el identificador del producto
        \post Se da de baja el producto con el identificador, si éste no existe o le quedan unidades, devuelve false
     */
    bool quitar_prod(string& idprod);
    
    /** @brief Se colocan tantas unidades como quepan en la sala y se devuelve un entero con las unidades sobrantes
        \pre Cierto
        \post Se colocan todas las unidades que quepan las que sobren no se guardan en almacen, devuelve los items sobrantes. Si idprod no existe devuelve -1 para indicar error.
     */
    int poner_items(int& idsala, string& idprod, int cant);
    
    /** @brief Elimina tantos items como pueda de la sala
        \pre Cierto
        \post Se han quitado tantos items como se puede, devuelve los items sobrantes. Si idprod no existe devuelve -1 para indicar error.
     */
    int quitar_items(int& idsala, string& idprod, int cant);
    
    /** @brief Se distribuye el producto segun la polıtica explicada previamente
        \pre idpro existe en el almacen 
        \post Se han distribuido las unidades, devuelve los items sobrantes. Los que han entrad no se guardan en el almacen. Si idprod no existe cant = -1 que indica error.
     */
    void distribuir(string& idprod, int& cant);
    
    /** @brief Se realiza la compactación de la estanteria de la sala con el id introducido
        \pre Cierto
        \post Los productos quedan compactados hacia la izquierda y hacia, no hay hueco entre dos productos
     */
    void compactar(int idsala);
    
    /** @brief Se realiza la reorganización de la estanteria de la sala con el id introducido
        \pre Cierto
        \post Los productos quedan reorganizados alfabéticamente sin dejar espacios antes de ellos
     */
    void reorganizar(int idsala);
    
    /** @brief Se redimensiona la estanteria de la estanteria de la sala con el id introducido
        \pre Los productos de la sala entran en las nuevas dimensiones
        \post Sala redimensionada, con las nuevas dimensiones. Si los productos no entran en el nuevo tamaño sale error
     */
    bool redimensionar(int idsala, int f, int c);
    
    /** @brief Lee un almacen con sus correspondientes salas
        \pre Hay preparados en el canal estándar de entrada n enteros que representan el almacen
        \post El parámetro implícito pasa a tener los atributos leídos del canal estándar de entrada
     */
    void leer_almacen(int& n);

    /** @brief Lee las salas del almacen, inicialmente vacias
        \pre Hay preparados en el canal estándar de entrada n par de enteros que representan el tamaño de cada sala
        \post El parámetro implícito pasa a tener los atributos leídos del canal estándar de entrada
     */
    void leer_salas(int& n);
    
    /** @brief Escribe por pantalla el parámetro implícito de la sala correspondiente
        \pre Cierto
        \post Se han escrito por canal estándar de salida los estudiantes del parámetro implícito
     */
    void escribir(int idsala);
    
    /** @brief Escribe por pantalla cada identificador con su respectiva cantidad en el almacen
        \pre Cierto
        \post Para cada producto en el sistema se escribe su identificador y la cantidad total en el almacen
     */
    void inventario();
    
    
private:
    
    /** @brief Funcion inmersiva de la funcion distribuir
        \pre Cierto
        \post Se han distribuido las unidades. Las que no, no se guardan en el almacen
     */
    int i_distribuir(BinTree<int> a, int cant, string idprod);
    
    /** @brief Funcion inmersiva que lee un almacen con sus correspondientes salas
        \pre Hay preparados en el canal estándar de entrada n enteros que representan el almacen
        \post El almacen pasa a tener los atributos leídos del canal estándar de entrada
     */
    static void i_leer_almacen(BinTree<int>& a, int& n);
};

#endif
    


    
