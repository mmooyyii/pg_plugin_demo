CREATE TYPE hex;

CREATE OR REPLACE FUNCTION hex_in(cstring)
    RETURNS hex
AS
'pg_hex'
    LANGUAGE C STRICT
               IMMUTABLE
               PARALLEL SAFE;

CREATE OR REPLACE FUNCTION hex_out(hex)
    RETURNS cstring
AS
'pg_hex'
    LANGUAGE C STRICT
               IMMUTABLE
               PARALLEL SAFE;

CREATE OR REPLACE FUNCTION hex_recv(internal)
    RETURNS hex
AS
'pg_hex'
    LANGUAGE C STRICT
               IMMUTABLE
               PARALLEL SAFE;

CREATE OR REPLACE FUNCTION hex_send(hex)
    RETURNS bytea
AS
'MODULE_PATHNAME',
'hex_send'
    LANGUAGE C STRICT
               IMMUTABLE
               PARALLEL SAFE;

CREATE TYPE hex
(
    INTERNALLENGTH = 1,
    INPUT = hex_in,
    OUTPUT = hex_out,
    receive = hex_recv,
    send = hex_send,
    STORAGE = plain,
    alignment = char
);
