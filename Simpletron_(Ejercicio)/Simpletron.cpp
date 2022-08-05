//
// Created by Javi on 05/08/2022.
//
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

#include "Simpletron.h"

// constructor inicializa los componentes de la Simpletron
Simpletron::Simpletron()
{
   // inicializa la memoria entera
   for ( int lugarMemoria : memoriaInt )
      lugarMemoria = +0000;

   // inicializa la memoria decimal
   for ( double lugarMemoria : memoriaDouble )
      lugarMemoria = +0000.0;

   terminar = false;

   /* IMPRIME ENCABEZADO */
   cout << "\n*** Bienvenido a Simpletron!                         ***\n";
   cout << "*** Por favor, introduzca a su programa una instruccion ***\n";
   cout << "*** a la vez (o palabra de datos).           ***\n";
   cout << "*** Yo escribire el numero de ubicacion y un       ***\n";
   cout << "*** signo de interrogacion (?). Usted escriba ***\n";
   cout << "*** la palabra para dicha ubicacion. Escriba el   ***\n";
   cout << "*** centinela -99999 para terminar la     ***\n";
   cout << "*** introduccion de datos a su programa.                    ***\n" << endl;

} // fin del constructor

// función para introducir las intrucciones en la memoria
void Simpletron::introduceDatos()
{
   int i = 0;           // inicializa contador
   char datoHexa[ 7 ];  // intrucción del usuario en números hexadeciamales
   int dato;            // instrucción del usuario

   // recorre el arreglo de la memoria desde 0
   do {

      // imprime el número de ubicación y el signo de interrogación (?)
      if ( i < 10 )  { cout << "0" << i << " ? "; }
      else           { cout << i << " ? "; }

      // lee la palabra e incrementa contador i
      cin >> datoHexa;

      dato = Hexadecimales::procesaHexadecimales( datoHexa );

      // si se introduce un dato incorrecto
      while ( ( dato != -99999 ) && ( dato < -99998 || dato > +99999 )  ) {

         cout << "Comando Incorrecto... Las palabras son de -9999 a +9999\n\n";

         // imprime el número de ubicación y el signo de interrogación (?)
         if ( i < 10 )  { cout << "0" << i << " ? "; }
         else           { cout << i << " ? "; }

         // lee la palabra e incrementa contador i
         cin >> datoHexa;
         dato = Hexadecimales::procesaHexadecimales( datoHexa );

      } // fin de while

      memoriaInt[ i++ ] = dato; /* almacena la intrucción en memoria */

   } while( dato != -99999 ); /* fin de do...while */

   memoriaInt[ --i ] = 0; /* elimina el -99999 */

} // fin de la función introduceDatos

