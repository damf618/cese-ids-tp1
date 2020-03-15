/*=====[Module Name]===========================================================
 * Copyright 2019 Esteban Daniel VOLENTINI <evolentini@gmail.com>
 * All rights reserved.
 * License: BSD-3-Clause <https://opensource.org/licenses/BSD-3-Clause>)
 *
 * Version: 0.1.0
 * Creation Date: 2019/03/01
 */

/*=====[Avoid multiple inclusion - begin]====================================*/

//Intento de Documentacion mas copleta

/**
 *@file  alumnos.h
 *@version 1.0
 *@brief Introduccion al archivo alumnos.h, trabajo:TP1 y practica de Documentacion de TP1 IS  CESE11 
 */

#ifndef _ALUMNOS_H_
#define _ALUMNOS_H_

/*=====[Inclusions of public function dependencies]==========================*/

#include <stdbool.h>
#include <stddef.h>

/*=====[C++ - begin]=========================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*=====[Definition macros of public constants]===============================*/

/*=====[Public function-like macros]=========================================*/

/*=====[Definitions of public data types]====================================*/

/// Estructura de Alumno.  
///
/// Elemento utilizado para el almacenamiento de informacion correspondiente a Daniel
/// @param apellidos elemento para almacenar los *apellidos* del Alumno a crear
/// @param nombres elemento para almacenar los *nombres* del Alumno a crear
/// @param documento elemento para almacenar el *documento* del Alumno a crear
/// @note Se debe tener en consideracion la longitud maxima de cada variable para evitar errores.

typedef struct alumno_s {
    char apellidos[30];
    char nombres[30];
    char documento[11];
} const * alumno_t;

/*=====[Definitions of public global variables]==============================*/

extern const alumno_t ALUMNOS[];

extern const int CANTIDAD_ALUMNOS;

/*=====[Prototypes (declarations) of public functions]=======================*/

/// Funcion de Impresion Individual.  
///
/// Funcion para la impresion de los datos almacenados en la estructura Alumno con el formato requerido.
/// @param cadena almacena la cadenade texto a imprimir
/// @param espacio nro de caracteres a imprimir
/// @param alumno elemento donde se almacena la informacion del Alumno a imprimir.
/// @note requiere que los datos del alumno se almacenan en la estructura Alumno.
/// @see SerializarAlumnos

bool SerializarAlumno(char * cadena, size_t espacio, const alumno_t alumno);

/// Funcion de Impresion Grupal.  
///
/// Funcion para la impresion de los datos de un grupo de Alumnos,con el formato requerido.
/// @param cadena almacena la cadenade texto a imprimir
/// @param espacio nro de caracteres a imprimir
/// @param alumnos arreglo conformado por los Alumno cuyosdatossedesean imprimir.
/// @note requiere que los datos de los alumnos se almacenan en la estructura Alumno.
/// @see SerializarAlumno

bool SerializarAlumnos(char * cadena, size_t espacio, const alumno_t alumnos[], int cantidad);

/*=====[Prototypes (declarations) of public interrupt functions]=============*/

/*=====[C++ - end]===========================================================*/

#ifdef __cplusplus
}
#endif

/*=====[Avoid multiple inclusion - end]======================================*/

#endif /* _ALUMNOS_H_ */
