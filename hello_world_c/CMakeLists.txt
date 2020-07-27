set(hello_world_c_src
        hello_world_c.c)
add_executable(hello_world_c ${hello_world_c_src})
include_directories(/usr/local/Cellar/postgresql/12.2/include/postgresql/server)

