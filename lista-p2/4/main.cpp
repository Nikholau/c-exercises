#include <iostream>
#include "ThrowException.cpp"
#include "../3/EspecialArray.cpp"

int main()
{
  try
  {
    ArrayEspecial<int> arrayInt;
    arrayInt.insere(5, 0);
    arrayInt.insere(10, 1);
    arrayInt.insere(15, 2);
    arrayInt.insere(20, 1); // Lança exceção PosicaoOcupadaException
  }
  catch (const PosicaoOcupadaException &e)
  {
    std::cout << "Excecao capturada: " << e.what() << std::endl;
  }

  try
  {
    ArrayEspecial<int> arrayInt;
    arrayInt.insere(5, 0);
    arrayInt.insere(10, 1);
    arrayInt.insere(15, 2);
    arrayInt.insere(20, 5); // Lança exceção PosicaoInvalidaException
  }
  catch (const PosicaoInvalidaException &e)
  {
    std::cout << "Excecao capturada: " << e.what() << std::endl;
  }

  try
  {
    ArrayEspecial<int> arrayInt;
    arrayInt.insere(5, 0);
    arrayInt.insere(10, 1);
    arrayInt.insere(15, 2);
    arrayInt.remove(3); // Lança exceção RemocaoInvalidaException
  }
  catch (const RemocaoInvalidaException &e)
  {
    std::cout << "Excecao capturada: " << e.what() << std::endl;
  }

  try
  {
    ArrayEspecial<int> arrayInt;
    arrayInt.insere(5, 0);
    arrayInt.insere(10, 1);
    arrayInt.insere(15, 2);
    arrayInt.remove(1);
    arrayInt.remove(1); // Lança exceção PosicaoLiberadaException
  }
  catch (const PosicaoLiberadaException &e)
  {
    std::cout << "Excecao capturada: " << e.what() << std::endl;
  }

  return 0;
}
