#pragma once
#include <vector>

//	worth noting that if I want to add the edges as connections to both vertices' edge lists instead of
//	just the 'source' vertex (as this currently mimics a directed graph), I could add a boolean for visitations
//	for usage during Graph algorithms and then add the edge to each vertex's list when it is created.
//	For directed graphs, however, the current implementation works well enough - each vertex maintains
//	a list of its outgoing edges.

template <typename T> class Vertex
{
private:
	T data;

	//	Inner class
	class Edge
	{
	public:
		Edge(Vertex<T>* dst, int w = 1) : weight(w), dest(dst)
		{
		}
		Vertex<T> getDest()
		{
			return *dest;
		}

	private:
		Vertex<T>* source;
		Vertex<T>* dest;
		int weight;
		bool visited = false;
	};

	std::vector<Edge> edges;

public:
	bool visited = false;

	Vertex<T>(T d) : data(d) {}	//	simple constructor.

	void addNeighbour(T val, int w = 1)	//	Adds a neighbouring vertex with a value along a weighted edge.
	{
		//	Create a new edge connecting this vertex with a new vertex of data val
		//	with this edge having weight w.
		edges.push_back(new Edge(new Vertex<T>(val), w));
	}

	void connectTo(Vertex<T>& vert, int w = 1)	//	Function to connect to another already-created vertex.
	{
		//	Connect to a pre-existing vertex
		edges.emplace_back(new Edge(vert, w));
	}

	T visit()	//	mark this node as visited and get its data value.
	{
		visted = true;
		return data;
	}

	std::vector<Vertex<T>> getVertices()	//	returns a vector of vertices connect to this one.
	{
		std::vector<Vertex<T>> result;

		for (std::vector<Edge>::iterator iter = edges.begin(); iter != edges.end(); ++iter)
		{
			result.push_back(iter->getDest());
		}

		return result;
	}


	std::vector<Vertex<T>> getUnvisitedVertices()	//	returns a list of unvisited vertices connect to this one.
	{
		std::vector<Vertex<T>> result;

		for (std::vector<Edge>::iterator iter = edges.begin(); iter != edges.end(); ++iter)
		{
			if (!(iter->getDest().visited))
				result.push_back(*iter);
		}

		return result;
	}
};