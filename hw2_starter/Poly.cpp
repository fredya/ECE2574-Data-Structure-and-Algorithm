/////////////////////////////////////////////////////////////
//  HW2 -- starter - ALA 2/2018

/** Implementation file for the class Poly.
 @file Poly.cpp */

#include "Poly.h"
#include "Node.h"
#include <cstddef>

// TO-DO: Implement the default constructor here.
template<class ItemType>
Poly<ItemType>::Poly() 
{
	headPtr = nullptr;
	pointCount = 0;
}  // end default constructor

// TO-DO: Implement the copy constructor here.
template<class ItemType>
Poly<ItemType>::Poly(const Poly<ItemType>& aPoly)
{
	pointCount = aPoly.pointCount;
	Node<ItemType>* originalPtr = aPoly.headPtr;
	if (originalPtr == nullptr)
	{
		headPtr = nullptr;
	}
	else
	{
		headPtr = new Node<ItemType>();
		headPtr->setX(originalPtr->getX());
		headPtr->setY(originalPtr->getY());
		Node<ItemType>* newCurPtr = headPtr;
		Node<ItemType>* originalNextPtr = originalPtr->getNext();
		while (originalNextPtr != nullptr)
		{
			Node<ItemType>* newNodePtr = new Node<ItemType>();
			newCurPtr->setNext(newNodePtr);
			newNodePtr->setX(originalNextPtr->getX());
			newNodePtr->setY(originalNextPtr->getY());
			newCurPtr = newNodePtr;
			originalNextPtr = originalNextPtr->getNext();
		}
	}
} // end copy constructor

// TO-DO: Implement the isEmpty method here.
template<class ItemType>
bool Poly<ItemType>::isEmpty() const
{
	return pointCount == 0;
}  // end isEmpty

// TO-DO: Implement the getNumberOfPoints method here.
template<class ItemType>
int Poly<ItemType>::getNumberOfPoints() const
{
	return pointCount;
}  // end getNumberOfPoints

// TO-DO: Implement the insert method here.  The method must
// insert a node at location 'index', as described in the HW specification.
// No nodes are deleted. If index == 0, then the new node becomes the head node.
// If index == pointCount, then the new node is appended to the tail of the linked list.
template<class ItemType>
bool Poly<ItemType>::insert(const ItemType x, const ItemType y, int index)
{
	bool canInsert = (index > -1 && index < pointCount + 1);
	if (canInsert)
	{
		Node<ItemType>* curPtr = new Node<ItemType>();
		Node<ItemType>* newNodePtr = new Node<ItemType>();
		newNodePtr->setX(x);
		newNodePtr->setY(y);
		
		//std::cout << " " << "test" << curPtr->getX() << "test";
		if (index == 0)
		{
		newNodePtr->setNext(headPtr);
		headPtr = newNodePtr;
		pointCount++;
		}
		else if (index == pointCount)
		{
			curPtr = getPointerTo(index);
			curPtr->setNext(newNodePtr);
			pointCount++;
		}
		else
		{
			curPtr = getPointerTo(index);
			newNodePtr->setNext(curPtr->getNext());
			curPtr->setNext(newNodePtr);
			pointCount++;
		}
	}
    return canInsert;
}  // end add

// TO-DO: Implement the remove method here. 
// The node at location 'index', as described in the HW specification, must be removed.
template<class ItemType>
bool Poly<ItemType>::remove(const int index)
{
	bool canRemove = ((!isEmpty()) && index < pointCount && index > -1);
	if (canRemove)
	{
		Node<ItemType>* curPtr = new Node<ItemType>();
		Node<ItemType>* nodeToDeletePtr = new Node<ItemType>();
		
		bool isLastNode = (index == pointCount - 1);
		if (isLastNode)
		{
			curPtr = getPointerTo(index);
			nodeToDeletePtr = curPtr->getNext();
			nodeToDeletePtr->setNext(nullptr);
			curPtr->setNext(nullptr);
			delete nodeToDeletePtr;
			nodeToDeletePtr = nullptr;
		}
		else
		{
			if (index == 0)
			{
				nodeToDeletePtr = headPtr;
				headPtr = nodeToDeletePtr->getNext();
				nodeToDeletePtr->setNext(nullptr);
				delete nodeToDeletePtr;
				nodeToDeletePtr = nullptr;
			}
			else
			{
				curPtr = getPointerTo(index);
				nodeToDeletePtr = curPtr->getNext();
				curPtr->setNext(nodeToDeletePtr->getNext());
				nodeToDeletePtr->setNext(nullptr);
				delete nodeToDeletePtr;
				nodeToDeletePtr = nullptr;
			}
		}
		pointCount--;
	}

	return canRemove;
}  // end remove

