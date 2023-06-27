#include <exception>
#include <string>

class PosicaoOcupadaException : public std::exception
{
public:
  const char *what() const throw()
  {
    return "Posicao ocupada";
  }
};

class PosicaoInvalidaException : public std::exception
{
public:
  const char *what() const throw()
  {
    return "Posicao invalida";
  }
};

class RemocaoInvalidaException : public std::exception
{
public:
  const char *what() const throw()
  {
    return "Remocao invalida";
  }
};

class PosicaoLiberadaException : public std::exception
{
public:
  const char *what() const throw()
  {
    return "Posicao ja liberada";
  }
};
