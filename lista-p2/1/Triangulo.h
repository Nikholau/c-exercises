#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "FormaBasica.h"

class Triangulo : public FormaBasica
{
public:
  Triangulo();
  Triangulo(const double x, const double y, const int cor, const int espessuraContorno, const int tipoContorno);
  Triangulo(const Triangulo &other);
  virtual ~Triangulo();

  Triangulo &operator=(const Triangulo &other);
  void imprime() const;
  double area() const;

  friend std::ostream &operator<<(std::ostream &out, const Triangulo &triangulo);
  friend std::istream &operator>>(std::istream &in, Triangulo &triangulo);
};

#endif // TRIANGULO_H
