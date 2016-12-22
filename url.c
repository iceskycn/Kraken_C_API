#include "url.h"


/* create the standard query uri's */

int make_url(struct kraken_api **kr_data){
	
	const char* domain = "https://api.kraken.com";
	const char* api_version = "/0";
	const char* api_private = "/private";
	const char* api_public = "/public";
	/* PRIVATE USER TRADING */
	const char* api_add_order = "/AddOrder";
	const char* api_cancel_order = "/CancelOrder";
	/* PRIVATE USER DATA */
	const char* api_balance = "/Balance";
	const char* api_trade_balance = "/TradeBalance";
	const char* api_open_orders = "/OpenOrders";
	const char* api_closed_orders = "/ClosedOrders";
	const char* api_query_orders = "/QueryOrders";
	const char* api_trades_history = "/TradesHistory";
	const char* api_query_trades_info = "/QueryTrades";
	const char* api_open_positions = "/OpenPositions";
	const char* api_ledgers_info = "/Ledgers";
	const char* api_query_ledgers = "/QueryLedgers";
	const char* api_trade_volume = "/TradeVolume";

	/* s_url contains just the domain */

	(*kr_data)->s_url = strdup(domain); 

	/* s_uri_path contains the way to the private uri */
	/* add api version to the string */
	(*kr_data)->s_uri_private = strdup(api_version);
	/* add private method to the string */
	(*kr_data)->s_uri_private = to_url((*kr_data)->s_uri_private, api_private);

	/* same procedure for the public part */
	/* copy apy-version to the string */
	(*kr_data)->s_uri_public = strdup(api_version);
	/* add public method to the string */
	(*kr_data)->s_uri_public = to_url((*kr_data)->s_uri_public, api_public);

	/* ### PRIVATE USER TRADING ### */

	/* ADD_ORDER */
	(*kr_data)->s_uri_addorder = strdup(api_add_order);

	/* CANCEL ORDER */
	(*kr_data)->s_uri_cancel_order = strdup(api_cancel_order);

	/* ### PRIVATE USER DATA */

	/* BALANCE */		
	(*kr_data)->s_uri_balance = strdup(api_balance);

	/* TRADE BALANCE */
	(*kr_data)->s_uri_trade_balance = strdup(api_trade_balance);

	/* OPEN ORDERS */
	(*kr_data)->s_uri_open_orders = strdup(api_open_orders);

	/* CLOSED ORDERS */
	(*kr_data)->s_uri_closed_orders = strdup(api_closed_orders);

	/* QUERY ORDERS */
	(*kr_data)->s_uri_query_orders = strdup(api_query_orders);

	/* TRADES HISTORY */
	(*kr_data)->s_uri_trades_history = strdup(api_trades_history);

	/* QUERY TRADES INFO */
	(*kr_data)->s_uri_query_trades_info = strdup(api_query_trades_info);

	/* OPEN POSITIONS */
	(*kr_data)->s_uri_open_positions = strdup(api_open_positions);

	/* LEDGERS INFO */
	(*kr_data)->s_uri_ledgers_info = strdup(api_ledgers_info);

	/* QUERY LEDGERS */
	(*kr_data)->s_uri_query_ledgers = strdup(api_query_ledgers);

	/* TRADE VOLUME */
	(*kr_data)->s_uri_trade_volume = strdup(api_trade_volume);


	PTRACE("s_url: %s", (*kr_data)->s_url);
	PTRACE("s_uri_private: %s", (*kr_data)->s_uri_private);
	PTRACE("s_uri_public: %s", (*kr_data)->s_uri_public);
	PTRACE("s_uri_addorder: %s", (*kr_data)->s_uri_addorder);


	return 0;
}

char *to_url(char* dest, const char *source){

	char* ptr = NULL;

	if((asprintf(&ptr, "%s%s", dest, source)) < 0){
		PDEBUG("ERROR");
		return NULL;
	}

	free(dest);

	return ptr;

}
