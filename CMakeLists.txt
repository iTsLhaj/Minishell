cmake_minimum_required(VERSION 3.22)
project(minishell C)

include_directories(include)
add_subdirectory(lib/libft)

set(CMAKE_C_STANDARD 11)

add_executable(minishell src/parser_main.c
        src/environment/init_env.c
        src/environment/env_getter.c
        src/tokenization/lexer_utils.c
        src/tokenization/token_handlers.c
        src/tokenization/tokenize.c
        src/utils/lexer_cleaning_utils.c
        src/environment/clear_env.c
        src/parser/parser.c
        src/utils/counting_utils.c
        src/parser/parsing_utils.c
        src/utils/other_tools.c
        src/parser/parsing_quotes.c
        src/errors/custom_errors.c
        src/expander/expander.c
        src/expander/unquote.c
        src/parser/clean_commands.c
        src/builtings/builtings.c
        src/builtings/cd.c
        src/builtings/check_path.c
        src/builtings/echo.c
        src/builtings/check_pipe.c
        src/builtings/env.c
        src/builtings/env_to_list.c
        src/builtings/exit.c
        src/builtings/export.c
        src/builtings/export.c
        src/builtings/here_doc.c
        src/builtings/pipex.c
        src/builtings/pwd.c
        src/builtings/red_in.c
        src/builtings/red_out.c
        src/builtings/unset.c
        src/builtings/other.c
        src/builtings/append_red.c)

target_link_libraries(minishell libft)
target_link_libraries(minishell readline)
