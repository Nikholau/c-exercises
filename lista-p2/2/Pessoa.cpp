#include "Pessoa.h"

Pessoa::Pessoa() : matriculaNoEvento(0) {}

Pessoa::Pessoa(const std::string &nome, int matriculaNoEvento)
    : nome(nome), matriculaNoEvento(matriculaNoEvento) {}

Pessoa::~Pessoa() {}

std::string Pessoa::getNome() const
{
  return nome;
}

void Pessoa::setNome(const std::string &nome)
{
  this->nome = nome;
}

int Pessoa::getMatriculaNoEvento() const
{
  return matriculaNoEvento;
}

void Pessoa::setMatriculaNoEvento(int matriculaNoEvento)
{
  this->matriculaNoEvento = matriculaNoEvento;
}

void Pessoa::imprimeInformacoes() const
{
  std::cout << "Nome: " << nome << std::endl;
  std::cout << "Matrícula no Evento: " << matriculaNoEvento << std::endl;
}

Pessoa &Pessoa::operator=(const Pessoa &other)
{
  if (this != &other)
  {
    nome = other.nome;
    matriculaNoEvento = other.matriculaNoEvento;
  }
  return *this;
}
