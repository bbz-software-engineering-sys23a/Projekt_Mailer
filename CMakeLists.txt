cmake_minimum_required(VERSION 3.28.1)
project(Projekt_Mailer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")


add_executable(Projekt_Mailer
        main.cpp
        Mitglieder.cpp
        Aktiv.cpp
        Passiv.cpp
        Ehrenmitglied.cpp
        Texte.h
)
