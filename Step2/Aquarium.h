/**
 * \file Aquarium.h
 *
 * \author Grant Youngs
 *
 * This is a class that simulates an aquarium and provides functions to draw it on the screen
 */

#pragma once

#include <memory>
#include <vector>
#include "Item.h"
#include "FishBeta.h"


/**
 * This is the aquarium class, defining public and private functions and variables.
 */
class CAquarium
{
public:
	/// Constructor
	CAquarium();

	/// Destructor
	virtual ~CAquarium();

	void OnDraw(Gdiplus::Graphics * graphics);

	void Add(std::shared_ptr<CItem> item);

	std::shared_ptr<CItem> HitTest(int x, int y);

	std::shared_ptr<CItem> TopImageHitTest(std::shared_ptr<CItem> imageOne, std::shared_ptr<CItem> imageTwo, int x, int y);

	void MoveToFront(std::shared_ptr<CItem> item);

	void Nudge(double stinkyX, double stinkyY);

	void Save(const std::wstring& filename);

	void Load(const std::wstring& filename);

	void Clear();

	void Update(double elapsed);

	/// Get the width of the aquarium
	/// \returns Aquarium width
	int GetWidth() const { return mBackground->GetWidth(); }

	/// Get the height of the aquarium
	/// \returns Aquarium height
	int GetHeight() const { return mBackground->GetHeight(); }

private:
	std::unique_ptr<Gdiplus::Bitmap> mBackground; ///< Background image to use

	/// All of the items to populate our aquarium
	std::vector<std::shared_ptr<CItem> > mItems;

	void XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node);
};

