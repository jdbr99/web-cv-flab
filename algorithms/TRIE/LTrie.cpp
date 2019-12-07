#include "LTrie.h"

#include <string>
#include <unordered_map>

LTrie::LTrie() {
    cnt = 0;
    dic.clear();
}

void LTrie::insert( const std::string& word ) {
    // Navegador del diccionario
    LTrie* tmp = this;
    for ( int i = 0; i < word.length(); i++ ) {
        char x = word[i];
        if ( tmp->dic.count( x ) == 0 )
            tmp->dic[x] = new LTrie();
        // Siguiente caracter
        tmp = tmp->dic[x];
    }
    // Agregar palabra
    tmp->cnt++;
}

unsigned int LTrie::search( const std::string& word ) {
    // Navegador del diccionario
    LTrie* tmp = this;
    for ( int i = 0; i < word.length(); i++ ) {
        char x = word[i];
        // La palabra no esta en el diccionario
        if ( tmp->dic.count( x ) == 0 )
            return 0;
        tmp = tmp->dic[x];
    }
    // La palabra existe
    return tmp->cnt;
}

LTrie* LTrie::delete_soft( const std::string& word, unsigned int depth ) {
    // Navegador del diccionario
    LTrie* tmp = this;
    // La palabra existe
    if ( depth == word.length() && tmp->cnt > 0 ) {
        tmp->cnt--;
        // Si ya no existe la palabra o palabras con el prefijo
        if ( tmp->cnt == 0 && tmp->dic.empty() == true ) {
            delete tmp;
            tmp = NULL;
        }
        return tmp;
    }
    // Si la siguiente letra de word existe en el diccionario
    if ( tmp->dic.count( word[depth] ) != 0 )
        tmp->dic[word[depth]] = tmp->dic[word[depth]]->delete_soft( word, depth + 1 );
    // Si tmp no es final de una palabra o tiene hijos
    if ( tmp->dic.empty() == true && tmp->cnt == 0 ) {
        delete tmp;
        tmp = NULL;
    }
    return tmp;
}
