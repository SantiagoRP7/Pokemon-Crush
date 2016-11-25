/* -*- Mode: C++; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
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
	 CRC
	 Clase: Caja.
	 Responsabilidad: Simula ser una caja que contiene atributos para ser utilizados.
	 Colaboracion: Deja que la Clase tablero use sus metodos y modifique sus atributos.
	 
 */

#ifndef _CAJA_H_
#define _CAJA_H_

#include "coordenada.h"

class Caja
{
public:
  Caja();
  ~Caja();
  int getValor();
  int getNum();
  void setNum(int num1);
  void setValor(int valor1);
  void setCoordenada(int x, int y);
  void setMove();
  void setCanBeFree();
  void setCantBeFree();
  bool getCanBeFree();
  void setRemov();

protected:

private:
	int num; // representacion de pokemon.
	int valor; // 
	Coordenada coor;// donde "coor" es la cooredenada relativa de la caja en la matriz.
};

#endif // _CAJA_H_
