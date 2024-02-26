#include "mercadoria.h"

Mercadoria::Mercadoria(){
  this->id   = -1;
  this->nome = "";
};  

Mercadoria::Mercadoria(int id, std::string nome){
  this->id    = id;
  this->nome  = nome;
}

std::string Mercadoria::getNome() const {
  return nome;
}

int Mercadoria::getID() const{
  return id;
}
