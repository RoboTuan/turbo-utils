add_executable(ItemTest ItemTest.c)
target_link_libraries(ItemTest PRIVATE DataStructures)

add_test(itemTester ItemTest)