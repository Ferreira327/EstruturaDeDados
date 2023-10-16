#include <iostream>

using namespace std;

class noh{

    friend class Fila;

private:
    int mValor;
    noh* proximo;

public:
    noh(int valor);

};

noh::noh(int valor){
    mValor = valor;
    proximo = NULL;
}

class Fila{
private:
    noh* primeiro;
    noh* ultimo;
public:
    Fila();
    ~Fila();
    int desenfileirar();
    void enfileirar(int valor);
    bool vazio();
    void desenfileirar_tudo();
};

Fila::Fila(){
    primeiro = NULL;
    ultimo = NULL;
}

Fila::~Fila(){
    while(!vazio()){
        desenfileirar();
    }
}

bool Fila::vazio(){
    if(primeiro == NULL || ultimo == NULL){
        return 1;
    }
    else
        return 0;
}

int Fila::desenfileirar(){
    if(!vazio()){
    int guardar = primeiro->mValor;
    noh* temp = primeiro;
    primeiro = primeiro->proximo;
    delete temp;
    return guardar;}
    else
        cout << "\nFila Vazia\n";
}

void Fila::enfileirar(int valor){
    noh* novo = new noh(valor);
    if(vazio()){
        primeiro = novo;
    }
    else{
        ultimo->proximo = novo;
    }
    ultimo = novo;
}

void Fila :: desenfileirar_tudo(){
    while(!vazio())
        cout << desenfileirar() << endl;
}

void ordenar(Fila& Indiana){
    int aux_m;
    int aux;
    Fila Aux;
    Fila Aux2;

    while(!Indiana.vazio()){
    aux_m = Indiana.desenfileirar();
    while(!Indiana.vazio()){
        aux = Indiana.desenfileirar();
        if(aux<aux_m){
            Aux.enfileirar(aux_m);
            aux_m = aux;
        }
        else
            Aux.enfileirar(aux);
    }

    Aux2.enfileirar(aux_m);

    while(!Aux.vazio()){
        Indiana.enfileirar(Aux.desenfileirar());
    }
    }

    while(!Aux2.vazio())
        Indiana.enfileirar(Aux2.desenfileirar());
}


int main(){

    Fila indiana;
    int valor;
    char escolha = '4';

    while(escolha != '0'){
        system("pause");
        system("cls");
        cout << "[1]Enfilheirar\n[2]Desenfileirar\n[3]Desenfileirar Tudo\n";
        cin >> escolha;
        if(escolha == '1'){
            cin >> valor;
            indiana.enfileirar(valor);}
        else if(escolha == '2')
            cout << indiana.desenfileirar();
        else if(escolha == '3')
            indiana.desenfileirar_tudo();
        else if(escolha == '4')
            ordenar(indiana);
    }     


    return 0;
}