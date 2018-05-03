#pragma once
#include "Vertex.h"
#include <queue>

//	Contains algorithms to be run on the graphs I'll construct with my vertices.

template <typename T>
class GraphAlgs
{
public:
	GraphAlgs();
	~GraphAlgs();

	void BFS(Vertex<T> v, T target);	//	Breadth-first search function for seeking a specific T.
};

