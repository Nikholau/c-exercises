#include "Quadrado.h"

Quadrado::Quadrado() {}

Quadrado::Quadrado(const double x, const double y, const int cor, const int espessuraContorno, const int tipoContorno, const double lado)
    : Retangulo(x, y, cor, espessuraContorno, tipoContorno, lado, lado) {}

Quadrado::Quadrado(const Quadrado &other) : Retangulo(other) {}

Quadrado::~Quadrado() {}

Quadrado &Quadrado::operator=(const Quadrado &other)
{
  if (this != &other)
  {
    Retangulo::operator=(other);
  }
  return *this;
}

void Quadrado::imprime() const
{
  Retangulo::imprime();
  std::cout << "Quadrado" << std::endl;
}

double Quadrado::area() const
{
  // Implemente o cálculo da área do quadrado aqui
  return 0.0;
}

std::ostream &operator<<(std::ostream &out, const Quadrado &quadrado)
{
  out << static_cast<const Retangulo &>(quadrado);
  out << "Quadrado" << std::endl;
  return out;
}

std::istream &operator>>(std::istream &in, Quadrado &quadrado)
{
  Retangulo &retangulo = quadrado;
  in >> retangulo;
  return in;
}
