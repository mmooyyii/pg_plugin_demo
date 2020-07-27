#include <stdio.h>
#include "postgres.h"
#include "fmgr.h"
#include "utils/builtins.h"
#include "lib/stringinfo.h"
#include <string.h>
#include "utils/errcodes.h"
#include "libpq/pqformat.h"
#include <unistd.h>
#include <math.h>

#define hex_size  8

PG_MODULE_MAGIC;

Datum hex_in(PG_FUNCTION_ARGS);

PG_FUNCTION_INFO_V1(hex_in);

Datum hex_out(PG_FUNCTION_ARGS);

PG_FUNCTION_INFO_V1(hex_out);

Datum hex_send(PG_FUNCTION_ARGS);

PG_FUNCTION_INFO_V1(hex_send);

Datum hex_recv(PG_FUNCTION_ARGS);

PG_FUNCTION_INFO_V1(hex_recv);


bool vaild_hex(const char *hex);