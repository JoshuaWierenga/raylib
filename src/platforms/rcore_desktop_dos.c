/**********************************************************************************************
*
*   rcore_desktop_dos template - Functions to manage window, graphics device and inputs
*
*   PLATFORM: DESKTOP: DOS
*       - DOS (DJGPP)
*
*   LIMITATIONS:
*       - Software renderer (rlsw)
*
*   POSSIBLE IMPROVEMENTS:
*       - Improvement 01
*       - Improvement 02
*
*   ADDITIONAL NOTES:
*       - TRACELOG() function is located in raylib [utils] module
*
*   CONFIGURATION:
*       #define RCORE_PLATFORM_CUSTOM_FLAG
*           Custom flag for rcore on target platform -not used-
*
*   DEPENDENCIES:
*       - rlsw: Software renderer
*       - gestures: Gestures system for touch-ready devices (or simulated from mouse inputs)
*
*
*   LICENSE: zlib/libpng
*
*   Copyright (c) 2013-2026 Ramon Santamaria (@raysan5) and contributors
*
*   This software is provided "as-is", without any express or implied warranty. In no event
*   will the authors be held liable for any damages arising from the use of this software.
*
*   Permission is granted to anyone to use this software for any purpose, including commercial
*   applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*     1. The origin of this software must not be misrepresented; you must not claim that you
*     wrote the original software. If you use this software in a product, an acknowledgment
*     in the product documentation would be appreciated but is not required.
*
*     2. Altered source versions must be plainly marked as such, and must not be misrepresented
*     as being the original software.
*
*     3. This notice may not be removed or altered from any source distribution.
*
**********************************************************************************************/

#include <dpmi.h>

#include "external/mkkbd3/keyboard.h"
#include "external/vesa-dos-djgpp/src/types.h"
#include "external/vesa-dos-djgpp/src/vesa.h"

//----------------------------------------------------------------------------------
// Types and Structures Definition
//----------------------------------------------------------------------------------
typedef struct {
    VBESURFACE *surface;
    bool mouseSupported;
    bool mouseMiddleClickSupported;
    bool mouseScrollWheelSupported;
} PlatformData;

//----------------------------------------------------------------------------------
// Global Variables Definition
//----------------------------------------------------------------------------------
extern CoreData CORE;                   // Global CORE state context

static PlatformData platform = { 0 };   // Platform specific data

//----------------------------------------------------------------------------------
// Module Internal Functions Declaration
//----------------------------------------------------------------------------------
int InitPlatform(void);          // Initialize platform (graphics, inputs and more)
bool InitGraphicsDevice(void);   // Initialize graphics device

//----------------------------------------------------------------------------------
// Module Functions Declaration
//----------------------------------------------------------------------------------
// NOTE: Functions declaration is provided by raylib.h

//----------------------------------------------------------------------------------
// Module Functions Definition: Window and Graphics Device
//----------------------------------------------------------------------------------

// Check if application should close
bool WindowShouldClose(void)
{
    if (CORE.Window.ready) return CORE.Window.shouldClose;
    else return true;
}

// Toggle fullscreen mode
void ToggleFullscreen(void)
{
    TRACELOG(LOG_WARNING, "ToggleFullscreen() not available on target platform");
}

// Toggle borderless windowed mode
void ToggleBorderlessWindowed(void)
{
    TRACELOG(LOG_WARNING, "ToggleBorderlessWindowed() not available on target platform");
}

// Set window state: maximized, if resizable
void MaximizeWindow(void)
{
    TRACELOG(LOG_WARNING, "MaximizeWindow() not available on target platform");
}

// Set window state: minimized
void MinimizeWindow(void)
{
    TRACELOG(LOG_WARNING, "MinimizeWindow() not available on target platform");
}

// Restore window from being minimized/maximized
void RestoreWindow(void)
{
    TRACELOG(LOG_WARNING, "RestoreWindow() not available on target platform");
}

// Set window configuration state using flags
void SetWindowState(unsigned int flags)
{
    TRACELOG(LOG_WARNING, "SetWindowState() not available on target platform");
}

// Clear window configuration state flags
void ClearWindowState(unsigned int flags)
{
    TRACELOG(LOG_WARNING, "ClearWindowState() not available on target platform");
}

