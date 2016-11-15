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
#include "caja.cc"
#include "coordenada.h"
#include <cstdlib>

Tablero::Tablero()
{
 //Caja pokemonCrush[8][8]= {};
 int j= rand() % 8;
 int k= rand() % 8;
 for(int i=0;i<8;i++)
 {
 	for(int e=0;e<8;e++)
	{
		pokemonCrush[i][e].setCoordenada(i, e);
		pokemonCrush[i][e].setNum(0);
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
void Tablero::cambCaja(const Coordenada caja1, const Coordenada caja2 )
{
 	
}

void Tablero::liberarCaja()
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			if (pokemonCrash[i][j].getCanBeFree() == true)
			{
				pokemonCrash[i][j].setCanBeFree;
				pokemonCrash[i][j].setNum(6);
			}
		}
	}
}










///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Tablero::validMove(int f,int c, int i, int e)
{
    int dir;
    dir=0;
    if (f==i)
    {
        switch (c)
        {
           case (e+1):
           {
              int aux1, aux2, aux3, aux4;
              aux1=pokemonCrush[f][c].getNum();
              aux2=pokemonCrush[i][e+1];
              aux3=pokemonCrush[i][e+2];
              aux4=pokemonCrush[i][e-1];
              aux5=pokemonCrush[i][e-2];
              switch  (aux1)
              {
                 case aux2:
                 if (aux1==aux3||aux1==aux4)
                 {
                    dir=2;
                 }
                 else{}
                 break;
                 case aux4:
                 if (aux1==aux2||aux1==aux5)
                 {
                    dir=2;
                 }
                 break;
              }
           }
           break;
           case (e-1):
           {
              int aux1, aux2, aux3, aux4;
              aux1=pokemonCrush[f][c].getNum();
              aux2=pokemonCrush[i][e-1];
              aux3=pokemonCrush[i][e-2];
              aux4=pokemonCrush[i][e+1];
              aux5=pokemonCrush[i][e+2];
              switch  (aux1)
              {
                 case aux2:
                 if (aux1==aux3||aux1==aux4)
                 {
                    dir=2;
                 }
                 else{}
                 break;
                 case aux4:
                 if (aux1==aux2||aux1==aux5)
                 {
                    dir=2;
                 }
              }
           }
           break;
        }
    }
    else
    {
    if (c==e)
    {
        switch (f)
        {
           case (i+1):
           {
              int aux1, aux2, aux3, aux4;
              aux1=pokemonCrush[f][c].getNum();
              aux2=pokemonCrush[i+1][e];
              aux3=pokemonCrush[i+2][e];
              aux4=pokemonCrush[i-1][e];
              aux5=pokemonCrush[i-2][e];
              switch  (aux1)
              {
                 case aux2:
                 if (aux1==aux3||aux1==aux4)
                 {
                    dir=1;
                 }
                 else{}
                 break;
                 case aux4:
                 if (aux1==aux2||aux1==aux5)
                 {
                    dir=1;
                 }
                 break;
              }
           }
           break;
           case (i-1):
           {
              int aux1, aux2, aux3, aux4;
              aux1=pokemonCrush[f][c].getNum();
              aux2=pokemonCrush[i-1][e];
              aux3=pokemonCrush[i-2][e];
              aux4=pokemonCrush[i+1][e];
              aux5=pokemonCrush[i+2][e];
              switch  (aux1)
              {
                 case aux2:
                 if (aux1==aux3||aux1==aux4)
                 {
                    dir=1;
                 }
                 else{}
                 break;
                 case aux4:
                 if (aux1==aux2||aux1==aux5)
                 {
                    dir=1;
                 }
              }
           }
           break;
        }
    }
    else{}
    }
    
    if (dir != 0)
    {
    movCaja(f,c,i,e,dir);
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Tablero::movCaja(int f, int c, int i,int e, int dir)
{
//Se crean dos auxiliares para guardar el numero del pokemon 
    int aux1,aux2;
    aux1=pokemonCrush[f][c].getNum;
    aux2=pokemonCrush[i][e].getNum;
//Se setea el nuevo valor en la posicion a ambas cajas
    pokemonCrush[f][c]=aux2;
    pokemonCrush[i][e]=aux1;

    makeRemov(i,e,dir);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Tablero::makeRemov(int i, int e int dir)
{
//setea removible la posicion inicial
    pokemonCrush[i][e].setRemov();
    
    int aux1;
    auxi1=pokemonCrush[i][e].getNum();
    
    bool condicion, condicion2;
    condicion=true;    
    condicion2=true;
    
    switch (dir)
    {
        case 1:// caso misma columna
        int auxV1;
        //ejecuta hacia abajo 
        for (l=(e+1);condicion;l++)
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
        for (l=(e-1);condicion;l++)
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
        for (t=(i+1);condicion;t++)
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
        for (t=(i-1);condicion;t++)
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
