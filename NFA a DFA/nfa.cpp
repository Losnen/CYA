#include "nfa.hpp"

typedef struct{
	set<estado> antigestados;
	unsigned int newestado;
	bool marca;
}EstadosDFA;

int tamaniocad(char cadena[]){
	int i = 0;
	while(cadena[i] != '\0')
	i++;
	return i;
}

typedef struct{
	vector<estado> est;
	vector<unsigned int> index;
}Estructura;

//-----------------------------------------------INICIO-------------------------

//------------------------------Constructor y destructor
nfa::nfa(){
	n_est_ = 0;
    ini_est_ = 0;
    nchar_ = 0;
}

nfa::nfa(char nombre[]){
	cargar(nombre);
}

nfa::~nfa(){}

//------------------------------Semiconstructor
void nfa::cargar(char nombre[]){
	ifstream file;	//variable stream en la que vamos a abrir el fichero
	unsigned int id;
	unsigned int ntrans;
	unsigned int aux1;
	bool acc;
	estado aux;
	estados_.clear();
	file.open(nombre);	//abrimos el archivo
	if(file.is_open()){
		file >> (unsigned int &) n_est_ >> (unsigned int &) aux1;
		for(int i = 0; i < n_est_; i++){
			file >> (unsigned int &) id >> (bool &) acc;
			if(id == aux1){	
				//cout << "El inicio será " << id;
				aux.charge(id,true,acc,file);
				estados_.insert(aux);
			}else{
				aux.charge(id,false,acc,file);
				estados_.insert(aux);
			}
			
		}
		ini_est_ = aux1;
		file.close();		//cerramos el archivo
	}else{
		cout << "Error en la apertura del fichero" << endl;
	}
	if(estados_.size() == n_est_){
		cout << "NFA creado correctamente" << endl;
	}
	else
	{	
		cout << "El NFA se ha creado con errores" << endl;
	}
	
}

//------------------------------Geters
estado nfa::estadon(unsigned int x){
	for(set <estado>::iterator i = estados_.begin(); i != estados_.end(); i++){
		estado tmp;
	    tmp = (*i);
		if(tmp.get_identifier() == x)
		return tmp;
	}
}

estado nfa::estadoinicial(){
	for(set <estado>::iterator i = estados_.begin(); i != estados_.end(); i++){
		estado tmp;
	    tmp = (*i);
		if(tmp.get_identifier() == ini_est_)
		return tmp;
	}
}

//------------------------------Métodos propios
void nfa::descargar(char* output){
   ofstream fs(output); 

   // Enviamos una cadena al fichero de salida:
   fs << n_est_ << endl;
   fs << ini_est_ << endl;
   for(set <estado>::iterator i = estados_.begin(); i != estados_.end(); i++){
	    estado tmp;
	    tmp = (*i);
	    fs << tmp.get_identifier() << " " << tmp.get_final() << " " << tmp.get_ntransiciones();
	   	set<transicion>::iterator j = tmp.get_posts().begin();
	   	for(int k = 0; k < tmp.get_ntransiciones(); k++){
        	transicion tmp2;
	    	tmp2 = (*j);
	    	fs << " " << tmp2.get_caracter() << " " << tmp2.get_siguiente();
	    	j++;
    	}
    	fs << endl;
      
    }
   // Cerrar el fichero, 
   // para luego poder abrirlo para lectura:
   fs.close();
}

void nfa::print(){
	cout << n_est_ << endl;
	cout << ini_est_ << endl;
	for(set <estado>::iterator i = estados_.begin(); i != estados_.end(); i++){
	    estado tmp;
	    tmp = (*i);
	    tmp.print();
	  
	}
	
	
}
 
void nfa::identify_death(){
	bool es = false;
	//Recorremos el set, determinando si son de muerte
	for(set <estado>::iterator i = estados_.begin(); i != estados_.end(); i++){
		estado tmp;
		tmp = (*i);
		tmp.identify_death();
	}
    
}

