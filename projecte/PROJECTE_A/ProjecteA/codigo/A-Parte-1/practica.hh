#ifndef PRACTICA_HH
#define PRACTICA_HH

#include <iostream>
#include <vector>
#include <list>
#include <limits>
#include <algorithm>
using namespace std;

typedef vector<vector<int>> Graph;
typedef vector<int> Pids;

/**
 * @brief 
 * 
 */
class Practica{
private:
    Graph G;
    Pids pids;
    
    int min_pids(Pids state);
    void in_out(Pids& state, int pos);
    bool is_pids(Pids state);
    list<Pids> generate_successors(Pids state);
    Pids best_successor(list<Pids>);
    bool can_add(Pids state, int pos);
    bool can_remove(Pids state, int pos);
    void add_vertex(Pids& state, int pos);
    void remove_vertex(Pids& state, int pos);
    Pids copy_vector(Pids D, int i);
    
public:
    Practica();
    Practica(Graph g);
    void llegir_graf(int n, int m);
    Graph obtenir_graf();
    Pids llegir_conjunt();
    bool es_cjt_dominador_inf_pos(Graph G, Pids D);
    bool es_minimal(Graph G, Pids D);
    Pids trobar_conjunt(Graph G, Pids D);
    void search(Pids pids);
    void print_goal();

};
#endif

