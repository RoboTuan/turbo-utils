add_library(
    DataStructures
    #Item
    Item/item.c
    Item/item.h
    #Lists
    Lists/linkedList.c
    Lists/linkedList.h
)

target_include_directories(DataStructures PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Item")
target_include_directories(DataStructures PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Lists")