void nfa::analize(char cadena[]){
	bool aceptadisimo = false;
	cout << "Cadena de entrada: " << cadena << endl << endl;
	unsigned int var_cont = 0;
	stack<Estructura> pila;
	Estructura analisis;
	//Introducimos en la pila el estado inicial
	analisis.est.push_back(estadoinicial());
	analisis.index.push_back(0);
	pila.push(analisis);
	while(!pila.empty()){
		//Recorremos las transiciones desde el estado que nos indique el top de la pila
		// en busca de una transición con ~ o el caracter deseado
		Estructura tmp = pila.top();
		pila.pop();
		set<transicion> trans = tmp.est[tmp.est.size()-1].get_posts();
		bool epstrans = false;
		for(set<transicion>::iterator i = trans.begin(); i != trans.end(); i++){
				Estructura tmp3 = tmp;
				transicion tmp2;
				tmp2 = (*i);
				if(tmp2.get_caracter() == '~')
				epstrans = true;
		}
		
		//Si está vacío el set anterior, hay que mostrar por pantalla tmp
		if((trans.empty() or tmp.index[tmp.est.size()-1] == tamaniocad(cadena)) and !epstrans){
			var_cont++;
			cout << "Camino " << var_cont << endl;
			cout << "Estado actual    Entrada    Siguiente estado" << endl;
			for(int k = 0; k < tmp.est.size() - 1; k++){
				cout << "Q" << tmp.est[k].get_identifier() << "               ";
				if(tmp.index[k] == tmp.index[k+1])
				cout << "~";
				else
				cout << cadena[tmp.index[k]];
				cout << "          " << "Q" << tmp.est[k+1].get_identifier() << endl;
			}
			if(tmp.est[tmp.est.size()-1].get_final()){
				cout << "Cadena ACEPTADA" << endl;
				aceptadisimo = true;
			}
			else
			cout << "Cadena NO ACEPTADA" << endl;
			cout << endl;
		}else{
			for(set<transicion>::iterator i = trans.begin(); i != trans.end(); i++){
				Estructura tmp3 = tmp;
				transicion tmp2;
				tmp2 = (*i);
				unsigned int indice = tmp3.index[tmp3.index.size() - 1];
				estado aux = tmp3.est[tmp3.est.size() - 1];
				if(tmp2.get_caracter() == '~' or tmp2.get_caracter() == cadena[indice]){
					if(tmp2.get_caracter() == cadena[indice])
					indice++;
					tmp3.index.push_back(indice);
					tmp3.est.push_back(estadon(tmp2.get_siguiente()));
					pila.push(tmp3);
				}
				
			}
		}
		
	}
	cout << "Decisión final:" << endl;
	cout << "Cadena ";
	if(!aceptadisimo)
	cout << "NO ";
	cout << "ACEPTADA" << endl;

} 

/*void nfa::swap(){
	set<set<estado> > guardados;
	set<estado> inicial;
	inicial.insert(ini_est_);
	guardados.insert(eclausura(inicial));
	//Realizamos la eclausura del estado inicial y la colocamos en guardados
	for(//Recorremos el alfabeto){
		set<estado> aux1 = megatransicion;
	}
}*/


set<estado> nfa::megatransicion(set<estado> C, char a){
	set<estado> T;
	for(set<estado>::iterator i = C.begin(); i != C.end(); i++){
		estado q = (*i);
		set<transicion> tran = q.get_posts();
		for(set<transicion>::iterator j = tran.begin(); j != tran.end(); j++){
			transicion tmp = (*j);
			if(tmp.get_caracter() == a){
				unsigned int most = tmp.get_siguiente();
				
				estado aux = estadon(most);
				T.insert(aux);
			}
		}
	}
	return (eclausura(T));
}

set<estado> nfa::eclausura(set<estado> C){
	set<estado> Cv;
	do{
		Cv = C;
		set<estado> aux = epsclausura(Cv);
		C.insert(aux.begin(), aux.end());
	}while(Cv != C);
	return C;
}

