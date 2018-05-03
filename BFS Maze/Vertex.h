#pragma once
#include <vector>

template <typename T> class Vertex
{
public:
	
	void addNeighbour(T val, int w=1);	//	Adds a neighbouring vertex with a value along a weighted edge.
	void connectTo(Vertex* vert, int w = 1;);	//	Function to connect to another already-created vertex.
	std::vector<Edge>& getEdges();	//	Returns a reference to the vector of edges for this vertex.

private:
	T data;
	std::vector<Edge> edges;

	//	Inner class
	class Edge
	{
	public:
		Edge(Vertex* dst, int w = 1) : weight(w), dest(dst)
		{
		}

	private:
		Vertex* source;
		Vertex* dest;
		int weight;
	};

};