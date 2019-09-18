add_executable(ItemTest.o ItemTest.c)
target_link_libraries(ItemTest.o PRIVATE DataStructures)

add_test(itemTester ItemTest.o)