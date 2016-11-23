/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * main.cc
 * Copyright (C) 2016 CRISTIAN MANOSALVA BELTRAN <crismb@s4pc20>
 * 
 * foobar-cpp is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * foobar-cpp is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
using namespace std;
#include "caja.h"
#include "tablero.h"

int main()
{	int x,y,x1,y1,op;
	int t = 0;
	int veces =0;
	Tablero matrix1;
	matrix1.drawmatrix();
	cout << "----------------\n";

	bool mIni;
	mIni=true;
	while (mIni)
	{
		mIni=false;
		for(int i=0; i<=7;i++)
		{
			for(int j=0; j<=7;j++)
			{
				if (matrix1.retoUno (i,j))
				{
					matrix1.liberarCaja();
					matrix1.fillmatrix();
					veces++;
					mIni=true;
				}
				matrix1.inicialMatrix();
			}
		}
	}
	veces=0;
	
	cout << "----------------\n";
	matrix1.drawmatrix();
	while(op != -1)
	{
		cout << "1 - Consulta \n";
		cout << "2 - Cambiar numero \n";
		cout << "3 - rellenar \n";
		cout << "4 - Dibujar \n";
		cout << "OP: ";
		cin >> op;
		switch(op)
		{
			case 1:
				/*
				matrix1.liberarCaja();
				matrix1.drawmatrix();
				cout << "x: ";
				cin >> x;
				cout << "y: ";
				cin >> y;
				//cout << "Pos requerida: "<<matrix1.getnumpos(x,y)<<endl;

			*/	break;
			
			case 2:
				//matrix1.liberarCaja();
				cout << "x: ";
				cin >> x;
				cout << "y: ";
				cin >> y;
				cout << "x1: ";
				cin >> x1;
				cout << "y1: ";
				cin >> y1;
				matrix1.validMove(x,y,x1,y1);
				matrix1.liberarCaja();
				//matrix1.inicialMatrix();
				matrix1.drawmatrix();
				matrix1.fillmatrix();
				//matrix1.inicialMatrix();
				matrix1.drawmatrix();
				break;
			
			case 3:
				matrix1.fillmatrix();
				matrix1.liberarCaja();
				matrix1.drawmatrix();
								
				cout << "----------------\n";
				matrix1.drawmatrix();
				break;
			case 4:
				matrix1.liberarCaja();
				cout << "----------------\n";
				matrix1.drawmatrix();
				cout << "----------------\n";
		}			
	}
		
	return 0;
}