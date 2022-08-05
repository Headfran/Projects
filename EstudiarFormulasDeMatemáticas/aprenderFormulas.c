/* Programa que pregunta las fórmulas matemáticas principales
   y a lo que el usuario le conteste, le dirá si es correcto o incorrecto */
/** ERROR LÓGICO VIGENTE: No toma la función gets en la primera ejecución de la función */
#include <stdio.h>
#include <stdlib.h>  /* Biblioteca para usar system("cls") y funciones de números aleatorios */
#include <time.h>    /* Biblioteca que tiene constantes y funciones respecto al tiempo */
#include <string.h>  /* Biblioteca para funciones con cadenas */
#include <ctype.h>

/* prototipos de funciones */
void mensajeBienvenida( void );
int generaProblemaAngulos( const int );
int generaProblemaDerivadas( const int );
int generaProblemaIntegrales( const int );

/* la función main comienza la ejecución del programa */
int main()
{
   /* arreglo de apuntadores a funciones */
   int ( *ptrGeneraProblemas[ 3 ] )( const int ) =
      { generaProblemaAngulos, generaProblemaDerivadas, generaProblemaIntegrales };

   int opcion, posibilidad;
   int sigue;

   srand( time( NULL ) ); /* genera una semilla aleatoria */

   mensajeBienvenida(); /* imprime el mensaje de bienvenida del programa */

   printf( "Escoja una opcion:\n1. Angulos notables\n2. Derivadas\n3. Integrales\n" );
   printf( "4. Identidades Trigonometricas [No disponible :(]\n-1. Terminar\n : " );
   scanf( "%d", &opcion );

   if ( opcion >= 1 && opcion <= 3 ) { /* ángulos notables */
      printf( "\nEscriba 1 y presione enter... (Escriba -999 para terminar): " );
      scanf( "%d", &sigue );

      while( sigue != -999 ) {

         /* Mira las opciones */
         if ( opcion == 1 ) { posibilidad = rand() % 21; }
         else if ( opcion == 2 ) { posibilidad = rand() % 20; }
         else if ( opcion == 3 ) { posibilidad = rand() % 16; }

         while( !( *ptrGeneraProblemas[ opcion - 1 ] )( posibilidad ) );
         printf( "CORRECTO!!!\n" );
         printf( "\nEscriba 1 y presione enter... (Escriba -999 para terminar): " );
         scanf( "%d", &sigue );

         system( "cls" );

      } /* fin de while */
   } /* fin de if */
   else {
      printf( "no disponible :(\n\n" );
   } /* fin de else */

   system( "cls" );
   printf( "GRACIAS POR USAR ESTE HUMILDE PROGRAMA XD.\nFELIZ DIA :D\n\n" );

   return 0; /* indica terminación exitosa */

} /* fin de main */

/* la función despliega un mensaje de bienvenida así como las instrucciones básicas */
void mensajeBienvenida( void )
{
   int c;
   /* despliega mensaje de bienvenida */
   printf( "Bienvenido!!!\n" );
   printf( "Este programa esta hecho para que practiques\nlas formulas matematicas principales\n" );
   printf( "(Angulos notables, derivadas, integrales...)\n" );
   printf( "y asi poder aprendertelas.\n\n" );
   printf( "Presione enter para continuar..." );
   while( ( c = getchar() ) != '\n' );
   system( "cls" );

   /* despliega las instrucciones */
   printf( "No podras escribir los simbolos respectivos en este programa.\nPero hay una escritura alternativa:\n\n" );
   printf( "## Fracciones: x/y\n\tx = numerador, y = denominador\n\t" );
   printf( "Para escribir varios datos en numerador o denominador,\n\tagrupalos en parentesis:\n\t" );
   printf( "(x + 8)/(y - 8)\n\n" );
   printf( "## Elevados o exponentes: x^n\n\tx = base, n = exponente\n\t" );
   printf( "Para escribir varios datos en base o exponente,\n\tagrupalos en parentesis:\n\t" );
   printf( "(x + y)^(i + 2)\n\n" );
   printf( "## Raices cuadradas: sqrt< x >\n\tsqrt = comando de raiz cuadrada, x = numero positivo\n\t" );
   printf( "Para escribir varios datos en numero,\n\tagrupelos en parentesis (fracciones, exponentes...):\n\t" );
   printf( "sqrt< ( x - 2 ) / 4 >\n\n" );
   printf( "## Operaciones basicas: +: suma, -: resta, *: multiplicar, /: dividir\n\n" );
   printf( "Si ha entendido los comandos,\n presione enter para continuar..." );

   while( ( c = getchar() ) != '\n' );

   system( "cls" );

} /* fin de la función mensajeBienvenida */

