#pragma once
#include <vector>
#include <functional>

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
		Vertex<T>& getDest()
		{
			return *dest;
		}

	private:
		Vertex<T>* source;
		Vertex<T>* dest;
		int weight;
		bool visited = false;	//	We'll see about this.
	};

	std::vector<Edge> edges;

public:
	bool visited = false;

	Vertex<T>(T d) : data(d) {}	//	simple constructor.

	//	Adds a neighbouring vertex with a value along a weighted edge.
	void addNeighbour(T val, int w = 1)	
	{
		//	Create a new edge of weight w connecting to a new vertex of data val.
		edges.push_back(Edge(new Vertex<T>(val), w));
		edges.back().getDest().edges.push_back(Edge(this, w));
	}

	//	Function to connect to another already-created vertex.
	void connectTo(Vertex<T>& vert, int w = 1)	
	{
		//	Connect to a pre-existing vertex
		edges.push_back(Edge(&vert, w));
		vert.edges.push_back(Edge(this, w));
	}

	//	Mark this node as visited and get its data value.
	T visit()
	{
		visited = true;
		return data;
	}

	//	Commit 7: Will update this function accordingly... if it becomes needed. Probably will anyways, for sake of completeness.
	//	Get a vector of vertices connect to this one.
	std::vector<std::reference_wrapper<Vertex<T>>> getVertices()	
	{
		std::vector<std::reference_wrapper<Vertex<T>>> result;
		
		for (auto& edge : edges)
		{
			result.push_back(edge.getDest());
		}

		return result;
	}

	//	Get a list of unvisited vertices connect to this one.
	std::vector<std::reference_wrapper<Vertex<T>>> getUnvisitedVertices()	
	{
		std::vector<std::reference_wrapper<Vertex<T>>> result;

		for(auto& edge : edges)
		{
			if (!(edge.getDest().visited))
				result.push_back(edge.getDest());
		}

		return result;
	}
};