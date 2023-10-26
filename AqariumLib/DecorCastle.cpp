/**
 * @file DecorCastle.cpp
 * @author Quinton Strausbaugh
 *
 * Initialize the Decor Castle Class
 */

#include "pch.h"
#include "DecorCastle.h"

using namespace std;

/// fish filename
const wstring DecorCastleImageName = L"images/castle.png";

/**
* Constructor
* @param aquarium The aquarium this item is a member of
*/
DecorCastle::DecorCastle(Aquarium *aquarium) : Item(aquarium, DecorCastleImageName)
{
}

/**
 * Save this fish to an XML node
 * @param node The parent node we are going to be a child of
 * @return node The node of the item to be saved
 */
wxXmlNode* DecorCastle::XmlSave(wxXmlNode* node)
{
    auto itemNode = Item::XmlSave(node);
    itemNode->AddAttribute(L"type", L"castle");

    return itemNode;
}