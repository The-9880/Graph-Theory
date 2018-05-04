#pragma once
#include "Vertex.h"
#include <iostream>
#include <queue>

//	Contains algorithms to be run on the graphs I'll construct with my vertices.

template <typename T>
class GraphAlgs
{
public:
	GraphAlgs() {};
	~GraphAlgs() {};

	static void BFS(Vertex<T>& v, T target)	//	Breadth-first search function for seeking a specific T.
	{
		std::queue<Vertex<T>> verts;

		verts.push(v);

		while (!verts.empty())	//	while we have vertices to perform BFS on
		{
			T data = verts.front().visit();	//	visit the next node in the queue
			if (data == target)
			{
				std::cout << "Found target!\n";
				return;
			}

			std::vector<Vertex<T>> unvis = verts.front().getUnvisitedVertices();	//	get a list of this node's unvisited neighbours.
			verts.pop();	//	pop our visited node off the list once we've gotten the next-level nodes.

			for (auto& u : unvis)	//	place each next-level node in the queue.
			{
				verts.push(u);
			}
			unvis.clear();	//	clear my temporary list.


		}

		std::cout << "Could not find target in the graph.\n";
	}
};

