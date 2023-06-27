#include "Competidor.h"
#include <iostream>

Competidor::Competidor() : colocacao(0) {}

Competidor::Competidor(const std::string &nome, int matriculaNoEvento, double premioParticipacao, const std::string &nomeEquipe, int colocacao)
    : Participante(nome, matriculaNoEvento, premioParticipacao), nomeEquipe(nomeEquipe), colocacao(colocacao) {}

Competidor::~Competidor() {}

std::string Competidor::getNomeEquipe() const
{
  return nomeEquipe;
}

void Competidor::setNomeEquipe(const std::string &nomeEquipe)
{
  this->nomeEquipe = nomeEquipe;
}

int Competidor::getColocacao() const
{
  return colocacao;
}

void Competidor::setColocacao(int colocacao)
{
  this->colocacao = colocacao;
}

void Competidor::imprimeInformacoes() const
{
  Participante::imprimeInformacoes();
  std::cout << "Nome da equipe: " << nomeEquipe << std::endl;
  std::cout << "Colocação: " << colocacao << std::endl;
}

double Competidor::dinheiroRecebido() const
{
  if (colocacao == 1 || colocacao == 2 || colocacao == 3)
  {
    return getPremioParticipacao() + 300.0 / colocacao;
  }
  else
  {
    return getPremioParticipacao();
  }
}

Competidor &Competidor::operator=(const Competidor &other)
{
  if (this != &other)
  {
    Participante::operator=(other);
    nomeEquipe = other.nomeEquipe;
    colocacao = other.colocacao;
  }
  return *this;
}
