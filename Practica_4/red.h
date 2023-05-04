#ifndef RED_H
#define RED_H
#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;



class Router
{
private://atributos
    string nombre;
    long long int enlase;//inesesario por que es =0
    map<string,long long int> nombre_;//definimos el mapa toma los valores
    map<string,long long int>::iterator it;//definimos el iterador el saca la info de map

public://metodos
    Router(string,long long int);//hacemos el costructor
    map<string,long long int> router2();
    void agg_enrutadores(string,long long int);//agregamos al mapa lo indicado
    void dltt_enrutadores(string);//eliminamos enrutadores
    void imp_enrutadores();//impimimos(atualizamos) enrutadores
    void imp_enrutadores_nom();//imprimimos las keys
    void cam_enlase_enrutadores(string,long long int);//cambiamos valor de enlace
    string router_vector();
    list<long long int> router_list();
    vector<long long int>router_list_vt();

};

class red
{
private:
map<string,Router> red_;//definimos el mapa toma los valores
map<string,Router>::iterator it_red;//definimos el iterador el saca la info de map



public:
//red(string,long long int);
void agg_router_red(string);
void cam_enlase_enrutadores_red(string nombre1,string nombre2, long long valor);
void dllt_router_red(string);
void imp_router_red();
void archivo_router_red();
void algoritmo_dijkstra();


};

#endif // RED_H
