cmake_minimum_required(VERSION 3.8)
project(ProyectoCompis)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Automaton/ConvertPostfix.cpp Automaton/ConvertPostfix.h Automaton/SyntacticTree.cpp Automaton/SyntacticTree.h Automaton/Node.cpp Automaton/Node.h Automaton/Automaton.cpp Automaton/Automaton.h Automaton/DState.cpp Automaton/DState.h LexerScanner.cpp LexerScanner.h Parser/SLR.cpp Parser/SLR.h Parser/Production.cpp Parser/Production.h Parser/KernelItem.cpp Parser/KernelItem.h Parser/Symbol.cpp Parser/Symbol.h Parser/Node.cpp Parser/Node.h Parser/State.cpp Parser/State.h Parser/AutomatonP.cpp Parser/AutomatonP.h)
add_executable(ProyectoCompis ${SOURCE_FILES})