/*
 * @file dsets.cpp
 * Definition of the DisjointSets class for the EasyPNG library.
 * @see https://chara.cs.illinois.edu/cs225//doxygen/mp7/classDisjointSets.html
 *
 * @author Robert J Paul
 * @date Created: Fall 2014
 */

#include "dsets.h"

void DisjointSets::addelements(int num)
{
	for(int i = 0; i < num; i++)
		vect.push_back(-1);
}

int DisjointSets::find(int elem)
{
	if(vect[elem] < 0)
		return elem;

	else
	{
		vect[elem] = find(vect[elem]);
		return find(vect[elem]);
	}
}

void DisjointSets::setunion(int a, int b)
{
	int aRoot = find(a);
	int bRoot = find(b);
	int newSize = vect[aRoot] + vect[bRoot];

	if(aRoot == bRoot)
		return;

	else if(vect[aRoot] > vect[bRoot])
	{
		vect[aRoot] = bRoot;
		vect[bRoot] = newSize;
	}

	else
	{
		vect[aRoot] = newSize;
		vect[bRoot] = aRoot;
	}
}

