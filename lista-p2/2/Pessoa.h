#ifndef PESSOA_H
#define PESSOA_H

#include <string>

class Pessoa
{
private:
  std::string nome;
  int matriculaNoEvento;

public:
  Pessoa();
  Pessoa(const std::string &nome, int matriculaNoEvento);
  virtual ~Pessoa();

  std::string getNome() const;
  void setNome(const std::string &nome);
  int getMatriculaNoEvento() const;
  void setMatriculaNoEvento(int matriculaNoEvento);

  virtual void imprimeInformacoes() const;
  virtual double dinheiroRecebido() const = 0;

  Pessoa &operator=(const Pessoa &other);
};

#endif // PESSOA_H
