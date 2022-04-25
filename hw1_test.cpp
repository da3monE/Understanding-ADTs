////////////////////////////////////////////////////////
// ECE 2574, Homework 1, Sofia Jimenez
//
//File name: hw1_test.cpp
//Description: This a modified bag ADT. New methods are needed to be added
//to modify the bag.
//Date: 7/9/2018
#define CATCH_CONFIG_MAIN			// this line tells Catch to provide a main() function
#define CATCH_CONFIG_COLOUR_NONE	// this line avoids problems due to color-coding the output
#include "catch.hpp"

#include "ArrayBag.h"

// The following set of tests needs to be expanded
TEST_CASE("Test an empty bag of integers", "[ArrayBag]") {

	ArrayBag<int> b;
	REQUIRE(b.getCurrentSize() == 0);
	REQUIRE(b.isEmpty());
	REQUIRE(!b.remove(5));
	REQUIRE(!b.contains(5));
	REQUIRE(b.getFrequencyOf(5) == 0);
	REQUIRE(!b.flatten());
	REQUIRE(!b.reduce());
	REQUIRE(b.replace(5, 6));

	b.clear();
	REQUIRE(b.getCurrentSize() == 0);
	REQUIRE(b.isEmpty());
	REQUIRE(!b.remove(5));
	REQUIRE(!b.contains(5));
	REQUIRE(b.getFrequencyOf(5) == 0);
	REQUIRE(!b.flatten());
	REQUIRE(!b.reduce());
	REQUIRE(b.replace(5, 6));

}

TEST_CASE("Test an empty bag of strings", "[ArrayBag]") {

	ArrayBag<std::string> b;
	REQUIRE(b.getCurrentSize() == 0);
	REQUIRE(b.isEmpty());
	REQUIRE(!b.remove(""));
	REQUIRE(!b.contains(""));
	REQUIRE(b.getFrequencyOf("") == 0);
	REQUIRE(!b.flatten());
	REQUIRE(!b.reduce());
	REQUIRE(b.replace("", "i"));

	b.clear();
	REQUIRE(b.getCurrentSize() == 0);
	REQUIRE(b.isEmpty());
	REQUIRE(!b.remove(""));
	REQUIRE(!b.contains(""));
	REQUIRE(b.getFrequencyOf("") == 0);
	REQUIRE(!b.flatten());
	REQUIRE(!b.reduce());
	REQUIRE(b.replace("", "i"));

}

TEST_CASE("Test a full bag of strings", "[ArrayBag]") {

	ArrayBag<std::string> b;
	REQUIRE(b.getCurrentSize() == 0);
	REQUIRE(b.isEmpty());

	for (int i = 0; i < 6; i++) //find the size.... not 6: in arraybag.h
	{
		REQUIRE(b.add(""));
		REQUIRE(b.contains(""));
		//check to remove and then add again
	}

	REQUIRE(!b.add(""));
	REQUIRE(b.contains(""));
	REQUIRE(b.contains(""));
	REQUIRE(b.flatten());
	REQUIRE(b.reduce());
	REQUIRE(b.replace("", "i"));

}

TEST_CASE("Test a full bag of integers", "[ArrayBag]") {

	ArrayBag<int> b;
	REQUIRE(b.getCurrentSize() == 0);
	REQUIRE(b.isEmpty());

	for (int i = 0; i < 6; i++) //find the size.... not 6: in arraybag.h
	{
		REQUIRE(b.add(i));
		REQUIRE(b.contains(i));
		//check to remove and then add again
	}

	REQUIRE(!b.add(100));
	REQUIRE(!b.contains(100));
	REQUIRE(b.contains(5));
	REQUIRE(!b.flatten());
	REQUIRE(b.reduce());
	REQUIRE(b.replace(5, 6));

}


TEST_CASE("Tests new constructor", "[ArrayBag]"){
	int arr[6];
	ArrayBag<int> b;
	REQUIRE(b.add(5));
	REQUIRE(b.getCurrentSize() == 1);
	REQUIRE(!b.isEmpty());
	REQUIRE(b.contains(5));
	REQUIRE(b.getFrequencyOf(5) == 1);
	REQUIRE(!b.flatten());
	REQUIRE(b.reduce());
	REQUIRE(b.replace(5, 6));

}


TEST_CASE("Test bag union", "[ArrayBag]") {
	
}
