/**
 * \file Magikarp.cpp
 *
 * \author Grant Youngs
 *
 * Implements a Magikarp object
 */

#include "pch.h"
#include "Magikarp.h"
#include <string>
#include "XmlNode.h"


using namespace std;
using namespace Gdiplus;
using namespace xmlnode;

/// Fish filename
const wstring MagikarpImageName = L"images/magikarp.png";

/// Width of the image
const double ImageWidth = 150;

/// Height of the image
const double ImageHeight = 185;

/// Minimum speed of Magikarp in X direction
const double MinSpeedX = 120;

/// Minimum speed of Magikarp in Y direction
const double MinSpeedY = 10;

/** Constructor
 * \param aquarium The aquarium this is a member of
*/
CMagikarp::CMagikarp(CAquarium* aquarium) :
	CFish(aquarium, MagikarpImageName)
{
	// Sets the width of the image
	SetImageWidth(ImageWidth);

	// Sets the height of the image
	SetImageHeight(ImageHeight);

	// Sets the minimum speed member variables
	SetMinSpeedX(MinSpeedX);
	SetMinSpeedY(MinSpeedY);
}

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 */
std::shared_ptr<xmlnode::CXmlNode>
CMagikarp::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
	auto itemNode = CFish::XmlSave(node);

	itemNode->SetAttribute(L"type", L"magikarp");

	return itemNode;
}


