/**
 * @file AquariumView.cpp
 * @author Quinton Strausbaugh
 *
 * Initializes the view of the Aquarium and menus
 */

#include "pch.h"
#include "ids.h"
#include <wx/dcbuffer.h>
#include <algorithm>
#include "AquariumView.h"
#include "FishBeta.h"
#include "FishGoldeen.h"
#include "FishMagikarp.h"
#include "FishNemo.h"
#include "DecorCastle.h"

using namespace std;

/// Frame duration in milliseconds
const int FrameDuration = 30;

/**
* Initialize the aquarium view class.
* @param parent The parent window for this class
*/
void AquariumView::Initialize(wxFrame *parent)
{
     Create(parent, wxID_ANY);
     SetBackgroundStyle(wxBG_STYLE_PAINT);

     Bind(wxEVT_PAINT, &AquariumView::OnPaint, this);

     parent->Bind(wxEVT_COMMAND_MENU_SELECTED,
                  &AquariumView::OnAddFishBetaFish,
                  this,
                  IDM_ADDFISHBETA);
     parent->Bind(wxEVT_COMMAND_MENU_SELECTED,
                  &AquariumView::OnAddFishGoldeen,
                  this,
                  IDM_ADDFISHGOLDEEN);
     parent->Bind(wxEVT_COMMAND_MENU_SELECTED,
                  &AquariumView::OnAddFishMagikarp,
                  this,
                  IDM_ADDFISHMAGIKARP);
     parent->Bind(wxEVT_COMMAND_MENU_SELECTED,
                  &AquariumView::OnAddFishNemo,
                  this,
                  IDM_ADDFISHNEMO);
     parent->Bind(wxEVT_COMMAND_MENU_SELECTED,
                  &AquariumView::OnAddDecorCastle,
                  this,
                  IDM_ADDDECORCASTLE);

     parent->Bind(wxEVT_COMMAND_MENU_SELECTED,
                  &AquariumView::OnFileSaveAs,
                  this,
                  wxID_SAVEAS);
     parent->Bind(wxEVT_COMMAND_MENU_SELECTED,
                  &AquariumView::OnFileOpen,
                  this,
                  wxID_OPEN);

     Bind(wxEVT_LEFT_DOWN, &AquariumView::OnLeftDown, this);
     Bind(wxEVT_LEFT_UP, &AquariumView::OnLeftUp, this);
     Bind(wxEVT_MOTION, &AquariumView::OnMouseMove, this);


     mTimer.SetOwner(this);
     mTimer.Start(FrameDuration);

     Bind(wxEVT_TIMER, &AquariumView::OnTimer, this);
     mStopWatch.Start();

}

/**
* Paint event, draws the window.
* @param event Paint event object
*/
void AquariumView::OnPaint(wxPaintEvent& event)
{
    // Compute the time that has elapsed
    // since the last call to OnPaint.
    auto newTime = mStopWatch.Time();
    auto elapsed = (double)(newTime - mTime) * 0.001;
    mTime = newTime;

    wxAutoBufferedPaintDC dc(this);

    wxBrush background(*wxWHITE);
    dc.SetBackground(background);
    dc.Clear();

    mAquarium.OnDraw(&dc);
    mAquarium.Update(elapsed);
}

/**
* Menu handler for Add Fish>Beta Fish
* @param event Mouse event
*/
void AquariumView::OnAddFishBetaFish(wxCommandEvent& event)
{
    auto fish = make_shared<FishBeta>(&mAquarium);
    mAquarium.Add(fish);
    Refresh();
}

/**
* Menu handler for Add Fish>Goldeen Fish
* @param event Mouse event
*/
void AquariumView::OnAddFishGoldeen(wxCommandEvent& event)
{
      auto fish = make_shared<FishGoldeen>(&mAquarium);
      mAquarium.Add(fish);
      Refresh();
}

/**
* Menu handler for Add Fish>Magikarp fish
* @param event Mouse event
*/
void AquariumView::OnAddFishMagikarp(wxCommandEvent &event)
{
     auto fish = make_shared<FishMagikarp>(&mAquarium);
     mAquarium.Add(fish);
     Refresh();
}

/**
* Menu handler for Add Fish>Nemo fish
* @param event Mouse event
*/
void AquariumView::OnAddFishNemo(wxCommandEvent &event)
{
    auto fish = make_shared<FishNemo>(&mAquarium);
    mAquarium.Add(fish);
    Refresh();
}

/**
* Menu handler for Add Fish>Decor Castle
* @param event Mouse event
*/
void AquariumView::OnAddDecorCastle(wxCommandEvent &event)
{
    auto castle = make_shared<DecorCastle>(&mAquarium);
    mAquarium.Add(castle);
    Refresh();
}

/**
* Handle the left mouse button down event
* @param event mouse event
*/
void AquariumView::OnLeftDown(wxMouseEvent &event)
{
    mGrabbedItem = mAquarium.HitTest(event.GetX(), event.GetY());
    if (mGrabbedItem != nullptr)
    {
        // We have selected an item
        // Move it to the end of the list of items
        // you'll need code here to do that...
        mAquarium.ReAppend(mGrabbedItem);
    }
}

/**
* Handle the left mouse button down event
* @param event mouse event
*/
void AquariumView::OnLeftUp(wxMouseEvent &event)
{
    OnMouseMove(event);
}

/**
* Handle the left mouse button down event
* @param event mouse event
*/
void AquariumView::OnMouseMove(wxMouseEvent &event)
{
    // See if an item is currently being moved by the mouse
    if (mGrabbedItem != nullptr)
    {
        // If an item is being moved, we only continue to
        // move it while the left button is down.
        if (event.LeftIsDown())
        {

            mGrabbedItem->SetLocation(event.GetX(), event.GetY());
        }
        else
        {
            // When the left button is released, we release the item.
            mGrabbedItem = nullptr;
        }

        // Force the screen to redraw
        Refresh();
    }
}

/**
* Handle the Save As event
* @param event Save as event
*/
void AquariumView::OnFileSaveAs(wxCommandEvent & event)
{
    wxFileDialog saveFileDialog(this, L"Save Aquarium file", L"", L"",
                                L"Aquarium Files (*.aqua)|*.aqua", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    if (saveFileDialog.ShowModal() == wxID_CANCEL)
    {
        return;
    }

    auto filename = saveFileDialog.GetPath();
    mAquarium.Save(filename);
}

/**
 * File>Open menu handler
 * @param event Menu event
 */
void AquariumView::OnFileOpen(wxCommandEvent& event)
{
    wxFileDialog loadFileDialog(this, L"Load Aquarium file", L"", L"",
                                L"Aquarium Files (*.aqua)|*.aqua", wxFD_OPEN);
    if (loadFileDialog.ShowModal() == wxID_CANCEL)
    {
        return;
    }

    auto filename = loadFileDialog.GetPath();
    mAquarium.Load(filename);
    Refresh();
}

/**
 * Event handler for timer event
 * @param event The timer event to handle
 */
 void AquariumView::OnTimer(wxTimerEvent &event)
{
     Refresh();
}
