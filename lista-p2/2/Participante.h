#ifndef PARTICIPANTE_H
#define PARTICIPANTE_H

#include "Pessoa.h"

class Participante : public Pessoa
{
private:
  double premioParticipacao;

public:
  Participante();
  Participante(const std::string &nome, int matriculaNoEvento, double premioParticipacao);
  ~Participante();

  double getPremioParticipacao() const;
  void setPremioParticipacao(double premioParticipacao);

  void imprimeInformacoes() const override;
  double dinheiroRecebido() const override;

  Participante &operator=(const Participante &other);
};

#endif // PARTICIPANTE_H
