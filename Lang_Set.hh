#include "Language.hh"
#include <map>

class Lang_Set{
private:
    map<string,Language> Lset;
public:
    //Cre
    Lang_Set();
    ~Lang_Set();
    //Cons
    bool is_in_set(string name) const; 
    bool is_in_lang(string name, string c, string& aux);
    //IO
    void leer();
    void escribir_frec(string name);
    void escribir_cod(string name);
    void escribir_treecode(string name);
};