// Set icon for window
void SetWindowIcon(Image image)
{
    TRACELOG(LOG_WARNING, "SetWindowIcon() not available on target platform");
}

// Set icon for window
void SetWindowIcons(Image *images, int count)
{
    TRACELOG(LOG_WARNING, "SetWindowIcons() not available on target platform");
}

// Set title for window
void SetWindowTitle(const char *title)
{
    CORE.Window.title = title;
}

// Set window position on screen (windowed mode)
void SetWindowPosition(int x, int y)
{
    TRACELOG(LOG_WARNING, "SetWindowPosition() not available on target platform");
}

// Set monitor for the current window
void SetWindowMonitor(int monitor)
{
    TRACELOG(LOG_WARNING, "SetWindowMonitor() not available on target platform");
}

// Set window minimum dimensions (FLAG_WINDOW_RESIZABLE)
void SetWindowMinSize(int width, int height)
{
    CORE.Window.screenMin.width = width;
    CORE.Window.screenMin.height = height;
}

// Set window maximum dimensions (FLAG_WINDOW_RESIZABLE)
void SetWindowMaxSize(int width, int height)
{
    CORE.Window.screenMax.width = width;
    CORE.Window.screenMax.height = height;
}

// Set window dimensions
void SetWindowSize(int width, int height)
{
    TRACELOG(LOG_WARNING, "SetWindowSize() not available on target platform");
}

// Set window opacity, value opacity is between 0.0 and 1.0
void SetWindowOpacity(float opacity)
{
    TRACELOG(LOG_WARNING, "SetWindowOpacity() not available on target platform");
}

// Set window focused
void SetWindowFocused(void)
{
    TRACELOG(LOG_WARNING, "SetWindowFocused() not available on target platform");
}

// Get native window handle
void *GetWindowHandle(void)
{
    return platform.surface;
}

// Get number of monitors
int GetMonitorCount(void)
{
    return 1;
}

// Get current monitor where window is placed
int GetCurrentMonitor(void)
{
    return 0;
}

// Get selected monitor position
Vector2 GetMonitorPosition(int monitor)
{
    return (Vector2){ 0, 0 };
}

// Get selected monitor width (currently used by monitor)
int GetMonitorWidth(int monitor)
{
    return CORE.Window.display.width;
}

// Get selected monitor height (currently used by monitor)
int GetMonitorHeight(int monitor)
{
    return CORE.Window.display.width;
}

// Get selected monitor physical width in millimetres
int GetMonitorPhysicalWidth(int monitor)
{
    TRACELOG(LOG_WARNING, "GetMonitorPhysicalWidth() not implemented on target platform");
    return 0;
}

// Get selected monitor physical height in millimetres
int GetMonitorPhysicalHeight(int monitor)
{
    TRACELOG(LOG_WARNING, "GetMonitorPhysicalHeight() not implemented on target platform");
    return 0;
}

// Get selected monitor refresh rate
int GetMonitorRefreshRate(int monitor)
{
    TRACELOG(LOG_WARNING, "GetMonitorRefreshRate() not implemented on target platform");
    return 0;
}

// Get the human-readable, UTF-8 encoded name of the selected monitor
const char *GetMonitorName(int monitor)
{
    TRACELOG(LOG_WARNING, "GetMonitorName() not implemented on target platform");
    return "";
}

// Get window position XY on monitor
Vector2 GetWindowPosition(void)
{
    return (Vector2){ 0, 0 };
}

// Get window scale DPI factor for current monitor
Vector2 GetWindowScaleDPI(void)
{
    TRACELOG(LOG_WARNING, "GetWindowScaleDPI() not implemented on target platform");
    return (Vector2){ 1.0f, 1.0f };
}

// Set clipboard text content
void SetClipboardText(const char *text)
{
    TRACELOG(LOG_WARNING, "SetClipboardText() not implemented on target platform");
}

// Get clipboard text content
const char *GetClipboardText(void)
{
    TRACELOG(LOG_WARNING, "GetClipboardText() not implemented on target platform");
    return NULL;
}

// Get clipboard image
Image GetClipboardImage(void)
{
    Image image = { 0 };

    TRACELOG(LOG_WARNING, "GetClipboardImage() not implemented on target platform");

    return image;
}

