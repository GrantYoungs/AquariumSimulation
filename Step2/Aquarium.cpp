/**
 * \file Aquarium.cpp
 *
 * \author Grant Youngs
 *
 * Defines the functions for an Aquarium object as declared in Aquarium.h
 */

#include "pch.h"
#include <algorithm>
#include "Aquarium.h"
#include "Item.h"
#include "FishBeta.h"
#include "Magikarp.h"
#include "XmlNode.h"
#include "Buddha.h"
#include "DecorCastle.h"


using namespace Gdiplus;
using namespace std;
using namespace xmlnode;

/**
 * Constructor for the Aquarium object
 */
CAquarium::CAquarium()
{
	mBackground = unique_ptr<Gdiplus::Bitmap>(
		Bitmap::FromFile(L"images/background1.png"));

	if (mBackground->GetLastStatus() != Ok)
	{
		AfxMessageBox(L"Failed to open images/background1.png");
	}
	
}

/**
 * Destructor for the Aquarium object
 */
CAquarium::~CAquarium()
{
}

/** Draw the aquarium
* \param graphics The GDI+ graphics context to draw on
*/
void CAquarium::OnDraw(Gdiplus::Graphics *graphics)
{
	graphics->DrawImage(mBackground.get(), 0, 0,
		mBackground->GetWidth(), mBackground->GetHeight());

	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 16);

	SolidBrush green(Color(0, 64, 0));
	graphics->DrawString(L"Under the Sea!", -1, &font, PointF(2, 2), &green);

	// Draws each item to the screen
	for (auto item : mItems)
	{
		item->Draw(graphics);
	}
}

/**
 * Add an item to the aquarium
 * \param item New item to add
 */
void CAquarium::Add(std::shared_ptr<CItem> item)
{
	mItems.push_back(item);
}


/** Test an x,y click location to see if it clicked
* on some item in the aquarium.
* \param x X location
* \param y Y location
* \returns Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<CItem> CAquarium::HitTest(int x, int y)
{
	for (auto i = mItems.rbegin(); i != mItems.rend(); i++)
	{
		if ((*i)->HitTest(x, y))
		{
			return *i;
		}
	}

	return  nullptr;
}


/**
 * 
 * \param imageOne First image of the two stacked images.
 * \param imageTwo Second image of the two stacked images. 
 * \param x X Location of the test
 * \param y Y Location of the test
 * \returns 
 */
std::shared_ptr<CItem> CAquarium::TopImageHitTest(std::shared_ptr<CItem> imageOne, std::shared_ptr<CItem> imageTwo, int x, int y)
{
	// If neither object is hit with the given coordinates
	if (imageOne->HitTest(x, y) == false && imageTwo->HitTest(x, y) == false)
	{
		return nullptr;
	}
	else
	{
		for (auto i = mItems.rbegin(); i != mItems.rend(); i++)
		{
			if (*i == imageOne) // if imageOne is found first, that's the image on top
			{
				return imageOne;
			}
			if (*i == imageTwo) // if imageTwo is found first, that's the image on top
			{
				return imageTwo;
			}
		}
	}
	return nullptr;
}

/**
 * This function moves the item to the front of mItems, into the foreground of the GUI
 * \param item Item to move to the end of mItems, and therefore to the foreground
 */
void CAquarium::MoveToFront(std::shared_ptr<CItem> item)
{
	auto location = find(begin(mItems), end(mItems), item);		// Find the location of the item.
	if (location != end(mItems))								// If the item exists
	{
		mItems.erase(location);
		//CAquarium::Add(item);
	}
	CAquarium::Add(item);
}

/**
 * Nudges other fish away.
 * \param stinkyX Stinky's X position
 * \param stinkyY Stinky's Y position
 */
void CAquarium::Nudge(double stinkyX, double stinkyY)
{
	for (auto fish : mItems)
	{
		fish->UpdatePosition(stinkyX, stinkyY);
	}
}

/**
 * Save the aquarium as a .aqua XML file.
 *
 * Open an XML file and stream the aquarium data to it.
 *
 * \param filename The filename of the file to save the aquarium to
 */
void CAquarium::Save(const std::wstring& filename)
{
	//
	// Create an XML document
	//
	auto root = CXmlNode::CreateDocument(L"aqua");

	// Iterate over all items and save them
	for (auto item : mItems)
	{
		item->XmlSave(root);
	}

	try
	{
		root->Save(filename);
	}
	catch (CXmlNode::Exception ex)
	{
		AfxMessageBox(ex.Message().c_str());
	}

	try
	{
		root->Save(filename);
	}
	catch (CXmlNode::Exception ex)
	{
		AfxMessageBox(ex.Message().c_str());
	}
}

/**
 * Load the aquarium from a .aqua XML file.
 *
 * Opens the XML file and reads the nodes, creating items as appropriate.
 *
 * \param filename The filename of the file to load the aquarium from.
 */
void CAquarium::Load(const std::wstring& filename)
{
	// We surround with a try/catch to handle errors
	try
	{
		// Open the document to read
		shared_ptr<CXmlNode> root = CXmlNode::OpenDocument(filename);

		// Once we know it is open, clear the existing data
		Clear();
		//
		// Traverse the children of the root
		// node of the XML document in memory!!!!
		//
		for (auto node : root->GetChildren())
		{
			if (node->GetType() == NODE_ELEMENT && node->GetName() == L"item")
			{
				XmlItem(node);
			}
		}
	}
	catch (CXmlNode::Exception ex)
	{
		AfxMessageBox(ex.Message().c_str());
	}

}

/**
 * Clear the aquarium data.
 *
 * Deletes all known items in the aquarium.
 */
void CAquarium::Clear()
{
	mItems.clear();
}

/**
* Handle an item node.
* \param node Pointer to XML node we are handling
*/
void CAquarium::XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
	// A pointer for the item we are loading
	shared_ptr<CItem> item;

	// We have an item. What type?
	wstring type = node->GetAttributeValue(L"type", L"");
	if (type == L"beta")
	{
		item = make_shared<CFishBeta>(this);
	}
	if (type == L"buddha")
	{
		item = make_shared<CBuddha>(this);
	}
	if (type == L"magikarp")
	{
		item = make_shared<CMagikarp>(this);
	}
	if (type == L"castle")
	{
		item = make_shared<CDecorCastle>(this);
	}


	if (item != nullptr)
	{
		item->XmlLoad(node);
		Add(item);
	}
}

/** Handle updates for animation
* \param elapsed The time since the last update
*/
void CAquarium::Update(double elapsed)
{
	for (auto item : mItems)
	{
		item->Update(elapsed);
	}
}