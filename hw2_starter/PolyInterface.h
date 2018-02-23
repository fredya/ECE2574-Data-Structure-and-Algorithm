////////////////////////////////////////////////////////
//  ECE 2574, Homework 2  
//  Description: Interface file for a polyline ADT.
//  Date:        2/10/2018
/** @file PolyInterface.h */

#ifndef POLY_INTERFACE_
#define POLY_INTERFACE_

template<class ItemType>
class PolyInterface
{
public:
	/** Reports whether this polyline is empty.
	@return  True if the polyline is empty, or false if not. */
	virtual bool isEmpty() const = 0;
	
	/** Reports the number of points in this polyline.
    @return  An integer indicating the number of points currently in the polyline. */
    virtual int getNumberOfPoints() const = 0;
      
   /** Adds a new point to this polyline.
    @post  If successful, the point (x, y) is in the polyline 
	   at position indicated by 'index' 
	   (where index 0 refers to the first point in the sequence),
       and the count of points in the polyline has increased by 1.
    @param x  The x coordinate of the point to be added to the polyline.
	@param y  The y coordinate of the point to be added to the polyline.
    @return   True if addition was successful, or false if not. */
   virtual bool insert(const ItemType x, const ItemType y, int index) = 0;
   
   /** Removes a point from this polyline.
    @post  If successful, the point indicated by 'index' has been 
	   removed from the polyline (index 0 refers to the first point in the sequence),
       and the count of items in the polyline has decreased by 1.
    @return  True if removal was successful, or false if not. */
   virtual bool remove(const int index) = 0;
   
   /** Removes all points from this polyline.
    @post  polyline contains no points, and the count of points is 0. */
   virtual void clear() = 0;

   /** Reports the x coordinate of a point in this polyline.
   @return  The value of x coordinate of the point at location 'index' in the polyline, 
       if the index is valid; or -1 if the index is not valid. */
   virtual ItemType getCoordinateX(const int index) const = 0;

   /** Reports the y coordinate of a point in this polyline.
   @return  The value of y coordinate of the point at location 'index' in the polyline,
       if the index is valid; or -1 if the index is not valid. */
   virtual ItemType getCoordinateY(const int index) const = 0;

   /** Reports the length of this polyline.
       By definition, the length is 0 for a polyline containing only 0 or 1 points.
    @return  The sum of lengths of all line segments in this polyline. */
   virtual double getArcLength() const = 0; 

   /** Applies translation to this polyline.
   @post  If successful, every point in this polyline will be at a new location.
      The new location is obtained by a adding (deltaX, deltaY) to each point.
   @param deltaX  The value to be added to the x coordinate of every point.
   @param deltaY  The value to be added to the y coordinate of every point.
   @return  True if the operation was successful, or false if invoked for an empty polyline. */
   virtual bool translate(const ItemType deltaX, const ItemType deltaY) = 0;
   
   /** Destroys this object and frees its assigned memory. (See C++ Interlude 2.) */
   virtual ~PolyInterface() { }
}; // end PolyInterface
#endif