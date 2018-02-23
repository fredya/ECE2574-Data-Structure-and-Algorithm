//////////////////////////////////////////////////////////////////////////////
// ECE 2574, Homework 2
//
// File Name:	Node.cpp
// Description:	The implementation file for a Node object to be used in a linked
//				list, with one node representing the exponent and coefficient
//				of a term of a polynomial.
// Date:		2/11/2018
// Adapted from Frank M. Carrano and Timothy M. Henry.
//
/** @file Node.cpp  */

#include "Node.h"

template<class ItemType>
Node<ItemType>::Node() : next(nullptr)
{
} // end default constructor

template<class ItemType>
Node<ItemType>::Node(const ItemType x, const ItemType y)
				: itemX(x), itemY(y), next(nullptr)
{
} // end constructor


template<class ItemType>
Node<ItemType>::Node(const ItemType x, const ItemType y, Node<ItemType> *nextNodePtr)
				: itemX(x), itemY(y), next(nextNodePtr)
{
} // end constructor


template<class ItemType>
void Node<ItemType>::setX(const ItemType x)
{
	itemX = x;
} // end setX


template<class ItemType>
void Node<ItemType>::setY(const ItemType y)
{
	itemY = y;
} // end setY


template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType> *nextNodePtr)
{
	next = nextNodePtr;
} // end setNext


template<class ItemType>
ItemType Node<ItemType>::getX() const
{
	return itemX;
} // end getX


template<class ItemType>
ItemType Node<ItemType>::getY() const
{
	return itemY;
} // end getY


template<class ItemType>
Node<ItemType> *Node<ItemType>::getNext() const
{
	return next;
} // end getNext