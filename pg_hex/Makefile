EXTENSION = pg_hex
MODULES = pg_hex

MODULE_big = pg_hex
OBJS = pg_hex.o

PG_CONFIG = pg_config

DATA = $(wildcard *--*.sql)
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)