// TO-DO: Implement the clear method here. 
template<class ItemType>
void Poly<ItemType>::clear()
{
	while (headPtr != nullptr)
	{
		Node<ItemType>* nodeToDeletePtr = headPtr;
		headPtr = headPtr->getNext();
		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;
	}
	pointCount = 0;
}  // end clear

// TO-DO: Implement the getCoordinateX method here.
// If index is not valid, return -1 (instead of raising an exception).
template<class ItemType>
ItemType Poly<ItemType>::getCoordinateX(const int index) const
{
	Node<ItemType>* curPtr = new Node<ItemType>();
	bool canGetX = ((!isEmpty()) && index < pointCount && index > -1);
	if (canGetX)
	{
		if (index == 0)
		{
			curPtr = headPtr;
			return curPtr->getX();
		}
		else
		{
			ItemType x;
			curPtr = getPointerTo(index);
			x = curPtr->getNext()->getX();
			return x;
		}
	}
	else
	{
		return -1;
	}
	
}

// TO-DO: Implement the getCoordinateY method here.
// If index is not valid, return -1 (instead of raising an exception).
template<class ItemType>
ItemType Poly<ItemType>::getCoordinateY(const int index) const
{
	Node<ItemType>* curPtr = new Node<ItemType>();
	bool canGetY = ((!isEmpty()) && index < pointCount && index > -1);
	if (canGetY)
	{
		if (index == 0)
		{
			curPtr = headPtr;
			return curPtr->getY();
		}
		else
		{
			ItemType y;
			curPtr = getPointerTo(index);
			y = curPtr->getNext()->getY();
			return y;
		}
	}
	else
	{
		return -1;
	}
}

// TO-DO: Implement the getArcLength method here.
template<class ItemType>
double Poly<ItemType>::getArcLength() const
{
	double arcLength = 0;
	if (pointCount > 1)
	{
		int count = 0;
		double x1, x2;
		double y1, y2;	
		double deltaX, deltaY;
		while (count < pointCount - 1)
		{
			x1 = getCoordinateX(count);
			x2 = getCoordinateX(count + 1);
			y1 = getCoordinateY(count);
			y2 = getCoordinateY(count + 1);
			deltaX = x2 - x1;
			deltaY = y2 - y1;
			arcLength = arcLength + pow(pow(deltaX, 2) + pow(deltaY, 2), 0.5);
			count++;
		}
	}
	return arcLength;
}  // end getArcLength

// TO-DO: Implement the translate method here.
template<class ItemType>
bool Poly<ItemType>::translate(const ItemType deltaX, const ItemType deltaY)
{
	Node<ItemType>* curPtr = new Node<ItemType>();
	bool canTranslate = !isEmpty();
	if (canTranslate)
	{
		// index == 0
		curPtr = headPtr;
		ItemType x = curPtr->getX() + deltaX;
		ItemType y = curPtr->getY() + deltaY;
		curPtr->setX(x);
		curPtr->setY(y);
		// index > 0
		int count = 0;
		while (count < pointCount - 1)
		{
			curPtr = getPointerTo(count + 1);
			x = curPtr->getNext()->getX() + deltaX;
			y = curPtr->getNext()->getY() + deltaY;
			curPtr->getNext()->setX(x);
			curPtr->getNext()->setY(y);
			count++;
		}
	}
	return canTranslate;
}

// TO-DO: Implement the destructor here
template<class ItemType>
Poly<ItemType>::~Poly()
{
	clear();
}


////////////////////////////////////////////////////////////////////////////////////
// overloaded operators

