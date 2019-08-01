#include "FSR.h"


t_result* FSR::read_and_eval(int analogPin, t_reading_limits* rLim, t_result* evalRes ){
	
	if ( analogPin == 0 ) // Si no indica un PIN uso el que este definido en el .h como default
		evalRes->reading = analogRead(FSR_DEFAULTPIN);
	else
		evalRes->reading = analogRead(analogPin);

	if ( rLim == NULL ){
		
		if ( evalRes->reading < NO_PRESSURE_LIM ){
			evalRes->pressure_applied = "No Pressure";
		}	else if ( evalRes->reading < LIGHT_TOUCH_LIM ){
			evalRes->pressure_applied = "Light touch";
		}	else if ( evalRes->reading < LIGHT_SQUEEZE_LIM ){
			evalRes->pressure_applied = "Light squeeze";
		}	else if ( evalRes->reading < MEDIUM_SQUEEZE_LIM ){
			evalRes->pressure_applied = "Medium squeeze";
		}	else {
			evalRes->pressure_applied = "Big squeeze";
		}
			
	}
	else{

		if ( evalRes->reading < rLim->no_pressure_lim ){
			evalRes->pressure_applied = "No Pressure";
		}	else if ( evalRes->reading < rLim->light_touch_lim ){
			evalRes->pressure_applied = "Light touch";
		}	else if ( evalRes->reading < rLim->light_squeeze_lim ){
			evalRes->pressure_applied = "Light squeeze";
		}	else if ( evalRes->reading < rLim->medium_squeeze_lim ){
			evalRes->pressure_applied = "Medium squeeze";
		}	else {
			evalRes->pressure_applied = "Big squeeze";
		}
		
	}
	
	return evalRes;

}