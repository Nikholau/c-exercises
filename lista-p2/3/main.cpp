#include <iostream>
#include "EspecialArray.cpp"

int main()
{
  // Testando com inteiros
  ArrayEspecial<int> arrayInt;
  arrayInt.insere(5, 0);
  arrayInt.insere(10, 1);
  arrayInt.insere(15, 2);
  arrayInt.imprimeElementos(); // Saída: 5 10 15

  // Testando com strings
  ArrayEspecial<std::string> arrayString;
  arrayString.insere("Hello", 0);
  arrayString.insere("World", 1);
  arrayString.imprimeElementos(); // Saída: Hello World

  // Testando com doubles
  ArrayEspecial<double> arrayDouble;
  arrayDouble.insere(3.14, 0);
  arrayDouble.insere(2.718, 1);
  arrayDouble.insere(1.618, 2);
  arrayDouble.imprimeElementos(); // Saída: 3.14 2.718 1.618

  return 0;
}
