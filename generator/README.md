# Informationen

Die idee ist mit cmake ein C++ Projekt anlegen zu lassen. Dafür gibt es die
Datei CMakeLists.txt mit dem folgenden Inhalt:

    cmake_minimum_required(VERSION 3.16.4)
    
    project(generator)
    
    set(PROJECT       project)
    set(LIB_CLASS     Generator)
    set(LIB_CLASS_DEF GENERATOR)
    set(LIB_NAME      genlib)
    set(LIB_NAMESPACE gen)
    set(CCSD          \${CMAKE_CURRENT_SOURCE_DIR})
    
    configure_file(resources/CMakeListsRoot.txt.in ${PROJECT}/CMakeLists.txt)
    configure_file(resources/CMakeListsSrc.txt.in  ${PROJECT}/src/CMakeLists.txt)
    configure_file(resources/main.cpp.in           ${PROJECT}/src/main.cpp)
    configure_file(resources/CMakeListsLib.txt.in  ${PROJECT}/lib/CMakeLists.txt)
    configure_file(resources/lib.cpp.in            ${PROJECT}/lib/${LIB_CLASS}.cpp)
    configure_file(resources/lib.h.in              ${PROJECT}/lib/${LIB_CLASS}.h)
    configure_file(resources/CMakeListsTest.txt.in ${PROJECT}/test/CMakeLists.txt)
    configure_file(resources/test.cpp.in           ${PROJECT}/test/test${LIB_CLASS}.cpp)

Es sind zwei größere Abschnitte zu erkennen. In dem ersten Abschnitt werden die
parameter festgelegt, mit der die in dem zweiten Abschnitt die Dateien erzeugt
werden sollen.

| Parameter     | Beschreibung                                  |
| ------------- |-----------------------------------------------|
| PROJECT       | Das Verzeichnis des Projektes                 |
| LIB_CLASS     | Dateiname und Klassenname in einer Bibliothek |
| LIB_CLASS_DEF | Name der Definition in der Header-Datei       |
| LIB_NAME      | Name der Bibliothek (lib)                     |
| LIB_NAMESPACE | Namensraum der Klasse                         |
| CCSD          | Für die Bewahrung der Variable                |

# Ausführung der Erstellung eines C++ Projektes.

Um ein Projekt von cmake erstellen zu lassen müssen folgende Schritte
ausgefühert werden:

    mkdir build
    cd build
    cmake ..

Wie in der Welt von cmake üblich ist, wird ein build Verzeichnis erstell,
in dieses Verzeichnis gewechselt und dann von dort der Aufruf des cmake
Programms ausgeführt. Wenn diese Schritte ausgeführt wurden, ensteht
die folgende Struktur:

    project
    ├── CMakeLists.txt
    ├── lib
    │   ├── CMakeLists.txt
    │   ├── Generator.cpp
    │   └── Generator.h
    ├── src
    │   ├── CMakeLists.txt
    │   └── main.cpp
    └── test
        ├── CMakeLists.txt
        └── testGenerator.cpp

Hier sind schon einige Parameter zu erkennen. Der Name des Wurzelverzeiches kommt von
PROJECT. Der Name der C++-Dateien in dem Verzeichnis lib, kommt von LIB_CLASS. Der
Name der Test-Datei kommt ebenfalls von LIB_CLASS.

# Kompilierten und Testfälle ausführen

Num kann man in das erzeuge Porjekt (project) wecheln und ebnfalls die Befehle
ausführen

    mkdir build
    cd build
    cmake ..
    make

Nach dem Ausführen des Befehls make sind verschiedene Dateien
kompiliert. Hier der wesendliche Teil des kompilierten Projetes:

    .
    ├── lib
    │   ├── libgenlib.a
    │   └── Makefile
    ├── Makefile
    ├── src
    │   ├── Makefile
    │   └── prog
    └── test
        ├── Makefile
        └── testGenerator

Die von cmake erstellen Verzeichnisse sind ausgelassen worden.
Es ist folgendes zu erkennen:

- eine Bibliothek mit dem Namen libgenlib.a in dem Verzeichnis lib erstellt wurde.
- eine ausführbare Datei prog in dem Verzeichnis src erstellt wurde.
- eine ausführbare Datei testGenerator in dem Verzeichnis test erstellt wurde.

Um die Testfälle ausfürehn zu lassen recht der Aufruf

    ctest

Ist alles gut gelaufen, sieht der Testfall so aus

    Test project /home/saj/dev/cpp/bla/build/project/build
        Start 1: test
    1/1 Test #1: test .............................   Passed    0.00 sec
