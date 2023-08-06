#include "practica.hh"


int Practica::min_pids(Pids state){
    int res = 0;
    for(int i = 0; i < state.size(); ++i){
        if(state[i] == 1) ++res;
    }
    return res;
}

bool Practica::is_pids(Pids state){
    for(int i = 0; i < this->G.size(); ++i){
        int count = 0;
        for(int j = 0; j < this->G[i].size(); ++j){
            bool found = (state[j] == 1);
            
            if(found) ++count;
        }
        if((float(count)/this->G[i].size()) < 0.5) return false; 
    }
    return true;
}

bool Practica::can_add(Pids state, int pos){
    bool condition1 = (state[pos] == 0);
    if(condition1){
        state[pos] = 1;
        bool condition2 = is_pids(state);
        return condition1 and condition2;
    }
    return false;
}

bool Practica::can_remove(Pids state, int pos){
    bool condition1 = (state[pos] == 1);
    if(condition1){
        state[pos] = 0;
        bool condition2 = is_pids(state);
        return condition1 and condition2;
    }
    return false;
}

void Practica::in_out(Pids& state, int pos){
    state[pos] = state[pos] ^ 1;  
}

void Practica::add_vertex(Pids& state, int pos){
    state[pos] = 1;
}

void Practica::remove_vertex(Pids& state, int pos){
    state[pos] = 0;
}

list<Pids> Practica::generate_successors(Pids state){
    list<Pids> res;
    list<Pids>::iterator it = res.begin();
    for(int i = 0; i < state.size(); ++i){
        Pids aux = state;
        if(can_add(aux, i)){
            add_vertex(aux, i);
            res.insert(it, aux);
        }
        if(can_remove(aux, i)){
            remove_vertex(aux, i);
            res.insert(it, aux);
        }
    }
    return res;
}

Pids Practica::best_successor(list<Pids> successors){
    list<Pids>::iterator it = successors.begin();
    successors.sort([&](const Pids& pids1, const Pids& pids2)
    {
      if(min_pids(pids1) == min_pids(pids2)) return pids1 < pids2;
      return min_pids(pids1) < min_pids(pids2);
    });
    return *it;

}

Pids Practica::copy_vector(Pids D, int i) {
	Pids aux;
	for (int x = 0; x < D.size(); ++x) {
		if (x != i) {
			aux.push_back(D[x]);
		}
	}
	return aux;
}

Practica::Practica(){
}

Practica::Practica(Graph g){
    int n = g.size();
    this->pids = vector<int>(n, 0);
    this->G = g;
}

void Practica::llegir_graf(int n, int m){
    Graph g = Graph(n);
    int x, y;
    for (int j = 0; j < m; j++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    this->G = g;
}

Graph Practica::obtenir_graf(){
    return this->G;
}

Pids Practica::llegir_conjunt(){
    Pids d;
	int x;
	while (cin >> x) {
		d.push_back(x);
	}
	return d;
}

bool Practica::es_cjt_dominador_inf_pos(Graph G, Pids D) {
	for (int i = 0; i < G.size(); ++i) {
		float contador = 0;
		for (int j = 0; j < G[i].size(); ++j) {
			for (int l = 0; l < D.size(); ++l) {
				if (G[i][j] == D[l]) ++contador;
			}
		}
		if ((contador/G[i].size()) < 0.5) return false;
	}
	return true;
}

bool Practica::es_minimal(Graph G, Pids D) {
	for (int i = 0; i < D.size(); ++i) {
		Pids Daux = copy_vector(D, i);
		if (es_cjt_dominador_inf_pos(G, Daux)) return false;

	}
	return true;
}

Pids Practica::trobar_conjunt(Graph G, Pids D) {
	for (int i = 0; i < D.size(); ++i) {
		Pids Daux = copy_vector(D, i);
		if (es_cjt_dominador_inf_pos(G, Daux)) {
			D = Daux;
			--i;
		}
	}
	return D;
}

void Practica::search(Pids pids){
    Pids act = pids;
    list<Pids> successors;
    list<Pids>::iterator it = successors.begin();
    bool end = false;
    while (not end){
        successors= generate_successors(act);
        Pids succ = best_successor(successors);
        if(min_pids(act) > min_pids(succ)){
            act = succ;
        }
        else end = true;
    }
    this->pids = act;
}

void Practica::print_goal(){
    bool first = true;
    cout << "Conjunt dominador d'influencia positiva:" <<endl;
    cout << "D = {";
    for(int i = 0; i < this->pids.size(); ++i){
        if(first){
            if(this->pids[i] == 1) cout << i;
            first = false;
        }
        else {
            if(this->pids[i] == 1) cout << ", " << i;
        }
    }
    cout << "}" <<endl;
}