// Show mouse cursor
void ShowCursor(void)
{
    CORE.Input.Mouse.cursorHidden = false;
}

// Hides mouse cursor
void HideCursor(void)
{
    CORE.Input.Mouse.cursorHidden = true;
}

// Enables cursor (unlock cursor)
void EnableCursor(void)
{
    // Set cursor position in the middle
    SetMousePosition(CORE.Window.screen.width/2, CORE.Window.screen.height/2);

    CORE.Input.Mouse.cursorHidden = false;
}

// Disables cursor (lock cursor)
void DisableCursor(void)
{
    // Set cursor position in the middle
    SetMousePosition(CORE.Window.screen.width/2, CORE.Window.screen.height/2);

    CORE.Input.Mouse.cursorHidden = true;
}

// From https://opengameart.org/content/nats-8x8-ui-pack-over-50-ui-elements
static unsigned char cursor[] = {
  229, 229, 229, 229, 191,   0,   0,   0,
  229, 229, 191,   0,   0,   0,   0,   0,
  229, 191, 229, 191,   0,   0,   0,   0,
  229, 191,   0, 229, 191,   0,   0,   0,
  191,   0,   0,   0, 229, 191,   0,   0,
    0,   0,   0,   0,   0, 229, 191,   0,
    0,   0,   0,   0,   0,   0, 229, 191,
    0,   0,   0,   0,   0,   0,   0, 229
};

static void DrawCursor(void)
{
    unsigned char *buffer = platform.surface->offscreen_ptr;
    unsigned int width = 4 * platform.surface->x_resolution;

    // Add (1, 1) to point at but not cover mouse position
    unsigned int startX = 4 * (CORE.Input.Mouse.currentPosition.x + 1);
    unsigned int startY = CORE.Input.Mouse.currentPosition.y + 1;
    unsigned int incY = 2 * width;

    unsigned int endX;
    unsigned int endY;
    if (FLAG_IS_SET(CORE.Window.flags, FLAG_WINDOW_DOS_SCALE))
    {
        endX = width;
        endY = width * platform.surface->y_resolution;
    }
    else
    {
        endX = 4 * CORE.Window.screen.width;
        endY = width * CORE.Window.screen.height;
    }

    // Draw as 16x16 instead of 8x8 by unrolling to set 2x2 areas for inner loop iteration
    for (unsigned int i = 0, y = width * startY; i < 64 && y < endY; i += 8, y += incY)
    {
        for (unsigned int j = 0, x = startX; j < 8 && x < endX; ++j, x += 8)
        {
            unsigned int color = cursor[i + j];
            if (color == 0) continue;

            unsigned int bufferPos = y + x;
            buffer[bufferPos + 0] = color;
            buffer[bufferPos + 1] = color;
            buffer[bufferPos + 2] = color;
            buffer[bufferPos + 4] = color;
            buffer[bufferPos + 5] = color;
            buffer[bufferPos + 6] = color;

            bufferPos += width;
            buffer[bufferPos + 0] = color;
            buffer[bufferPos + 1] = color;
            buffer[bufferPos + 2] = color;
            buffer[bufferPos + 4] = color;
            buffer[bufferPos + 5] = color;
            buffer[bufferPos + 6] = color;
        }
    }
}

#define MIN(a,b) (((a)<(b))? (a):(b))

// Swap back buffer with front buffer (screen drawing)
void SwapScreenBuffer(void)
{
    // Currently there are three buffers:
    // RLSW buffer, user requested size in RGBA
    // VBE back buffer, 640/720x480 in BGRX, X is unused and should be zero
    // VBE front buffer, 640/720x480 in BGRX, X is unused and should be zero

    // Move from RLSW to VBE back buffer, changing byte order
    if (FLAG_IS_SET(CORE.Window.flags, FLAG_WINDOW_DOS_SCALE))
    {
        // TODO: Explicitly set every fourth byte to 0
        swBlitFramebuffer(0, 0, CORE.Window.display.width, CORE.Window.display.height, 0, 0, RLSW.framebuffer.width, RLSW.framebuffer.height, SW_RGBA, SW_UNSIGNED_BYTE, platform.surface->offscreen_ptr);
    }
    else
    {
        // If the RLSW buffer is smaller than the VBE buffers than pad with black pixels
        const sw_pixel_t *src = RLSW.framebuffer.pixels;
        uint8_t *dst = platform.surface->offscreen_ptr;

        size_t xSkip = 4 * (CORE.Window.display.width - RLSW.framebuffer.width);

        uint8_t color[4];
        for (int dy = 0; dy < MIN(RLSW.framebuffer.height, CORE.Window.display.height); ++dy)
        {
            for (int dx = 0; dx < MIN(RLSW.framebuffer.width, CORE.Window.display.width); ++dx)
            {
                sw_framebuffer_read_color8(color, src);

                dst[0] = color[2];
                dst[1] = color[1];
                dst[2] = color[0];

                dst += 4;
                ++src;
            }

            dst += xSkip;
        }
    }

    if (!CORE.Input.Mouse.cursorHidden)
    {
        DrawCursor();
    }

    // TODO: Call VGAwaitVrt?
    // Move from VBE back buffer to front buffer
    flipScreen();
}

