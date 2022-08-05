Probar el Simpletron con los siguientes comandos :)

/// Suma de dos números:
00 ? +0A07  (Lee A)
01 ? +0A08  (Lee B)
02 ? +1407  (Carga A al acumulador)
03 ? +1E08  (Suma B al acumulador)
04 ? +1508  (Almacena el valor de acumulador en B)
05 ? +0B08  (Escribe el valor de B)
06 ? +2B00  (Alto)
07 ? +0000  (Variable A)
08 ? +0000  (Variable B)
09 ? -99999

/// Suma de números positivos hasta que se introduzca un número negativo
00 ? +0A09  (Lee A)
01 ? +1409  (Carga A al acumulador)
02 ? +2907  (Salta a línea 07 si el acumulador cargado es negativo)
03 ? +140A  (Carga B al acumulador)
04 ? +1E09  (Suma A al acumulador)
05 ? +150A  (Almacena el valor de acumulador en B)
06 ? +2800  (Salta a linea 00)
07 ? +0B0A  (Escribe el valor de B)
08 ? +2B00  (Alto)
09 ? +0000  (Variable A)
10 ? +0000  (Variable B)
11 ? -99999

/// Lista de Comandos
LeeInt          +0A  (lee un entero desde el teclado y lo almacena en la posición que siga después del comando)
LeeDouble       -0A  (lee un número decimal desde el teclado y lo almacena en la posición que siga después del comando)
EscribeInt      +0B  (escribe un entero guardado en la posición despúes del comando)
EscribeDouble   -0B  (escribe un número decimal guardado después del comando)
EscribeNewL     +0C  (escribe una nueva línea \n)
LeeChar         +13  (lee una cadena desde el teclado y lo almacena en la posicion indicada después del comando)
EscribeChar     +14  (escribe una cadena guardada en la posición indicada después del comando)

CargaInt        +20  (carga una variable entera en la posición indicada después del comando en la memoria para ser operado)
AlmacenaInt     +21  (almacena el valor que este en la memoria en la variable indicada después del comando)

CargaDouble     -20  (carga una variable decimal en la posición indicada después del comando en la memoria para ser operado)
AlmacenaDouble  -21  (almacena el valor que este en la memoria en la variable indicada después del comando)

SumaInt         +30  (suma una variable entera indicada después del comando en el acumulador de la memoria)
RestaInt        +31  (resta una variable entera indicada después del comando en el acumulador de la memoria)
DivideInt       +32  (divide una variable entera indicada después del comando en el acumulador de la memoria)
MultiplicaInt   +33  (multiplica una variable entera indicada después del comando en el acumulador de la memoria)
Residua         +34  (obtiene el residuo de una división de una variable entera indicada después del comando en el acumulador de la memoria)
Exponencia      +35  (eleva una variable entera indicada después del comando en el acumulador de la memoria)

SUMADOUBLE         -30  (suma una variable decimal indicada después del comando en el acumulador de la memoria)
RESTADOUBLE        -31  (resta una variable decimal indicada después del comando en el acumulador de la memoria)
DIVIDEDOUBLE       -32  (divide una variable decimal indicada después del comando en el acumulador de la memoria)
MULTIPLICADOUBLE   -33  (multiplica una variable decimal indicada después del comando en el acumulador de la memoria)

SALTA     +40  (lleva el control de la ejecución a la línea indicada después del comando)
SALTANEG  +41  (lleva el control de la ejecución a la línea indicada despúes del comando si el acumulador de la memoria es negativo)
SALTACERO +42  (lleva el control de la ejecución a la línea indicada despúes del comando si el acumulador de la memoria es cero)
ALTO      +43  (termina la ejecución del programa)