// función donde ocurre la lógica del Simpletron
void Simpletron::iniciarSimpleton()
{
   /*** COMIENZA LA EJECUCIÓN DEL PROGRAMA ***/

   // encabezado
   cout << "\n*** Carga del programa completa ***\n";
   cout << "*** Comienza la ejecucion del programa ***\n" << endl;

   // inicializa variables
   acumulador = +0000;
   contadorInstrucciones = 00;
   registroInstruccion = +0000;
   codigoOperacion = 00;
   operando = 00;

   // reccorre memoria ejecutando cada instrucción
   while ( !terminar ) {

      // copiar la instrucción de la memoria en el registro
      registroInstruccion = memoriaInt[ contadorInstrucciones ];
      // separar el codigoOperacion y el operando
      if ( registroInstruccion > 10000 || registroInstruccion < -10000 ) {
         codigoOperacion = registroInstruccion / 1000;
         operando = abs( registroInstruccion % 1000 );
      }  // fin de if
      else {
         codigoOperacion = registroInstruccion / 100;
         operando = abs( registroInstruccion % 100 );
      } // fin de else

      // selección de instrucciones
      switch ( codigoOperacion ) {

         case LEEINT: // lee un dato entero desde el teclado
            cout << "? ";
            cin >> memoriaInt[ operando ];

            if ( memoriaInt[ operando ] < -9999 || memoriaInt[ operando ] > +9999 ) {
               printf( "\n*** Desbordamiento de la memoria mayor que +9999 o menor que -9999 ***\n" );
               printf( "*** Terminacion anormal del programa ***\n\n" );
               terminar = true;

               imprimeVaciadoDeMemoria();
            } // fin de if

            ++contadorInstrucciones;

            break;

         case LEEDOUBLE: // lee un dato flotante desde el teclado
            cout << "? ";
            cin >> memoriaDouble[ operando ];

            if ( memoriaDouble[ operando ] < -9999 || memoriaDouble[ operando ] > +9999 ) {
               printf( "\n*** Desbordamiento de la memoria mayor que +9999 o menor que -9999 ***\n" );
               printf( "*** Terminacion anormal del programa ***\n\n" );
               terminar = true;

               imprimeVaciadoDeMemoria();
            } // fin de if

            ++contadorInstrucciones;

            break;

         case LEECHAR: // lee una cadena y la cifra a entero
            cout << "char ? ";
            cin >> cadena;
            cifraChar( cadena, POSICIONCHAR );

            ++contadorInstrucciones;
            break;

         case ESCRIBEINT: // escribe un dato entero desde una posicion en memoria
            cout << "\n: " << memoriaInt[ operando ] << endl;

            ++contadorInstrucciones;

            break;

         case ESCRIBEDOUBLE: // escribe un dato flotante desde una posicion en memoria
            printf( "\n: %.2f\n", memoriaDouble[ operando ] );

            ++contadorInstrucciones;

            break;

         case ESCRIBENEWL: // escribe una nueva línea de salida
            cout << endl;

            ++contadorInstrucciones;
            break;

         case ESCRIBECHAR: // escribe una cadena cifrada en la memoria
            cout << "char : ";
            decifraChar( POSICIONCHAR );

            ++contadorInstrucciones;
            break;

         case CARGAINT: // carga desde la memoria al acumulador
            acumulador = memoriaInt[ operando ];

            ++contadorInstrucciones;
            break;

         case CARGADOUBLE: // carga desde la memoria al acumulador
            acumulador = memoriaDouble[ operando ];

            ++contadorInstrucciones;
            break;

         case ALMACENAINT: // almacena desde el acumulador a la memoria
            memoriaInt[ operando ] = static_cast< int >( acumulador );

            ++contadorInstrucciones;
            break;

         case ALMACENADOUBLE: // almacena desde el acumulador a la memoria
            memoriaDouble[ operando ] = acumulador;

            ++contadorInstrucciones;
            break;

         case SUMAINT: // suma un dato al acumulador
            acumulador += memoriaInt[ operando ];

            if ( acumulador < -9999 || acumulador > +9999 ) {
               printf( "\n*** Desbordamiento de la memoria mayor que +9999 o menor que -9999 ***\n" );
               printf( "*** Terminacion anormal del programa ***\n\n" );
               terminar = true;

               imprimeVaciadoDeMemoria();
            } // fin de if

            ++contadorInstrucciones;

            break;

         case SUMADOUBLE: // suma un dato al acumulador
            acumulador += memoriaDouble[ operando ];

            if ( acumulador < -9999 || acumulador > +9999 ) {
               printf( "\n*** Desbordamiento de la memoria mayor que +9999 o menor que -9999 ***\n" );
               printf( "*** Terminacion anormal del programa ***\n\n" );
               terminar = true;

               imprimeVaciadoDeMemoria();
            } // fin de if

            ++contadorInstrucciones;

            break;

         case RESTAINT: // resta un dato al acumulador
            acumulador -= memoriaInt[ operando ];

            if ( acumulador < -9999 || acumulador > +9999 ) {
               cerr << "\n*** Desbordamiento de la memoria mayor que +9999 o menor que -9999 ***\n";
               cerr << "*** Terminacion anormal del programa ***\n" << endl;
               terminar = true;

               imprimeVaciadoDeMemoria();
            } // fin de if

            ++contadorInstrucciones;

            break;

         case RESTADOUBLE: // resta un dato al acumulador
            acumulador -= memoriaDouble[ operando ];

            if ( acumulador < -9999 || acumulador > +9999 ) {
               printf( "\n*** Desbordamiento de la memoria mayor que +9999 o menor que -9999 ***\n" );
               printf( "*** Terminacion anormal del programa ***\n\n" );
               terminar = true;

               imprimeVaciadoDeMemoria();
            } // fin de if

            ++contadorInstrucciones;

            break;

         case DIVIDEINT: // divide un dato al acumulador
            if ( memoriaInt[ operando ] != 0 ) {
               acumulador /= memoriaInt[ operando ];

               ++contadorInstrucciones;
            } // fin de if
            else {
               printf( "\n*** Intento de division entre cero ***\n" );
               printf( "*** Terminacion anormal del programa ***\n\n" );

               terminar = true;

               imprimeVaciadoDeMemoria();
            } // fin de else

            break;

         case DIVIDEDOUBLE: // divide un dato al acumulador
            if ( memoriaDouble[ operando ] != 0 ) {
               acumulador /= memoriaDouble[ operando ];

               ++contadorInstrucciones;
            } // fin de if
            else {
               printf( "\n*** Intento de division entre cero ***\n" );
               printf( "*** Terminacion anormal del programa ***\n\n" );

               terminar = true;

               imprimeVaciadoDeMemoria();
            } // fin de else

            break;

         case MULTIPLICAINT: // multiplica un dato al acumulador
            acumulador *= memoriaInt[ operando ];

            if ( acumulador < -9999 || acumulador > +9999 ) {
               printf( "\n*** Desbordamiento de la memoria mayor que +9999 o menor que -9999 ***\n" );
               printf( "*** Terminacion anormal del programa ***\n\n" );
               terminar = true;

               imprimeVaciadoDeMemoria();
            } // fin de if

            ++contadorInstrucciones;

            break;

         case MULTIPLICADOUBLE: // multiplica un dato al acumulador
            acumulador *= memoriaDouble[ operando ];

            if ( acumulador < -9999 || acumulador > +9999 ) {
               printf( "\n*** Desbordamiento de la memoria mayor que +9999 o menor que -9999 ***\n" );
               printf( "*** Terminacion anormal del programa ***\n\n" );
               terminar = true;

               imprimeVaciadoDeMemoria();
            } // fin de if

            ++contadorInstrucciones;

            break;

         case RESIDUA: // divide un dato para residuar al acumulador
            if ( memoriaInt[ operando ] != 0 ) {
               acumulador = static_cast< int >( acumulador ) % static_cast< int >( memoriaInt[ operando ] );

               ++contadorInstrucciones;
            } // fin de if
            else {
               printf( "\n*** Desbordamiento de la memoria mayor que +9999 o menor que -9999 ***\n" );
               printf( "*** Terminacion anormal del programa ***\n\n" );

               terminar = true;

               imprimeVaciadoDeMemoria();
            } // fin de else

            break;

         case EXPONENCIA: // eleva un dato al acumulador
            for ( int counter = 1; counter <= memoriaInt[ operando ]; counter++ )
               acumulador *= acumulador;

            if ( acumulador < -9999 || acumulador > +9999 ) {
               printf( "\n*** Desbordamiento de la memoria mayor que +9999 o menor que -9999 ***\n" );
               printf( "*** Terminacion anormal del programa ***\n\n" );
               terminar = true;

               imprimeVaciadoDeMemoria();
            } // fin de if

            ++contadorInstrucciones;

            break;

         case SALTA: // salta a una posición en la memoria
            contadorInstrucciones = operando;
            break;

         case SALTANEG: // salta a una posición en la memoria si acumulador es negativo
            if ( acumulador < 0 )
               contadorInstrucciones = operando;
            else
               ++contadorInstrucciones;

            break;

         case SALTACERO: // salta a una posición en la memoria si acumulador es cero
            if ( acumulador == 0 )
               contadorInstrucciones = operando;
            else
               ++contadorInstrucciones;

            break;

         case ALTO: // termina la ejecución del programa
            printf( "\n*** Finaliza ejecucion de Simpletron ***\n\n" );

            terminar = true;
            break;

         default:
            printf( "\n*** Intento de ejecutar comando inexistente ***\n" );
            printf( "*** Terminacion anormal del programa ***\n\n" );

            imprimeVaciadoDeMemoria();

            terminar = true;

      } // fin de switch

   } // fin de while
} // fin de la función iniciarSimpletron