// TO-DO: Implement the operator+ method here
template<class ItemType>
Poly<ItemType>& Poly<ItemType>::operator+(const Poly<ItemType>& rightHandSide) const
{
	static Poly<ItemType> result;
	result.pointCount = pointCount + rightHandSide.pointCount;
	Poly<ItemType>* leftChain = new Poly<ItemType>();
	Poly<ItemType>* rightChain = new Poly<ItemType>();
	// Copy leftHandSide to leftChain
	Node<ItemType>* originalPtr = headPtr;
	if (originalPtr == nullptr)
	{
		leftChain->headPtr = nullptr;
	}
	else
	{
		leftChain->headPtr = new Node<ItemType>();
		leftChain->headPtr->setX(originalPtr->getX());
		leftChain->headPtr->setY(originalPtr->getY());
		Node<ItemType>* newCurPtr = leftChain->headPtr;
		Node<ItemType>* originalNextPtr = originalPtr->getNext();
		while (originalNextPtr != nullptr)
		{
			Node<ItemType>* newNodePtr = new Node<ItemType>();
			newCurPtr->setNext(newNodePtr);
			newNodePtr->setX(originalNextPtr->getX());
			newNodePtr->setY(originalNextPtr->getY());
			newCurPtr = newNodePtr;
			originalNextPtr = originalNextPtr->getNext();
		}
	}
	//Copy rightHandSide to rightChain
	originalPtr = rightHandSide.headPtr;
	if (originalPtr == nullptr)
	{
		rightChain->headPtr = nullptr;
	}
	else
	{
		rightChain->headPtr = new Node<ItemType>();
		rightChain->headPtr->setX(originalPtr->getX());
		rightChain->headPtr->setY(originalPtr->getY());
		Node<ItemType>* newCurPtr = rightChain->headPtr;
		Node<ItemType>* originalNextPtr = originalPtr->getNext();
		while (originalNextPtr != nullptr)
		{
			Node<ItemType>* newNodePtr = new Node<ItemType>();
			newCurPtr->setNext(newNodePtr);
			newNodePtr->setX(originalNextPtr->getX());
			newNodePtr->setY(originalNextPtr->getY());
			newCurPtr = newNodePtr;
			originalNextPtr = originalNextPtr->getNext();
		}
	}
	// Concatenate leftChain and rightChain
	result.headPtr = leftChain->headPtr;
	Node<ItemType>* resultCurPtr = result.headPtr;
	Node<ItemType>* resultNextPtr;
	if (pointCount != 0)
	{
		resultNextPtr = resultCurPtr->getNext();
		while (resultNextPtr != nullptr)
		{
			resultCurPtr = resultCurPtr->getNext();
			resultNextPtr = resultCurPtr->getNext();
		}
		resultCurPtr->setNext(rightChain->headPtr);
	}
	else
	{
		result.headPtr = rightChain->headPtr;
	}
	return result;
}

// TO-DO: Implement the operator= method here
template<class ItemType>
Poly<ItemType>& Poly<ItemType>::operator=(const Poly<ItemType>& rightHandSide) 
{
	if (this != &rightHandSide)
	{
		this->clear();
		pointCount = rightHandSide.pointCount;
		Node<ItemType>* originalPtr = rightHandSide.headPtr;
		if (originalPtr == nullptr)
		{
			headPtr = nullptr;
		}
		else
		{
			headPtr = new Node<ItemType>();
			headPtr->setX(originalPtr->getX());
			headPtr->setY(originalPtr->getY());
			Node<ItemType>* newCurPtr = headPtr;
			Node<ItemType>* originalNextPtr = originalPtr->getNext();
			while (originalNextPtr != nullptr)
			{
				Node<ItemType>* newNodePtr = new Node<ItemType>();
				newCurPtr->setNext(newNodePtr);
				newNodePtr->setX(originalNextPtr->getX());
				newNodePtr->setY(originalNextPtr->getY());
				newCurPtr = newNodePtr;
				originalNextPtr = originalNextPtr->getNext();
			}
		}
	}
	return *this; // Okay to change this statement; it is just a placeholder
}

////////////////////////////////////////////////////////////////////////////////////
// private methods

// TO-DO: Implement the getPointerTo method here
// Only get Pointer when index is not 0
template<class ItemType>
Node<ItemType> *Poly<ItemType>::getPointerTo(const int index) const
{
   Node<ItemType>* curPtr = new Node<ItemType>();
   curPtr = headPtr;
   int count = 0; // used for while loop
	   while (count < index - 1)
	   {
		   curPtr = curPtr->getNext();
		   count++;
	   }

   return curPtr;
}  // end getPointerTo
