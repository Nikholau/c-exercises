#ifndef FORMABASICA_H
#define FORMABASICA_H

#include <iostream>

class FormaBasica
{
private:
  double x;
  double y;
  int cor;
  int espessuraContorno;
  int tipoContorno;

public:
  FormaBasica();
  FormaBasica(const double x, const double y, const int cor, const int espessuraContorno, const int tipoContorno);
  FormaBasica(const FormaBasica &other);
  virtual ~FormaBasica();

  void setX(double x);
  double getX() const;
  void setY(double y);
  double getY() const;
  void setCor(int cor);
  int getCor() const;
  void setEspessura(int espessuraContorno);
  int getEspessura() const;
  void setContorno(int tipoContorno);
  int getContorno() const;

  FormaBasica &operator=(const FormaBasica &other);
  void imprime() const;

  friend std::ostream &operator<<(std::ostream &out, const FormaBasica &forma);
  friend std::istream &operator>>(std::istream &in, FormaBasica &forma);
};

#endif // FORMABASICA_H
