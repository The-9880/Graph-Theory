#include "GraphAlgs.h"


int main()
{
	//	Let us initialize a graph first.
	Vertex<char> v1('S');

	Vertex<char> v2('N');
	Vertex<char> v3('L');
	Vertex<char> v4('P');

	Vertex<char> v5('O');
	Vertex<char> v6('O');
	Vertex<char> v7('F');


	v1.connectTo(v2);
	v1.connectTo(v3);
	v1.connectTo(v4);

	v2.connectTo(v5);
	v2.connectTo(v6);
	v3.connectTo(v6);
	v4.connectTo(v7);

	v5.connectTo(v6);
	v6.connectTo(v7);

	GraphAlgs<char>::BFS(v1, 'F');
	GraphAlgs<char>::BFS(v1, 'L');

	v7.addNeighbour('T');
	GraphAlgs<char>::BFS(v1, 'T');

	GraphAlgs<char>::BFS(v3, 'S');
	GraphAlgs<char>::BFS(v7, 'S');


	system("pause");
	return 0;
}