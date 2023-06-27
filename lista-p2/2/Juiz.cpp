#include "Juiz.h"
#include <iostream>

Juiz::Juiz() : julgamentos(0) {}

Juiz::Juiz(const std::string &nome, int matriculaNoEvento, int horaEntrada, int qntDias, double salarioDiario, int julgamentos)
    : Organizador(nome, matriculaNoEvento, horaEntrada, qntDias, salarioDiario), julgamentos(julgamentos) {}

Juiz::~Juiz() {}

int Juiz::getJulgamentos() const
{
  return julgamentos;
}

void Juiz::setJulgamentos(int julgamentos)
{
  this->julgamentos = julgamentos;
}

void Juiz::imprimeInformacoes() const
{
  Organizador::imprimeInformacoes();
  std::cout << "Número de julgamentos: " << julgamentos << std::endl;
}

double Juiz::dinheiroRecebido() const
{
  return getQntDias() * getSalarioDiario() + 15 * julgamentos;
}

Juiz &Juiz::operator=(const Juiz &other)
{
  if (this != &other)
  {
    Organizador::operator=(other);
    julgamentos = other.julgamentos;
  }
  return *this;
}
