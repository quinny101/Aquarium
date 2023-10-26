/**
 * @file MainFrame.h
 * @author Quinton Strausbaugh
 *
 * Initialize the main frame of this class
 */

#ifndef AQUARIUM_AQUARIUMLIB_MAINFRAME_H
#define AQUARIUM_AQUARIUMLIB_MAINFRAME_H

/**
 * The top-level (main) frame of the application
 */
class MainFrame : public wxFrame {
private:
    // Exit menu option handlers
    void OnExit(wxCommandEvent& event);
public:
    // Function to handle initialization of the window
    void Initialize();
    // Function to follow the mouse movements
    void OnMouseEvent(wxCommandEvent &event);
};

#endif //AQUARIUM_AQUARIUMLIB_MAINFRAME_H
