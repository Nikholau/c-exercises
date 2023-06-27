#include "Circulo.h"

Circulo::Circulo() : raio(0.0) {}

Circulo::Circulo(const double x, const double y, const int cor, const int espessuraContorno, const int tipoContorno, const double raio)
    : FormaBasica(x, y, cor, espessuraContorno, tipoContorno), raio(raio) {}

Circulo::Circulo(const Circulo &other) : FormaBasica(other), raio(other.raio) {}

Circulo::~Circulo() {}

void Circulo::setRaio(double raio)
{
  this->raio = raio;
}

double Circulo::getRaio() const
{
  return raio;
}

Circulo &Circulo::operator=(const Circulo &other)
{
  if (this != &other)
  {
    FormaBasica::operator=(other);
    raio = other.raio;
  }
  return *this;
}

void Circulo::imprime() const
{
  FormaBasica::imprime();
  std::cout << "Raio: " << raio << std::endl;
}

double Circulo::area() const
{
  return 3.14159 * raio * raio;
}

std::ostream &operator<<(std::ostream &out, const Circulo &circulo)
{
  out << static_cast<const FormaBasica &>(circulo);
  out << "Raio: " << circulo.raio << std::endl;
  return out;
}

std::istream &operator>>(std::istream &in, Circulo &circulo)
{
  FormaBasica &formaBasica = circulo;
  in >> formaBasica;
  std::cout << "Digite o raio: ";
  in >> circulo.raio;
  return in;
}
