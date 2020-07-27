#include "pg_hex.h"


bool vaild_hex(const char *hex) {
    for (int i = 0; i < strlen(hex); i++) {
        if (!(('A' <= hex[i] && hex[i] <= 'F') || ('0' <= hex[i] && hex[i] <= '9'))) {
            return false;
        }
    }
    return true;
}

static void raise_error(int reason, const char *message) {
    ereport(ERROR, (errcode(reason), errmsg(message)));
}

static bool is_hex_string(char *input) {
    return true;
}

static void print(const char *message) {
    ereport(ERROR, (errcode(ERRCODE_INVALID_PARAMETER_VALUE), errmsg(message)));
}


Datum hex_in(PG_FUNCTION_ARGS) {
    char *input = PG_GETARG_CSTRING(0);
    if (!(vaild_hex(input))) { raise_error(1, "TypeError:invaild hex"); }
    char *ret = palloc(hex_size + 1);
    memset(ret, 0, hex_size + 1);
    memcpy(ret, input, hex_size);
    PG_RETURN_POINTER(ret);
}

Datum hex_out(PG_FUNCTION_ARGS) {
    char *recv = PG_GETARG_POINTER(0);
    char *ret = psprintf("%s", recv);
    PG_RETURN_CSTRING(ret);
}

Datum hex_recv(PG_FUNCTION_ARGS) {
    StringInfo buf = (StringInfo) PG_GETARG_POINTER(0);
    char *result = palloc(hex_size);
    pq_copymsgbytes(buf, result, hex_size);
    PG_RETURN_POINTER(result);
}

Datum hex_send(PG_FUNCTION_ARGS) {
    char *h = PG_GETARG_POINTER(0);
    StringInfoData buf;
    pq_sendbytes(&buf, h, hex_size);
    PG_RETURN_BYTEA_P(pq_endtypsend(&buf));
}




