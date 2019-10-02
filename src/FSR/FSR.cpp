#include "FSR.h"

/**		get_reading
		Definicion: Obtener una lectura de "fuerza" del FSR.
		
		Parametros:	
						analogPing 	-> 	Pin que se utilizara para realizar la lectura. 
										- DEFAULT: Si es 0 se utiliza FSR_DEFAULTPIN (ver FSR.h).
						res			->	Estructura t_result en la que se almacena la lectura obtenida (en reading).
											
		Retorno:
						t_result* 	->	Direccion de la estructura t_result que llega por parametro.
										Si res es NULL, devuelve NULL.

*/
t_result* FSR::get_reading(int analogPin, t_result* res){
	
	if ( res == NULL )
		return NULL;
	
	if ( analogPin == 0 ) // Si no indica un PIN uso el que este definido en el .h como default
		res->reading = analogRead(FSR_DEFAULTPIN);
	else
		res->reading = analogRead(analogPin);
	
	return res;
	
}

/**		eval_reading
		Definicion: Evaluar una lectura segun los limites de lectura suministrados.
		
		Parametros:	
						rLim		->	Estructura con los valores correspondientes a cada limite.
										- DEFAULT: Si es NULL, se utiliza la enumeracion e_def_readings_limits (ver FSR.h).
						res			->	Estructura t_result en la que se almacena el resultado 
											de la evaluacion (en pressure_applied).
											
		Retorno:
						t_result* 	->	Direccion de la estructura t_result que llega por parametro.
										Si res es NULL, devuelve NULL.

*/
t_result* FSR::eval_reading(t_reading_limits* rLim, t_result* res){
	
	if ( res == NULL )
		return NULL;
	
	if ( rLim == NULL ){
		
		if ( res->reading < NO_PRESSURE_LIM ){
			res->pressure_applied = "No Pressure";
		}	else if ( res->reading < LIGHT_TOUCH_LIM ){
			res->pressure_applied = "Light touch";
		}	else if ( res->reading < LIGHT_SQUEEZE_LIM ){
			res->pressure_applied = "Light squeeze";
		}	else if ( res->reading < MEDIUM_SQUEEZE_LIM ){
			res->pressure_applied = "Medium squeeze";
		}	else {
			res->pressure_applied = "Big squeeze";
		}
			
	}
	else{

		if ( res->reading < rLim->no_pressure_lim ){
			res->pressure_applied = "No Pressure";
		}	else if ( res->reading < rLim->light_touch_lim ){
			res->pressure_applied = "Light touch";
		}	else if ( res->reading < rLim->light_squeeze_lim ){
			res->pressure_applied = "Light squeeze";
		}	else if ( res->reading < rLim->medium_squeeze_lim ){
			res->pressure_applied = "Medium squeeze";
		}	else {
			res->pressure_applied = "Big squeeze";
		}
		
	}
	
	return res;
	
}

/**		read_and_eval 
		Definicion: Obtener una lectura de "fuerza" del FSR y evaluar segun los limites de lectura suministrados.
		
		Parametros:	
						analogPing 	-> 	Pin que se utilizara para realizar la lectura. 
										- DEFAULT: Si es 0 se utiliza FSR_DEFAULTPIN (ver FSR.h).
						rLim		->	Estructura con los valores correspondientes a cada limite.
										- DEFAULT: Si es NULL, se utiliza la enumeracion e_def_readings_limits (ver FSR.h).
						res			->	Estructura t_result en la que se almacena la lectura obtenida (en reading)
											y el resultado de la evaluacion (en pressure_applied).
											
		Retorno:
						t_result* 	->	Direccion de la estructura t_result que llega por parametro.
										Si res es NULL, devuelve NULL.

*/
t_result* FSR::read_and_eval(int analogPin, t_reading_limits* rLim, t_result* res ){
	
	if ( FSR::get_reading(analogPin, res) == NULL )
		return NULL;
	
	FSR::eval_reading(rLim, res);
	
	return res;

}

