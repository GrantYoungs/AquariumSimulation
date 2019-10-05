/**
 * \file Fish.cpp
 *
 * \author Grant Youngs
 */

#include "pch.h"
#include "Fish.h"
#include "Aquarium.h"

 /// Maximum speed in the X direction in
 /// in pixels per second
const double MaxSpeedX = 200;

/// Maximum speed in the Y direction in
/// pixels per second
const double MaxSpeedY = 50;

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 */
std::shared_ptr<xmlnode::CXmlNode> CFish::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
	auto itemNode = CItem::XmlSave(node);

	itemNode->SetAttribute(L"speedx", GetSpeedX());
	itemNode->SetAttribute(L"speedy", GetSpeedY());

	return itemNode;
}

/**
 * Load the attributes for an item node.
 *
 * This is the  base class version that loads the attributes
 * common to all items. Override this to load custom attributes
 * for specific items.
 *
 * \param node The Xml node we are loading the item from
 */
void CFish::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
	CItem::XmlLoad(node);
	mSpeedX = node->GetAttributeDoubleValue(L"speedx", 0);
	mSpeedY = node->GetAttributeDoubleValue(L"speedy", 0);
}

/**
  * Constructor
  * \param aquarium The aquarium we are in
  * \param filename Filename for the image we use
  */
CFish::CFish(CAquarium* aquarium, const std::wstring& filename) :
	CItem(aquarium, filename)
{
	mSpeedX = mMinSpeedX + (((double)rand() / RAND_MAX) * (MaxSpeedX - mMinSpeedX));
	mSpeedY = mMinSpeedY + (((double)rand() / RAND_MAX) * (MaxSpeedY - mMinSpeedY));
}

/**
 * Handle updates in time of our fish
 *
 * This is called before we draw and allows us to
 * move our fish. We add our speed times the amount
 * of time that has elapsed.
 * \param elapsed Time elapsed since the class call
 */
void CFish::Update(double elapsed)
{
	SetLocation(GetX() + mSpeedX * elapsed,
		GetY() + mSpeedY * elapsed);

	if (mSpeedX > 0 && GetX() >= GetAquarium()->GetWidth() - 10 - GetImageWidth()/2)
	{
		mSpeedX = -mSpeedX;
		SetMirror(mSpeedX < 0);
	}
	if (mSpeedX < 0 && GetX() <= 10 + GetImageWidth()/2)
	{
		mSpeedX = -mSpeedX;
		SetMirror(mSpeedX < 0);
	}
	if (mSpeedY > 0 && GetY() >= GetAquarium()->GetHeight() - 10 - GetImageHeight()/2)
	{
		mSpeedY = -mSpeedY;
	}
	if (mSpeedY < 0 && GetY() <= 10 + GetImageHeight()/2)
	{
		mSpeedY = -mSpeedY;
	}
}