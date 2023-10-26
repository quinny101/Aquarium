/**
 * @file FishNemo.cpp
 * @author Quinton Strausbaugh
 *
 * Initialize class for Fish Nemo
 */

#include "pch.h"
#include <string>
#include "FishNemo.h"
#include "Aquarium.h"

using namespace std;

/// fish filename
const wstring FishNemoImageName = L"images/nemo.png";

/**
* Constructor
* @param aquarium Aquarium this fish is a member of
*/
FishNemo::FishNemo(Aquarium *aquarium) : Fish(aquarium, FishNemoImageName)
{
    SetSpeedY(100);
}

/**
 * Save this fish to an XML node
 * @param node The parent node we are going to be a child of
 * @return node The node of the item to be saved
 */
wxXmlNode* FishNemo::XmlSave(wxXmlNode* node)
{
    auto itemNode = Fish::XmlSave(node);
    itemNode->AddAttribute(L"type", L"nemo");

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
void FishNemo::Update(double elapsed)
{
    SetSpeedY(GetSpeedY() * 1.06) ;
    if ((GetSpeedY() < 0) && GetY() <= 200)
    {
        SetSpeedY(-(GetY()-200));
    }
    if ((GetSpeedY() > 0 && (GetY() >= 500)))
    {
        SetSpeedY(-(GetY()-500));
    }
    Fish::Update(elapsed);
}


