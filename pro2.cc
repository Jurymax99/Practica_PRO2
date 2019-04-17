#include <iostream>
#include "BinTree.hh"
#include <set>
#include <string>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair <string,int> Key;
typedef pair <string,string> Code;
typedef BinTree<Key> Tree;

class Language{
private:
    Tree treecode;
    vector <Key> tab_frec;
    vector <Code> tab_codes;
    static bool comp(const Key& a, const Key& b);
    Key merge_node(const Tree& a, const Tree& b);
    Tree crea_tree(set<Tree, less <Tree>>& treeset);
    void crea_codes();
    string codificar_caracter(const Tree& a, string& code, const string& aux);
    void escribir_treecode_pre(const Tree& tc);
    void escribir_treecode_in(const Tree& tc);
    void tomeu_coding(const Tree& a,string& code);
public:    
    Language();
    ~Language();    
    //IO
    void leer();
    void escribir_frec();
    void escribir_cod();
    void escribir_treecode();
    //void escribir_cod(const vector <Key>& aux);
};

Language::Language(){
    treecode=Tree();
    tab_frec=vector <Key>();
    tab_codes=vector <Code>();
}

Language::~Language(){}


bool Language::comp(const Key& a, const Key& b){
    return a.first < b.first;
}

bool operator<(const Tree& a, const Tree& b){
    if(a.value().second!=b.value().second){
        return a.value().second < b.value().second;
    }
    else return a.value().first < b.value().first;
}

Key Language::merge_node(const Tree& a, const Tree& b){
    Key aux;
    aux.second=a.value().second + b.value().second;
    if(a.value().first<b.value().first){
        aux.first=a.value().first + b.value().first;
    }
    else aux.first=b.value().first + a.value().first;
    return aux;
}

Tree Language::crea_tree(set<Tree, less<Tree>>& treeset){
    if(treeset.size()==1) return *treeset.begin();
    else{
        set<Tree, less<Tree>>::const_iterator it=treeset.begin();
        Tree left =*it;
        it=treeset.erase(it);
        Tree right=*it;
        it=treeset.erase(it);
        treeset.insert(Tree(merge_node(left,right),left,right));
        return crea_tree(treeset);
    }
}

void Language::crea_codes(){
    for(int i=0;i<tab_codes.size();++i){
        string aux,code;
        aux=tab_codes[i].first;
        code=codificar_caracter(treecode,code,aux);
        tab_codes[i].second=code;        
    }
}

string Language::codificar_caracter(const Tree& a, string& code, const string& aux){
    if(a.empty() and code!= aux) return "A";        
    else return "B";
}
    
void Language::tomeu_coding(const Tree& a,string& code){
    if(a.empty()){
        tab_codes.push_back(make_pair(a.value().first,code));
    }
    else 
}
    
void Language::leer(){
    int size;
    cin >> size;
    set<Tree, less<Tree>> nodes;
    for(int i=0;i<size;++i){
        string s;
        int n;
        cin >> s >> n;
        Key aux=make_pair(s,n);
        tab_frec.push_back(aux);
        nodes.insert(Tree(aux));
        
    }
    treecode=crea_tree(nodes);
    string code;
    tomeu_coding(treecode,code);
}

void Language::escribir_frec(){
    cout << "------------FREC------------" << endl;
    sort(tab_frec.begin(),tab_frec.end(),comp);
    for(int i=0;i<tab_frec.size();++i){
        cout << tab_frec[i].first << " " << tab_frec[i].second << endl;
    }
}

void Language::escribir_cod(){
    cout << "-----------CODES------------" << endl;
    for(int i=0;i<tab_codes.size();++i){
        cout << tab_codes[i].first << " " << tab_codes[i].second << endl;
    }
}

void Language::escribir_treecode(){
    cout << "recorrido en preorden:" << endl;
    escribir_treecode_pre(treecode);
    cout << "recorrido en inorden:" << endl;
    escribir_treecode_in(treecode);  
}
    
void Language::escribir_treecode_pre(const Tree& tc){
    if (not tc.empty()){
        cout << tc.value().first << " " << tc.value().second << endl;
        escribir_treecode_pre(tc.left());
        escribir_treecode_pre(tc.right());
    }
}

void Language::escribir_treecode_in(const Tree& tc){
    if (not tc.empty()){
        escribir_treecode_in(tc.left());
        cout << tc.value().first << " " << tc.value().second << endl;
        escribir_treecode_in(tc.right());
    }
}

int main(){
    Language i;
    i.leer();
    i.escribir_cod();
    i.escribir_frec();
    i.escribir_treecode();
    
}


/*
int main(){
    Cjt_Language tot;
    tot.leer();
    string op;
    while(cin >> op and op!= "fin"){
        if(op==""){
            //añadir/modificar language
        }
        else if(op==""){
            //codificar
        }
        else if(op==""){
            //decodificar
        }
        else if(op=="tabla_frec"){
            //consultar freqtb
        }
        else if(op=="treecode"){
            //consultar treecode
        }
        else if(op=="codigos"){
            //consultar codigos
        }
    }
}
*/
