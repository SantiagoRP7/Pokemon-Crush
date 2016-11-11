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

#ifndef _TABLERO_H_
#define _TABLERO_H_

#include <string>
#include <vector>
#include "coordenada.h"
#include "caja.h"


using namespace std;

class Tablero
{
public:
  Tablero();
  ~Tablero();
  void leerNivel(string lev);
  void showInstruc();
  // void showTablero();
  void cambCaja(const Coordenada (* ), Direcction);
  vector <const Coordenada * > verifVerti();
  vector <const Coordenada * > verifHoriz();
//  bool hayPokeball(const Coordenada *c);
  bool CompMatch();
 // void pokeOpen(const Coordenada *c);
  void toWin(Caja *b);
  //[aumentarValorLateral]
  void liberarCaja();
  bool validarCoor();
  void bajarCajas();
  void generarCajas();
 // void letPokeball();
 //fiveMarcthEfect();
 //ConfirmarMovimiento();
 void jugar();

protected:

private:

};

#endif // _TABLERO_H_
