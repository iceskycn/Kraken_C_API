
CC=gcc 

DEBUG =y
TRACE =y

CFLAGS= -std=c1x -c -Wall -Wextra -Woverlength-strings -g -O0 -D_POSIX_C_SOURCE=200112L -D_GNU_SOURCE  


# PROGRAM DEBUG FUNCTIONS

ifeq ($(DEBUG),y)
  DEBFLAGS = -DAPI_DEBUG # "-O" is needed to expand inlines
  CFLAGS += $(DEBFLAGS)
endif

# PROGRAM TRACING FUNCTIONS

ifeq ($(TRACE),y)
  TRACEFLAGS = -DAPI_TRACE # "-O" is needed to expand inlines
  CFLAGS += $(TRACEFLAGS)

endif

DEFINES= -DPASSWORD='"$(PASSWORD)"'
# LIBS muss im lezten Schritt angehängt werden
LIBS = -L/usr/local/lib -L/usr/lib -L/usr/lib/x86_64-linux-gnu -lm -lssl -lcrypto

PASSWORD= '"Default"'

DEPS = logging.h kraken_api.h main_header.h curl.h url.h crypto.h kr_private_trading_functions.h kr_public_functions.h kr_private_user_functions.h 

OBJ = kraken_api.o main.o curl.o url.o crypto.o  kr_private_trading_functions.o kr_public_functions.o kr_private_user_functions.o

all: REST
	@echo "CFLAGS: $(CFLAGS)"
	@echo "Compiled with PASSWORD= $(PASSWORD)"

# PHONY !
REST: $(OBJ)
	$(CC) $(OBJ) $(LIBS) -o $@ 


%.o: %.c $(DEPS)
	$(CC) $(DEFINES) $(CFLAGS) -c -o $@ $<




