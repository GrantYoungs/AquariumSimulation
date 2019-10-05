/**
 * \file Stinky.h
 *
 * \author Grant Youngs
 *
 * Implements a Stinky fish that pushes away all fish that get near it.
 */

#pragma once

#include <memory>
#include "Item.h"


/**
 * Implements a Stinky fish.
 */
class CStinky : public CItem
{
public:
	/// Constructor
	CStinky(CAquarium* aquarium);

	/// Default constructor (disabled)
	CStinky() = delete;

	/// Copy constructor (disabled)
	CStinky(const CStinky&) = delete;

	virtual void Draw(Gdiplus::Graphics* graphics) override;

	bool HitTest(int x, int y);

	void SetLocation(double x, double y);

private:
	/// The image of the Stinky fish to be displayed
	std::unique_ptr<Gdiplus::Bitmap> mFishImage;
};

