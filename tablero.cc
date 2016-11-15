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
 //Caja pokemonCrush[8][8]= {};
 int j= rand() % 8;
 int k= rand() % 4;
 for(int i=0;i<8;i++)
 {
 	for(int e=0;e<8;e++)
	{
		 int k= rand() % 4 + 1;
		pokemonCrush[i][e].setCoordenada(i, e);
		pokemonCrush[i][e].setNum(k);
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
				pokemonCrush[i][j].setCanBeFree();
				pokemonCrush[i][j].setNum(6);
			}
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Tablero::validMove (int f,int c, int i, int e)
{
	int dir;
	dir=0;
	if (f==i)
	{
		int aux1, aux2, aux3, aux4, aux5;
		aux1=pokemonCrush[f][c].getNum();
		aux2=pokemonCrush[i][e+1].getNum();
		aux3=pokemonCrush[i][e+2].getNum();
		aux4=pokemonCrush[i][e-1].getNum();
		aux5=pokemonCrush[i][e-2].getNum();
		if((c==(e+1)) || (c==(e-1)))
		{
			if(((aux1==aux2)&&(aux1==aux3))||((aux1==aux4)&&(aux1==aux5)))
			{
				dir=1;
			}
				
		}
	}
	if (c==e)
	{
		int aux1, aux2, aux3, aux4, aux5;
		aux1=pokemonCrush[f][c].getNum();
		aux2=pokemonCrush[i+1][e].getNum();
		aux3=pokemonCrush[i+2][e].getNum();
		aux4=pokemonCrush[i-1][e].getNum();
		aux5=pokemonCrush[i-2][e].getNum();
		if((c==(e+1)) || (c==(e-1)))
		{
			if(((aux1==aux2)&&(aux1==aux3))||((aux1==aux4)&&(aux1==aux5)))
			{
				dir=2;
			}
				
		}
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

    makeRemov(i,e,dir);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Tablero::makeRemov(int i, int e, int dir)
{
//setea removible la posicion inicial
    pokemonCrush[i][e].setRemov();
    
    int aux1;
    aux1=pokemonCrush[i][e].getNum();
    
    bool condicion, condicion2;
    condicion=true;    
    condicion2=true;
    
    switch (dir)
    {
        case 1:// caso misma columna
        int auxV1;
        //ejecuta hacia abajo 
        for (int l=(e+1);condicion;l++)
        {
            auxV1=pokemonCrush[i][l].getNum();
            if (aux1==auxV1)
            {
                pokemonCrush[i][l].setRemov();
            }
            else 
            {
                condicion=false;
            }
        }
        condicion=true;
        //ejecuta hacia arriba
        for (int l=(e-1);condicion;l++)
        {
            auxV1=pokemonCrush[i][l].getNum();
            if (aux1==auxV1)
            {
                pokemonCrush[i][l].setRemov();
            }
            else 
            {
                condicion=false;
            }
        }
        break;
        
        case 2:// caso misma fila 
        int auxH1;
        //ejecuta hacia la derecha 
        for (int t=(i+1);condicion;t++)
        {
            auxV1=pokemonCrush[t][e].getNum();
            if (aux1==auxH1)
            {
                pokemonCrush[t][e].setRemov();
            }
            else 
            {
                condicion=false;
            }
        }
        condicion=true;
        //ejecuta hacia la izquierda
        for (int t=(i-1);condicion;t++)
        {
            auxV1=pokemonCrush[t][e].getNum();
            if (aux1==auxV1)
            {
                pokemonCrush[t][e].setRemov();
            }
            else 
            {
                condicion=false;
            }
        }
        break;
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Tablero::retoUno()
{
   for (int i=0;i<8;i++)
   {
      for (int j=0;j<8;j++)
      {    
          int aux1, aux2, aux3;
          aux1=pokemonCrush[i][j].getNum();
          aux2=pokemonCrush[i][j+1].getNum();
          aux3=pokemonCrush[i][j+2].getNum();
		  int aux4, aux5;
          if (j>=1)
          {
          aux4=pokemonCrush[i][j-1].getNum();
          }
          if (j>=2)
          {
          aux5=pokemonCrush[i][j-2].getNum();
          }
          if (aux1==aux2 && aux1==aux3)
		  {
			  makeRemov(i,j,2);
		  }
          if(aux1==aux4 && aux1==aux5)
		  {
             makeRemov(i,j,2);
		  }
          if (aux1==aux2 && aux1==aux4)
		  {
			  makeRemov(i,j,2);
		  }
                
      }
   }
   for (int j=0;j<8;j++)
   {
      for (int i=0;i<8;i++)
      {    
          int aux1, aux2, aux3, aux4, aux5;
          aux1=pokemonCrush[i][j].getNum();
          aux2=pokemonCrush[i+1][j].getNum();
          aux3=pokemonCrush[i+2][j].getNum();
          if (i>=1)
          {
          aux4=pokemonCrush[i-1][j].getNum();
          }
          if (i>=2)
          {
          aux5=pokemonCrush[i-2][j].getNum();
          }
		  if (aux1==aux2 && aux1==aux3)
		  {
			  makeRemov(i,j,1);
		  }
          if (aux1==aux4 && aux1==aux5)
		  {
			  makeRemov(i,j,1);
		  }
          if (aux1==aux2 && aux1==aux4)
		  {
			  makeRemov(i,j,1);
		  }
          
          }
                
      }
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
}
