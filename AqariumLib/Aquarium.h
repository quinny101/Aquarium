/**
 * @file Aquarium.h
 * @author Quinton Strausbaugh
 *
 * Initialize the class Aquarium
 */

#ifndef AQUARIUM_AQUARIUMLIB_AQUARIUM_H
#define AQUARIUM_AQUARIUMLIB_AQUARIUM_H

#include <memory>
#include <vector>
#include <random>

class Item;


/**
 * Main class to represent the Aquarium
 */
class Aquarium {
private:
    /// Background image to use
    std::unique_ptr<wxBitmap> mBackground;

    /// All of the items to populate our aquarium
    std::vector<std::shared_ptr<Item>> mItems;

    // Handle a node of type item.
    void XmlItem(wxXmlNode *node);

    /// Random number generator
    std::mt19937 mRandom;

public:
    // Constructor
    Aquarium();
    // Draws the Aquarium
    void OnDraw(wxDC *dc);
    // Tests if mouse landed on image
    std::shared_ptr<Item> HitTest(int x, int y);
    // Adds Item to the aquarium
    void Add(std::shared_ptr<Item> item);
    // Takes a value and brings it end of list
    void ReAppend(std::shared_ptr<Item> item);
    // Saves the aquarium as a .aqua XML file
    void Save(const wxString &filename);
    // Loads the aquarium from a .aqua XML file
    void Load(const wxString &filename);
    // Clears the aquarium data.
    void Clear();
    // Updates the timer
    void Update(double elapsed);

    /**
    * Get the random number generator
    * @return Pointer to the random number generator
    */
    std::mt19937& GetRandom() {return mRandom; }

    /**
    * Get the width of the aquarium
    * @return Aquarium width in pixels
    */
    int GetWidth() const { return mBackground->GetWidth(); }

    /**
    * Get the height of the aquarium
    * @return Aquarium height in pixels
    */
    int GetHeight() const { return mBackground->GetHeight(); }
};

#endif //AQUARIUM_AQUARIUMLIB_AQUARIUM_H
