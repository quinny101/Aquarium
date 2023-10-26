/**
 * @file FishNemo.h
 * @author Quinton Strausbaugh
 *
 * Initialize the class Fish nemo
 */

#ifndef AQUARIUM_AQUARIUMLIB_FISHNEMO_H
#define AQUARIUM_AQUARIUMLIB_FISHNEMO_H

#include "Fish.h"

/**
 * Initialize the class for fish image Nemo
 */
class FishNemo : public Fish
{
public:
    // Default constructor (disabled)
    FishNemo() = delete;

    // Copy constructor (disabled)
    FishNemo(const FishNemo &) = delete;

    // Assignment operator
    void operator=(const FishNemo &) = delete;

    // Constructor
    FishNemo(Aquarium * aquarium);

    // Save this fish to an XML node
    wxXmlNode* XmlSave(wxXmlNode* node) override;

    // Handle updates in time of our fish
    void Update(double elapsed) override;
};

#endif //AQUARIUM_AQUARIUMLIB_FISHNEMO_H
