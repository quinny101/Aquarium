/**
 * @file FishMagikarp.cpp
 * @author Quinton Strausbaugh
 *
 * Initialize class for Fish Magikarp
 */

#include "pch.h"
#include <string>
#include "FishMagikarp.h"
#include "Aquarium.h"

using namespace std;

/// fish filename
const wstring FishMagikarpImageName = L"images/magikarp.png";

/**
* Constructor
* @param aquarium Aquarium this fish is a member of
*/
FishMagikarp::FishMagikarp(Aquarium *aquarium) : Fish(aquarium, FishMagikarpImageName)
{
    SetSpeedY(11);
}

/**
 * Save this fish to an XML node
 * @param node The parent node we are going to be a child of
 * @return node The node of the item to be saved
 */
wxXmlNode* FishMagikarp::XmlSave(wxXmlNode* node)
{
    auto itemNode = Fish::XmlSave(node);
    itemNode->AddAttribute(L"type", L"magikarp");

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
void FishMagikarp::Update(double elapsed)
{
    SetSpeedY(GetSpeedY() + 1);

    if ((int(GetSpeedY()) % 10 == 0) &&
        (GetSpeedY()) > 0 &&
        ((GetY() >= (GetAquarium()->GetHeight() - (GetHeight()/2) - 50)) ||
        (GetSpeedY() < 0) && GetY() <= (50 + GetHeight()/2)))
    {
        SetSpeedY(-GetSpeedY());
    }

    Fish::Update(elapsed);
}