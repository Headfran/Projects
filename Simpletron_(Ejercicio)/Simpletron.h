//
// Created by Javi on 05/08/2022.
//

#ifndef SIMPLETRON_H
#define SIMPLETRON_H

#define LEEINT          10
#define LEEDOUBLE       -10
#define ESCRIBEINT      11
#define ESCRIBEDOUBLE   -11
#define ESCRIBENEWL     12
#define LEECHAR         13
#define ESCRIBECHAR     14

#define CARGAINT        20
#define ALMACENAINT     21

#define CARGADOUBLE     -20
#define ALMACENADOUBLE  -21

#define SUMAINT         30
#define RESTAINT        31
#define DIVIDEINT       32
#define MULTIPLICAINT   33
#define RESIDUA         34
#define EXPONENCIA      35

#define SUMADOUBLE         -30
#define RESTADOUBLE        -31
#define DIVIDEDOUBLE       -32
#define MULTIPLICADOUBLE   -33

#define SALTA     40
#define SALTANEG  41
#define SALTACERO 42
#define ALTO      43

#define TAMANIO_MEMORIA 1000
#define POSICIONCHAR    800

class Simpletron {
public:
    Simpletron(); // constructor

    // funciones miembro
    void introduceDatos();
    void iniciarSimpleton();

private:
    // variables principales donde se almacenan las instrucciones
    int memoriaInt[ TAMANIO_MEMORIA ];
    double memoriaDouble[ TAMANIO_MEMORIA ];
    char cadena[ 80 ];
    bool terminar;

    // variables que se encargan de manipular la memoria
    int contadorInstrucciones;
    int registroInstruccion;
    int codigoOperacion;
    int operando;
    double acumulador;

    // clase que contiene funciones para procesar un string que contiene un número hexadecimal
    class Hexadecimales {
    public:
        static int procesaHexadecimales( const char * );
        static int obtieneValorLetra( char );
    };

    // funciones de utilidad
    void imprimeVaciadoDeMemoria();
    void cifraChar( const char *, int );
    void decifraChar( int );
};



#endif //SIMPLETRON_H
