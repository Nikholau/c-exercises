#include <iostream>

template <typename T>
class ArrayEspecial
{
private:
  T *elementos;
  bool *ativos;
  int tam;
  int max;

public:
  ArrayEspecial() : tam(0), max(10)
  {
    elementos = new T[max];
    ativos = new bool[max];
    for (int i = 0; i < max; i++)
    {
      ativos[i] = false;
    }
  }

  ArrayEspecial(const ArrayEspecial<T> &other) : tam(other.tam), max(other.max)
  {
    elementos = new T[max];
    ativos = new bool[max];
    for (int i = 0; i < max; i++)
    {
      elementos[i] = other.elementos[i];
      ativos[i] = other.ativos[i];
    }
  }

  ~ArrayEspecial()
  {
    delete[] elementos;
    delete[] ativos;
  }

  ArrayEspecial<T> &operator=(const ArrayEspecial<T> &other)
  {
    if (this != &other)
    {
      delete[] elementos;
      delete[] ativos;

      tam = other.tam;
      max = other.max;

      elementos = new T[max];
      ativos = new bool[max];
      for (int i = 0; i < max; i++)
      {
        elementos[i] = other.elementos[i];
        ativos[i] = other.ativos[i];
      }
    }
    return *this;
  }

  void insere(T e, int pos)
  {
    if (pos >= 0 && pos < max && !ativos[pos])
    {
      elementos[pos] = e;
      ativos[pos] = true;
      tam++;
    }
  }

  void remove(int pos)
  {
    if (pos >= 0 && pos < max && ativos[pos])
    {
      ativos[pos] = false;
      tam--;
    }
  }

  void imprimeElementos() const
  {
    for (int i = 0; i < max; i++)
    {
      if (ativos[i])
      {
        std::cout << elementos[i] << " ";
      }
    }
    std::cout << std::endl;
  }
};