//----------------------------------------------------------------------------------
// Module Functions Definition: Misc
//----------------------------------------------------------------------------------

// Get elapsed time measure in seconds since InitTimer()
double GetTime(void)
{
    double time = 0.0;

    // clock/rawclock have 18.2 ticks per second which leads to inaccurate fps reporting
    // uclock has 1193180 ticks per second but rolls over every 24 to 48 hours
    uclock_t ticks = uclock();
    time = (double)ticks/UCLOCKS_PER_SEC;  // Elapsed time since InitTimer()

    return time;
}

// Open URL with default system browser (if available)
// NOTE: This function is only safe to use if you control the URL given.
// A user could craft a malicious string performing another action.
// Only call this function yourself not with user input or make sure to check the string yourself.
// Ref: https://github.com/raysan5/raylib/issues/686
void OpenURL(const char *url)
{
    // Security check to (partially) avoid malicious code on target platform
    if (strchr(url, '\'') != NULL) TRACELOG(LOG_WARNING, "SYSTEM: Provided URL could be potentially malicious, avoid [\'] character");
    else
    {
        // TODO: Load url using default browser
    }
}

//----------------------------------------------------------------------------------
// Module Functions Definition: Inputs
//----------------------------------------------------------------------------------

// Set internal gamepad mappings
int SetGamepadMappings(const char *mappings)
{
    TRACELOG(LOG_WARNING, "SetGamepadMappings() not implemented on target platform");
    return 0;
}

// Set gamepad vibration
void SetGamepadVibration(int gamepad, float leftMotor, float rightMotor, float duration)
{
    TRACELOG(LOG_WARNING, "SetGamepadVibration() not implemented on target platform");
}

// Set mouse position XY
void SetMousePosition(int x, int y)
{
    CORE.Input.Mouse.currentPosition = (Vector2){ (float)x, (float)y };
    CORE.Input.Mouse.previousPosition = CORE.Input.Mouse.currentPosition;
}

// Set mouse cursor
void SetMouseCursor(int cursor)
{
    TRACELOG(LOG_WARNING, "SetMouseCursor() not implemented on target platform");
}

// Get physical key name.
const char *GetKeyName(int key)
{
    TRACELOG(LOG_WARNING, "GetKeyName() not implemented on target platform");
    return "";
}

