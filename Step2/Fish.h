/**
 * \file Fish.h
 *
 * \author Grant Youngs
 *
 * Implements a Fish object that the other fish classes are a part of.
 */

#pragma once
#include "Item.h"

 /**
  * Base class for a fish
  * This applies to all of the fish, but not the decor
  * items in the aquarium.
  */
class CFish : public CItem
{
public: 
	/// Default constructor (disabled)
	CFish() = delete;

	/// Copy constructor (disabled)
	CFish(const CFish&) = delete;

	/// Returns the speed in the X direction
	double GetSpeedX() { return mSpeedX; }

	/// Returns the speed in the Y direction
	double GetSpeedY() { return mSpeedY; }

	/// Saves the attributes of the Fish object
	virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

	/// Loads the attributes of the fish object
	virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

protected:
	/// Constructor
	CFish(CAquarium* aquarium, const std::wstring& filename);

	/// Updates the location of the fish as it moves around the aquarium
	void Update(double elapsed);

	/// Sets the minimum speed of the fish in the X direction
	void SetMinSpeedX(double speedX) { mMinSpeedX = speedX; }

	/// Sets the minimum speed of the fish in the Y direction
	void SetMinSpeedY(double speedY) { mMinSpeedY = speedY; }

private:
	/// Fish speed in the X direction
	double mSpeedX;

	/// Fish speed in the Y direction
	double mSpeedY;

	/// Minimum speed for each fish in X direction
	double mMinSpeedX = 0;

	/// Minimum speed for each fish in Y direction
	double mMinSpeedY = 0;
};