// función de utilidad para procesar el número hexadecimal
int Simpletron::Hexadecimales::procesaHexadecimales( const char *s )
{
   int numero; // palabra de datos en orden normal
   int total = 0;
   int multiplo = 1;
   int a, b, c;
   const char *ptrS = s;

   // obtiene el tamaño de la cadena
   while ( *ptrS != '\0' ) {

      if ( isalnum( *ptrS ) ) { multiplo *= 10; }

      ptrS++;

   } /* fin de while */

   a = Hexadecimales::obtieneValorLetra( s[ 1 ] );
   b = Hexadecimales::obtieneValorLetra( s[ 2 ] );

   numero = ( a * 16 ) + b;

   total += ( numero * ( multiplo / 100 ) );

   a = Hexadecimales::obtieneValorLetra( s[ 3 ] );
   b = Hexadecimales::obtieneValorLetra( s[ 4 ] );
   c = multiplo > 10000 ? Hexadecimales::obtieneValorLetra( s[ 5 ] ) : 0;

   numero = ( c * 100 ) + ( a * 10 ) + ( b * 1 );

   total += ( numero * ( multiplo / 10000 ) );

   if ( total == 162990 ) return -99999;

   return s[ 0 ] == '-' ? -total : total;

} /* fin de la función procesaHexadecimales */

