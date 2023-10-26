/**
 * @file Fish.h
 * @author Quinton Strausbaugh
 *
 * Initialize the derived class Fish from Item
 */

#ifndef AQUARIUM_AQUARIUMLIB_FISH_H
#define AQUARIUM_AQUARIUMLIB_FISH_H

#include "Item.h"

/**
 * Base class for a fish
 * This applies to all of the fish, but not the decor
 * items in the aquarium.
 */
class Fish : public Item {
private:
    /// Fish speed in the X direction in pixels per second
    double mSpeedX;

    /// Fish speed in the Y direction in pixels per second
    double mSpeedY;

protected:
    // Constructor
    Fish(Aquarium *aquarium, const std::wstring &filename);

    /**
     * Getter for Speed X member variable
     * @return mSpeedX The member variable mSpeedx
     */
    double GetSpeedX() const {return mSpeedX; }

    /**
     * Getter for Speed Y member variable
     * @return mSpeedY The member variable mSpeedy
     */
    double GetSpeedY() const {return mSpeedY; }

    /**
     * Setter for mSpeedX
     * @param x The speed to set mSpeedX to in pixels
     */
    void SetSpeedX(double x) { mSpeedX = x;}

    /**
     * Setter for mSpeedY
     * @param y The speed to set mSpeedY to in pixels
     */
    void SetSpeedY(double y) { mSpeedY = y;}

public:
    /// Default constructor (disabled)
    Fish() = delete;

    /// Copy constructor (disabled)
    Fish(const Fish &) = delete;

    /// Assignment operator
    void operator=(const Fish &) = delete;

    // Handles updates in time for our fish
    void Update(double elapsed) override;

    // Fish save
    wxXmlNode * XmlSave(wxXmlNode *node) override;

    // Fish load
    void XmlLoad(wxXmlNode *node) override;
};

#endif //AQUARIUM_AQUARIUMLIB_FISH_H
