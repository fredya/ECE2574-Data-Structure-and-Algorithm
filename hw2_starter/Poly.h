////////////////////////////////////////////////////////
//  ECE 2574, Homework 2  
//  Description: Class specification file for a polyline ADT 
//				 that uses a linked-list representation to store a sequence of 2D points.
//  Date:        2/10/2018
/** @file Poly.h */

#ifndef POLYLINE_
#define POLYLINE_

#include "PolyInterface.h"		// Interface file for abstract base class PolyInterface 
#include "Node.h"				// Interface file for Node class

template<class ItemType>
class Poly : public PolyInterface<ItemType>
{
private:
	Node<ItemType> *headPtr;	// Pointer to head node of linked list
	int pointCount;				// Current count of points in this polyline

   /** Returns either a pointer to the node with the given index,
				or the null pointer if that index is not in the linked list.
	@param		index - the index of the point in the polyline  
	@return		A pointer to a node, or nullptr
	*/
	Node<ItemType> *getPointerTo(const int index) const;   

public:
	Poly();                                // Default constructor
	Poly(const Poly<ItemType>& aPolyline); // Copy constructor	
	bool isEmpty() const;
	int  getNumberOfPoints() const;
	bool insert(const ItemType x, const ItemType y, int index); 
    bool remove(const int index);
	void clear();
	ItemType getCoordinateX(const int index) const;
	ItemType getCoordinateY(const int index) const;
	double getArcLength() const;
	bool translate(const ItemType deltaX, const ItemType deltaY);

	/** Overload the '+' operator to concatenate 2 polylines.
	 @pre     Two valid polylines exist
	 @post    If the initial polylines are p and q, 
		then the result of p+q will be a newly created polyline that contains
		nodes identical to those in p followed by nodes identical to those in q
    @param rightHandSide  This is a polyline at the right of '+' (q in discussion above)
    @return   A valid polyline */
	Poly<ItemType>& operator+(const Poly<ItemType>& rightHandSide) const;

	/** Overload the '=' operator to perform assignment.
	@pre     Two valid polylines exist
	@post    If the initial polylines are p and q,
		then operation p=q will cause p to contain a copy of the polyline in q.
	@param rightHandSide  This is a polyline at the right of '=' (q in discussion above)
	@return   A valid polyline */
	Poly<ItemType>& operator=(const Poly<ItemType>& rightHandSide);

	/** Destructor- must delete any memory that has been dynamically allocated */
	virtual ~Poly();	
}; // end Poly

#include "Poly.cpp"	// Implementation file for the Poly class
#endif
