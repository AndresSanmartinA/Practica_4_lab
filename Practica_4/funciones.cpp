#include "funciones.h"
#include "red.h"
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <fstream>
#include <sstream>
#include <cmath>
#include <vector>
#include <queue>


const int INF = 1e9;
using namespace std;
string leer_texto(string name_texto)
{
    string datos;
    char letra;
    unsigned long long tamaño;
    fstream base_de_datos;
    base_de_datos.open(name_texto,ios::in | ios::binary | ios::ate);//parametro de entrada binario y coloca el cursor al final del texto
    if(base_de_datos.is_open()){
        tamaño=base_de_datos.tellg();//toma la longitud de datos hasta donde se encuentra el cursor
        base_de_datos.seekg(0);//colocamos el puntero en la primer posicion
        for(unsigned long long i=0;i<tamaño;i++){

            base_de_datos.get(letra);//asigna a letra el caracter en esa posicion
           if(letra!='\r'){
            datos.push_back(letra);//concatenar letra con letra en datos
}
        }
    }
    else {datos = "";cout<<"Error de Lectura"<<endl;}
    base_de_datos.close();
    return datos;}
/*red crear_routers_texto(string texto)
{
    string linea,letras;
    stringstream saltos_linea(texto);//esto es una especie de split para separar las letras o caracteres
    long long int cont=0;
    // red x;  //miramos si nos da para hacer el costructor red

    while (getline(saltos_linea, linea, '\n'))
//        while (getline(saltos_linea, linea, '\n'))
    {
        stringstream grupos(linea);

    while(getline(grupos, letras, ' ')) {
        //cout<<letras<<'\t';
        cont++;
        if(cont%3!=0){
        red_.agg_router_red(letras);}
    }

}
    return x;
}*/

red agregar_datos_texto(red x,string datos){
    string linea,letras,nombre1,nombre2;
    stringstream saltos_linea(datos);//esto es una especie de split para separar las letras o caracteres
    long long int cont=0,valor=0;
    //red x;
    while (getline(saltos_linea, linea, '\n'))
//        while (getline(saltos_linea, linea, '\n'))
    {
        stringstream grupos(linea);

    while(getline(grupos, letras, ' ')) {
        cont++;
        if(cont%3==0){valor=string_numeros(letras);
        x.cam_enlase_enrutadores_red(nombre1,nombre2,valor);
        x.cam_enlase_enrutadores_red(nombre2,nombre1,valor);}
        else if(cont%2==0){nombre2=letras;}
        else if(cont%1==0){nombre1=letras;}


    }
    cont=0;

}
    return x;

}

long long int string_numeros(string numeros_txt){
    long long int numero=0;
    for(long long int x=0;numeros_txt[x]!='\0';x++){
        if(numeros_txt[x]>='0' and numeros_txt[x]<='9'){
            numero=numero*10;
            numero=numero+(numeros_txt[x]-48);
        }
    }
    return numero;
}

void dijkstra(vector<vector<long long int>> &grafo, long long int origen,map<string,Router> red_,map<string,Router>::iterator it_red){
long long int n = grafo.size();
    vector<long long int> distancia(n, INF);
    vector<long long int> previo(n, -1);
    distancia[origen] = 0;
    priority_queue<pair<long long int,long long int>, vector<pair<long long int,long long int>>, greater<pair<long long int,long long int>>> pq;
    pq.push({0, origen});

    while(!pq.empty()) {
        long long int u = pq.top().second;
        long long int distancia_u = pq.top().first;
        pq.pop();
        if(distancia_u > distancia[u]) continue;
        for(long long int v = 0; v < n; ++v) {
           // if(grafo[u][v] != INF) {
            if(grafo[u][v] != (-1)) {
                long long int distancia_v = distancia[u] + grafo[u][v];
                if(distancia_v < distancia[v]) {
                    distancia[v] = distancia_v;
                    previo[v] = u;
                    pq.push({distancia[v], v});
                }
            }
        }
    }

map<string,Router>::iterator it_red2;
it_red2=red_.begin();
    for(long long int v = 0; v < n; ++v,it_red2++) {
        if(v == origen) continue;
       // if(distancia[v] == INF) {
         if(distancia[v] == (-1)) {
            cout << "No hay camino desde " << it_red->first<< " hasta " << it_red2->first << "\n";
        } else {
            cout << "El camino mas corto desde " << it_red->first << " hasta " << it_red2->first << " es " << distancia[v] << ": ";
            vector<long long int> camino;
            long long int u = v;
            while(u != -1) {
                camino.push_back(u);
                u = previo[u];
            }


            for(long long int i = camino.size()-1; i >= 0; --i) {

                    auto it_red=red_.begin();
                    long long int lugar=camino[i];
                    advance(it_red,lugar);
                    cout<<it_red->first<<" ";
                if(i>0){
                    cout<<"-->";
                }
               // cout << camino[i] << " ";
                //cout<<it
            }
            cout << "\n";
        }
    }
}
void red_matriz(red){

}
string numero_string(long long numero){
    string numerof="";
    for(long long x;numero>0;x++){
        numerof=(numero%10)+48;
        numero=numero/10;
    }
    return numerof;
}
/*
red aleatory(){//esto lo podemos usar desde la clase a coomo una funcion de a
    //red a; //miramos si podemos hacer el costructor de red
    long long int num = 0;
    cout<<"De cuantos routers quiere su red aleatoria"<<endl;
    cin>>num;
    long long int nom=ceil(log(num)/log(26));
    if(nom<=26){
    string letra_ramdom = "";
    srand(time(NULL)); // Se establece la semilla aleatoria una vez al inicio del programa

    while (num > 0) {
        for (int i = 0; i < nom; i++) {
        letra_ramdom += (char)(97 + rand() % (26)); // Se agrega cada letra generada al final del string
            }
            //cout << letra_ramdom << endl;
            a.agg_router_red(letra_ramdom);
            letra_ramdom = ""; // Se reinicia el string para la siguiente iteración
            num--;

    }
     return a;}
    else{cout<<"la cantidad de routers excede las letras disponobles"<<endl;}
}
*/
bool true_false(int porcentaje){
    srand(time(NULL));
    int num_aleatorio=rand()%100;
    return(num_aleatorio<porcentaje);//aqui miramos lo de la probabilidad y si se cumple retorna un true o false si nno
}
red probabilidad(map<string,Router>& a){

int x=0;
cout<<"ingrese la probabilidad de 1 a 100 para la conexion de los routers"<<endl;
cin>> x;
long long int costo=0,numero_f;
cout<<"ingrese de cuantos digitos quieres el costo de los enlases"<<endl;
cin>>costo;
map<string,Router>::iterator it_red;
map<string,Router>::iterator it_red2;
map<string,long long int> cambio;
long long int contador=0;
map<string,long long int>::iterator it_router;

for (it_red = a.begin(); it_red != a.end(); it_red++){
  cambio=it_red->second.router2();
    for (it_router = (cambio).begin(); it_router != (cambio).end(); it_router++){
        //aqui deberia venir el if
        bool resultado = true_false(x);
        if (resultado){
            if(it_red->first!=it_router->first){
      numero_f += (long long int)(rand() % ((10)^costo));
      it_red->second.cam_enlase_enrutadores(it_router->first,numero_f);
              numero_f=0;
    }}
  }it_red->second.imp_enrutadores();
}}

