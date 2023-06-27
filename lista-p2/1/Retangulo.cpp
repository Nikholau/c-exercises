#include "Retangulo.h"

Retangulo::Retangulo() : largura(0.0), altura(0.0) {}

Retangulo::Retangulo(const double x, const double y, const int cor, const int espessuraContorno, const int tipoContorno, const double largura, const double altura)
    : FormaBasica(x, y, cor, espessuraContorno, tipoContorno), largura(largura), altura(altura) {}

Retangulo::Retangulo(const Retangulo &other) : FormaBasica(other), largura(other.largura), altura(other.altura) {}

Retangulo::~Retangulo() {}

void Retangulo::setLargura(double largura)
{
  this->largura = largura;
}

double Retangulo::getLargura() const
{
  return largura;
}

void Retangulo::setAltura(double altura)
{
  this->altura = altura;
}

double Retangulo::getAltura() const
{
  return altura;
}

Retangulo &Retangulo::operator=(const Retangulo &other)
{
  if (this != &other)
  {
    FormaBasica::operator=(other);
    largura = other.largura;
    altura = other.altura;
  }
  return *this;
}

void Retangulo::imprime() const
{
  FormaBasica::imprime();
  std::cout << "Largura: " << largura << std::endl;
  std::cout << "Altura: " << altura << std::endl;
}

double Retangulo::area() const
{
  return largura * altura;
}

std::ostream &operator<<(std::ostream &out, const Retangulo &retangulo)
{
  out << static_cast<const FormaBasica &>(retangulo);
  out << "Largura: " << retangulo.largura << std::endl;
  out << "Altura: " << retangulo.altura << std::endl;
  return out;
}

std::istream &operator>>(std::istream &in, Retangulo &retangulo)
{
  FormaBasica &formaBasica = retangulo;
  in >> formaBasica;
  std::cout << "Digite a largura: ";
  in >> retangulo.largura;
  std::cout << "Digite a altura: ";
  in >> retangulo.altura;
  return in;
}
