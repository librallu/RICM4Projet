#ifndef __CALLER__
#define __CALLER__

#ifdef __cplusplus
EXTERN "C"{
#endif	
	
	struct connection_info_t {
		char* ssid;
		char* pass;
	}connection_info;
	
	volatile int i=0;
	const char* ssid ="ssid";
	const char* pass ="42";
	
	enum typeRes{WACC,WDEN,NONE}
	enum typeParam{WCON,WID,PRT}
	
	typeRes probe(typeParam type,void* param,void* result);	
	
#ifdef __cplusplus
}
#endif	
