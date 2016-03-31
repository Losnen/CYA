#include "MT.hpp"


MT::MT(char* nombre)
{
	ifstream fichero_tm;
	fichero_tm.open(nombre);
	string fin;
	if(fichero_tm.is_open()) 
	{
		
		fichero_tm >> num_estados;
		fichero_tm >> arranque;
		fichero_tm >> prim_final;
		fichero_tm >> num_uplas;

		M_uplas = new string[5*num_uplas];
		for (int i=0; i<num_uplas; i++)
		{
			for (int j=0; j<5; j++) 
			{
				fichero_tm >> M_uplas[i*5+j];
			}
		}
	}
}
/*
 * @name    MT
 * @brief   Constructor
 *
 * Construye la maquina de Turing con los datos que recoge de fichero
 *
 * @param El fichero del que recoge los datos
 */
MT::~MT(void) 
{}
/*
 * @name    ~MT
 * @brief   Destructor
 */
void MT::leer_MT(char nombre[])
{
	num_estados =0;
    arranque = 0;
    prim_final.clear();
    num_uplas = 0;
    M_uplas = NULL; 
    
	ifstream fichero_tm;
	fichero_tm.open(nombre);
	string fin;
	if(fichero_tm.is_open()) 
	{
		
		fichero_tm >> num_estados;
		fichero_tm >> arranque;
		fichero_tm >> prim_final;
		fichero_tm >> num_uplas;

		M_uplas = new string[5*num_uplas];
		for (int i=0; i<num_uplas; i++)
		{
			for (int j=0; j<5; j++) 
			{
				fichero_tm >> M_uplas[i*5+j];
			}
		}
	} 
	
}
/*
 * @name    leer_MT
 * @brief   Lee una nueva MT
 *
 * Construye la maquina de Turing con los datos que recoge de fichero
 *
 * @param El fichero del que recoge los datos
 */
void MT::mostrar(void)
{
	cout << num_estados << endl;
	cout << arranque << endl;
	cout << prim_final << endl;
	cout << num_uplas << endl;

	for(int k=0; k<5; k++) {
		cout << M_uplas[k] << " ";
	}
	cout << endl;

	for(int i=1; i<num_uplas; i++) {
		for(int j=0; j<5; j++) {
			cout << M_uplas[i*5+j] << " ";
		}
		cout << endl;
	}
}
/**
 * @name    Mostrar
 * @brief   Imprime la MT
 *
 * Muestra la máquina de Turing por pantalla.
 */
void MT::simular(string cad_entrada)
{

	vector<string> cadena;
	bool senal_tipo = true;
	bool fin = false;
	string estado_actual = "0";
	unsigned int n = 1;
	bool movimiento;
	int j;
	int hecho;



	cadena.resize(cad_entrada.size()+2);
	for(unsigned int i=0; i<cad_entrada.size()+2; i++) 
	{
		if(i==0 || i==cad_entrada.size()+1) 
		{
			cadena[i] = '$';
		} 
		else 
		{
			cadena[i] = cad_entrada[i-1];
		}
	}

	while(fin != true) 
	{
		movimiento = false;
		j=0;
		hecho=0;
		while(movimiento != true) 
		{
			if((senal_tipo==true) && (hecho==0)) 
			{
				hecho++;
				cout << "q" << estado_actual << " ";
				for(unsigned int x=0; x<cadena.size(); x++) 
				{
					if(x==cadena.size()-1) 
					{
						if(x==n) 
						{
							cout << cadena[x] << endl;
						} 
						else 
						{
							cout << cadena[x] << endl;
						}
					} 
					else 
					{
						if(x==n) 
						{
							cout << cadena[x];
						} 
						else 
						{
							cout << cadena[x];
						}
					}
				}
			
			}
			if((M_uplas[j*5] == estado_actual)&&(M_uplas[j*5+1]==cadena[n])) 
			{
				movimiento = true;
				cadena[n]=M_uplas[j*5+2];
				if(M_uplas[j*5+3]=="R") 
				{
					if(n==(cadena.size()-1)) 
					{
						cadena.push_back("$");
						n=cadena.size();
					} 
					else 
					{
						n++;
					}
				} 
				else 
				{
					if(M_uplas[j*5+3]=="L") 
					{
						if(n==0) 
						{
							camb_vec(cadena);
						} 
						else 
						{
							n--;
						}
					}
				}
				estado_actual = M_uplas[j*5+4];
			}
			j++;
			if(j==num_uplas) 
			{
				fin = true;
				movimiento = true;
			}
		}
	}
	if(estado_actual>=prim_final) 
	{
		if(senal_tipo==true) 
		{
			cout << "q" << estado_actual << " ";
			for(unsigned int x=0; x<cadena.size(); x++) 
			{
				if(x==cadena.size()-1) 
				{
					if(x==n) 
					{
						cout << cadena[x] << endl;
					} 
					else 
					{
						cout << cadena[x] << endl;
					}
				} 
				else 
				{
					if(x==n) 
					{
						cout << cadena[x];
					} 
					else 
					{
						cout << cadena[x];
					}
				}
			}
		
		}
		cout << "\nCadena aceptada." << endl;
	} 
	else 
	{
		cout << "\nCadena rechazada." << endl;
	}
}
/**
 * @name    Simular
 * @brief   Simlador
 *
 * Simula la máquina de Turing con la cadena que le pasamos
 *
 * @param La cadena que recogemos del fichero cadena.tape
 */
void MT::camb_vec(std::vector<string>& cad)
{
	std::vector<string> aux;
	aux.resize(cad.size()+1);
	aux[0]="$";
	for(unsigned int i=0; i<cad.size(); i++) 
	{
		aux[i+1]=cad[i];
	}
	cad.resize(aux.size());
	cad=aux;
}
/**
 * @name    camb_vec
 * @brief   Agranda el vector.
 *
 * Agranda el Vector para simular que es infinito
 *
 * @param La cadena a agrandar.
 */