int Simpletron::Hexadecimales::obtieneValorLetra( char c )
{
   int resultado;

   if ( isalpha( c ) && tolower( c ) > 'f' ) {
      cerr << "Datos invalidos! Terminando programa..." << endl;
      abort();
   } // fin de if

   resultado = ( isalpha( c ) ? ( tolower( c ) - 'a' + 10 ) : ( c - '0' ) );

   return resultado;

} // fin de la función de la privada Hexadecimales::obtieneValorLetra

//
void Simpletron::imprimeVaciadoDeMemoria()
{
   int i, j;   // contador
   int copiaMI, copiaR;
   double copiaMD;

   // ENCABEZADO
   printf( "\nREGISTROS:\n" );

   // acumulador
   copiaR = acumulador;
   printf( "acumulador\t\t" );

   if ( copiaR < 0 ) { printf( "%2s", "-" ); copiaR = -copiaR; }
   else              { printf("%2s", "+"); }

   if ( acumulador == 0 || acumulador < 10 ) { printf( "000" ); }
   else if ( acumulador < 100 )              { printf( "00" ); }
   else if ( acumulador < 1000 )             { printf( "0" ); }
   printf( "%-4d\n", copiaR );

   // contadorInstrucciones
   printf( "contadorInstrucciones\t    %s%-2d\n", ( ( contadorInstrucciones >= 0 && contadorInstrucciones < 10 ) ? "0" : "" ), contadorInstrucciones );

   // registroInstrucción
   copiaR = registroInstruccion;

   printf( "registroInstruccion\t" );

   if ( copiaR < 0 ) { printf( "%2s", "-" ); copiaR = -copiaR; }
   else printf( "%2s", "+" );

   if ( registroInstruccion >= 0 && registroInstruccion < 10 ) { printf( "000" ); }
   else if ( registroInstruccion < 100 )                       { printf( "00" ); }
   else if ( registroInstruccion < 1000 )                      { printf( "0" ); }
   printf( "%-4d\n", copiaR );

   // codigoOperación
   printf( "codigoOperacion\t\t    %s%-2d\n", ( ( codigoOperacion >= 0 && codigoOperacion < 10 ) ? "0" : "" ), codigoOperacion );

   // operando
   printf( "operando\t\t    %s%-2d\n", ( ( operando >= 0 && operando < 10 ) ? "0" : "" ), operando );



   // ENCABEZADO
   printf( "\nMEMORIA\n         " );

   for ( i = 0; i < 10; i++ ) printf( "%d%6s", i, i != 9 ? "" : "\n" );

   for ( j = 0; j < TAMANIO_MEMORIA; j += 10 ) {

      printf( "%3d  ", j );

      for ( i = 0; i < 10; i++ ) {

         // La dirección contiene un número de punto flotante
         if ( memoriaDouble[ i + j ] != 0.0 ) {

            copiaMD = memoriaDouble[ i + j ];

            if ( copiaMD < 0 ) { printf( "-" ); copiaMD = -copiaMD; }
            else { printf("+"); }

            if ( copiaMD > 100 ) {
               printf( "%.0f  ", copiaMD );
            } // fin de if
            else if ( copiaMD > 10 ) {
               printf( "%.1f  ", copiaMD );
            } // fin de if
            else if ( copiaMD == 0 || copiaMD < 10 ) {
               printf( "%s", "00" );
               printf( "%.2f  ", copiaMD );
            } // fin de if


         } // fin de if
         else {
            copiaMI = memoriaInt[ i + j ];

            if ( copiaMI < 0 ) { printf( "-" ); copiaMI = -copiaMI; }
            else { printf("+"); }

            if ( copiaMI == 0 || copiaMI < 10 ) { printf( "%s", "000" ); }
            else if ( copiaMI < 100 ) { printf( "00" ); }
            else if ( copiaMI < 1000 ) { printf( "0" ); }

            printf( "%d  ", copiaMI );
         } // fin de else

      } // fin de for

      printf( "\n" );

   } // fin de for

   printf( "\n\n" ); /* nueva línea de salida */

} // fin de la función de utilidad imprimeVaciadoDeMemoria

