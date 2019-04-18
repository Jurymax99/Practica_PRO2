#ifndef LANG_HH
#define LANG_HH

#include "BinTree.hh"
#include <set>
#include <vector>
#include <iostream>
using namespace std;

typedef pair <string,int> Key;
typedef pair <string,string> Code;
typedef BinTree<Key> Tree;

class Language{
private:
    Tree treecode;
    vector <Key> tab_frec;
    vector <Code> tab_codes;
    //Comps
    static bool comp(const Key& a, const Key& b);
    static bool comp2(const Code& a, const Code& b);
    //Modif
    Key merge_node(const Tree& a, const Tree& b);
    Tree crea_tree(set<Tree, less <Tree>>& treeset);
    void crea_codes();
    void reverse_codes();
    string codificar_caracter(const Tree& a, string& code, const string& aux);
    //IO
    void escribir_treecode_pre(const Tree& tc);
    void escribir_treecode_in(const Tree& tc);
public:    
    //Cre
    Language();
    ~Language();
    //Cons
    bool is_in_lang(string c,string& n);
    //IO
    void leer();
    void escribir_frec();
    void escribir_cod();
    void escribir_treecode();
};

#endif
