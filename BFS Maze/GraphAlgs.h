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

	 static std::list<Vertex<T>*> pathTo(Vertex<T>& v, T target)
	{
		std::list<Vertex<T>*> allVisited;
		std::list<Vertex<T>*> path;

		bool result = recursiveBFSPath(v, target, path, allVisited);	//	Modify recursiveBFSPath to function under this definition.
		std::cout << std::endl;
		
		for (auto& vertex : path)
		{
			std::cout << vertex->visit() << " ";
		}
		std::cout << std::endl;

		unmarkNodes(allVisited);

		return path;
	}

	static bool recursiveBFSPath(Vertex<T>& v, T target, std::list<Vertex<T>*>& path, std::list<Vertex<T>*>& visited)
	{
		std::vector<std::reference_wrapper<Vertex<T>>> unVis;
		std::list<Vertex<T>*> pathFromHere;

		visited.push_back(&v);

		if (v.visit() == target)	//	Right here - can, at this point, store 'path' in a super vector that holds vectors of successful paths
		{							//	to be later compared with each other. Same thing at the other success point.
			path.push_back(&v);
			return true;
		}
		else
		{
			unVis = v.getUnvisitedVertices();

			if (!unVis.empty())
			{
				pathFromHere.push_back(&v);
				for (auto& vertex : unVis)
				{
					if (recursiveBFSPath(vertex, target, pathFromHere, visited))
					{
						path.insert(std::end(path), std::begin(pathFromHere), std::end(pathFromHere));
						return true;
					}
				}
			}
			else
			{
				path.clear();
				return false;
			}
		}
		path.clear();
		return false;
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

