// HW2 starter code for testing
#define CATCH_CONFIG_MAIN			// this line tells Catch to provide a main() function
#define CATCH_CONFIG_COLOUR_NONE	// this line avoids problems due to color-coding the output
#include "catch.hpp"
#include "Poly.h" 

TEST_CASE("Testing empty polyline", "[Poly]") 
{
	INFO("Hint: testing all methods with an empty polyline");

	Poly<int> p;
	REQUIRE(p.isEmpty());
	REQUIRE(p.getNumberOfPoints() == 0);

	std::cout << p.insert(1, 2, 0) << std::endl;
	std::cout << p.insert(2, 24, 1) << std::endl;
	std::cout << p.insert(3, 25, 2) << std::endl;
	std::cout << p.insert(4, 5, 3) << std::endl;
	std::cout << p.insert(5, 5, 4) << std::endl;
	//std::cout << p.remove(3) << std::endl;
	std::cout << p.remove(0) << std::endl;
	std::cout << p.insert(6, 5, 0) << std::endl;
	std::cout << p.insert(7, 5, 4) << std::endl;
	std::cout << "" << std::endl;
	std::cout << p.getCoordinateX(0) << std::endl;
	std::cout << p.getCoordinateX(1) << std::endl;
	std::cout << p.getCoordinateX(2) << std::endl;
	std::cout << p.getCoordinateX(3) << std::endl;
	std::cout << p.getCoordinateX(4) << std::endl;
	std::cout << p.getCoordinateX(5) << " " << p.getCoordinateY(5) << std::endl;
	std::cout <<  "arclength " << p.getArcLength()  << std::endl;
	Poly<int> p1(p);
	std::cout << "copy " << std::endl;
	std::cout << p1.getCoordinateX(0) << std::endl;
	std::cout << p1.getCoordinateX(1) << std::endl;
	std::cout << p1.getCoordinateX(2) << std::endl;
	std::cout << p1.getCoordinateX(3) << std::endl;
	std::cout << p1.getCoordinateX(4) << std::endl;
	std::cout << "overload = " << std::endl;
	Poly<int> p2;
	p2 = p;
	std::cout << p2.remove(0) << std::endl;
	std::cout << p2.insert(2, 24, 0) << std::endl;
	
	std::cout << p2.getCoordinateX(0) << std::endl;
	std::cout << p2.getCoordinateX(1) << std::endl;
	std::cout << p2.getCoordinateX(2) << std::endl;
	std::cout << p2.getCoordinateX(3) << std::endl;
	std::cout << p2.getCoordinateX(4) << std::endl;
	std::cout << p2.getCoordinateX(5) << std::endl;
	std::cout << "overload + " << std::endl;
	Poly<int> p3;
	Poly<int> p4;
	Poly<int> p5;
	p3 = p4 + p2;
	std::cout << p3.getCoordinateX(0) << std::endl;
	std::cout << p3.getCoordinateX(1) << std::endl;
	std::cout << p3.getCoordinateX(2) << std::endl;
	std::cout << p3.getCoordinateX(3) << std::endl;
	std::cout << p3.getCoordinateX(4) << std::endl;
	std::cout << p3.getCoordinateX(5) << std::endl;
	std::cout << p3.getCoordinateX(6) << std::endl;
	std::cout << p3.getCoordinateX(7) << std::endl;
	std::cout << p3.getCoordinateX(8) << std::endl;
	std::cout << p3.getCoordinateX(9) << std::endl;
	std::cout << "overload + again" << std::endl;
	p3 = p + p5;
	std::cout << p3.getCoordinateX(0) << std::endl;
	std::cout << p3.getCoordinateX(1) << std::endl;
	std::cout << p3.getCoordinateX(2) << std::endl;
	std::cout << p3.getCoordinateX(3) << std::endl;
	std::cout << p3.getCoordinateX(4) << std::endl;
	std::cout << p3.getCoordinateX(5) << std::endl;
	std::cout << p3.getCoordinateX(6) << std::endl;
	std::cout << p3.getCoordinateX(7) << std::endl;
	std::cout << p3.getCoordinateX(8) << std::endl;
	std::cout << p3.getCoordinateX(9) << std::endl;
	std::cout << "translate" << std::endl;
	p3.translate(1, 4);
	std::cout << p3.getCoordinateX(0) << std::endl;
	std::cout << p3.getCoordinateX(1) << std::endl;
	std::cout << p3.getCoordinateX(2) << std::endl;
	std::cout << p3.getCoordinateX(3) << std::endl;
	std::cout << p3.getCoordinateX(4) << std::endl;
	std::cout << p3.getCoordinateX(5) << std::endl;
	std::cout << p3.getCoordinateX(6) << std::endl;
	std::cout << p3.getCoordinateX(7) << std::endl;
	std::cout << p3.getCoordinateX(8) << std::endl;
	std::cout << p3.getCoordinateX(9) << std::endl;
	REQUIRE(!p.insert(1, 2, -1));
	//REQUIRE(!p.insert(1, 2, 1));
	//REQUIRE(!p.remove(-1));
	//REQUIRE(!p.remove(0));
	//REQUIRE(!p.remove(1));
	//REQUIRE(p.getCoordinateX(0) == -1);		
	//REQUIRE(p.getCoordinateY(0) == -1);
	//REQUIRE(p.getArcLength() == 0.0);
	//REQUIRE(!p.translate(1, 2));

	//INFO("Hint: testing several methods after clearing an empty polyline");
	//p.clear();
	//REQUIRE(p.isEmpty());
	//REQUIRE(p.getNumberOfPoints() == 0);
	//REQUIRE(!p.remove(0));
}

//TEST_CASE("Testing polyline with a single node", "[Poly]") 
//{
//	INFO("Hint: testing all methods on a polyline with 1 node");
//
//	Poly<int> p;
//	REQUIRE(p.insert(1, 2, 0));
//
//	REQUIRE(!p.isEmpty());
//	REQUIRE(p.getNumberOfPoints() == 1);
//	REQUIRE(p.getCoordinateX(0) == 1);
//	REQUIRE(p.getCoordinateY(0) == 2);
//	REQUIRE(p.getArcLength() == 0.0);
//	REQUIRE(p.translate(3, 4));
//	REQUIRE(p.getCoordinateX(0) == 4);
//	REQUIRE(p.getCoordinateY(0) == 6);
//
//	// TO-DO:  add more REQUIRE statements here to test a polyline with 1 node.
//
//}

// TO-DO:  add more TEST_CASEs here to test your code.
