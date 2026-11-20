cmake_minimum_required(VERSION 4.0)
project(Study_Clion C)

set(CMAKE_C_STANDARD 99)

# Each source file has its own main and is run as a separate target.
add_executable(multiplication_table exercises/basics/9plus9.c)

# Build exercises on demand so unfinished functions do not block other targets.
function(add_exercise target source)
    add_executable(${target} EXCLUDE_FROM_ALL ${source})
    target_compile_options(${target} PRIVATE
        $<$<C_COMPILER_ID:GNU,Clang,AppleClang>:-Werror=return-type>
        $<$<C_COMPILER_ID:MSVC>:/we4716>)
endfunction()

add_exercise(subtract_product_and_sum exercises/leetcode/1281_subtract_product_and_sum.c)
add_exercise(average_salary exercises/leetcode/1491_average_salary.c)
add_exercise(armstrong_number exercises/basics/armstrong_number.c)
add_exercise(fibonacci_number exercises/leetcode/509_fibonacci_number.c)