set<estado> nfa::epsclausura(set<estado> conjunto){
	set<estado> T;
	for(set<estado>::iterator i = conjunto.begin(); i != conjunto.end(); i++){
		estado q = (*i);
		T.insert(q);
		set<transicion> tran = q.get_posts();
		for(set<transicion>::iterator j = tran.begin(); j != tran.end(); j++){
			transicion tmp = (*j);
			if(tmp.get_caracter() == '~'){
				estado aux = estadon(tmp.get_siguiente());
				T.insert(aux);
			}
		}
	}
	return T;
}

void nfa::nfa2dfa(char* output){
	vector<set<estado> > orden;
	unsigned int saveini;
	bool final[25];
	for(int i = 0; i < 25; i++)
	final[i] = false;
	bool beginning[25];
	for(int i = 0; i < 25; i++)
	beginning[i] = false;
	rellenaabecedario();

	set<estado> DFATransiciones[nchar_][25][2];
	set<set<estado> > estadosdfa;
	set<set<estado> > marcados;
	set<estado> dummy;
	dummy.insert(estadon(ini_est_));

	estadosdfa.insert(eclausura(dummy));
	orden.push_back(eclausura(dummy));
	while(estadosdfa.size() != marcados.size()){

		set<estado> T = buscarT(estadosdfa, marcados);
		singlesetprint(T);
		marcados.insert(T);
		for(int i = 0; i < nchar_; i++){
			set<estado> H = megatransicion(T, abecedario[i]);
			estadosdfa.insert(H);
			if(!alreadyin(orden, H))
			orden.push_back(H);
			if(hasfin(T)){
				final[get_n_estadodfa(estadosdfa, T)] = true;
			}
			
			DFATransiciones[i][get_n_estvect(orden, T)][0] = H;
			DFATransiciones[i][get_n_estvect(orden, T)][1] = T;
			cout << abecedario[i] << endl;
			singlesetprint(H);
		}
	}
}
	
 
bool nfa::alreadyin(vector<set<estado> > vect, set<estado> ab){
	bool in = false;
	for(int i = 0; i < vect.size(); i++){
		set<estado> tmp = vect[i];
		if(tmp == ab)
		in = true;
	}
	return in;
}
 
bool nfa::hasfin(set<estado> C){
	bool resp = false;
	for(set<estado>::iterator i = C.begin(); i != C.end(); i++){
		estado tmp = (*i);
		if(tmp.get_final())
		resp = true;
	}
	return resp;
}

bool nfa::hasbegin(set<estado> C){
	bool resp = false;
	for(set<estado>::iterator i = C.begin(); i != C.end(); i++){
		estado tmp = (*i);
		if(tmp.get_identifier() == ini_est_)
		resp = true;
	}
	return resp;
}

unsigned int nfa::get_n_estvect(vector<set<estado> > vect, set<estado> ab){
	for(int i = 0; i < vect.size(); i++){
		set<estado> tmp = vect[i];
		if(tmp == ab)
		return i;
	}
}

unsigned int nfa::get_n_estadodfa(set<set<estado> > dfaest, set<estado> ab){
	unsigned int cont = 0;
	for(set<set<estado> >::iterator i = dfaest.begin(); i != dfaest.end(); i++){
		set<estado> tmp = (*i);
		if(tmp == ab)
		return cont;
		cont++;
	}
}

set<estado> nfa::buscarT(set<set<estado> > conju, set<set<estado> > marcados){
	for(set<set<estado> >::iterator i = conju.begin(); i != conju.end(); i++){
		set<estado> tmp = (*i);
		if(!marcado(marcados, tmp)){
			return tmp;
		}
	}
}

bool nfa::marcado(set<set<estado> > marcas, set<estado> prob){
	bool enc = false;
	for(set<set<estado> >::iterator i = marcas.begin(); i != marcas.end(); i++){
		set<estado> tmp = (*i);
		if (tmp == prob){
			enc = true;
		}
	}
	return enc;
}

