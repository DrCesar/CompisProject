cmake_minimum_required(VERSION 3.8)
project(ProyectoCompis)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp ConvertPostfix.cpp ConvertPostfix.h SyntacticTree.cpp SyntacticTree.h Node.cpp Node.h Automaton.cpp Automaton.h DState.cpp DState.h SyntaxValidator.cpp SyntaxValidator.h PredictiveParser.cpp PredictiveParser.h Production.cpp Production.h)
add_executable(ProyectoCompis ${SOURCE_FILES})