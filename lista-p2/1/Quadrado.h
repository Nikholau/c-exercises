#ifndef QUADRADO_H
#define QUADRADO_H

#include "Retangulo.h"

class Quadrado : public Retangulo
{
public:
  Quadrado();
  Quadrado(const double x, const double y, const int cor, const int espessuraContorno, const int tipoContorno, const double lado);
  Quadrado(const Quadrado &other);
  virtual ~Quadrado();

  Quadrado &operator=(const Quadrado &other);
  void imprime() const;
  double area() const;

  friend std::ostream &operator<<(std::ostream &out, const Quadrado &quadrado);
  friend std::istream &operator>>(std::istream &in, Quadrado &quadrado);
};

#endif // QUADRADO_H
