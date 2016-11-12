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