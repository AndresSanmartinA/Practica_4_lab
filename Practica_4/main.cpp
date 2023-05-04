#include "funciones.h"
#include "red.h"
#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;
string leer_texto(string name_texto);
//void crear_routers_texto(string texto);
red crear_routers_texto(string texto);
red agregar_datos_texto(red z,string datos);
red aleatory();
red probabilidad(map<string,Router>& a);

int main()
{

/*Router a("A",0);
a.imp_enrutadores();
a.agg_enrutadores("B",5);
a.agg_enrutadores("C",10);
a.agg_enrutadores("D",15);
a.agg_enrutadores("E",-1);
a.imp_enrutadores();
a.dltt_enrutadores("D");
a.imp_enrutadores();
a.cam_enlase_enrutadores("C",33);
a.imp_enrutadores();
a.router_vector();*/
/*red c,z;
c.agg_router_red("Z");
c.agg_router_red("F");
c.agg_router_red("X");
c.agg_router_red("I");
c.agg_router_red("L");
c.agg_router_red("Y");
c.imp_router_red();
c.dllt_router_red("F");
c.imp_router_red();
c.dllt_router_red("I");
c.imp_router_red();
string name_texto;
cout<<"ingrese el nombre del archivo"<<endl;
cin>>name_texto;

name_texto=leer_texto(name_texto);
//crear_routers_texto(name_texto);
z=crear_routers_texto(name_texto);
z.imp_router_red();
z=agregar_datos_texto(z,name_texto);
z.imp_router_red();
z.algoritmo_dijkstra();*/
red a;
//map<string,Router>::iterator the_red;
//the_red=a.begin();
a=aleatory();
a.imp_router_red();
a=probabilidad(a);

    return 0;

}
