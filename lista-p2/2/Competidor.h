#ifndef COMPETIDOR_H
#define COMPETIDOR_H

#include "Participante.h"

class Competidor : public Participante
{
private:
  std::string nomeEquipe;
  int colocacao;

public:
  Competidor();
  Competidor(const std::string &nome, int matriculaNoEvento, double premioParticipacao, const std::string &nomeEquipe, int colocacao);
  ~Competidor();

  std::string getNomeEquipe() const;
  void setNomeEquipe(const std::string &nomeEquipe);
  int getColocacao() const;
  void setColocacao(int colocacao);

  void imprimeInformacoes() const override;
  double dinheiroRecebido() const override;

  Competidor &operator=(const Competidor &other);
};

#endif // COMPETIDOR_H
