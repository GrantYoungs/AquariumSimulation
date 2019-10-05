/**
 * \file DecorCastle.h
 *
 * \author Grant Youngs
 *
 * Class implements a castle decoration
 */

#pragma once

#include <memory>
#include "Item.h"

 /**
  * Class implements a castle decoration
  */
class CDecorCastle : public CItem
{
public:
	/// Constructor
	CDecorCastle(CAquarium* aquarium);

	/// Saves the attributes of the Castle
	virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

	/// Default constructor (disabled)
	CDecorCastle() = delete;

	/// Copy constructor (disabled)
	CDecorCastle(const CDecorCastle&) = delete;
};

