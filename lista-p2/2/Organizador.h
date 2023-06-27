#ifndef ORGANIZADOR_H
#define ORGANIZADOR_H

#include "Pessoa.h"

class Organizador : public Pessoa
{
private:
  int horaEntrada;
  int qntDias;
  double salarioDiario;

public:
  Organizador();
  Organizador(const std::string &nome, int matriculaNoEvento, int horaEntrada, int qntDias, double salarioDiario);
  ~Organizador();

  int getHoraEntrada() const;
  void setHoraEntrada(int horaEntrada);
  int getQntDias() const;
  void setQntDias(int qntDias);
  double getSalarioDiario() const;
  void setSalarioDiario(double salarioDiario);

  void imprimeInformacoes() const override;
  double dinheiroRecebido() const override;

  Organizador &operator=(const Organizador &other);
};

#endif // ORGANIZADOR_H
