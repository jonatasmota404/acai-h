cmake_minimum_required(VERSION 3.15)
project(acai_h C)

set(CMAKE_C_STANDARD 99)

add_executable(acai_h main.c despesas.h menu.h estoque.h funcionario.h fluxo-de-caixa.h estruturas-auxiliares-fx.h estruturas-auxiliares-st.h)