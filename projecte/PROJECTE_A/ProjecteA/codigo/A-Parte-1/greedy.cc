#include "practica.hh"

int main(){
    int n, m;			//n -> número de vértices y m número de aristas
    Practica p;
    cin >> n >> m;
    //Grafo G
    //Graph G;
    p.llegir_graf(n, m); //representació amb una llista d'adjacència
    Pids D;
    for (int i = 0; i < n; ++i) {
    	D.push_back(i);
    }
    D = p.trobar_conjunt(p.obtenir_graf(), D);
    for (int j = 0; j < D.size(); ++j) {
    	cout << D[j] << " ";
    }
    cout << endl;
}