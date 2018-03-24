#pragma once
#ifndef BSTREE_H
#define BSTREE_H

#include "Dictionary.h"

using namespace std;

template<class K, class E>
class BsTree : public Dictionary<K, E>
{
public:
	virtual void ascend() = 0;//°´¹Ø¼ü×ÖÉıĞòÊä³ö
};
#endif