static KeyboardKey GetKey(unsigned int scancode, char pressed, bool extended)
{
    unsigned int ext_scancode = scancode;
    if (pressed == 0)
    {
        ext_scancode &= ~SCAN_RELEASED_PREFIX;
    }
    if (extended)
    {
        ext_scancode |= SCAN_EXT;
    }

    switch (ext_scancode)
    {
        case SCAN_ESC: return KEY_ESCAPE;
        case SCAN_1: return KEY_ONE;
        case SCAN_2: return KEY_TWO;
        case SCAN_3: return KEY_THREE;
        case SCAN_4: return KEY_FOUR;
        case SCAN_5: return KEY_FIVE;
        case SCAN_6: return KEY_SIX;
        case SCAN_7: return KEY_SEVEN;
        case SCAN_8: return KEY_EIGHT;
        case SCAN_9: return KEY_NINE;
        case SCAN_0: return KEY_ZERO;
        case SCAN_MINUS: return KEY_MINUS;
        case SCAN_EQUALS: return KEY_EQUAL;
        case SCAN_BACKSP: return KEY_BACKSPACE;
        case SCAN_TAB: return KEY_TAB;
        case SCAN_Q: return KEY_Q;
        case SCAN_W: return KEY_W;
        case SCAN_E: return KEY_E;
        case SCAN_R: return KEY_R;
        case SCAN_T: return KEY_T;
        case SCAN_Y: return KEY_Y;
        case SCAN_U: return KEY_U;
        case SCAN_I: return KEY_I;
        case SCAN_O: return KEY_O;
        case SCAN_P: return KEY_P;
        case SCAN_LANGLE: return KEY_LEFT_BRACKET;
        case SCAN_RANGLE: return KEY_RIGHT_BRACKET;
        case SCAN_ENTER: return KEY_ENTER;
        case SCAN_CTRL: return KEY_LEFT_CONTROL;
        case SCAN_A: return KEY_A;
        case SCAN_S: return KEY_S;
        case SCAN_D: return KEY_D;
        case SCAN_F: return KEY_F;
        case SCAN_G: return KEY_G;
        case SCAN_H: return KEY_H;
        case SCAN_J: return KEY_J;
        case SCAN_K: return KEY_K;
        case SCAN_L: return KEY_L;
        case SCAN_SCOLON: return KEY_SEMICOLON;
        case SCAN_QUOTA: return KEY_APOSTROPHE;
        case SCAN_RQUOTA: return KEY_GRAVE;
        case SCAN_LSHIFT: return KEY_LEFT_SHIFT;
        case SCAN_BSLASH: return KEY_BACKSLASH;
        case SCAN_Z: return KEY_Z;
        case SCAN_X: return KEY_X;
        case SCAN_C: return KEY_C;
        case SCAN_V: return KEY_V;
        case SCAN_B: return KEY_B;
        case SCAN_N: return KEY_N;
        case SCAN_M: return KEY_M;
        case SCAN_COMA: return KEY_COMMA;
        case SCAN_DOT: return KEY_PERIOD;
        case SCAN_SLASH: return KEY_SLASH;
        case SCAN_RSHIFT: return KEY_RIGHT_SHIFT;
        case SCAN_GREY_STAR: return KEY_KP_MULTIPLY;
        case SCAN_ALT: return KEY_LEFT_ALT;
        case SCAN_SPACE: return KEY_SPACE;
        case SCAN_CAPS: return KEY_CAPS_LOCK;
        case SCAN_F1: return KEY_F1;
        case SCAN_F2: return KEY_F2;
        case SCAN_F3: return KEY_F3;
        case SCAN_F4: return KEY_F4;
        case SCAN_F5: return KEY_F5;
        case SCAN_F6: return KEY_F6;
        case SCAN_F7: return KEY_F7;
        case SCAN_F8: return KEY_F8;
        case SCAN_F9: return KEY_F9;
        case SCAN_F10: return KEY_F10;
        case SCAN_NUMLOCK: return KEY_NUM_LOCK;
        case SCAN_SCRLOCK: return KEY_SCROLL_LOCK;
        case SCAN_HOME: return KEY_KP_7;
        case SCAN_UP: return KEY_KP_8;
        case SCAN_PGUP: return KEY_KP_9;
        case SCAN_GREY_MINUS: return KEY_KP_SUBTRACT;
        case SCAN_LEFT: return KEY_KP_4;
        case SCAN_PAD_5: return KEY_KP_5;
        case SCAN_RIGHT: return KEY_KP_6;
        case SCAN_GREY_PLUS: return KEY_KP_ADD;
        case SCAN_END: return KEY_KP_1;
        case SCAN_DOWN: return KEY_KP_2;
        case SCAN_PGDN: return KEY_KP_3;
        case SCAN_INSERT: return KEY_KP_0;
        case SCAN_DEL: return KEY_KP_DECIMAL;
        case SCAN_F11: return KEY_F11;
        case SCAN_F12: return KEY_F12;

        case SCAN_EXT | SCAN_EXT_KP_ENTER: return KEY_KP_ENTER; // TODO: Fix, this doesn't trigger for me @JoshuaWierenga
        case SCAN_EXT | SCAN_EXT_PRINT_SCREEN: return KEY_PRINT_SCREEN;
        case SCAN_EXT | SCAN_CTRL: return KEY_RIGHT_CONTROL;
        case SCAN_EXT | SCAN_SLASH: return KEY_KP_DIVIDE;
        case SCAN_EXT | SCAN_ALT: return KEY_RIGHT_ALT;
        case SCAN_EXT | SCAN_HOME: return KEY_HOME;
        case SCAN_EXT | SCAN_UP: return KEY_UP;
        case SCAN_EXT | SCAN_PGUP: return KEY_PAGE_UP;
        case SCAN_EXT | SCAN_LEFT: return KEY_LEFT;
        case SCAN_EXT | SCAN_RIGHT: return KEY_RIGHT;
        case SCAN_EXT | SCAN_END: return KEY_END;
        case SCAN_EXT | SCAN_DOWN: return KEY_DOWN;
        case SCAN_EXT | SCAN_PGDN: return KEY_PAGE_DOWN;
        case SCAN_EXT | SCAN_INSERT: return KEY_INSERT;
        case SCAN_EXT | SCAN_DEL: return KEY_DELETE;
        case SCAN_EXT | SCAN_EXT_LGUI: return KEY_LEFT_SUPER;  // TODO: Test, dosbox-x doesn't trigger this
        case SCAN_EXT | SCAN_EXT_RGUI: return KEY_RIGHT_SUPER; // TODO: Test, dosbox-x doesn't trigger this

        default: return KEY_NULL;
    }
}

