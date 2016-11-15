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

#include "caja.h"
#include "coordenada.h"
#include <iostream>
using namespace std;

Caja::Caja()
{
  valor=0;
  num=0;
  canBeFree= false;
  move=true;
}
Caja::~Caja()
{
}

int Caja::getValor()
{
  return valor;
}

int Caja::getNum()
{
  return num;
}

void Caja::setNum(int num1)
{
  num=num1;
}

void Caja::setValor(int valor1)
{
  valor=valor1;
}

void Caja::setCoordenada(int x, int y)
{
	coor.setX(x);
	coor.setY(y);
}

void Caja::setMove()
{
	move= !move;
}

void Caja::setCanBeFree()
{
	canBeFree = !canBeFree;
}

bool Caja::getCanBeFree()
{
	return canBeFree;
}
void Caja::setRemov()
{
		removable=true;
}