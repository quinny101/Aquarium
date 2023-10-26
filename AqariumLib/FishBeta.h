/**
 * @file FishBeta.h
 * @author Quinton Strausbaugh
 *
 * Initialize the beta fish information
 */

#ifndef AQUARIUM_AQUARIUMLIB_FISHBETA_H
#define AQUARIUM_AQUARIUMLIB_FISHBETA_H

#include "Fish.h"

/**
 * Initialize the class Fish Beta
 */
class FishBeta : public Fish
{
public:
    /// Default constructor (disabled)
    FishBeta() = delete;

    /// Copy constructor (disabled)
    FishBeta(const FishBeta &) = delete;

    /// Assignment operator
    void operator=(const FishBeta &) = delete;

    // constructor
    FishBeta(Aquarium *aquarium);

    // Save this fish to an XML node
    wxXmlNode* XmlSave(wxXmlNode* node) override;

    // Handle updates in time of our fish
    void Update(double elapsed) override;
};

#endif //AQUARIUM_AQUARIUMLIB_FISHBETA_H
