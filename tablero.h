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
	 CRC:
	 Clase: Tablero
	 Responsabilidad: Simula ser un tablero que contiene Cajas equivalentes a un pokemon.
	 Colaboracion: Usa la clase Caja para modificar posiciones y atributos.
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
  bool CompMatch();
  void toWin(Caja *b);
  void liberarCaja();
  bool validarCoor();
  void bajarCajas();
  void generarCajas();
  void jugar();
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  bool validMove(int f,int c, int i, int e);
  void movCaja(int f, int c, int i,int e);
  void makeRemov(int i, int e, int dir, int prov);
  int retoUno(int i, int e);
  void quedanMov();
/////////////////////////////////////////
  void fillmatrix();
  void drawmatrix();
  void swap(int i, int j);
  bool inicialMatrix();
	void escribirArchivo();
	void leerArchivo();
 
protected:

private:
Caja pokemonCrush[8][8];

};

#endif // _TABLERO_H_