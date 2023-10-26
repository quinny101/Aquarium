/**
 * @file DecorCastle.h
 * @author Quinton Strausbaugh
 *
 * Initialize the decor castle class
 */

#ifndef AQUARIUM_AQUARIUMLIB_DECORCASTLE_H
#define AQUARIUM_AQUARIUMLIB_DECORCASTLE_H

#include "Item.h"

/**
 * Initialize the Decor Castle class
 */
class DecorCastle : public Item
{
public:
    /// Default constructor (disabled)
    DecorCastle() = delete;

    /// Copy constructor (disabled)
    DecorCastle(const DecorCastle &) = delete;

    /// Assignment operator
    void operator=(const DecorCastle &) = delete;

    /// Constructor
    DecorCastle(Aquarium * aquarium);

    // Save this decor to an XML node
    wxXmlNode* XmlSave(wxXmlNode* node) override;
};

#endif //AQUARIUM_AQUARIUMLIB_DECORCASTLE_H
