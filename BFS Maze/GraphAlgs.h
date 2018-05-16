#pragma once
#include "Vertex.h"
#include <iostream>
#include <queue>
#include <list>
#include <algorithm>

//	Contains algorithms to be run on the graphs I'll construct with my vertices.

template <typename T>
class GraphAlgs
{
public:
	GraphAlgs() {};
	~GraphAlgs() {};

	//	Breadth-first search function for seeking a specific T.
	static void BFS(Vertex<T>& v, T target)	
	{
		std::queue<Vertex<T>*> verts;
		std::list<Vertex<T>*> allVisited;

		verts.push(&v);
		allVisited.push_back(&v);

		while (!verts.empty())	//	while we have vertices to perform BFS on
		{
			T data = verts.front()->visit();	//	visit the next node in the queue
			if (data == target)
			{
				std::cout << "Found target!\n";

				//	Unmark the vertices.
				unmarkNodes(allVisited);

				// return; nothing else to be done here.
				return;
			}
			else
			{
				std::cout << "Found: " << data << std::endl;
			}

			std::vector<std::reference_wrapper<Vertex<T>>> unvis = verts.front()->getUnvisitedVertices();	//	implicit move; get a list of this node's unvisited neighbours.
			verts.pop();	//	pop our visited node off the list once we've gotten the next-level nodes.

			for (auto& unVert : unvis)	//	place each next-level node in the queue.
			{
				if (std::find(allVisited.begin(), allVisited.end(), &(unVert.get())) == allVisited.end())
				{
					verts.push(&(unVert.get()));
					allVisited.push_back(&(unVert.get()));
				}
			}
			unvis.clear();	//	clear my temporary list.
		}
		std::cout << "Could not find target in the graph.\n";

		//	Now to unmark the vertices I marked during the search.
		unmarkNodes(allVisited);
	}

private:

	//	Used to unmark nodes in a list of pointers to vertices; not in use yet because I'd like to retain the testing code I have.
	static void unmarkNodes(std::list<Vertex<T>*>& aList)
	{
		for (auto& unMark : aList)
		{
			unMark->visited = false;
		}
	}
};

