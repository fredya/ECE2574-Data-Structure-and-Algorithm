//////////////////////////////////////////////////////////////////////////////
// ECE 2574, Homework 2
//
// File Name:	Node.h
// Description:	The header file for a Node object to be used in a linked
//				list, with one node containing the X and Y coordinates of a 2D point.
// Date:		2/11/2018
// Adapted from Frank M. Carrano and Timothy M. Henry.
//
/** @file Node.h  */

#ifndef NODE_
#define NODE_

template<class ItemType>
class Node
{
private:
    ItemType		itemX;		// X coordinate
    ItemType		itemY;		// Y coordinate
	Node<ItemType> *next;		// Pointer to next node in linked list
   
public:
	//Constructors
	Node();
	Node(const ItemType x, const ItemType y);
	Node(const ItemType x, const ItemType y, Node<ItemType> *nextNodePtr);

	/**			Sets the x-coordinate field of a Node object 
	@param		x - new value of x coordinate
	@return		None
	*/
	void setX(const ItemType x);

	/**			Sets the y-coordinate field of a Node object
	@param		x - new value of x coordinate
	@return		None
	*/
	void setY(const ItemType y);
	
	/**			Sets the next field of a Node object.
	@param		nextNodePtr - Represents a pointer to a Node object
				that is presumed be the next one in a linked list; 
				the value nullptr is used to indicate the tail node.
	@pre		nextNodePtr is either nullptr or the valid address of a Node object
	@post		the next field of this node contains the value nextNodePtr
	@return		None
	*/
	void setNext(Node<ItemType> *nextNodePtr);
	
	/**			Returns the X coordinate value from this node
	@param		None
	@pre		None
	@return		itemX
	*/
	ItemType getX() const;


	/**			Returns the Y coordinate value from this node
	@param		None
	@pre		None
	@return		itemY
	*/
	ItemType getY() const;

	/**			Returns the address of the next node in this linked list
	@param		None
	@pre		None
	@return		The 'next' value from this node
	*/
	Node<ItemType> *getNext() const;

}; // end Node

#include "Node.cpp"
#endif