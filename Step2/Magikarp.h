/**
 * \file Magikarp.h
 *
 * \author Grant Youngs
 *
 * Class implements the legendary Pokemon, Magikarp.
 */

#pragma once

#include <memory>
#include "Item.h"
#include "Fish.h"

/**
 * Class implements the legendary Pokemon, Magikarp
 */
class CMagikarp : public CFish
{
public:
	/// Constructor
	CMagikarp(CAquarium* aquarium);

	virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

	/// Default constructor (disabled)
	CMagikarp() = delete;

	/// Copy constructor (disabled)
	CMagikarp(const CMagikarp&) = delete;
};

