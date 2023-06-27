#ifndef AJUDANTE_H
#define AJUDANTE_H

#include "Organizador.h"

class Ajudante : public Organizador
{
private:
  int assistencias;

public:
  Ajudante();
  Ajudante(const std::string &nome, int matriculaNoEvento, int horaEntrada, int qntDias, double salarioDiario, int assistencias);
  ~Ajudante();

  int getAssistencias() const;
  void setAssistencias(int assistencias);

  void imprimeInformacoes() const override;
  double dinheiroRecebido() const override;

  Ajudante &operator=(const Ajudante &other);
};

#endif // AJUDANTE_H