//------------------------------Métodos de minimización de DFAs
void nfa::minimizar(){
	//Creamos primero el alfabeto
/*
	set<estado>::iterator iter_es = estados_.begin();
	estado tmp;
	tmp = (*iter_es);
	set<transicion>::iterator iter_trans = tmp.get_posts().begin();
	for(int k = 0; k < tmp.get_ntransiciones(); k++){
		
		transicion tmp2;
		tmp2 = (*iter_trans);
		cout << tmp2.get_caracter() << " ";
		abecedario.insert(tmp2.get_caracter());
		iter_trans++;
		
	}
	*/
	nchar_ = 0;
	set<estado>::iterator it = estados_.begin();
	estado tmp;
	tmp = (*it);
	for(set<transicion>::iterator j = tmp.get_posts().begin();j != tmp.get_posts().end(); j++){
		transicion tmp2;
		tmp2 = (*j);
		char c = tmp2.get_caracter();
		abecedario.push_back(c);//abecedario.insert(c);
		nchar_++;
	}
	cout << endl;
	//Inicializamos el conjunto separando los estado de finalizacion del DFA
	set<set<estado> > conjunto;
	set<set<estado> >conjunto_viejo;
	set<estado> aux1;
	set<estado> aux2;
	for(set <estado>::iterator i = estados_.begin(); i != estados_.end(); i++){
	    estado tmp2;
	    tmp2 = (*i);
	    if(tmp2.get_final() == true){
	    	aux2.insert(tmp2);
	    }else{
	    	aux1.insert(tmp2);
	    }
	}
	conjunto.insert(aux1);
	conjunto.insert(aux2);
	int i = 0;
	conjunto_viejo = conjunto;
	setprint(conjunto);
	do{
		conjunto_viejo = conjunto;
		conjunto = crear_nueva_particion(conjunto_viejo);
		i++;
		cout  << endl << " Paso " << i << endl;
		setprint(conjunto);
	}while(!(conjunto == conjunto_viejo));
	construir_DFA(conjunto);
	
}

set<set<estado> > nfa::crear_nueva_particion(set<set<estado> > conjunto_viejo){
	set<set<estado> > conjunto;
	for(set<set<estado> >::iterator i = conjunto_viejo.begin(); i != conjunto_viejo.end(); i++){
		set<estado> G;
		G = (*i);
		set<set<estado> > auxiliar;
		auxiliar = descomp(G, conjunto_viejo);
		conjunto.insert(auxiliar.begin(), auxiliar.end());
	}

	return conjunto;
}

set<set<estado> > nfa::descomp(set<estado> G, set<set<estado> > conjunto){
	set<set<estado> > T;
	T.insert(G);
	char a;
	
	set<set<estado> > Tprima;
	for(int i = 0; i < nchar_; i++){
		a = abecedario[i];
		set<set<estado> > p;
		for(set<set<estado> >::iterator j = T.begin(); j != T.end(); j++){
			G = (*j);
			
			Tprima = part(G, a, conjunto);
			for(set<set<estado> >::iterator w = Tprima.begin(); w != Tprima.end(); w++){
				set<estado> tmp4 = (*w);
				p.insert(tmp4);
			}
		}
		T = p;
	}
	

	return T;
}

set<set<estado> > nfa::part(set<estado> G, char a, set<set<estado> > conjunto){
	set<set<estado> > T;
	
	for(set<set<estado> >::iterator i = conjunto.begin(); i != conjunto.end(); i++){
		set<estado> auxiliar2;
		set<estado> H;
		H = (*i);
		for(set<estado>::iterator j = G.begin(); j != G.end(); j++){
			
			estado tmp;
			tmp = (*j);
			set<transicion>::iterator tran = tmp.get_posts().begin();
			for(set<estado>::iterator item = H.begin(); item != H.end(); item++){
				estado tmp2 = (*item);
				if(tmp.get_siguiente(a) == tmp2.get_identifier()){
					auxiliar2.insert(tmp);
					
					
				}
            	

			}
			
			
			
		}
		if(!auxiliar2.empty())
		T.insert(auxiliar2);
	}
	

	return T;
}

