#include "Triangulo.h"

Triangulo::Triangulo() {}

Triangulo::Triangulo(const double x, const double y, const int cor, const int espessuraContorno, const int tipoContorno)
    : FormaBasica(x, y, cor, espessuraContorno, tipoContorno) {}

Triangulo::Triangulo(const Triangulo &other) : FormaBasica(other) {}

Triangulo::~Triangulo() {}

Triangulo &Triangulo::operator=(const Triangulo &other)
{
  if (this != &other)
  {
    FormaBasica::operator=(other);
  }
  return *this;
}

void Triangulo::imprime() const
{
  FormaBasica::imprime();
  std::cout << "Triângulo" << std::endl;
}

double Triangulo::area() const
{
  // Implemente o cálculo da área do triângulo aqui
  return 0.0;
}

std::ostream &operator<<(std::ostream &out, const Triangulo &triangulo)
{
  out << static_cast<const FormaBasica &>(triangulo);
  out << "Triângulo" << std::endl;
  return out;
}

std::istream &operator>>(std::istream &in, Triangulo &triangulo)
{
  FormaBasica &formaBasica = triangulo;
  in >> formaBasica;
  return in;
}
