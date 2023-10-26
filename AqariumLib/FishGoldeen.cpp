/**
 * @file FishGoldeen.cpp
 * @author Quinton Strausbaugh
 *
 * Initialize the goldeen fish class
 */

#include "pch.h"
#include <string>
#include "FishGoldeen.h"
#include "Aquarium.h"

using namespace std;

/// fish filename
const wstring FishGoldeenImageName = L"images/goldeen.png";

/**
 * Constructor
 * @param aquarium Aquarium this fish is a member of
 */
FishGoldeen::FishGoldeen(Aquarium *aquarium) : Fish(aquarium, FishGoldeenImageName)
{
    SetSpeedY(75);
    SetSpeedX(100);
}

/**
 * Save this fish to an XML node
 * @param node The parent node we are going to be a child of
 * @return node The node of the item to be saved
 */
wxXmlNode* FishGoldeen::XmlSave(wxXmlNode* node)
{
    auto itemNode = Fish::XmlSave(node);
    itemNode->AddAttribute(L"type", L"goldeen");

    return itemNode;
}

/**
 * Handle updates in time of our fish
 *
 * This is called before we draw and allows us to
 * move our fish. We add our speed times the amount
 * of time that has elapsed.
 * @param elapsed Time elapsed since the class call
 */
void FishGoldeen::Update(double elapsed)
{

    if (GetSpeedY() > 0 && GetY() >= 400)
    {
        SetSpeedY(-GetSpeedY());
    }
    if (GetSpeedY() < 0 && GetY() <= 100)
    {
        SetSpeedY(-GetSpeedY());
    }

    Fish::Update(elapsed);
}