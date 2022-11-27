# See the build system documentation in IDF programming guide
# for more information about component CMakeLists.txt files.

set(srcs "main.c"
"../component/ps3/src/Ps3Controller.cpp"
"../component/ps3/src/esp32-hal-bt.c"
"../component/ps3/src/ps3_l2cap.c"
"../component/ps3/src/ps3_parser.c"
"../component/ps3/src/ps3_spp.c"
"../component/ps3/src/ps3.c"
)

idf_component_register(
    SRCS "${srcs}"
    INCLUDE_DIRS "../component/ps3/src/include"
    PRIV_INCLUDE_DIRS   # optional, add here private include directories
    REQUIRES
    PRIV_REQUIRES       # optional, list the private requirements
)
