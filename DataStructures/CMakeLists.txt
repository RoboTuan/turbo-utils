add_library(
    DataStructures
    #Item
    Item/item.c
    Item/item.h
)

target_include_directories(DataStructures PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Item")