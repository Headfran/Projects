#include <iostream>

#include "Simpletron.h"

// la función main comienza la ejecución del programa
int main()
{
   Simpletron emulador;

   emulador.introduceDatos();
   emulador.iniciarSimpleton();

   return 0;
} // fin de main
