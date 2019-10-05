/**
 * \file FishBeta.cpp
 *
 * \author Grant Youngs
 *
 * Implements a Beta Fish in the aquarium
 */


#include "pch.h"
#include <string>
#include "FishBeta.h"
#include "XmlNode.h"


using namespace std;
using namespace Gdiplus;
using namespace xmlnode;


/// Fish filename
const std::wstring FishBetaImageName = L"images/beta.png";

/// Width of the image
const double ImageWidth = 125;

/// Height of the image
const double ImageHeight = 117;

/// Minimum speed of Beta fish in X direction
const double MinSpeedX = 100;

/// Minimum speed of Beta fish in Y direction
const double MinSpeedY = 10;

/** Constructor
 * \param aquarium The aquarium this is a member of
*/
CFishBeta::CFishBeta(CAquarium* aquarium) :
	CFish(aquarium, FishBetaImageName)
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
CFishBeta::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
	auto itemNode = CFish::XmlSave(node);

	itemNode->SetAttribute(L"type", L"beta");

	return itemNode;
}