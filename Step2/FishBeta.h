/**
 * \file FishBeta.h
 *
 * \author Grant Youngs
 *
 * Class implements a Beta fish
 */

#pragma once

#include <memory>
#include "Item.h"
#include "Fish.h"

/**
 * Implements a Beta Fish
 */
class CFishBeta : public CFish
{
public:
	/// Constructor
	CFishBeta(CAquarium* aquarium);

	virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

	/// Default constructor (disabled)
	CFishBeta() = delete;

	/// Copy constructor (disabled)
	CFishBeta(const CFishBeta&) = delete;

};

