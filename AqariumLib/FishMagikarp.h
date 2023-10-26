/**
 * @file FishMagikarp.h
 * @author Quinton Strausbaugh
 *
 * Initialize class fish Magikarp
 */

#ifndef AQUARIUM_AQUARIUMLIB_FISHMAGIKARP_H
#define AQUARIUM_AQUARIUMLIB_FISHMAGIKARP_H

#include "Fish.h"

/**
 * Initialize class Fish Magikarp
 */
class FishMagikarp : public Fish
{
public:
    /// Default constructor (disabled)
    FishMagikarp() = delete;

    /// Copy constructor (disabled)
    FishMagikarp(const FishMagikarp &) = delete;

    /// Assignment operator
    void operator=(const FishMagikarp &) = delete;

    // Constructor
    FishMagikarp(Aquarium * aquarium);

    // Save this fish to an XML node
    wxXmlNode* XmlSave(wxXmlNode* node) override;

    // Update this fish
    void Update(double elapsed) override;
};

#endif //AQUARIUM_AQUARIUMLIB_FISHMAGIKARP_H
