/**
 * @file FishBeta.cpp
 * @author Quinton Strausbaugh
 *
 * Initialize the beta fish information
 */

#include "pch.h"
#include <string>
#include "FishBeta.h"
#include "Aquarium.h"

using namespace std;

/// Fish filename
const wstring FishBetaImageName = L"images/beta.png";

/**
 * Constructor
 * @param aquarium Aquarium this fish is a member of
 */
FishBeta::FishBeta(Aquarium *aquarium) : Fish(aquarium, FishBetaImageName)
{
    SetSpeedY(50);
}

/**
 * Save this fish to an XML node
 * @param node The parent node we are going to be a child of
 * @return node The node of the item to be saved
 */
wxXmlNode* FishBeta::XmlSave(wxXmlNode* node)
{
    auto itemNode = Fish::XmlSave(node);
    itemNode->AddAttribute(L"type", L"beta");

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
void FishBeta::Update(double elapsed)
{
    if (GetSpeedY() > 0 && (GetY() >= (GetAquarium()->GetHeight() - (GetHeight()/2) - 50)))
    {
        SetSpeedY(GetSpeedY()*-1.5);
    }
    if ((GetSpeedY() < 0) && GetY() <= (50 + GetHeight()/2)) {
        SetSpeedY(GetSpeedY()*-.5);

    }


    Fish::Update(elapsed);
}