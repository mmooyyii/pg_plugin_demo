#include "postgres.h"
#include "fmgr.h"
#include "utils/builtins.h"

PG_MODULE_MAGIC;

PG_FUNCTION_INFO_V1(hello_world_c);

Datum hello_world_c(PG_FUNCTION_ARGS) {
    PG_RETURN_TEXT_P(cstring_to_text("Hello, world!"));
}
