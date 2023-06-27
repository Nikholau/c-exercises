#include "Participante.h"
#include <iostream>

Participante::Participante() : premioParticipacao(0.0) {}

Participante::Participante(const std::string &nome, int matriculaNoEvento, double premioParticipacao)
    : Pessoa(nome, matriculaNoEvento), premioParticipacao(premioParticipacao) {}

Participante::~Participante() {}

double Participante::getPremioParticipacao() const
{
  return premioParticipacao;
}

void Participante::setPremioParticipacao(double premioParticipacao)
{
  this->premioParticipacao = premioParticipacao;
}

void Participante::imprimeInformacoes() const
{
  Pessoa::imprimeInformacoes();
  std::cout << "Prêmio de participação: " << premioParticipacao << std::endl;
}

double Participante::dinheiroRecebido() const
{
  return premioParticipacao;
}

Participante &Participante::operator=(const Participante &other)
{
  if (this != &other)
  {
    Pessoa::operator=(other);
    premioParticipacao = other.premioParticipacao;
  }
  return *this;
}
