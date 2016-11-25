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
{	
	int x,y,x1,y1,op1, op2;
	int t = 0;
	int veces =0;
	Tablero matrix1;
	int cantidad1,cantidad2,cantidad3,cantidad4,cantidad5;
	int tipo1,tipo2,tipo3,tipo4,tipo5;
	bool mIni;
	mIni=true;
	cantidad1=0;
	cantidad2=0;
	cantidad3=0;
	cantidad4=0;
	cantidad5=0;
	tipo1=1;
	tipo2=2;
	tipo3=3;
	tipo4=4;
	tipo5=5;
	
	while(op2 != -1)
	{
		cout << "Digite la opcion: \n";
		cout << "1 - Iniciar nueva partida \n";
		cout << "2 - Cargar ultima partida \n";
		cout << "3 - Salir \n";
		cin >> op2;
		switch (op2)
		{
			case 1:
				
				break;
			case 2:
				matrix1.leerArchivo();
				break;
			case 3:
				op2= -1;
				op1= -1;
				break;
		}
		
		while(op1 != -1)
		{
			mIni=true;
			
			while (mIni)
			{
				mIni=false;
				for(int i=0; i<=7;i++)
				{
					for(int j=0; j<=7;j++)
					{
						int prueba1=matrix1.retoUno (i,j);
						switch (prueba1)
						{
							case 1:
								mIni=true;
								cantidad1--;
								
						matrix1.drawmatrix();
								matrix1.fillmatrix();
								break;
							case 2:
								mIni=true;
								cantidad2--;
								
						matrix1.drawmatrix();
								matrix1.fillmatrix();
								break;
							case 3:
								mIni=true;
								cantidad3--;
								
						matrix1.drawmatrix();
								matrix1.fillmatrix();
								break;
							case 4:
								mIni=true;
								cantidad4--;
								
						matrix1.drawmatrix();
								matrix1.fillmatrix();
								break;
							default:
								break;
								
							
						}					
						matrix1.fillmatrix();
					}
				}
					veces++;
				cout<<endl;
				matrix1.drawmatrix();
			}
			cout <<"Se ejecuto "<< veces<<" veces por matches"<< endl;
			veces=0;
			cout << "Necesitas "<< cantidad1<<" pokemon de tipo " <<tipo1 << endl;
			cout << "Necesitas "<< cantidad2<<" pokemon de tipo " <<tipo2 << endl;
			cout << "Necesitas "<< cantidad3<<" pokemon de tipo " <<tipo3 << endl;
			cout << "Necesitas "<< cantidad4<<" pokemon de tipo " <<tipo4 << endl;
			cout << "Necesitas "<< cantidad5<<" pokemon de tipo " <<tipo5 << endl;
			//matrix1.drawmatrix();
			cout << "Digite la opcion: \n";
			cout << "1 - Cambiar numero \n";
			cout << "2 - Guardar y salir \n";
			
			cin >> op1;
			switch(op1)
			{		
				case 1:
					cout << "x: ";
					cin >> x;
					cout << "y: ";
					cin >> y;
					cout << "x1: ";
					cin >> x1;
					cout << "y1: ";
					cin >> y1;
					if(matrix1.validMove(x,y,x1,y1))
					{
						matrix1.movCaja(x,y,x1,y1);
						int prueba1=matrix1.retoUno (x1,y1);
						switch (prueba1)
						{
							case 1:
								mIni=true;
								cantidad1--;
								
						matrix1.drawmatrix();
								matrix1.fillmatrix();
								break;
							case 2:
								mIni=true;
								cantidad2--;
								
						matrix1.drawmatrix();
								matrix1.fillmatrix();
								break;
							case 3:
								mIni=true;
								cantidad3--;
								
						matrix1.drawmatrix();
								matrix1.fillmatrix();
								break;
							case 4:
								mIni=true;
								cantidad4--;
								
						matrix1.drawmatrix();
								matrix1.fillmatrix();
								break;
							default:
								break;
								
							
						}							
						matrix1.fillmatrix();
						matrix1.drawmatrix();
					}
					break;

				case 2:
					matrix1.escribirArchivo ();
					op2=-1;
					op1=-1;
					break;
			}			
		}
	}
	return 0;
}