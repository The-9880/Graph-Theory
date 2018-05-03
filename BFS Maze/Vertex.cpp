#include "Vertex.h"

template <typename T>
void Vertex::addNeighbour(T val, int w = 1)
{
	//	Create a new edge connecting this vertex with a new vertex of data val
	//	with this edge having weight w.
	edges.push_back(new Edge(new Vertex(val), w));
}

template <typename T>
void connectTo(Vertex* vert, int w = 1)
{
	//	Connect to a pre-existing vertex
	edges.push_back(new Edge(vert, w));
}

template <typename T>
std::vector<Edge>& getEdges()
{
	return edges;	//	Return a reference to the edges vector
}
