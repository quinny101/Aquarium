/**
 * @file AquariumView.h
 * @author Quinton Strausbaugh
 *
 * Initialize the class of our aquarium view
 */

#ifndef AQUARIUM_AQUARIUMLIB_AQUARIUMVIEW_H
#define AQUARIUM_AQUARIUMLIB_AQUARIUMVIEW_H

#include "Aquarium.h"

/**
 * View class for our aquarium
 */
class AquariumView : public wxWindow {
private:
    // Paint event, draws the window.
    void OnPaint(wxPaintEvent& event);
    /// An object that describes our aquarium
    Aquarium mAquarium;
    /// Any item we are currently dragging
    std::shared_ptr<Item> mGrabbedItem;
    /// The timer that allows for animation
    wxTimer mTimer;
    /// Stopwatch used to measure elapsed time
    wxStopWatch mStopWatch;
    /// The last stopwatch time
    long mTime = 0;

public:
    // Initialize the aquarium view class
    void Initialize(wxFrame* parent);
    // The following 5 functions are used to add fish to the menu options
    void OnAddFishBetaFish(wxCommandEvent &event);
    void OnAddFishGoldeen(wxCommandEvent &event);
    void OnAddFishMagikarp(wxCommandEvent &event);
    void OnAddFishNemo(wxCommandEvent &event);
    void OnAddDecorCastle(wxCommandEvent &event);
    // The following functions are handlers for file related events
    void OnFileSaveAs(wxCommandEvent &event);
    void OnFileOpen(wxCommandEvent &event);
    // The following events are mouse events when interacting with screen
    void OnLeftDown(wxMouseEvent &event);
    void OnLeftUp(wxMouseEvent &event);
    void OnMouseMove(wxMouseEvent &event);
    // Handles the timer event
    void OnTimer(wxTimerEvent &event);

};

#endif //AQUARIUM_AQUARIUMLIB_AQUARIUMVIEW_H
