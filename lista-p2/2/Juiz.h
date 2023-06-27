#ifndef JUIZ_H
#define JUIZ_H

#include "Organizador.h"

class Juiz : public Organizador
{
private:
  int julgamentos;

public:
  Juiz();
  Juiz(const std::string &nome, int matriculaNoEvento, int horaEntrada, int qntDias, double salarioDiario, int julgamentos);
  ~Juiz();

  int getJulgamentos() const;
  void setJulgamentos(int julgamentos);

  void imprimeInformacoes() const override;
  double dinheiroRecebido() const override;

  Juiz &operator=(const Juiz &other);
};

#endif // JUIZ_H
