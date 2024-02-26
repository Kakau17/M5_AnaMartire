#include "hash.h" 
#include <iostream>

using namespace std;

Hash::Hash(int max) {  
  length = 0;
  max_items = max;
  structure = new Mercadoria[max_items];   
}

Hash::~Hash(){
  delete [] structure;
}

bool Hash::isFull() const {
  return (length == max_items);
}

int Hash::getLength() const {
  return length;
}

// função que recupera uma mercadoria
void Hash::retrieveItem(Mercadoria& mercadoria, bool& found) {
  int startLoc = getHash(mercadoria);
  bool moreToSearch = true;
  int location = startLoc;
  do {
    if (structure[location].getID() == mercadoria.getID() ||
      structure[location].getID() == -1)
      moreToSearch = false;
    else
      location = (location + 1) % max_items;
  }
    while (location != startLoc && moreToSearch);

  found = (structure[location].getID() == mercadoria.getID());
  if (found){
    mercadoria = structure[location];
  }
}

// função que  insere itens na tabela hash
void Hash::insertItem(Mercadoria mercadoria) {
  int location;
  location = getHash(mercadoria);
  while (structure[location].getID() > 0)
    location = (location + 1) % max_items;
  structure[location] = mercadoria;
  length++;
}

// função para excluir um item da tabela hash
void Hash::deleteItem(Mercadoria mercadoria) {
  int startLoc = getHash(mercadoria);
  bool moreToSearch = true;
  int location = startLoc;
  do {
    if (structure[location].getID() == mercadoria.getID() ||
      structure[location].getID() == -1)
      moreToSearch = false;
    else
      location = (location + 1) % max_items;
  }
    while (location != startLoc && moreToSearch);

  if (structure[location].getID() == mercadoria.getID()) {
    structure[location] = Mercadoria(-2, "");
    length--;
  }
  }

// void Hash::deleteItem(Mercadoria mercadoria) {
//     int startLoc = getHash(mercadoria);
//     bool found = false;
//     int location = startLoc;

//     do {
//         if (structure[location].getID() == mercadoria.getID()) {
//             found = true;
//             break;
//         }
//         location = (location + 1) % max_items;
//     } while (location != startLoc);

//     if (found) {
//         while (true) {
//             int nextLocation = (location + 1) % max_items; // calcula a próxima posição
//             if (structure[nextLocation].getID() == -1 || getHash(structure[nextLocation]) == startLoc) { // verifica se a prox posição está vazia ou se é a própria posição inicial
//                 structure[location] = Mercadoria(-1, ""); // se estiver vazia, termina o loop
//                 break;
//             } else {
//                 structure[location] = structure[nextLocation]; // move a mercadoria da prox posição pra atual
//                 location = nextLocation; //atualiza posicao atual
//             }
//         }
//         length--;
//     }
// }

// função que "printa" a tabela hash
void Hash::print() {
  for (int i = 0; i < max_items; i++) {
    cout << i <<":"<<
      structure[i].getID()<<", "<<
      structure[i].getNome()<<endl;
  }
}

int Hash::getHash(Mercadoria mercadoria){
  return mercadoria.getID() % max_items;
}
