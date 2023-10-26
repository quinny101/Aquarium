/**
 * @file FishGoldeen.h
 * @author Quinton Strausbaugh
 *
 * Initialize the fish goldeen process
 */

#ifndef AQUARIUM_AQUARIUMLIB_FISHGOLDEEN_H
#define AQUARIUM_AQUARIUMLIB_FISHGOLDEEN_H

#include "Fish.h"

/**
 * Initialize the class Fish Goldeen
 */
class FishGoldeen : public Fish
{
public:
    /// Default constructor (disabled)
    FishGoldeen() = delete;

    /// Copy constructor (disabled)
    FishGoldeen(const FishGoldeen &) = delete;

    /// Assignment operator
    void operator=(const FishGoldeen &) = delete;

    // Constructor
    FishGoldeen(Aquarium *aquarium);

    // Save this fish to an XML node
    wxXmlNode* XmlSave(wxXmlNode* node) override;

    // Handle updates in time of our fish
    void Update(double elapsed) override;
};

#endif //AQUARIUM_AQUARIUMLIB_FISHGOLDEEN_H
