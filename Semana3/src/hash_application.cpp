#include <iostream>
#include "hash.h" 

using namespace std;



// Função para realizar o Caso de Teste 1: Inserção de Mercadoria
void testCase1() {
    Hash mercadoriasHash(10);

    cout << "------------------------------" << endl;
    cout << "Teste 1: Inserção de Mercadoria" << endl;
    cout << "------------------------------" << endl;

    Mercadoria mercadoria1(1001, "Caneta");
    mercadoriasHash.insertItem(mercadoria1);
  bool found = false;
  mercadoriasHash.retrieveItem(mercadoria1, found);
  if (found) {
      cout << "Mercadoria inserida com sucesso." << endl;
  } else {
      cout << "Falha ao inserir a mercadoria." << endl;
  }
}

// Função para realizar o Caso de Teste 2: Exclusão de Mercadoria
void testCase2() {
    Hash mercadoriasHash(10);

    cout << "------------------------------" << endl;
    cout << "Teste 2: Exclusão de Mercadoria" << endl;
    cout << "------------------------------" << endl;

    Mercadoria mercadoriaExclusao(1001, "Caneta");
    mercadoriasHash.insertItem(mercadoriaExclusao);
    mercadoriasHash.deleteItem(mercadoriaExclusao);
    bool found = false;
    mercadoriasHash.retrieveItem(mercadoriaExclusao, found);
    if (!found) {
        cout << "Mercadoria excluída com sucesso." << endl;
    } else {
        cout << "Falha ao excluir a mercadoria." << endl;
    }
}

// Função para realizar o Caso de Teste 3: Recuperação de Mercadoria
void testCase3() {
    Hash mercadoriasHash(10);

    cout << "------------------------------" << endl;
    cout << "Teste 3: Recuperação de Mercadoria" << endl;
    cout << "------------------------------" << endl;

    Mercadoria mercadoriaRecuperacao(1001, "Caneta");
    mercadoriasHash.insertItem(mercadoriaRecuperacao);
    bool found = false;
    mercadoriasHash.retrieveItem(mercadoriaRecuperacao, found);
    if (found) {
        cout << "Mercadoria recuperada: " << mercadoriaRecuperacao.getNome() << endl;
    } else {
        cout << "Falha ao recuperar a mercadoria." << endl;
    }
}



// Função para realizar o Caso de Teste 4: Recuperação de Mercadoria Inexistente
void testCase4() {
    Hash mercadoriasHash(10);

    cout << "------------------------------" << endl;
    cout << "Teste 4: Recuperação de Mercadoria Inexistente" << endl;
    cout << "------------------------------" << endl;

    Mercadoria mercadoriaInexistente(9999, "Tesoura");
    bool found = false;
    mercadoriasHash.retrieveItem(mercadoriaInexistente, found);
    if (found) {
        cout << "Mercadoria encontrada: " << mercadoriaInexistente.getNome() << endl;
    } else {
        cout << "Mercadoria não encontrada." << endl;
    }
}

// Função para realizar o Caso de Teste 5: Exclusão de Mercadoria por Colisão
void testCase5() {
    Hash mercadoriasHash(10);

    cout << "------------------------------" << endl;
    cout << "Teste 5: Exclusão de Mercadoria por Colisão" << endl;
    cout << "------------------------------" << endl;

    // Insere mercadorias que causam colisões
    Mercadoria mercadoriaColisao1(1002, "Borracha");
    Mercadoria mercadoriaColisao2(1003, "Caderno");
    mercadoriasHash.insertItem(mercadoriaColisao1);
    mercadoriasHash.insertItem(mercadoriaColisao2);

    // Exclui uma dessas mercadorias
    mercadoriasHash.deleteItem(mercadoriaColisao1);

    // Imprime a tabela de hash
    cout << "Tabela de Hash após exclusão:" << endl;
    mercadoriasHash.print();
}

int main() {
    testCase1();
    testCase2();
    testCase3();
    testCase4();
    testCase5();

    return 0;

}