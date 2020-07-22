CREATE FUNCTION hello_world_c() RETURNS text
AS
'$libdir/hello_world_c'
    LANGUAGE C IMMUTABLE
               STRICT;