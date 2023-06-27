#include "FormaBasica.h"

FormaBasica::FormaBasica() : x(0.0), y(0.0), cor(0), espessuraContorno(0), tipoContorno(0) {}

FormaBasica::FormaBasica(const double x, const double y, const int cor, const int espessuraContorno, const int tipoContorno)
    : x(x), y(y), cor(cor), espessuraContorno(espessuraContorno), tipoContorno(tipoContorno) {}

FormaBasica::FormaBasica(const FormaBasica &other)
    : x(other.x), y(other.y), cor(other.cor), espessuraContorno(other.espessuraContorno), tipoContorno(other.tipoContorno) {}

FormaBasica::~FormaBasica() {}

void FormaBasica::setX(double x)
{
  this->x = x;
}

double FormaBasica::getX() const
{
  return x;
}

void FormaBasica::setY(double y)
{
  this->y = y;
}

double FormaBasica::getY() const
{
  return y;
}

void FormaBasica::setCor(int cor)
{
  this->cor = cor;
}

int FormaBasica::getCor() const
{
  return cor;
}

void FormaBasica::setEspessura(int espessuraContorno)
{
  this->espessuraContorno = espessuraContorno;
}

int FormaBasica::getEspessura() const
{
  return espessuraContorno;
}

void FormaBasica::setContorno(int tipoContorno)
{
  this->tipoContorno = tipoContorno;
}

int FormaBasica::getContorno() const
{
  return tipoContorno;
}

FormaBasica &FormaBasica::operator=(const FormaBasica &other)
{
  if (this != &other)
  {
    x = other.x;
    y = other.y;
    cor = other.cor;
    espessuraContorno = other.espessuraContorno;
    tipoContorno = other.tipoContorno;
  }
  return *this;
}

void FormaBasica::imprime() const
{
  std::cout << "Posição: (" << x << ", " << y << ")" << std::endl;
  std::cout << "Cor: " << cor << std::endl;
  std::cout << "Espessura do contorno: " << espessuraContorno << std::endl;
  std::cout << "Tipo do contorno: " << tipoContorno << std::endl;
}

std::ostream &operator<<(std::ostream &out, const FormaBasica &forma)
{
  out << "Posição: (" << forma.x << ", " << forma.y << ")" << std::endl;
  out << "Cor: " << forma.cor << std::endl;
  out << "Espessura do contorno: " << forma.espessuraContorno << std::endl;
  out << "Tipo do contorno: " << forma.tipoContorno << std::endl;
  return out;
}

std::istream &operator>>(std::istream &in, FormaBasica &forma)
{
  std::cout << "Digite a posição x: ";
  in >> forma.x;
  std::cout << "Digite a posição y: ";
  in >> forma.y;
  std::cout << "Digite a cor: ";
  in >> forma.cor;
  std::cout << "Digite a espessura do contorno: ";
  in >> forma.espessuraContorno;
  std::cout << "Digite o tipo do contorno: ";
  in >> forma.tipoContorno;
  return in;
}
