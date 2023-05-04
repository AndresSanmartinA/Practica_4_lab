#include "red.h"
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <list>
using namespace std;

string numero_string(int numero);
//void dijkstra(vector<vector<long long int>> &grafo, long long int origen,map<string,Router> red_);
void dijkstra(vector<vector<long long int>> &grafo, long long int origen,map<string,Router> red_,map<string,Router>::iterator it_red);
Router::Router(string _nombre, long long int _enlase)
{
_enlase=0;
nombre=_nombre;//le cambiamos el nombre para que sepa que no se refiere al nombre en class
enlase=_enlase;

agg_enrutadores(_nombre,_enlase);

}

map<string, long long int> Router::router2()
{
    return nombre_;
}

void Router::agg_enrutadores(string nombre_agg, long long int cost_enlase)
{
    if(nombre_.find(nombre_agg)==nombre_.end()){//verificamos si el nombre no existe
        nombre_.insert(pair<string,long long int>(nombre_agg,cost_enlase));
    }
}

void Router::dltt_enrutadores(string del_nombre)
{
    if(nombre_.find(del_nombre)!=nombre_.end()){

          nombre_.erase(nombre_.find(del_nombre));
    }
}

void Router::imp_enrutadores()
{
    it=nombre_.begin();
    cout<<nombre<<'\t';
    for(long long int itt;itt<nombre_.size();itt++,it++){
        cout<<it->first<<"\t";
    }
    for(it=nombre_.begin(),it=nombre_.begin();it!=nombre_.end();it++){
        //cout<< it -> first <<" "<< it->second<<"\t";//first trae el nombre de la key y second el valor de la key
        cout<< it -> second <<"\t";

    }
    cout<<endl;

}

void Router::imp_enrutadores_nom()
{

    for(it=nombre_.begin(),it=nombre_.begin();it!=nombre_.end();it++){
         cout<< it -> first <<"\t";

    }
    cout<<endl;
}

void Router::cam_enlase_enrutadores(string nombre_mod, long long int num_new)
{
if(nombre_.find(nombre_mod)!=nombre_.end()){//verificamos si el nombre existe

      nombre_[nombre_mod]= num_new;
}
}

string Router::router_vector()
{ int x=0;
    long long int z=0;
   for(it=nombre_.begin();it!=nombre_.end();it++,x++);
   string b="",c="";

   for(it=nombre_.begin();it!=nombre_.end();it++){
       z=it->second;
       if(z==-1){z=9999;}
       if(z>9){
           string numerof="",numerof2="";

           for(long long x;z>0;x++){
               if(z==10){numerof="10";
                   numerof2=numerof2+numerof;
               z=0;}
               else{
               numerof=(z%10)+48;
           numerof2=numerof2+numerof;
           z=z/10;}

           }
               c=c+" "+numerof2;
       }
           else{
       b =(z+48);
       c=c+" "+b;
   }}
   b=c+'\n';
   return b;
}

list <long long int> Router::router_list()
{long long int z=0;
    list<long long int> nombre;
    for(it=nombre_.begin();it!=nombre_.end();it++){
        z=it->second;
        nombre.push_back(z);}
    return nombre;

}

vector<long long> Router::router_list_vt()
{long long int z=0;
    vector<long long int> nombre;
    for(it=nombre_.begin();it!=nombre_.end();it++){
        z=it->second;
        nombre.push_back(z);}
    return nombre;

}



void red::agg_router_red(string nom_agg_red)
{
   if(red_.find(nom_agg_red)==red_.end()){//miramos si no existe
       Router a(nom_agg_red,0);
       for(it_red=red_.begin();it_red!=red_.end();it_red++){
           a.agg_enrutadores(it_red->first,-1);
            it_red->second.agg_enrutadores(nom_agg_red,-1);//agregamos la desconexion en los otros routers
       }
       //a.imp_enrutadores();
       red_.insert(pair<string,Router>(nom_agg_red,a));

       //a.imp_enrutadores();


   }
}

void red::cam_enlase_enrutadores_red(string nombre1,string nombre2, long long valor)
    {
for (it_red = red_.begin(); it_red != red_.end(); ++it_red) {
if((it_red->first)==nombre1){
it_red->second.cam_enlase_enrutadores(nombre2,valor);}


        }
            }


void red::dllt_router_red(string nom_red_eli)
{
    if(red_.find(nom_red_eli)!=red_.end()){
        Router a(nom_red_eli,0);
        for(it_red=red_.begin();it_red!=red_.end();it_red++){
            //a.dltt_enrutadores(nom_red_eli);
             it_red->second.dltt_enrutadores(nom_red_eli);
        }
        //a.imp_enrutadores();

        red_.erase(red_.find(nom_red_eli));

        //a.imp_enrutadores();


    }
}

void red::imp_router_red()
{
    it_red=red_.begin();
    cout<<"RED"<<'\t';
    it_red->second.imp_enrutadores_nom();

    for(it_red=red_.begin();it_red!=red_.end();it_red++){

   it_red->second.imp_enrutadores();

    }
    cout<<endl;
}

void red::algoritmo_dijkstra()
{
    string a="",vector_string="";
    list <list<long long int>>lineal;
    vector<vector<long long int>>the_vector;
 for(it_red=red_.begin();it_red!=red_.end();it_red++){
   a=it_red->second.router_vector();
   lineal.push_back(it_red->second.router_list());
   the_vector.push_back(it_red->second.router_list_vt());
   vector_string+=a;
 }

it_red=red_.begin();
     for(int origen = 0; origen < the_vector.size(); ++origen) {
//aqui agregamos el nodo de origen cuando nos interese buscar alguno en especidico con un if,agregar nodo fin a la funcion
         cout << "Nodo de origen: " << it_red->first << "\n";

         dijkstra(the_vector, origen,red_,it_red);
         it_red++;
         cout << "\n";
     }
}



