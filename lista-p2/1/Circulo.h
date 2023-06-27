#ifndef CIRCULO_H
#define CIRCULO_H

#include "FormaBasica.h"

class Circulo : public FormaBasica
{
private:
  double raio;

public:
  Circulo();
  Circulo(const double x, const double y, const int cor, const int espessuraContorno, const int tipoContorno, const double raio);
  Circulo(const Circulo &other);
  virtual ~Circulo();

  void setRaio(double raio);
  double getRaio() const;

  Circulo &operator=(const Circulo &other);
  void imprime() const;
  double area() const;

  friend std::ostream &operator<<(std::ostream &out, const Circulo &circulo);
  friend std::istream &operator>>(std::istream &in, Circulo &circulo);
};

#endif // CIRCULO_H
