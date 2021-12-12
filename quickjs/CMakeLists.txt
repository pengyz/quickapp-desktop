add_library(quickjs
    ${CMAKE_SOURCE_DIR}/deps/quickjs/quickjs.h
    ${CMAKE_SOURCE_DIR}/deps/quickjs/quickjs.c
    ${CMAKE_SOURCE_DIR}/deps/quickjs/quickjs-debugger.h
    ${CMAKE_SOURCE_DIR}/deps/quickjs/quickjs-debugger.c
    ${CMAKE_SOURCE_DIR}/deps/quickjs/quickjs-debugger-transport-unix.c
    # ${CMAKE_SOURCE_DIR}/deps/quickjs/quickjs-libc.h
    # ${CMAKE_SOURCE_DIR}/deps/quickjs/quickjs-libc.c
    ${CMAKE_SOURCE_DIR}/deps/quickjs/quickjs-atom.h
    ${CMAKE_SOURCE_DIR}/deps/quickjs/quickjs-opcode.h
)
# read version from VERSION file and define as CONFIG_VERSION
file(READ "${CMAKE_SOURCE_DIR}/deps/quickjs/VERSION" VERSION_STRING)
string(STRIP ${VERSION_STRING} VERSION_STRING)
target_compile_definitions(quickjs PRIVATE
    CONFIG_VERSION="${VERSION_STRING}"
)

target_include_directories(quickjs INTERFACE
    ${CMAKE_SOURCE_DIR}/deps
)