void nfa::construir_DFA(set<set<estado> > conjunto){
	cout << "Nótese que se repite el último paso para comprobar que no hay mejoras" << endl << endl;
	set<estado> total;
	unsigned int id = 0;
	//Para marcar estado de inicio
	bool inicialgot;
	unsigned int inicial = 0;
	//Para marcar estados de aceptacion
	bool fini;
	
	for(set<set<estado> >::iterator i = conjunto.begin(); i != conjunto.end(); i++){
		//Para marcar transiciones
		int nt = nchar_;
		
		
		set<transicion> transitarae;
		set<estado> tmp;
		tmp = (*i);
		if(!tmp.empty()){
			inicialgot = false;
			fini = false;
			for(set<estado>::iterator j = tmp.begin(); j != tmp.end(); j++){
				estado tmp2;
				tmp2 = (*j);
			
				
			
				if(tmp2.get_inicial()){
					inicial = id;
					inicialgot = true;
				}
				if(tmp2.get_final()){
					fini = true;
				}
			}
			set<estado>::iterator jt = tmp.begin();
			estado tmp2 = (*jt);
	
			
			for(int i = 0; i < nchar_; i++){
				char tmpab;
				tmpab = abecedario[i];
				transicion tmp3;
				tmp3.cargar(tmpab, tmp2.get_siguiente(tmpab));
				transitarae.insert(tmp3);
			}
			
	
			
			
			
			
		
			estado ainsertar;
			ainsertar.cargar(id, inicialgot, fini, nt, transitarae);
			total.insert(ainsertar);
		
		
		}
		
		id++;	

	}
	
	n_est_ = id++;
	ini_est_ = inicial;
	estados_ = total;
	cout << "Su DFA ha sido simplificado, pulse enter para continuar";
}

void nfa::singlesetprint(set<estado> C){
    cout << "{";
    for(set<estado>::iterator i = C.begin(); i!=C.end(); i++)  
    {
        estado aux = (*i);
        
        cout << aux.get_identifier();
        cout <<",";
    }
    cout << "}" <<endl;
    
}

void nfa::setprint(set<set<estado> > C){
    int cont = 0;
    for(set<set<estado> >::iterator i = C.begin(); i!=C.end(); i++)  
    {
        set<estado> aux = (*i);
        cout << "P " << cont << "{";
        for(set<estado>::iterator j = aux.begin(); j!=aux.end(); j++)
        {
            estado auxe = (*j);
            cout << auxe.get_identifier();
            if(aux.size() != cont) 
            cout <<",";
            
            
        }
        cont++;
        cout << "}" <<endl;
    }
}

//-------------------------------Métodos auxiliares
void nfa::mostraralfabeto(){
	cout << "Método 1:" << endl;
	for(set<estado>::iterator i = estados_.begin(); i != estados_.end(); i++){
		estado tmp;
		tmp = (*i);
		cout << "Estado " << tmp.get_identifier() << endl;
		for(set<transicion>::iterator j = tmp.get_posts().begin();j != tmp.get_posts().end(); j++){
			transicion tmp2;
			tmp2 = (*j);
			cout << tmp2.get_caracter() << " ";
		}
		cout << endl;
	}
	cout << "Método 2:" << endl;
	int nchars = 0;
	for(int i = 0; i < nchar_; i++){
		char tmp;
		tmp = abecedario[i];
		cout << tmp << " " << endl;
		nchars++;
	}
	cout << nchars << endl;
}


void nfa::rellenaabecedario(){
	abecedario.clear();
	nchar_ = 0;
	for(set<estado>::iterator i = estados_.begin(); i != estados_.end(); i++){
		estado tmp = (*i);
		set<transicion> tmp2 = tmp.get_posts();
		for(set<transicion>::iterator j = tmp2.begin(); j != tmp2.end(); j++){
			transicion tmp3 = (*j);
			char c = tmp3.get_caracter();
			if(c != '~')
			comprobarabc(c);
		}
	}
}

void nfa::comprobarabc(char c){
	bool existe = false;
	for(int i = 0; i < nchar_; i++){
		if(c == abecedario[i])
		existe = true;
	}
	if(!existe){
		nchar_++;
		abecedario.push_back(c);
	}
}