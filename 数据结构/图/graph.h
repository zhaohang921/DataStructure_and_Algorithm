#ifndef GRAPH_H
#define GRAPH_H

#include<iostream>

using namespace std;

template <typename T>
class edge
{
public:
    virtual ~edge() {};
    virtual int vertex1() const = 0;
    virtual int vertex2() const = 0;
    virtual T weight() const = 0;
};
//
template<typename T>
class vertexIterator 
{
   public:
      virtual ~vertexIterator() {}
      virtual int next() = 0;
      virtual int next(T&) = 0;
};
//图的抽象类
template<typename T>
class graph{
public:
    graph(){}
    virtual ~graph(){}
    virtual int numberofVertices() const = 0;
    virtual int numberofEdges() const = 0;
    virtual int existsEdges(int , int ) const = 0;
    virtual int insertEdge(edge<T>* ) =0;
    virtual void eraseEdge(int, int) = 0;
    virtual int degree(int) const = 0;
    virtual int inDegree(int) const = 0;
    virtual int outDegree(int) const = 0;

    virtual bool directed() const = 0; //当且仅当是有向图时，返回值是true
    virtual bool weighted() const = 0; //当且仅当是加权图时，返回值是true
    virtual vertexIterator<T>* iterator(int) = 0; //访问指定顶点的相邻顶点
    virtual void output(ostream&) const = 0;


};











#endif