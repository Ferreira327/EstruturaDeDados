#include <iostream>

using namespace std;

class noh{
    friend class Pilha;

private:
    int mValor;
    noh* mProximo;
public:
    noh(int valor);
};

noh::noh(int valor){
    mValor = valor;
    mProximo = NULL;
}

class Pilha{
private:
    noh* mTopo;
public:
    void empilhar(int valor);
    int desempilhar();
    bool vazio();
    void desempilhar_Tudo();
    void verTopo();
    Pilha();
    ~Pilha();
};

Pilha::Pilha(){
    mTopo = NULL;
}

Pilha::~Pilha(){
    delete[] mTopo;
}

void Pilha::empilhar(int valor){
    noh* novo = new noh(valor);
    novo->mProximo = mTopo;
    mTopo = novo;
}

int Pilha::desempilhar(){
    if(!vazio()){
    int guardar = mTopo->mValor;
    noh* temp = mTopo;
    mTopo = mTopo->mProximo;
    delete temp;
    return guardar;
    }
    else
        cout << "Pilha Vazia!\n";
}

bool Pilha::vazio(){
    if(mTopo == NULL)
        return 1;
    else
        return 0;
}

void Pilha::verTopo(){
    if(vazio())
        cout << "Pilha vazia!\n";
    else
        cout << mTopo->mValor << " ";
}

void Pilha::desempilhar_Tudo(){
    while(!vazio()){
        cout << desempilhar() << " ";
    }

}

int main(){

    Pilha duracell;
    int escolha = 10;
    int valor;

    while(escolha != 5){
        system("pause");
        cout << "[1]Empilhar\n[2]Desempilhar\n[3]Ver o Topo\n[4]Desempilhar Tudo\n";
        cin >> escolha;
        system("cls");
        if(escolha == 1){
            cin >> valor;
            duracell.empilhar(valor);
        }
        else if(escolha == 2){
            cout << duracell.desempilhar() << " ";
        }
        else if(escolha == 3){
            duracell.verTopo();
        }
        else if(escolha == 4){
            duracell.desempilhar_Tudo();
        }
    }





    return 0;
}