/* función que pregunta un angulo notable */

int generaProblemaAngulos( const int p )
{
   char *problemas[ 21 ] = { "sen 0°", "sen 30°", "sen 45°", "sen 60°", "sen 90°", "sen 180°", "sen 270°",
                             "cos 0°", "cos 30°", "cos 45°", "cos 60°", "cos 90°", "cos 180°", "cos 270°",
                             "tan 0°", "tan 30°", "tan 45°", "tan 60°", "tan 90°", "tan 180°", "tan 270°" };
   char respuesta[ 30 ];
   char auxiliar[ 25 ];

   int i, j;
   int correcto = 0; /* inicializado en falso */
   /* imprime la pregunta */
   system( "cls" );
   printf( "Cual es el valor de %s = ", problemas[ p ] );
   fgets( respuesta, 30, stdin );

   /* transforma la respuesta a una sin espacios */
   for ( i = j = 0; i < strlen( respuesta ); i++ ) {
      if ( respuesta[ i ] != ' ' ) { auxiliar[ j++ ] = respuesta[ i ]; }
   } /* fin de for */
   auxiliar[ j ] = '\0';

   /* sección de respuestas. PARA LAS 21 PREGUNTAS!!! */
   if ( p == 0 ) { /** PREGUNTA 1 */
      if ( strncmp( "0", auxiliar, 1 ) == 0 ) { correcto = 1; }
   } /* fin de if */
   else if ( p == 1 ) { /** PREGUNTA 2 */
      if ( strncmp( "1/2", auxiliar, 3 ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 2 ) { /** PREGUNTA 3 */
      if ( strncmp( "sqrt<2>/2", auxiliar, 9 ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 3 ) { /** PREGUNTA 4 */
      if ( strncmp( "sqrt<3>/2", auxiliar, 9 ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 4 ) { /** PREGUNTA 5 */
      if ( strncmp( "1", auxiliar, 1 ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 5 ) { /** PREGUNTA 6 */
      if ( strncmp( "0", auxiliar, 1 ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 6 ) { /** PREGUNTA 7 */
      if ( strncmp( "-1", auxiliar, 2 ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 7 ) { /** PREGUNTA 8 */
      if ( strncmp( "1", auxiliar, 1 ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 8 ) { /** PREGUNTA 9 */
      if ( strncmp( "sqrt<3>/2", auxiliar, 9 ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 9 ) { /** PREGUNTA 10 */
      if ( strncmp( "sqrt<2>/2", auxiliar, 9 ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 10 ) { /** PREGUNTA 11 */
      if ( strncmp( "1/2", auxiliar, 3 ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 11 ) { /** PREGUNTA 12 */
      if ( strncmp( "0", auxiliar, 1 ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 12 ) { /** PREGUNTA 13 */
      if ( strncmp( "-1", auxiliar, 2 ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 13 ) { /** PREGUNTA 14 */
      if ( strncmp( "0", auxiliar, 1 ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 14 ) { /** PREGUNTA 15 */
      if ( strncmp( "0", auxiliar, 1 ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 15 ) { /** PREGUNTA 16 */
      if ( strncmp( "sqrt<3>/3", auxiliar, 9 ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 16 ) { /** PREGUNTA 17 */
      if ( strncmp( "1", auxiliar, 1 ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 17 ) { /** PREGUNTA 18 */
      if ( strncmp( "sqrt<3>", auxiliar, 7 ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 18 ) { /** PREGUNTA 19 */
      if ( strncmp( "non", auxiliar, 3 ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 19 ) { /** PREGUNTA 20 */
      if ( strncmp( "0", auxiliar, 1 ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 20 ) { /** PREGUNTA 21 */
      if ( strncmp( "non", auxiliar, 3 ) == 0 ) { correcto = 1; }
   } /* fin de else if */

   return correcto;
} /* fin de la función generaProblemaAngulos */

int generaProblemaDerivadas( const int p )
{
   char *problemas[ 20 ] =
      { "(u/v)\'", "(u*v)\'", "(k*u)\'", "(u+v-w)\'", "(u*v*w*z)\'",
        "( (u*v)/(w*z) )\'", "(u^n)\'", "(k^u)\'", "(e^u)\'", "(e^x)\'",
        "(log<b, u>)\'", "(ln<u>)\'", "(ln<x>)\'", "(sen u)\'", "(cos u)\'",
        "(tan u)\'", "(ctg u)\'", "(sec u)\'", "(csc u)\'", "(sqrt<u>)\'" };
   char respuesta[ 40 ];
   char auxiliar[ 38 ];

   int i, j;
   int correcto = 0; /* inicializado en falso */
   /* imprime la pregunta */
   system( "cls" );
   printf( "Cual es el valor de %s = ", problemas[ p ] );
   fgets( respuesta, 40, stdin );

   /* transforma la respuesta a una sin espacios */
   for ( i = j = 0; i < strlen( respuesta ); i++ ) {
      if ( respuesta[ i ] != ' ' ) { auxiliar[ j++ ] = respuesta[ i ]; }
   } /* fin de for */
   auxiliar[ j ] = '\0';

   /* sección de respuestas. PARA LAS 20 PREGUNTAS!!! */
   if ( p == 0 ) { /** PREGUNTA 1 */
      if ( strcmp( "(u'*v-v'*u)/(v^2)", auxiliar ) == 0 ) { correcto = 1; }
   } /* fin de if */
   else if ( p == 1 ) { /** PREGUNTA 2 */
      if ( strcmp( "u'*v+v'*u", auxiliar ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 2 ) { /** PREGUNTA 3 */
      if ( strcmp( "k*u'", auxiliar ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 3 ) { /** PREGUNTA 4 */
      if ( strcmp( "u'+v'-w'", auxiliar ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 4 ) { /** PREGUNTA 5 */
      if ( strcmp( "u'*v*w*z+u*v'*w*z+u*v*w'*z+u*v*w*z'", auxiliar ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 5 ) { /** PREGUNTA 6 */
      if ( strcmp( "(u'*v*w*z+u*v'*w*z-u*v*w'*z-u*v*w*z')/(w^2*z^2)", auxiliar ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 6 ) { /** PREGUNTA 7 */
      if ( strcmp( "n*u^(n-1)*u'", auxiliar ) == 0 || strcmp( "u'*n*u^(n-1)", auxiliar ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 7 ) { /** PREGUNTA 8 */
      if ( strcmp( "k^u*u'*ln<k>", auxiliar ) == 0 || strcmp( "u'*k^u*ln<k>", auxiliar ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 8 ) { /** PREGUNTA 9 */
      if ( strcmp( "e^u*u'", auxiliar ) == 0 || strcmp( "u'*e^u", auxiliar ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 9 ) { /** PREGUNTA 10 */
      if ( strcmp( "e^x", auxiliar ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 10 ) { /** PREGUNTA 11 */
      if ( strcmp( "u'/u*1/(ln<b>)", auxiliar ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 11 ) { /** PREGUNTA 12 */
      if ( strcmp( "u'/u", auxiliar ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 12 ) { /** PREGUNTA 13 */
      if ( strcmp( "1/x", auxiliar ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 13 ) { /** PREGUNTA 14 */
      if ( strcmp( "u'*cos<u>", auxiliar ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 14 ) { /** PREGUNTA 15 */
      if ( strcmp( "-u'*sen<u>", auxiliar ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 15 ) { /** PREGUNTA 16 */
      if ( strcmp( "u'*sec^2<u>", auxiliar ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 16 ) { /** PREGUNTA 17 */
      if ( strcmp( "-u'*csc^2<u>", auxiliar ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 17 ) { /** PREGUNTA 18 */
      if ( strcmp( "u'*sec<u>*tan<u>", auxiliar ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 18 ) { /** PREGUNTA 19 */
      if ( strcmp( "-u'*csc<u>*ctg<u>", auxiliar ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 19 ) { /** PREGUNTA 20 */
      if ( strcmp( "u'/(2*sqrt<u>)", auxiliar ) == 0 ) { correcto = 1; }
   } /* fin de else if */

   return correcto;
} /* fin de la función generaProblemaDerivadas */

int generaProblemaIntegrales( const int p )
{
   char *problemas[ 16 ] =
      { "Integral<u^n * du>", "Integral<u^-1 * du>", "Integral<sen u * du>", "Integral<cos u * du>",
        "Integral<tan u * du>", "Integral<sec u * du>", "Integral<csc u * du>", "Integral<ctg u * du>",
        "Integral< sec^2 <u> * du >", "Integral< csc^2 <u> * du >", "Integral<sec u * tan u * du>", "Integral<csc u * ctg u * du>",
        "Integral<du / (sqrt<a^2 - u^2>) >", "Integral<du / (a^2 + u^2)>", "Integral< du / (u * sqrt<u^2 - a^2>) >", "Integral<du / (a^2 - u^2)>" };
   char respuesta[ 50 ];
   char auxiliar[ 48 ];

   int i, j;
   int correcto = 0; /* inicializado en falso */
   /* imprime la pregunta */
   system( "cls" );
   printf( "Cual es el valor de: %s = ", problemas[ p ] );
   fgets( respuesta, 50, stdin );

   /* transforma la respuesta a una sin espacios */
   for ( i = j = 0; i < strlen( respuesta ); i++ ) {
      if ( respuesta[ i ] != ' ' ) { auxiliar[ j++ ] = tolower( respuesta[ i ] ); }
   } /* fin de for */
   auxiliar[ j ] = '\0';

   /* sección de respuestas. PARA LAS 20 PREGUNTAS!!! */
   if ( p == 0 ) { /** PREGUNTA 1 */
      if ( strcmp( "(u^(n+1))/(n+1)+c", auxiliar ) == 0 ) { correcto = 1; }
   } /* fin de if */
   else if ( p == 1 ) { /** PREGUNTA 2 */
      if ( strcmp( "ln<|u|>+c", auxiliar ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 2 ) { /** PREGUNTA 3 */
      if ( strcmp( "-cos<u>+c", auxiliar ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 3 ) { /** PREGUNTA 4 */
      if ( strcmp( "sen<u>+c", auxiliar ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 4 ) { /** PREGUNTA 5 */
      if ( strcmp( "ln<|sec<u>|>+c", auxiliar ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 5 ) { /** PREGUNTA 6 */
      if ( strcmp( "ln<|sec<u>+tan<u>|>+c", auxiliar ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 6 ) { /** PREGUNTA 7 */
      if ( strcmp( "ln<|csc<u>-ctg<u>|>+c", auxiliar ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 7 ) { /** PREGUNTA 8 */
      if ( strcmp( "ln<|sen<u>|>+c", auxiliar ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 8 ) { /** PREGUNTA 9 */
      if ( strcmp( "tan<u>+c", auxiliar ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 9 ) { /** PREGUNTA 10 */
      if ( strcmp( "-ctg<u>+c", auxiliar ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 10 ) { /** PREGUNTA 11 */
      if ( strcmp( "sec<u>+c", auxiliar ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 11 ) { /** PREGUNTA 12 */
      if ( strcmp( "-csc<u>+c", auxiliar ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 12 ) { /** PREGUNTA 13 */
      if ( strcmp( "arcsen<u/a>+c", auxiliar ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 13 ) { /** PREGUNTA 14 */
      if ( strcmp( "1/a*tan^-1<u/a>+c", auxiliar ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 14 ) { /** PREGUNTA 15 */
      if ( strcmp( "1/a*arcsec<u>+c", auxiliar ) == 0 ) { correcto = 1; }
   } /* fin de else if */
   else if ( p == 15 ) { /** PREGUNTA 16 */
      if ( strcmp( "1/(2*a)*ln<|(a-u)/(a+u)|>+c", auxiliar ) == 0 ) { correcto = 1; }
   } /* fin de else if */

   return correcto;
} /* fin de la función generaProblemaIntegrales */
