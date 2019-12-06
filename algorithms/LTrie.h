#ifndef LTRIE_H
#define LTRIE_H

#include <string>
#include <unordered_map>

class LTrie {
  public:
    // Constructor de la clase
    LTrie();
    // Agregar instancia de la palabra
    void insert( const std::string& );
    // Regresa cuantas instancias de la palabra existen
    unsigned int search( const std::string& );
    // Elimina solo una instancia de la palabra
    LTrie* delete_soft( const std::string&, unsigned int depth = 0 );
    // Elimina todas las instancias de la palabra
    LTrie* delete_hard( const std::string& );

  private:
    std::unordered_map< char, LTrie* > dic;
    unsigned int                       cnt;
};
#endif
