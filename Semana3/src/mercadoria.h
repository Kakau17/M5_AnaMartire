#ifndef MERCADORIA_H
#define MERCADORIA_H

#include <string>

class Mercadoria {
public:
  Mercadoria();
  Mercadoria(int id, std::string nome);

  std::string getNome() const;
  int getID() const;

private:
  int id;
  std::string nome;
};

#endif