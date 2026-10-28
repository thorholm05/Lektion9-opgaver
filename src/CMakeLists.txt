# Biblioteker til opgaverne
add_library(plural_lib plural.c)
add_library(strrev_lib strrev.c)

# Hovedprogrammer til opgaverne.
add_executable(opgave-a opgave-a.c)
target_link_libraries(opgave-a PRIVATE plural_lib)

add_executable(opgave-b opgave-b.c)
target_link_libraries(opgave-b PRIVATE strrev_lib)

add_executable(opgave-c opgave-c.c)
add_executable(opgave-d opgave-d.c)
add_executable(opgave-e opgave-e.c)
add_executable(opgave-f opgave-f.c)
add_executable(opgave-g opgave-g.c)

# Separate testprogrammer til CTest.
add_executable(test_plural test_plural.c)
target_link_libraries(test_plural PRIVATE plural_lib)
add_test(NAME PluralTest COMMAND test_plural)

add_executable(test_strrev test_strrev.c)
target_link_libraries(test_strrev PRIVATE strrev_lib)
add_test(NAME StrrevTest COMMAND test_strrev)
