cmake_minimum_required(VERSION 3.2)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})


# имя проекта
project(matrix VERSION ${PROJECT_VESRION})



# используем gtest
find_package(GTest REQUIRED)



# имя основной утилиты будет таким же как и имя проекта?
add_executable(matrix_test
  main.cpp 
  work_obj.cpp)

set_target_properties(matrix_test 
  PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(matrix_test
  PRIVATE 
    #${PROJECT_SOURCE_DIR}/./
    ${PROJECT_SOURCE_DIR}/../gtest/include/
)


target_link_libraries(matrix_test
    ${GTEST_LIBRARIES} 
    ${CMAKE_THREAD_LIBS_INIT}
)


if (MSVC)
    target_compile_options(matrix_test PRIVATE
        /W4
    )
else ()
    target_compile_options(matrix_test PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()


# регистрируем тест:
add_test("simple unit test for matrix" matrix_test)

