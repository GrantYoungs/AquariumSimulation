/**
 * \file Buddha.cpp
 *
 * \author Grant Youngs
 *
 * Defines the functions declared in Buddha.h
 */

#include "pch.h"
#include <string>
#include "Buddha.h"
#include "XmlNode.h"

using namespace std;
using namespace Gdiplus;
using namespace xmlnode;


/// Fish filename
const wstring BuddhaImageName = L"images/buddha.png";

/// Width of the image
const double ImageWidth = 250;

/// Height of the image
const double ImageHeight = 304;

/// Minimum speed of Buddha in X direction
const double MinSpeedX = 25;

/// Minimum speed of Buddha in Y direction
const double MinSpeedY = 10;

/** Constructor
 * \param aquarium The aquarium this is a member of
*/
CBuddha::CBuddha(CAquarium* aquarium) :
	CFish(aquarium, BuddhaImageName)
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
CBuddha::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
	auto itemNode = CFish::XmlSave(node);

	itemNode->SetAttribute(L"type", L"buddha");

	return itemNode;
}

