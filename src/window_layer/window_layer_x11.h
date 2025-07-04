#ifndef WINDOW_LAYER_XCB_H
#define WINDOW_LAYER_XCB_H

// XCB Includes
//=============================================================================

#include <xcb/xcb.h>

// Types
//=============================================================================

typedef struct Wl_X11_State Wl_X11_State;
struct Wl_X11_State {
    xcb_connection_t *connection;
    xcb_screen_t *screen;
    xcb_window_t window;
    xcb_atom_t wm_delete_window;
    xcb_atom_t wm_icon;
};

// Global Variables
//=============================================================================

global Wl_X11_State wl_x11_state = ZERO_STRUCT;

#endif // WINDOW_LAYER_XCB_H
