/*=====[Module Name]===========================================================
 * Copyright 2019 Esteban Daniel VOLENTINI <evolentini@gmail.com>
 * All rights reserved.
 * License: BSD-3-Clause <https://opensource.org/licenses/BSD-3-Clause>)
 *
 * Version: 0.1.0
 * Creation Date: 2019/03/01
 */
 
/*=====[Inclusion of own header]=============================================*/

#include "alumnos.h"
#include <stdio.h>
#include <string.h>

/*=====[Inclusions of private function dependencies]=========================*/

/*=====[Definition macros of private constants]==============================*/

/*=====[Private function-like macros]========================================*/

/*=====[Definitions of private data types]===================================*/

/*=====[Definitions of external public global variables]=====================*/

/*=====[Definitions of public global variables]==============================*/

/// Estructura de Alumno **DANIEL MARQUEZ**.  
///
/// Elemento utilizado para el almacenamiento de informacion correspondiente a Daniel
/// @param apellidos elemento para almacenar los *apellidos* de Daniel
/// @param nombres elemento para almacenar los *nombres* de Daniel
/// @param documento elemento para almacenar el *documento* de Daniel

static const struct alumno_s DANIEL_MARQUEZ = {
        .apellidos = "MARQUEZ FARIAS",
        .nombres = "Daniel Alexander",
        .documento = "95.956.478",
    };

const alumno_t ALUMNOS[] = {
    &DANIEL_MARQUEZ,
};

const int CANTIDAD_ALUMNOS = (sizeof(ALUMNOS) / sizeof(alumno_t));

/*=====[Definitions of private global variables]=============================*/

/*=====[Prototypes (declarations) of private functions]======================*/

/*=====[Implementations of public functions]=================================*/

/*=====[Implementations of interrupt functions]==============================*/


/// Impresion de Estructura de Alumno Individualmente.  
///
/// Elemento utilizado para el almacenamiento de informacion correspondiente del Alumno
/// @param cadena elemento para almacenar el texto estructurado del Alumno
/// @param espacio elemento con el largo de la cadena de texto
/// @param alumno elemento con toda la informacion del Alumno

bool SerializarAlumno(char * cadena, size_t espacio, const alumno_t alumno) {
    int resultado;
    const char FORMATO[] = "{"
        "\"documento\":\"%s\","
        "\"apellidos\":\"%s\","
        "\"nombres\":\"%s\""
    "}";

    resultado = snprintf(cadena, espacio, FORMATO, 
             alumno->documento, alumno->apellidos, alumno->nombres);

    return (resultado >= 0);
}


/// Impresion de Estructuras de Alumnos .  
///
/// Elemento utilizado para el almacenamiento de informacion correspondiente del Alumno
/// @param cadena con el formato deseado para laimpresion
/// @param alumnos[] array de Alumnos con todasuinformacion
/// @param cantidad cantidadde alumnos a imprimir Alumno


bool SerializarAlumnos(char * cadena, size_t espacio, const alumno_t alumnos[], int cantidad) {
    int posicion = snprintf(cadena, espacio, "[\r\n  ");
    bool resultado = (posicion > 0);

    if (resultado){
        for(int indice = 0; indice < cantidad; indice++ ) {
            resultado = SerializarAlumno(&cadena[posicion], espacio - posicion, alumnos[indice]);
            if (resultado) {
                posicion += strlen(&cadena[posicion]);
                posicion += snprintf(&cadena[posicion], espacio - posicion, ",\r\n  ");
            } else {
                break;
            }
        }
    }

    snprintf(&cadena[posicion] - 5, espacio - posicion + 5, "\r\n]");
    return resultado;
}

/*=====[Implementations of private functions]================================*/
