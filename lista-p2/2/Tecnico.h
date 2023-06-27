#ifndef TECNICO_H
#define TECNICO_H

#include "Participante.h"

class Tecnico : public Participante
{
private:
  int numEquipes;

public:
  Tecnico();
  Tecnico(const std::string &nome, int matriculaNoEvento, double premioParticipacao, int numEquipes);
  ~Tecnico();

  int getNumEquipes() const;
  void setNumEquipes(int numEquipes);

  void imprimeInformacoes() const override;
  double dinheiroRecebido() const override;

  Tecnico &operator=(const Tecnico &other);
};

#endif // TECNICO_H
