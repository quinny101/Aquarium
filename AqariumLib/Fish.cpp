/**
 * @file Fish.cpp
 * @author Quinton Strausbaugh
 *
 * Initialize the Base class Fish
 */

#include "pch.h"
#include <random>
#include "Fish.h"
#include "Aquarium.h"


/// Maximum speed in the X direction in in pixels per second
const double MaxSpeedX = 50;

/// Minimum speed in the X direction in pixels per second
const double MinSpeedX = 20;

/**
* Constructor
* @param aquarium The aquarium we are in
* @param filename Filename for the image we use
*/
Fish::Fish(Aquarium *aquarium, const std::wstring &filename) :
    Item(aquarium, filename)
{
    std::uniform_real_distribution<> distribution(MinSpeedX, MaxSpeedX);
    mSpeedX = distribution(aquarium->GetRandom());
    mSpeedY = 0;
}

/**
 * Handle updates in time of our fish
 *
 * This is called before we draw and allows us to
 * move our fish. We add our speed times the amount
 * of time that has elapsed.
 * @param elapsed Time elapsed since the class call
 */
void Fish::Update(double elapsed)
{
    SetLocation(GetX() + mSpeedX * elapsed,
                GetY() + mSpeedY * elapsed);

    if (mSpeedX > 0 && GetX() >= (GetAquarium()->GetWidth() - (this->GetWidth()/2) - 10))
    {
        mSpeedX = -mSpeedX;
        SetMirror(true);
    }
    else if (mSpeedX < 0 && GetX() <= 10 + (this->GetWidth()/2))
    {
        mSpeedX = -mSpeedX;
        SetMirror(false);
    }
}

/**
 * Save this item to an XML node
 * @param node The parent node we are going to be a child of
 * @return wxXmlNode that we saved the item into
 */
wxXmlNode *Fish::XmlSave(wxXmlNode *node)
{
    auto itemNode = new wxXmlNode(wxXML_ELEMENT_NODE, L"item");
    node->AddChild(itemNode);

    itemNode->AddAttribute(L"x", wxString::FromDouble(GetX()));
    itemNode->AddAttribute(L"y", wxString::FromDouble(GetY()));
    itemNode->AddAttribute(L"x-speed", wxString::FromDouble(mSpeedX));
    itemNode->AddAttribute(L"y-speed", wxString::FromDouble(mSpeedY));

    return itemNode;
}

/**
 * Load the attributes for an item node.
 *
 * This is the  base class version that loads the attributes
 * common to all items. Override this to load custom attributes
 * for specific items.
 *
 * @param node The Xml node we are loading the item from
 */
void Fish::XmlLoad(wxXmlNode *node)
{
    Item::XmlLoad(node);

    node->GetAttribute(L"x-speed", L"0").ToDouble(&mSpeedX);
    node->GetAttribute(L"y-speed", L"0").ToDouble(&mSpeedY);

}