static void HandleKey(unsigned int scancode, char pressed, bool extended)
{
    KeyboardKey key = GetKey(scancode, pressed, extended);

    // TRACELOG(LOG_INFO, "KEY: %s0x%hhx: %d", extended ? "0xe0 " : "", scancode, pressed);

    if (key != KEY_NULL)
    {
        CORE.Input.Keyboard.currentKeyState[key] = pressed;

        if ((key == CORE.Input.Keyboard.exitKey) && (pressed == 1)) CORE.Window.shouldClose = true;

    }
    else TRACELOG(LOG_WARNING, "INPUT: Unknown (or currently unhandled) virtual keycode %s0x%hhx", extended ? "0xe0 " : "", scancode);

    // TODO: Add key to the queue as well?
}

// TODO: Test modifier(s) + key
// TODO: Support KEY_KB_MENU(0xe0 0x5d, I just don't have one to test) & KEY_KP_EQUAL(no clue)?
void HandleKeys(bool extended)
{
    volatile char *map = extended ? ext_keyboard_map : keyboard_map;
    unsigned int start = extended ? SCAN_EXT_KP_ENTER : SCAN_ESC;
    unsigned int end = extended ? SCAN_EXT_RGUI : SCAN_F12;
    end |= SCAN_RELEASED_PREFIX;

    for (unsigned int scancode = start; scancode <= end; ++scancode)
    {
        if (map[scancode] == 0)
        {
            continue;
        }

        map[scancode] = 0;

        char pressed = scancode < SCAN_RELEASED_PREFIX;
        HandleKey(scancode, pressed, extended);
    }
}

void HandleMouseButtons(unsigned int status)
{
    CORE.Input.Mouse.currentButtonState[MOUSE_LEFT_BUTTON] = (status & 1) != 0;
    CORE.Input.Touch.currentTouchState[MOUSE_LEFT_BUTTON] = (status & 1) != 0;
    CORE.Input.Mouse.currentButtonState[MOUSE_RIGHT_BUTTON] = (status & 2) != 0;
    CORE.Input.Touch.currentTouchState[MOUSE_RIGHT_BUTTON] = (status & 2) != 0;
    if (platform.mouseMiddleClickSupported)
    {
        CORE.Input.Mouse.currentButtonState[MOUSE_MIDDLE_BUTTON] = (status & 4) != 0;
        CORE.Input.Touch.currentTouchState[MOUSE_MIDDLE_BUTTON] = (status & 4) != 0;
    }
}

