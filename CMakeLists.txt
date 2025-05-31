cmake_minimum_required(VERSION 3.10)  # Versão mínima do CMake

# Nome do projeto e a versão
project(MeuProjeto VERSION 1.0)

# Defina os diretórios onde os headers estão
include_directories(${CMAKE_SOURCE_DIR}/include)

# Adicionar todos os arquivos de código fonte da pasta src, de forma recursiva
file(GLOB_RECURSE SRC_FILES ${CMAKE_SOURCE_DIR}/src/**.cpp)

# Adiciona o arquivo main.cpp fora da pasta src
list(APPEND SRC_FILES ${CMAKE_SOURCE_DIR}/main.cpp)

# Definir o diretório onde o executável será gerado
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/)  # Diretório fora de build

# Criar o executável com os arquivos fonte
add_executable(main ${SRC_FILES})

# Se você estiver usando um compilador específico ou precisar de flags extras, pode adicionar como:
# target_compile_options(MeuProjeto PRIVATE -Wall -std=c++17)

# Links com bibliotecas adicionais (se houver)
# target_link_libraries(MeuProjeto PRIVATE alguma_biblioteca)
