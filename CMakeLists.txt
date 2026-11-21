cmake_minimum_required(VERSION 4.0)
project(Study_Clion C)

set(CMAKE_C_STANDARD 99)

# Each source file has its own main and is run as a separate target.
# Build exercises on demand so unfinished functions do not block other targets.
function(add_exercise target source)
    add_executable(${target} EXCLUDE_FROM_ALL ${source})
    target_compile_options(${target} PRIVATE
        $<$<C_COMPILER_ID:GNU,Clang,AppleClang>:-Werror=return-type>
        $<$<C_COMPILER_ID:MSVC>:/we4716>)
endfunction()

# 01_loops: 循环与基础逻辑
add_executable(multiplication_table exercises/01_loops/9plus9.c)
add_exercise(armstrong_number exercises/01_loops/armstrong_number.c)
add_exercise(subtract_product_and_sum exercises/01_loops/1281_subtract_product_and_sum.c)
add_exercise(leap_year exercises/01_loops/leap_year.c)
add_exercise(palindrome_number exercises/01_loops/9_palindrome_number.c)
add_exercise(gcd_and_lcm exercises/01_loops/gcd_and_lcm.c)
add_exercise(fibonacci_number exercises/01_loops/509_fibonacci_number.c)

# 02_arrays: 数组
add_exercise(average_salary exercises/02_arrays/1491_average_salary.c)
add_exercise(reverse_array exercises/02_arrays/reverse_array.c)
add_exercise(second_largest exercises/02_arrays/second_largest.c)
add_exercise(concatenation_of_array exercises/02_arrays/1929_concatenation_of_array.c)
add_exercise(running_sum exercises/02_arrays/1480_running_sum.c)

# 03_strings: 字符串
add_exercise(count_chars exercises/03_strings/count_chars.c)
add_exercise(to_lower_case exercises/03_strings/709_to_lower_case.c)
add_exercise(caesar_cipher exercises/03_strings/caesar_cipher.c)
add_exercise(reverse_string exercises/03_strings/344_reverse_string.c)
add_exercise(valid_palindrome exercises/03_strings/125_valid_palindrome.c)
add_exercise(my_string_ops exercises/03_strings/my_string_ops.c)

# 04_pointers_structs: 指针与结构体
add_exercise(swap_and_sort3 exercises/04_pointers_structs/swap_and_sort3.c)
add_exercise(find_element exercises/04_pointers_structs/find_element.c)
add_exercise(fn_ptr_calculator exercises/04_pointers_structs/fn_ptr_calculator.c)
add_exercise(array_callback exercises/04_pointers_structs/array_callback.c)
add_exercise(positional_pid exercises/04_pointers_structs/positional_pid.c)
add_exercise(singly_linked_list exercises/04_pointers_structs/singly_linked_list.c)
