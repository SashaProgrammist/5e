cmake_minimum_required(VERSION 3.16)
project(project C)

set(CMAKE_C_STANDARD 11)

# определение точки входа. Будет запущен файл main . c .
# указывается произвольная метка, в данном случае - project
add_executable(project main.c)

# создаём библиотеку
add_library(str string/string_.h string/string_.c
        string/test/test.h string/test/test.c
        string/tasks/removeNonLetters.c
        string/tasks/removeAdjacentEqualLetters.c
        string/tasks/forWordInString.c
        string/tasks/digitForSpaces.c
        string/tasks/replace.c
        string/tasks/isOrderedString.c
        string/tasks/outputWordForReversOrdered.c
        string/tasks/getCountPalindromes.c)

# описываем, что для запуска project потребуется сборка tasks
target_link_libraries(project str)