// Register all input events
void PollInputEvents(void)
{
#if defined(SUPPORT_GESTURES_SYSTEM)
    // NOTE: Gestures update must be called every frame to reset gestures correctly
    // because ProcessGestureEvent() is just called on an event, not every frame
    UpdateGestures();
#endif

    // Reset keys/chars pressed registered
    CORE.Input.Keyboard.keyPressedQueueCount = 0;
    CORE.Input.Keyboard.charPressedQueueCount = 0;

    // Reset last gamepad button/axis registered state
    CORE.Input.Gamepad.lastButtonPressed = 0; // GAMEPAD_BUTTON_UNKNOWN
    //CORE.Input.Gamepad.axisCount = 0;

    // Register previous touch states
    for (int i = 0; i < MAX_TOUCH_POINTS; i++) CORE.Input.Touch.previousTouchState[i] = CORE.Input.Touch.currentTouchState[i];

    // Reset touch positions
    // TODO: It resets on target platform the mouse position and not filled again until a move-event,
    // so, if mouse is not moved it returns a (0, 0) position... this behaviour should be reviewed!
    //for (int i = 0; i < MAX_TOUCH_POINTS; i++) CORE.Input.Touch.position[i] = (Vector2){ 0, 0 };

    // Register previous keys states
    memcpy(CORE.Input.Keyboard.previousKeyState, CORE.Input.Keyboard.currentKeyState, sizeof(CORE.Input.Keyboard.previousKeyState));
    memset(CORE.Input.Keyboard.keyRepeatInFrame, 0, sizeof(CORE.Input.Keyboard.keyRepeatInFrame));

    short mouseScroll = 0;
    unsigned int mouseX = 0;
    unsigned int mouseY = 0;
    if (platform.mouseSupported)
    {
        __dpmi_regs r;
        r.x.ax = 0x03;
        __dpmi_int(0x33, &r);
        HandleMouseButtons(r.x.bx);
        if (platform.mouseScrollWheelSupported) mouseScroll = (short)r.x.bx >> 8;
        mouseX = r.x.cx * CORE.Window.display.width / 640;
        mouseY = r.x.dx * CORE.Window.display.height / 200;
    }

    // Register previous mouse wheel state
    CORE.Input.Mouse.previousWheelMove = CORE.Input.Mouse.currentWheelMove;
    CORE.Input.Mouse.currentWheelMove.y = mouseScroll;

    // Register previous mouse position
    CORE.Input.Mouse.previousPosition = CORE.Input.Mouse.currentPosition;
    CORE.Input.Mouse.currentPosition = (Vector2){ mouseX, mouseY };

    HandleKeys(false);
    HandleKeys(true);

    // Pause has no release sequence so release on next frame
    char pausePressed = keyboard_map[SCAN_EXT_PAUSE] != 0;
    keyboard_map[SCAN_EXT_PAUSE] = 0;
    if (pausePressed != 0 || CORE.Input.Keyboard.currentKeyState[KEY_PAUSE])
    {
        // TRACELOG(LOG_INFO, "KEY: 0x%hhx: %d", SCAN_EXT_PAUSE, pausePressed);
        CORE.Input.Keyboard.currentKeyState[KEY_PAUSE] = pausePressed;
    }
}

//----------------------------------------------------------------------------------
// Module Internal Functions Definition
//----------------------------------------------------------------------------------

static unsigned int getVBEMode(VBEINFO *vbeInfo, unsigned int width)
{
    for (unsigned short *mode = vbeInfo->video_mode_ptr; *mode != 0xFFFF; ++mode)
    {
        MODEINFO *modeInfo = VBEgetModeInfo(*mode);
        if (modeInfo == NULL)
        {
            break;
        }

        // Skip modes without a linear frame buffer
        if ((modeInfo->mode_attributes & 0x80) != 0x80)
        {
            continue;
        }

        // Skip modes with complex color encodings
        if (modeInfo->memory_model != 6)
        {
            continue;
        }

        // Skip modes not using 640x480 and 720x640 as these are supported by all VGA compatible monitors so can skip checking monitor support
        if (modeInfo->x_resolution != width || modeInfo->y_resolution != 480)
        {
            continue;
        }

        // Skip modes not using 32 bit colours
        if (modeInfo->bits_per_pixel != 32)
        {
            continue;
        }

        // Skip modes not using 8 bit colour channels
        if (modeInfo->red_mask_size != 8 || modeInfo->green_mask_size != 8 || modeInfo->blue_mask_size != 8)
        {
            continue;
        }

        // Skip modes not using BGRX, RGBX would be better but dosbox-x doesn't use it so I can't test
        if (modeInfo->blue_field_position != 0 || modeInfo->green_field_position != 8 || modeInfo->red_field_position != 16)
        {
            continue;
        }

        return *mode;
    }

    return 0xFFFF;
}

