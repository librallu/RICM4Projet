#include "caller.h"


int main (){
	void* result;
	void* param;
	typeRes typeR;
	typeParam typeP;
	(connection_info*)param->ssid = "ssid";
	(connection_info*)param->pass = "42";
	switch(probe (WCON, param, result)){
		case WACC | WDEN:
			fprintf(stderr, (char*) result);
			break;
		default:
			fprintf(stderr,"not implemented signal");
			break;
	}	
}
