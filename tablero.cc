/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * pokemon-crush
 * Copyright (C) SAMIR FARID VALENCIA VELASCO 2016 <samirfvv@s5pc31>
 * 
pokemon-crush is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * pokemon-crush is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "tablero.h"
#include <iostream>
#include <fstream>
#include <string>
#include "caja.h"
#include "coordenada.h"
#include <cstdlib>

Tablero::Tablero()
{
 srand (time(NULL));
 int j= rand() % 8;
 int k= rand() % 4;
 for(int i=0;i<8;i++)
 {
 	for(int e=0;e<8;e++)
	{
		int k= rand() % 4 + 1;
		int aux1;
		aux1=pokemonCrush[i][e].getNum();
		if(aux1==0)
		{
			pokemonCrush[i][e].setCoordenada(i, e);
			pokemonCrush[i][e].setNum(k);
			pokemonCrush[i][e].setCantBeFree();
		}
	}
 }
// pokemonCrush[j][k].setNum(5);
 //pokemonCrush[j][k].setMove();
 
}

Tablero::~Tablero()
{
}

void Tablero::leerNivel(string lev)
{
}
void Tablero::showInstruc()
{
}
/* void Tablero::showTablero()
{
}
*/
void Tablero::liberarCaja()
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			if (pokemonCrush[i][j].getCanBeFree() == true)
			{
				//pokemonCrush[i][j].setCanBeFree();
				pokemonCrush[i][j].setNum(0);
				pokemonCrush[i][j].setCantBeFree();
			}
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Tablero::validMove (int f,int c, int i, int e)//0 1 1 1
{
	int dir;
	dir=0;
	int aux1, aux2, aux3, aux4, aux5, au2, au3, au4, au5;
		aux1=pokemonCrush[f][c].getNum(); // 		
		aux2=pokemonCrush[i][e+1].getNum(); //  		
		aux3=pokemonCrush[i][e+2].getNum(); //  		2
		aux4=pokemonCrush[i][e-1].getNum(); //  		1
		aux5=pokemonCrush[i][e-2].getNum(); //  		--
		
		au2=pokemonCrush[i+1][e].getNum(); //  2 1		2
		au3=pokemonCrush[i+2][e].getNum(); //  3 1		3
		au4=pokemonCrush[i-1][e].getNum(); //  0 1		1
		au5=pokemonCrush[i-2][e].getNum(); //  -1 1	--
	if (((aux1==aux2)&&(aux1==aux3))||((aux1==aux4)&&(aux1==aux5))||((aux1==aux2)&&(aux1==aux4)))
	{
		//Mover caja horizontal
		movCaja(f,c,i,e, 2);
	}
	
	if (((aux1==au2)&&(aux1==au3))||((aux1==au4)&&(aux1==au5))||((aux1==au2)&&(aux1==au4)))
	{
		//Move caja vertical
		movCaja(f,c,i,e, 1);
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Tablero::movCaja(int f, int c, int i,int e, int dir)
{
//Se crean dos auxiliares para guardar el numero del pokemon 
    int aux1,aux2;
    aux1=pokemonCrush[f][c].getNum();
    aux2=pokemonCrush[i][e].getNum();
//Se setea el nuevo valor en la posicion a ambas cajas
    pokemonCrush[f][c].setNum(aux2);
    pokemonCrush[i][e].setNum(aux1);

   // makeRemov(i,e,dir,1);
	retoUno(i,e);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Tablero::makeRemov(int i, int e, int dir, int prov)
{
    pokemonCrush[i][e].setCanBeFree();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Tablero::inicialMatrix()
{
	for (int i=0;i<8;i++)
	{
		for (int j=0;j<8;j++)
		{
			pokemonCrush[i][j].setCantBeFree();
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Tablero::retoUno(int f, int c)
{
	bool would = false;
	int pokePrincipal=pokemonCrush[f][c].getNum();
	int masAuxHoriz1=0;
	int masAuxHoriz2=0;
	int menosAuxHoriz1=0;
	int menosAuxHoriz2=0;
	int l;
	if (c<7)
	{
		masAuxHoriz1=pokemonCrush[f][c+1].getNum();
		if (c<6)
		{
			masAuxHoriz2=pokemonCrush[f][c+2].getNum();
		}
			
	}
	if(c>0)
	{
		menosAuxHoriz1=pokemonCrush[f][c-1].getNum();
		if(c>1)
		{
			menosAuxHoriz2=pokemonCrush[f][c-2].getNum();
		}
	}
	

	if((pokePrincipal==masAuxHoriz1)&&(pokePrincipal==masAuxHoriz2))
	{
		would = true;
		pokemonCrush[f][c].setNum(0);
		pokemonCrush[f][c+1].setNum(0);
		pokemonCrush[f][c+2].setNum(0);
		if(c<=5)
		{
			l=c+3;
			for(l;l<=7;l++)
			{
				if(pokemonCrush[f][l].getNum() == pokePrincipal)
				{
					pokemonCrush[f][l].setNum(0);
				}
				else 
				{
					l=8;
				}
			
			}
		}
	}
	if((pokePrincipal==menosAuxHoriz1)&&(pokePrincipal==menosAuxHoriz2))
	{
		would = true;
		pokemonCrush[f][c].setNum(0);
		pokemonCrush[f][c-1].setNum(0);
		pokemonCrush[f][c-2].setNum(0);
		if(c>=3)
		{
			l=c-3;
			for(l;l>=0;l--)
			{
				if(pokemonCrush[f][l].getNum() == pokePrincipal)
				{
					pokemonCrush[f][l].setNum(0);
				}
				else 
				{
					l=-1;
				}
			
			}
		}
	}




	int masAuxVerti1=0;
	int masAuxVerti2=0;
	int menosAuxVerti1=0;
	int menosAuxVerti2=0;
	
	if (f<7)
	{
		masAuxVerti1=pokemonCrush[f+1][c].getNum();
		if (f<6)
		{
			masAuxVerti2=pokemonCrush[f+2][c].getNum();
		}
			
	}
	if(f>0)
	{
		menosAuxVerti1=pokemonCrush[f-1][c].getNum();
		if(f>1)
		{
			menosAuxVerti2=pokemonCrush[f-2][c].getNum();
		}
	}
	

	if((pokePrincipal==masAuxVerti1)&&(pokePrincipal==masAuxVerti2))
	{
		would = true;
		pokemonCrush[f][c].setNum(0);
		pokemonCrush[f+1][c].setNum(0);
		pokemonCrush[f+2][c].setNum(0);
		if(f<=5)
		{
			l=f+3;
			for(l;l<=7;l++)
			{
				if(pokemonCrush[l][c].getNum() == pokePrincipal)
				{
					pokemonCrush[l][c].setNum(0);
				}
				else 
				{
					l=8;
				}
			
			}
		}
	}
	if((pokePrincipal==menosAuxVerti1)&&(pokePrincipal==menosAuxVerti2))
	{
		would = true;
		pokemonCrush[f][c].setNum(0);
		pokemonCrush[f-1][c].setNum(0);
		pokemonCrush[f-2][c].setNum(0);
		if(f>=3)
		{
			l=f-3;
			for(l;l>=0;l--)
			{
				if(pokemonCrush[l][c].getNum() == pokePrincipal)
				{
					pokemonCrush[l][c].setNum(0);
				}
				else 
				{
					l=-1;
				}
			
			}
		}
	}

	if((pokePrincipal==masAuxHoriz1)&&(pokePrincipal==menosAuxHoriz1))
	{
		would = true;
		pokemonCrush[f][c].setNum(0);
		pokemonCrush[f][c+1].setNum(0);
		pokemonCrush[f][c-1].setNum(0);
	}

	if((pokePrincipal==masAuxVerti1)&&(pokePrincipal==menosAuxVerti1))
	{
		would = true;
		pokemonCrush[f][c].setNum(0);
		pokemonCrush[f+1][c].setNum(0);
		pokemonCrush[f-1][c].setNum(0);
	}
	
	return would;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Tablero::quedanMov()
{
   for (int i=0;i<8;i++)
   {
      for (int j=0;j<8;j++)
      {    
          int aux1, aux2, aux3, aux4, aux5;
          aux1=pokemonCrush[i][j].getNum();
          aux2=pokemonCrush[i][j+2].getNum();
          aux3=pokemonCrush[i][j+3].getNum();
          if (j>=2)
          {
          aux4=pokemonCrush[i][j-2].getNum();
          }
          if (j>=3)
          {
          aux5=pokemonCrush[i][j-3].getNum();
          }
          if (aux1==aux2 && aux1==aux3)
		  {
			  cout <<"Aun hay movimientos posibles"<<endl;
		  }
		  if (aux1==aux4 && aux1==aux5)
		  {
			  cout <<"Aun hay movimientos posibles"<<endl;
		  }
		  if (aux1==aux2 && aux1==aux4)
		  {
			  cout <<"Aun hay movimientos posibles"<<endl;
		  }
	  }    
   }
	for (int j=0;j<8;j++)
	{
		for (int i=0;i<8;i++)
		{    
			int aux1, aux2, aux3, aux4, aux5;
			aux1=pokemonCrush[i][j].getNum();
			aux2=pokemonCrush[i+2][j].getNum();
			aux3=pokemonCrush[i+3][j].getNum();
			if (i>=2)
			{
				aux4=pokemonCrush[i-2][j].getNum();
			}
			if (i>=3)
			{
				aux5=pokemonCrush[i-3][j].getNum();
			}
			if (aux1==aux2 && aux1==aux3)
			{
				cout <<"Aun hay movimientos posibles"<<endl;
			}
			if (aux1==aux4 && aux1==aux5)
			{
				cout <<"Aun hay movimientos posibles"<<endl;
			}
			if (aux1==aux2 && aux1==aux4)
			{
				cout<<"Aun hay movimientos posibles"<<endl;
			}
          }              
	}
}
//////////////////////////////////////////////////////////////////////////

void Tablero::fillmatrix()
{
	//////////////////////////////////////////////////////////////////////////
	for (int k = 0; k < 8; k++)
	{
	for (int i = 7; i >= 0; i--)
	{
		for (int j = 0; j < 8; j++)
		{	
			swap(i,j);
		}
	}
	}
	
	srand (time(NULL));
	for(int i=0;i<8;i++)
	 {
	 	for(int e=0;e<8;e++)
		{
			int k= rand() % 4 + 1;
			int aux1;
			aux1=pokemonCrush[i][e].getNum();
			if(aux1==0)
			{
				pokemonCrush[i][e].setNum(k);
			}
		}
	 } 
}

void Tablero::swap(int i, int j)
{
	if ((i==0) && (pokemonCrush[i][j].getNum()== 0))
	{
	}
	else
	{
		if (pokemonCrush[i][j].getNum()== 0)
		{
			pokemonCrush[i][j].setNum(pokemonCrush[i-1][j].getNum());
			pokemonCrush[i-1][j].setNum(0);
		}
	}
}

void Tablero::drawmatrix()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << pokemonCrush[i][j].getNum() << "  ";
		}
		cout << endl;
	}
	cout <<endl;
}
void Tablero::escribirArchivo(){
	ofstream archivo("save.dat",ios::out);
	int level=0;
	int time=0;
	int pok1=0;
	int pok2=0;
	int pok3=0;
	int pok4=0;
	int pok5=0;
	int linea=0;
	string nombre[7]={"Level","Time","Pokemon1","Pokemon2","Pokemon3","Pokemon4","Pokemon5"};   
	int contenido[7]={level,time,pok1,pok2,pok3,pok4,pok5}; 
	if (!archivo){
		cout<<"no se pudo abrir el archivo"<<endl;       
	}
	else{
		for(int z=0;z<=6;z++){
			linea=linea+1;
			archivo<<linea<<' '<<nombre[z]<<' '<<contenido[z]<<endl;
		}
		linea=7;
		for(int i=0;i<=7;i++){
			linea=linea+1;
			archivo<<linea<<' ';
			for(int a=0;a<=7;a++){
				archivo<<pokemonCrush[i][a].getNum()<<' ';
			}
			archivo<<endl;
		}
	}
}
void Tablero::leerArchivo() {     
	ifstream archivo("save.dat",ios::in); //el archivo se abre para lectura   
	if (!archivo){ 
	    cerr<<"Error, archivo no encontrado!!"<<endl;
		}    
	else{
		int b;
		int linea;
		string snombre[7];
		int scontenido[7];
		for(int z=0;z<=6;z++){
			archivo>>linea>>snombre[z]>>scontenido[z];
			cout<<linea<<" "<<snombre[z]<<" "<<scontenido[z]<<endl;
		}  
        for(int i=0;i<=7;i++){
          	archivo>>linea;
          	cout<<linea<<" ";
			for(int a=0;a<=7;a++){
				archivo>>b;
				cout<<b<<" ";
				pokemonCrush[i][a].setNum(b);
			}
			cout<<endl;
		  }
	}
	archivo.close();
}
