#include "caller.h"

int unpack_con(connection_info param, char* result){
	if (! (strcmp(param->ssid, ssid) || strcmp(param->pass,pass)){
		result = "access granted";
		return 0;
	} else {
		result = "access denied";
		return 1;
	}
}


typeRes probe (typeParam type, void* param, void* result){
	switch (type){
		case WCON:
			if (!unpack_con((connection_info)* param, (char*) result) ){
				return WACC;
			} else {
				return WDEN;
			}
		case WID:
			break;
		case NONE:
			break;
			
	}
		
}
