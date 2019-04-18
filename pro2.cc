#include "Lang_Set.hh"

int main(){
    Lang_Set tot;
    tot.leer();
    string op;
    while(cin >> op and op!= "fin"){
        if(op=="1"){
            //añadir/modificar language
        }
        else if(op=="2"){
            //codificar
        }
        else if(op=="3"){
            //decodificar
        }
        else if(op=="tabla_frec"){
            //consultar freqtb
            string aux;
            cin >> aux;
            cout << "Tabla de frecuencias de " << aux << ":" << endl;
            if(tot.is_in_set(aux)){
                tot.escribir_frec(aux);
            }
            else cout << "El idioma no existe" << endl;
        }
        else if(op=="treecode"){
            //consultar treecode
            string aux;
            cin >> aux;
            cout << "Treecode de " << aux << ":" << endl;
            if(tot.is_in_set(aux)){
                tot.escribir_treecode(aux);
            }
            else cout << "El idioma no existe" << endl;
        }
        else if(op=="codigos"){
            //consultar codigos
            string aux,c;
            cin >> aux >> c;
            if(c=="todos"){
                cout << "Codigos de " << aux << ":" << endl;
                if(tot.is_in_set(aux)){                    
                    tot.escribir_cod(aux);
                }
                else cout << "El idioma no existe" << endl; 
            }
            else{
                cout << "Codigo de " << c << " en " << aux << ":" << endl;
                string n;
                if(tot.is_in_lang(aux,c,n)){
                    cout << c << " " << n << endl;
                }
                else cout << "El idioma no existe o el caracter no esta en el idioma" << endl;
            }
        }cout << endl;
    }
}

