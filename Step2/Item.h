/**
 * \file Item.h
 *
 * \author Grant Youngs
 *
 * Base class for any item in our aquarium
 */

#pragma once

#include <memory>
#include <string>
#include "XmlNode.h"

class CAquarium;


/**
 * Base class for any item in our aquarium
 */
class CItem
{
public:
	/// Default Constructor (disabled)
	CItem() = delete;

	/// Copy constructor (disabled)
	CItem(const CItem&) = delete;

	/// Destructor
	virtual ~CItem();

	/** The X location of th e item
	* \returns X location in pixels */
	double GetX() const { return mX; }

	/** The Y location of the item
	* \returns Y location in pixels */
	double GetY() const { return mY; }

	/// Set the item location
	/// \param x X location
	/// \param y Y location
	virtual void SetLocation(double x, double y) { mX = x; mY = y; }

	/// Draw this item
	/// \param graphics Graphics device to draw on
	virtual void Draw(Gdiplus::Graphics* graphics);

	virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node);

	virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);

	/** Test this item to see if it has been clicked on
	 * \param x X location on the aquarium to test
	 * \param y Y location on the aquarium to test
	 * \return true if clicked on */
	virtual bool HitTest(int x, int y);

	void UpdatePosition(double stinkyX, double stinkyY);

	/// Handle updates for animation
	/// \param elapsed The time since the last update
	virtual void Update(double elapsed) {}

	/// Get the aquarium this item is in
	/// \returns Aquarium pointer
	CAquarium* GetAquarium() { return mAquarium; }

	/// Set the mirror status
	/// \param m New mirror flag
	void SetMirror(bool m) { mMirror = m; }

	/// Gets the width of the image
	/// \return Width of the image
	double GetImageWidth() { return mImageWidth; }

	/// Gets the height of the image
	/// \return Height of the image
	double GetImageHeight() { return mImageHeight; }

protected:
	/// Constructor
	CItem(CAquarium* aquarium, const std::wstring &filename);

	/// Sets the width of the image
	void SetImageWidth(double width) { mImageWidth = width; }

	/// Sets the height of the image
	void SetImageHeight(double height) { mImageHeight = height; }

private:
	// Item location in the aquarium
	double mX = 0;		///< X location for the center of the item
	double mY = 0;		///< Y location for the center of the item

	/// The aquarium this item is contained in
	CAquarium* mAquarium;

	/// The image of the Fish to be displayed
	std::unique_ptr<Gdiplus::Bitmap> mItemImage;

	/// The width of the image
	double mImageWidth = 0;

	/// The height of the image
	double mImageHeight = 0;

	bool mMirror = false;   ///< True mirrors the item image
};

