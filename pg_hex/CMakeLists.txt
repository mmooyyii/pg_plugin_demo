set(hex_src
        pg_hex.c)
add_executable(hex ${hex_src})
include_directories(/usr/local/Cellar/postgresql/12.2/include/postgresql/server)