// función de utilidad que cifra una cadena para introducirla en la memoria
void Simpletron::cifraChar( const char *s, int indiceInicio )
{
   int i;
   int tamanio;

   // obtiene el tamaño del arreglo de caracteres
   for ( tamanio = 0, i = 0; s[ i ] != '\0'; i++, tamanio++ );

   // cifra el tamaño y su primer caracter
   memoriaInt[ indiceInicio ] = ( ( tamanio * 100 ) + ( s[ 0 ] - 50 ) );

   // sigue cifrando y almacenando los demás caracteres
   for ( int i = indiceInicio + 1, j = 1; j < tamanio; i++, j += 2 ) {

      if ( s[ j + 1 ] - 50 == -50 )
         memoriaInt[ i ] = ( ( s[ j ] - 50 ) * 100 ) + ( s[ j + 1 ] );
      else
         memoriaInt[ i ] = ( ( s[ j ] - 50 ) * 100 ) + ( s[ j + 1 ] - 50 );

   } // fin de for
} // fin de la función de utilidad cifraChar

// función de utilidad que decifra una cadena de la memoria
void Simpletron::decifraChar( int indiceInicio )
{
   int a, b;
   int tamanio;
   int i;

   // saca el tamaño y el primer caracter
   a = memoriaInt[ indiceInicio ] / 100;
   b = ( memoriaInt[ indiceInicio ] % 100 ) + 50;

   tamanio = a;

   cout << b;

   for ( i = indiceInicio + 1; tamanio > 0; i++, tamanio -= 2 ) {

      a = ( memoriaInt[ i ] / 100 );
      b = ( memoriaInt[ i ] % 100 );

      if ( a == 0 ) break;

      cout << ( a + 50 ) << ( ( b ) == 0 ? b : b + 50 );

   } /* fin de for */

   cout << endl;
} // fin de la función de utilidad decifraChar