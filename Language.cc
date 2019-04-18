#include "Language.hh"
#include <algorithm>

Language::Language(){
    treecode=Tree();
    tab_frec=vector <Key>();
    tab_codes=vector <Code>();
}

Language::~Language(){}

bool Language::comp(const Key& a, const Key& b){
    return a.first < b.first;
}

bool Language::comp2(const Code& a, const Code& b){
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

void Language::reverse_codes(){
    for (int i=0; i<tab_codes.size(); ++i){
        reverse(tab_codes[i].second.begin(),tab_codes[i].second.end());
    }
}

void Language::crea_codes(){
    for(int i=0;i<tab_codes.size();++i){
        string aux,code;
        aux=tab_codes[i].first;
        code=codificar_caracter(treecode,code,aux);
        tab_codes[i].second=code;        
    }
    reverse_codes();
}

string Language::codificar_caracter(const Tree& a, string& code, const string& aux){
    if(not a.empty()){
        if(a.value().first==aux){
            return code;
        }
        string left=codificar_caracter(a.left(),code,aux);
        if(left!="-1") return code +="0";
        string right=codificar_caracter(a.right(),code,aux);
        if(right!="-1") return code +="1";            
    }
    return "-1";
}

bool Language::is_in_lang(string c,string& n){
    for(int i=0;i<tab_codes.size();++i){
        if(tab_codes[i].first==c){
            n=tab_codes[i].second;
            return true;
        }
    }return false;
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
        Code aux1;
        aux1.first=s;
        tab_frec.push_back(aux);
        tab_codes.push_back(aux1);
        nodes.insert(Tree(aux));
    }
    treecode=crea_tree(nodes);
    crea_codes();
}

void Language::escribir_frec(){
    sort(tab_frec.begin(),tab_frec.end(),comp);
    for(int i=0;i<tab_frec.size();++i){
        cout << tab_frec[i].first << " " << tab_frec[i].second << endl;
    }
}

void Language::escribir_cod(){
    sort(tab_codes.begin(),tab_codes.end(),comp2);
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
