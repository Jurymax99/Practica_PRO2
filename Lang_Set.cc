#include "Lang_Set.hh"

Lang_Set::Lang_Set(){
    Lset=map<string,Language>();
}

Lang_Set::~Lang_Set(){}

bool Lang_Set::is_in_set(string name) const{
    map<string,Language>::const_iterator it=Lset.begin();
    for(;it!=Lset.end();++it){
        if(it->first==name) return true;
    }return false;
}

bool Lang_Set::is_in_lang(string name, string c, string& aux){
    return Lset[name].is_in_lang(c,aux);
}

void Lang_Set::leer(){
    int size;
    cin >> size;
    for(int i=0; i<size;++i){
        string name;
        cin >> name;
        Language l;
        l.leer();
        Lset[name]=l;
    }
}
    
void Lang_Set::escribir_frec(string name){
    Lset[name].escribir_frec();
}

void Lang_Set::escribir_cod(string name){
    Lset[name].escribir_cod();
}

void Lang_Set::escribir_treecode(string name){
    Lset[name].escribir_treecode();
}
