#include "Tecnico.h"
#include <iostream>

Tecnico::Tecnico() : numEquipes(0) {}

Tecnico::Tecnico(const std::string &nome, int matriculaNoEvento, double premioParticipacao, int numEquipes)
    : Participante(nome, matriculaNoEvento, premioParticipacao), numEquipes(numEquipes) {}

Tecnico::~Tecnico() {}

int Tecnico::getNumEquipes() const
{
  return numEquipes;
}

void Tecnico::setNumEquipes(int numEquipes)
{
  this->numEquipes = numEquipes;
}

void Tecnico::imprimeInformacoes() const
{
  Participante::imprimeInformacoes();
  std::cout << "Número de equipes lideradas: " << numEquipes << std::endl;
}

double Tecnico::dinheiroRecebido() const
{
  return getPremioParticipacao() + 50.0 * numEquipes;
}

Tecnico &Tecnico::operator=(const Tecnico &other)
{
  if (this != &other)
  {
    Participante::operator=(other);
    numEquipes = other.numEquipes;
  }
  return *this;
}
