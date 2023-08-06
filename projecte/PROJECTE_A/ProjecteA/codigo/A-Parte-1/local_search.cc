#include "practica.hh"

int main(){
    Graph graph {{2}, {1, 3, 4, 5}, {2}, {2, 5}, {2, 5}};
    Pids pids {true, true, true, true, false};
    Practica h {graph};
    h.search(pids);
    h.print_goal();
}