rm pg_hex.o
rm pg_hex.so
make install
psql -c "drop extension pg_hex;"
psql -c "create extension pg_hex;"
psql -c "select 'AFFF'::hex;"