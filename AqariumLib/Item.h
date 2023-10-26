/**
 * @file Item.h
 * @author Quinton Strausbaugh
 *
 * Base class for any item in our aquarium
 */

#ifndef AQUARIUM_AQUARIUMLIB_ITEM_H
#define AQUARIUM_AQUARIUMLIB_ITEM_H

class Aquarium;

/**
 * Class to describe an item in the Aquarium
 */
class Item {
private:
    /// The underlying fish image
    std::unique_ptr<wxImage> mItemImage;

    /// The bitmap we can display for this fish
    std::unique_ptr<wxBitmap> mItemBitmap;

    /// The aquarium this item is contained in
    Aquarium *mAquarium;

    // Item location in the aquarium
    double mX = 0;  ///< X location for the center of the item
    double mY = 0;  ///< Y location for the center of the item

    /// True mirrors the item image
    bool mMirror = false;

protected:
    Item(Aquarium* aquarium, const std::wstring &filename);

public:
    // Default constructor (disabled)
    Item() = delete;

    // Copy constructor (disabled)
    Item(const Item &) = delete;

    // Assignment operator
    void operator=(const Item &) = delete;

    // Destructor
    virtual ~Item();

    /**
    * The X location of the item
    * @return X location in pixels
    */
    double GetX() const { return mX;}

    /**
    * The Y location of the item
    * @return Y location in pixels
    */
    double GetY() const { return mY;}

    /**
     * The width of the image
     * @return Width of the image
     */
     double GetWidth() const { return mItemBitmap->GetWidth(); }

    /**
    * The width of the image
    * @return Width of the image
    */
    double GetHeight() const { return mItemBitmap->GetHeight(); }

    /**
    * Set the item location
    * @param x X location in pixels
    * @param y Y location in pixels
    */
    virtual void SetLocation(double x, double y) { mX = x; mY = y; }

    //Draw this item
    void Draw(wxDC *dc);

    //Test this item to see if it has been clicked on
    bool HitTest(int x, int y);

    // Saves the item to an XML node
    virtual wxXmlNode *XmlSave(wxXmlNode *node);

    // Load the attributes for an item node
    virtual void XmlLoad(wxXmlNode *node);

    // Sets if the image is being mirrored or not
    void SetMirror(bool m);

    /**
    * Get the pointer to the Aquarium object
    * @return Pointer to Aquarium object
    */
    Aquarium *GetAquarium() { return mAquarium;  }

    /**
    * Handle updates for animation
    * @param elapsed The time since the last update
    */
    virtual void Update(double elapsed) {}
};

#endif //AQUARIUM_AQUARIUMLIB_ITEM_H
