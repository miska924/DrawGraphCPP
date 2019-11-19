IF THERE IS NO OPENGL YOU HAVE TO INSTALL IT:
    for ubuntu:
        sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev

g++ solution.cpp -o draw --std=c++17 -O2 -lGL -lglut
g++ test.cpp -o mktest --std=c++17 -O2

To <RUN> the Program you need to use terminal:
        ./draw
    After that enter number of parallel processes you need
    And finally enter name of test you want to see
    
To make <NEW TEST> you need to use terminal:
        ./mktest
    After that you need to give your graph in this format:
        first number is N - number of vertexes
        second number if M - numper of edges
        next M lines includes edges(pairs of vertexes)
            (numeration of vertexes begins with 1 and ends with N)

WARNING:
    Your graph need to be connected.
    If it is not this program does not work correctly.
    Sorry about that, it's just first version.