// Initialize platform: graphics, inputs and more
int InitPlatform(void)
{
    // Dos doesn't support OpenGL so can only work with software renderer
    if (rlGetVersion() != RL_OPENGL_11_SOFTWARE)
    {
        TRACELOG(LOG_WARNING, "DISPLAY: DOS platform requires software renderer (GRAPHICS_API_OPENGL_11_SOFTWARE)");
        TRACELOG(LOG_FATAL, "PLATFORM: Failed to initialize graphics device");
        return -1;
    }

    __dpmi_regs r;
    r.x.ax = 0x00;
    __dpmi_int(0x33, &r);
    platform.mouseSupported = r.x.ax == 0xFFFF;
    platform.mouseMiddleClickSupported = r.x.bx = 0x3;

    r.x.ax = 0x11;
    __dpmi_int(0x33, &r);
    platform.mouseScrollWheelSupported = r.x.ax == 0x574d && r.x.cx & 1 == 1;

    VBEINFO *vbeInfo = VBEgetInfo();
    if (vbeInfo == NULL)
    {
        TRACELOG(LOG_FATAL, "PLATFORM: Failed to initialize platform");
        return -1;
    }

    unsigned int modeID = getVBEMode(vbeInfo, 720);
    if (modeID == 0xFFFF)
    {
        modeID = getVBEMode(vbeInfo, 640);
    }
    if (modeID == 0xFFFF)
    {
        TRACELOG(LOG_FATAL, "PLATFORM: Failed to initialize platform");
        return -1;
    }

    platform.surface = VBEsetMode(modeID);
    if (platform.surface == NULL)
    {
        TRACELOG(LOG_FATAL, "PLATFORM: Failed to initialize platform");
        return -1;
    }

    CORE.Window.display.width = platform.surface->x_resolution;
    CORE.Window.display.height = platform.surface->y_resolution;

    keyboard_init();
    keyboard_chain(0);

    // TODO: Handle flags

    if (FLAG_IS_SET(CORE.Window.flags, FLAG_WINDOW_DOS_SCALE))
    {
        CORE.Input.Mouse.scale.x = (float)CORE.Window.screen.width / CORE.Window.display.width;
        CORE.Input.Mouse.scale.y = (float)CORE.Window.screen.height / CORE.Window.display.height;
    }
    else
    {
        CORE.Window.screen.width = MIN(CORE.Window.screen.width, CORE.Window.display.width);
        CORE.Window.screen.height = MIN(CORE.Window.screen.height, CORE.Window.display.height);
    }

    CORE.Window.render.width = CORE.Window.screen.width;
    CORE.Window.render.height = CORE.Window.screen.height;
    CORE.Window.currentFbo.width = CORE.Window.render.width;
    CORE.Window.currentFbo.height = CORE.Window.render.height;
    CORE.Window.ready = true;

    TRACELOG(LOG_INFO, "DISPLAY: Device initialized successfully");
    TRACELOG(LOG_INFO, "    > Display size: %i x %i", CORE.Window.display.width, CORE.Window.display.height);
    TRACELOG(LOG_INFO, "    > Screen size:  %i x %i", CORE.Window.screen.width, CORE.Window.screen.height);
    TRACELOG(LOG_INFO, "    > Render size:  %i x %i", CORE.Window.render.width, CORE.Window.render.height);
    TRACELOG(LOG_INFO, "    > Viewport offsets: %i, %i", CORE.Window.renderOffset.x, CORE.Window.renderOffset.y);

    // Initialize timing system
    //----------------------------------------------------------------------------
    // First call to uclock always returns 0 so just need to call it to start timing
    uclock();
    InitTimer();
    //----------------------------------------------------------------------------

    // TODO: Initialize storage system
    //----------------------------------------------------------------------------
    CORE.Storage.basePath = GetWorkingDirectory();
    //----------------------------------------------------------------------------

    TRACELOG(LOG_INFO, "PLATFORM: DOS: Initialized successfully");

    return 0;
}

// Close platform
void ClosePlatform(void)
{
    keyboard_chain(1);
    keyboard_close();
    VBEshutdown();
}

// EOF
