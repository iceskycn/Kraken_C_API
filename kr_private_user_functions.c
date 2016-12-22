#include "kr_private_user_functions.h"


int account_balance(struct kraken_api **kr_api){

	/* create the temporary url for this type of api call */
	if(((*kr_api)->tmp_query_url = strdup((*kr_api)->s_uri_private)) == NULL){
		PDEBUG("ERROR on strdup");
		exit(-1);
	}

	
	(*kr_api)->tmp_query_url = to_url((*kr_api)->tmp_query_url, (*kr_api)->s_uri_balance);

	PTRACE("Query URL: %s", (*kr_api)->tmp_query_url);

	query_private(kr_api);

	return 0;
}


int trade_balance(struct kraken_api **kr_api, ...){

	const char* url_aclass = "aclass=";
	const char *var_arg = NULL;
	va_list ap;

	va_start(ap, kr_api);

	/* create the temporary url for this type of api call */
	if(((*kr_api)->tmp_query_url = strdup((*kr_api)->s_uri_private)) == NULL){
		PDEBUG("ERROR on strdup");
		exit(-1);
	}
	
	(*kr_api)->tmp_query_url = to_url((*kr_api)->tmp_query_url, (*kr_api)->s_uri_balance);

	PTRACE("Query URL: %s", (*kr_api)->tmp_query_url);
	
	if((strlen(var_arg = va_arg(ap, char*))) == 0){

		PTRACE("No Argument");
	}else{
		PTRACE("Argument = %s", var_arg);
		(*kr_api)->s_data = strdup(url_aclass);
	}


	va_end(ap);

	return 0;
}