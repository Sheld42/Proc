#include "container.h"
#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

void Out(shape *s, ofstream &ofst);
double Volume(shape *s);
void CheckOutputFile(ofstream &ofst);

void MultiMethod(container &c, ofstream &ofst)
{
	CheckOutputFile(ofst);
	if (c.len)
	{
		ofst << "MultiMethods:\n";
	}
	else
	{
		ofst << "Container is empty.\n";
		return;
	}

	shape* s1;
	shape* s2;
	for (int i = 0; i < c.len; i++)
	{
		s1 = c.cont[i];
		for (int j = 0; j < c.len; j++)
		{
			s2 = c.cont[j];
			switch (s1->key)
			{
			case shape::type::BALL:
			{
				switch (s2->key)
				{
				case shape::type::BALL:
				{
					ofst << "Ball and Ball:\n";
					break;
				}
				case shape::type::PARALLELEPIPED:
				{
					ofst << "Ball and Parallelepiped:\n";
					break;
				}
				case shape::type::TETRAEDR:
				{
					ofst << "Ball and Tetraedr:\n";
					break;
				}
				default:
					break;
				}
				break;
			}
			case shape::type::PARALLELEPIPED:
			{
				switch (s2->key)
				{
				case shape::type::BALL:
				{
					ofst << "Parallelepiped and Ball:\n";
					break;
				}
				case shape::type::PARALLELEPIPED:
				{
					ofst << "Parallelepiped and Parallelepiped:\n";
					break;
				}
				case shape::type::TETRAEDR:
				{
					ofst << "Parallelepiped and Tetraedr:\n";
					break;
				}
				default:
					break;
				}
				break;
			}
			case shape::type::TETRAEDR:
			{
				switch (s2->key)
				{
				case shape::type::BALL:
				{
					ofst << "Tetraedr and Ball:\n";
					break;
				}
				case shape::type::PARALLELEPIPED:
				{
					ofst << "Tetraedr and Parallelepiped:\n";
					break;
				}
				case shape::type::TETRAEDR:
				{
					ofst << "Tetraedr and Tetraedr:\n";
					break;
				}
				default:
					break;
				}
				break;
			}
			default:
				break;
			}

			Out(s1, ofst);
			Out(s2, ofst);
			ofst << endl;
		}
	}
	ofst.close();
}