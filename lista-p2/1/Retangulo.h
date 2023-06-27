#ifndef RETANGULO_H
#define RETANGULO_H

#include "FormaBasica.h"

class Retangulo : public FormaBasica
{
private:
  double largura;
  double altura;

public:
  Retangulo();
  Retangulo(const double x, const double y, const int cor, const int espessuraContorno, const int tipoContorno, const double largura, const double altura);
  Retangulo(const Retangulo &other);
  virtual ~Retangulo();

  void setLargura(double largura);
  double getLargura() const;
  void setAltura(double altura);
  double getAltura() const;

  Retangulo &operator=(const Retangulo &other);
  void imprime() const;
  double area() const;

  friend std::ostream &operator<<(std::ostream &out, const Retangulo &retangulo);
  friend std::istream &operator>>(std::istream &in, Retangulo &retangulo);
};

#endif // RETANGULO_H
