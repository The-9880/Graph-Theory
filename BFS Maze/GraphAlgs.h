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
		std::queue<Vertex<T>*> verts;

		verts.push(&v);

		while (!verts.empty())	//	while we have vertices to perform BFS on
		{
			T data = verts.front()->visit();	//	visit the next node in the queue
			if (data == target)
			{
				std::cout << "Found target!\n";
				return;
			}
			else
			{
				std::cout << "Found: " << data << std::endl;
			}

			//	IDENTIFIED AS PROBLEM LINE: (4/5/18)
			std::vector<Vertex<T>*> unvis = std::move(verts.front()->getUnvisitedVertices());	//	implicit move; get a list of this node's unvisited neighbours.
			verts.front()->getUnvisitedVertices();	//	Second check to ensure my original pointer aren't invalidated; they aren't.
			verts.pop();	//	pop our visited node off the list once we've gotten the next-level nodes.
			
			std::cout << "TEST:" << unvis[0]->peek() << std::endl;

			for (typename std::vector<Vertex<T>*>::iterator iter = unvis.begin(); iter != unvis.end(); ++iter)	//	place each next-level node in the queue.
			{
				verts.push(*iter);
			}
			unvis.clear();	//	clear my temporary list.
		}

		std::cout << "Could not find target in the graph.\n";
	}
};

