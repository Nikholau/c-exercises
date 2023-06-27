#include "Ajudante.h"
#include <iostream>

Ajudante::Ajudante() : assistencias(0) {}

Ajudante::Ajudante(const std::string &nome, int matriculaNoEvento, int horaEntrada, int qntDias, double salarioDiario, int assistencias)
    : Organizador(nome, matriculaNoEvento, horaEntrada, qntDias, salarioDiario), assistencias(assistencias) {}

Ajudante::~Ajudante() {}

int Ajudante::getAssistencias() const
{
  return assistencias;
}

void Ajudante::setAssistencias(int assistencias)
{
  this->assistencias = assistencias;
}

void Ajudante::imprimeInformacoes() const
{
  Organizador::imprimeInformacoes();
  std::cout << "Número de assistências: " << assistencias << std::endl;
}

double Ajudante::dinheiroRecebido() const
{
  return getQntDias() * getSalarioDiario() + 10 * assistencias;
}

Ajudante &Ajudante::operator=(const Ajudante &other)
{
  if (this != &other)
  {
    Organizador::operator=(other);
    assistencias = other.assistencias;
  }
  return *this;
}
