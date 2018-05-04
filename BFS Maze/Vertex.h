#pragma once
#include <vector>

//	worth noting that if I want to add the edges as connections to both vertices' edge lists instead of
//	just the 'source' vertex (as this currently mimics a directed graph), I could add a boolean for visitations
//	for usage during Graph algorithms and then add the edge to each vertex's list when it is created.
//	For directed graphs, however, the current implementation works well enough - each vertex maintains
//	a list of its outgoing edges.

//	when I eventually update this for both vertices to contain the edge, edge vectors must be updated to be
//	vectors of edge pointers -- this way, both vertices will have a pointer to the same edge, rather than two copies
//	of the same edge, and when that edge is visited in any pass, it will be considered visited from the other vertex's perspective
//	as well.

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
		edges.push_back(Edge(new Vertex<T>(val), w));
	}

	void connectTo(Vertex<T>& vert, int w = 1)	//	Function to connect to another already-created vertex.
	{
		//	Connect to a pre-existing vertex
		edges.push_back(Edge(&vert, w));
	}

	T visit()	//	mark this node as visited and get its data value.
	{
		visited = true;
		return data;
	}

	std::vector<Vertex<T>*> getVertices()	//	returns a vector of vertices connect to this one.
	{
		std::vector<Vertex<T>*> result;
		
		for (typename std::vector<Edge>::iterator iter = edges.begin(); iter != edges.end(); ++iter)
		{
			result.push_back(&(iter->getDest()));
		}

		return result;
	}


	std::vector<Vertex<T>*> getUnvisitedVertices()	//	returns a list of unvisited vertices connect to this one.
	{
		std::vector<Vertex<T>*> result;


		for(typename std::vector<Edge>::iterator iter = edges.begin(); iter != edges.end(); ++iter)
		{
			if (!(iter->getDest().visited))
				result.push_back(&(iter->getDest()));	//	using implicit copy constructor
			std::cout << iter->getDest().peek() << std::endl;
		}

		return result;
	}

	T peek()
	{
		return data;
	}
};