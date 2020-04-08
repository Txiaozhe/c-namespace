cmake_minimum_required(VERSION 3.6)
project(jerry_run_js C)

include_directories(/Users/tangxiaoji/GitHub/jerry/example_install/include)
include_directories(/Users/tangxiaoji/GitHub/jerry/jerryscript/jerry-core/include)
# include_directories(/Users/tangxiaoji/GitHub/jerry/jerryscript/jerry-core/jcontext)
include_directories(/Users/tangxiaoji/GitHub/jerry/jerryscript/jerry-ext/include)
include_directories(/Users/tangxiaoji/GitHub/jerry/jerryscript/jerry-port/default/include)

# link_directories(
#   /Users/tangxiaoji/GitHub/jerry/example_install/lib)

add_executable(jerry_run_js main.c)
