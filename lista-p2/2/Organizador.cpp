#include "Organizador.h"
#include <iostream>

Organizador::Organizador() : horaEntrada(0), qntDias(0), salarioDiario(0.0) {}

Organizador::Organizador(const std::string &nome, int matriculaNoEvento, int horaEntrada, int qntDias, double salarioDiario)
    : Pessoa(nome, matriculaNoEvento), horaEntrada(horaEntrada), qntDias(qntDias), salarioDiario(salarioDiario) {}

Organizador::~Organizador() {}

int Organizador::getHoraEntrada() const
{
  return horaEntrada;
}

void Organizador::setHoraEntrada(int horaEntrada)
{
  this->horaEntrada = horaEntrada;
}

int Organizador::getQntDias() const
{
  return qntDias;
}

void Organizador::setQntDias(int qntDias)
{
  this->qntDias = qntDias;
}

double Organizador::getSalarioDiario() const
{
  return salarioDiario;
}

void Organizador::setSalarioDiario(double salarioDiario)
{
  this->salarioDiario = salarioDiario;
}

void Organizador::imprimeInformacoes() const
{
  Pessoa::imprimeInformacoes();
  std::cout << "Hora de entrada: " << horaEntrada << std::endl;
  std::cout << "Quantidade de dias: " << qntDias << std::endl;
  std::cout << "Salário diário: " << salarioDiario << std::endl;
}

double Organizador::dinheiroRecebido() const
{
  return qntDias * salarioDiario;
}

Organizador &Organizador::operator=(const Organizador &other)
{
  if (this != &other)
  {
    Pessoa::operator=(other);
    horaEntrada = other.horaEntrada;
    qntDias = other.qntDias;
    salarioDiario = other.salarioDiario;
  }
  return *this;
}
