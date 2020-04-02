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
static const struct alumno_s DAVID_BROIN = {
    .apellidos = "BROIN",
    .nombres = "David Mauricio",
    .documento = "32.370.264",
};

static const struct alumno_s LUCAS_MONZONLANGUASCO = {
    .apellidos = "MONZON LANGUASCO",
    .nombres = "Lucas Fabricio",
    .documento = "38.876.668",
};

static const struct alumno_s KEVIN_MONCAYO = {
    .apellidos = "MONCAYO MUÑOZ",
    .nombres = "Jorge Kevin",
    .documento = "1.085.298.019",
};

static const struct alumno_s ESTEBAN_VOLENTINI = {
    .apellidos = "VOLENTINI",
    .nombres = "Esteban Daniel",
    .documento = "23.517.968",
};

static const struct alumno_s HANES_SCIARRONE = {
    .apellidos = "SCIARRONE",
    .nombres = "Hanes Nahuel",
    .documento = "37.867.564",
};

static const struct alumno_s JOSE_LOPEZ = {
    .apellidos = "LOPEZ",
    .nombres = "José Daniel",
    .documento = "20.010.452",
};

static const struct alumno_s FREDS_AMUNDARAY = {
    .apellidos = "AMUNDARAY CRUZ",
    .nombres = "Freds Argilio",
    .documento = "95.843.832",
};

static const struct alumno_s LUCIANO_VITTORI = {
    .apellidos = "VITTORI",
    .nombres = "Luciano Francisco",
    .documento = "35.440.774",
};

static const struct alumno_s MUNOZ_JORGE = {
      .apellidos = "MUÑOZ",
      .nombres = "Jorge Salvador",
      .documento = "33.027.191",
  };

static const struct alumno_s RAUL_CAMACHO = {
        .apellidos = "CAMACHO",
        .nombres = "Raul Alejandro",
        .documento = "75.656.530",
    };

static const struct alumno_s DANIEL_MARQUEZ = {
        .apellidos = "MARQUEZ FARIAS",
        .nombres = "Daniel Alexander",
        .documento = "95.956.478",
    };

const alumno_t ALUMNOS[] = {
    &DANIEL_MARQUEZ,
    &RAUL_CAMACHO,
    &DAVID_BROIN,
    &MUNOZ_JORGE,
    &LUCIANO_VITTORI,
    &LUCAS_MONZONLANGUASCO,
    &KEVIN_MONCAYO,
    &ESTEBAN_VOLENTINI,
    &HANES_SCIARRONE,
    &JOSE_LOPEZ,
    &FREDS_AMUNDARAY,  
};


const int CANTIDAD_ALUMNOS = (sizeof(ALUMNOS) / sizeof(alumno_t));

/*=====[Definitions of private global variables]=============================*/

/*=====[Prototypes (declarations) of private functions]======================*/

/*=====[Implementations of public functions]=================================*/

/*=====[Implementations of interrupt functions]==============================*/

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
