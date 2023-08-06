#include "practica.hh"

int main(){
    int n, m;
    Practica p;			//n -> número de vértices y m número de aristas
    cin >> n >> m;
    //Grafo G
    p.llegir_graf(n, m); //representació amb una llista d'adjacència

    //conjunto D
    Pids D;
    D = p.llegir_conjunt();
    bool b = p.es_cjt_dominador_inf_pos(p.obtenir_graf(), D);
    if (b) {
    	cout << "Es conjunt dominador d'influència positiva" << endl;
    	bool bb = p.es_minimal(p.obtenir_graf(), D);
    	if (bb) cout << "Es minimal" << endl;
    	else cout << "No es minimal" << endl;
    }
    else cout << "No es conjunt dominador d'influència positiva" << endl;
}