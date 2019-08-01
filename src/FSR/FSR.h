#ifndef FSR_H
#define FSR_H

#include <string.h>
#include "Arduino.h"

#define FSR_DEFAULTPIN A0

using namespace std;

typedef enum { // < al valor, ej, < 10 es SIN PRESION.
	
	NO_PRESSURE_LIM		=	10,
	LIGHT_TOUCH_LIM		=	200,
	LIGHT_SQUEEZE_LIM	=	500,
	MEDIUM_SQUEEZE_LIM	=	800	// BIG_SQUEEZE es superior a 800 en este esquema.
	
} e_def_readings_limits;
 
// Responsabilidad de quien use sus limites que cada limite sea inferior al siguiente
typedef struct {
	
	int	no_pressure_lim,
		light_touch_lim,
		light_squeeze_lim,
		medium_squeeze_lim;	// Habra big_squeeze si se supera este valor
	
} t_reading_limits;

typedef struct {
	
	int 	reading;
	String	pressure_applied; // Texto para mostrar
	
} t_result;

class FSR {
	
	public:
		static t_result* read_and_eval(int , t_reading_limits* , t_result* );	// Una lectura del FSR y evaluacion segun lecturas

};

#endif // FSR_H
