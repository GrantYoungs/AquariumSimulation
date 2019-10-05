/**
 * \file Buddha.h
 *
 * \author Grant Youngs
 *
 * Class implements THE Buddha.
 */

#pragma once

#include <memory>
#include "Item.h"
#include "Fish.h"

/**
 * Implements a Buddha
 */
class CBuddha : public CFish
{
public:
	/// Constructor
	CBuddha(CAquarium* aquarium);

	/// Saves the attributes of the Buddha
	virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

	/// Default constructor (disabled)
	CBuddha() = delete;

	/// Copy constructor (disabled)
	CBuddha(const CBuddha&) = delete;
};

