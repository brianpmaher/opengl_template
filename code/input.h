#pragma once

////////////////////////////////////////////////////////////////////////////////
//                             Input Definitions
////////////////////////////////////////////////////////////////////////////////
// These key codes are duplicates of those defined in glfw3.h, but are redefined
// as enums and remove the GLFW_ prefix as a personal preference. See GLFW docs
// for usage.
////////////////////////////////////////////////////////////////////////////////

typedef enum KeyboardKey {
    KEY_UNKNOWN       = -1,

    // Printable keys
    KEY_SPACE         =  32,
    KEY_APOSTROPHE    =  39,  /* ' */
    KEY_COMMA         =  44,  /* , */
    KEY_MINUS         =  45,  /* - */
    KEY_PERIOD        =  46,  /* . */
    KEY_SLASH         =  47,  /* / */
    KEY_0             =  48,
    KEY_1             =  49,
    KEY_2             =  50,
    KEY_3             =  51,
    KEY_4             =  52,
    KEY_5             =  53,
    KEY_6             =  54,
    KEY_7             =  55,
    KEY_8             =  56,
    KEY_9             =  57,
    KEY_SEMICOLON     =  59,  /* ; */
    KEY_EQUAL         =  61,  /* = */
    KEY_A             =  65,
    KEY_B             =  66,
    KEY_C             =  67,
    KEY_D             =  68,
    KEY_E             =  69,
    KEY_F             =  70,
    KEY_G             =  71,
    KEY_H             =  72,
    KEY_I             =  73,
    KEY_J             =  74,
    KEY_K             =  75,
    KEY_L             =  76,
    KEY_M             =  77,
    KEY_N             =  78,
    KEY_O             =  79,
    KEY_P             =  80,
    KEY_Q             =  81,
    KEY_R             =  82,
    KEY_S             =  83,
    KEY_T             =  84,
    KEY_U             =  85,
    KEY_V             =  86,
    KEY_W             =  87,
    KEY_X             =  88,
    KEY_Y             =  89,
    KEY_Z             =  90,
    KEY_LEFT_BRACKET  =  91,  /* [ */
    KEY_BACKSLASH     =  92,  /* \ */
    KEY_RIGHT_BRACKET =  93,  /* ] */
    KEY_GRAVE_ACCENT  =  96,  /* ` */
    KEY_WORLD_1       =  161, /* non-US #1 */
    KEY_WORLD_2       =  162, /* non-US #2 */

    // Function keys
    KEY_ESCAPE        =  257,
    KEY_ENTER         =  258,
    KEY_TAB           =  259,
    KEY_BACKSPACE     =  260,
    KEY_INSERT        =  261,
    KEY_DELETE        =  262,
    KEY_RIGHT         =  263,
    KEY_LEFT          =  264,
    KEY_DOWN          =  265,
    KEY_UP            =  266,
    KEY_PAGE_UP       =  267,
    KEY_PAGE_DOWN     =  268,
    KEY_HOME          =  269,
    KEY_END           =  270,
    KEY_CAPS_LOCK     =  281,
    KEY_SCROLL_LOCK   =  282,
    KEY_NUM_LOCK      =  283,
    KEY_PRINT_SCREEN  =  284,
    KEY_PAUSE         =  285,
    KEY_F1            =  291,
    KEY_F2            =  292,
    KEY_F3            =  293,
    KEY_F4            =  294,
    KEY_F5            =  295,
    KEY_F6            =  296,
    KEY_F7            =  297,
    KEY_F8            =  298,
    KEY_F9            =  299,
    KEY_F10           =  300,
    KEY_F11           =  301,
    KEY_F12           =  302,
    KEY_F13           =  303,
    KEY_F14           =  304,
    KEY_F15           =  305,
    KEY_F16           =  306,
    KEY_F17           =  307,
    KEY_F18           =  308,
    KEY_F19           =  309,
    KEY_F20           =  310,
    KEY_F21           =  311,
    KEY_F22           =  312,
    KEY_F23           =  313,
    KEY_F24           =  314,
    KEY_F25           =  315,
    KEY_KP_0          =  321,
    KEY_KP_1          =  322,
    KEY_KP_2          =  323,
    KEY_KP_3          =  324,
    KEY_KP_4          =  325,
    KEY_KP_5          =  326,
    KEY_KP_6          =  327,
    KEY_KP_7          =  328,
    KEY_KP_8          =  329,
    KEY_KP_9          =  330,
    KEY_KP_DECIMAL    =  331,
    KEY_KP_DIVIDE     =  332,
    KEY_KP_MULTIPLY   =  333,
    KEY_KP_SUBTRACT   =  334,
    KEY_KP_ADD        =  335,
    KEY_KP_ENTER      =  336,
    KEY_KP_EQUAL      =  337,
    KEY_LEFT_SHIFT    =  341,
    KEY_LEFT_CONTROL  =  342,
    KEY_LEFT_ALT      =  343,
    KEY_LEFT_SUPER    =  344,
    KEY_RIGHT_SHIFT   =  345,
    KEY_RIGHT_CONTROL =  346,
    KEY_RIGHT_ALT     =  347,
    KEY_RIGHT_SUPER   =  348,
    KEY_MENU          =  349,
    KEY_LAST          =  KEY_MENU,
} KeyboardKey;

typedef enum ModiferKey {
    MOD_SHIFT     = 0x0001,
    MOD_CONTROL   = 0x0002,
    MOD_ALT       = 0x0004,
    MOD_SUPER     = 0x0008,
    MOD_CAPS_LOCK = 0x0010,
    MOD_NUM_LOCK  = 0x0020,
} ModiferKey;

typedef enum MouseButton {
    MOUSE_BUTTON_1      = 0,
    MOUSE_BUTTON_2      = 1,
    MOUSE_BUTTON_3      = 2,
    MOUSE_BUTTON_4      = 3,
    MOUSE_BUTTON_5      = 4,
    MOUSE_BUTTON_6      = 5,
    MOUSE_BUTTON_7      = 6,
    MOUSE_BUTTON_8      = 7,
    MOUSE_BUTTON_LAST   = MOUSE_BUTTON_8,
    MOUSE_BUTTON_LEFT   = MOUSE_BUTTON_1,
    MOUSE_BUTTON_RIGHT  = MOUSE_BUTTON_2,
    MOUSE_BUTTON_MIDDLE = MOUSE_BUTTON_3,
} MouseButton;

typedef enum Joystick {
    JOYSTICK_1    = 0,
    JOYSTICK_2    = 1,
    JOYSTICK_3    = 2,
    JOYSTICK_4    = 3,
    JOYSTICK_5    = 4,
    JOYSTICK_6    = 5,
    JOYSTICK_7    = 6,
    JOYSTICK_8    = 7,
    JOYSTICK_9    = 8,
    JOYSTICK_10   = 9,
    JOYSTICK_11   = 10,
    JOYSTICK_12   = 11,
    JOYSTICK_13   = 12,
    JOYSTICK_14   = 13,
    JOYSTICK_15   = 14,
    JOYSTICK_16   = 15,
    JOYSTICK_LAST = JOYSTICK_16,
} Joystick;

typedef enum GamepadButton {
    GAMEPAD_BUTTON_A            = 0,
    GAMEPAD_BUTTON_B            = 1,
    GAMEPAD_BUTTON_X            = 2,
    GAMEPAD_BUTTON_Y            = 3,
    GAMEPAD_BUTTON_LEFT_BUMPER  = 4,
    GAMEPAD_BUTTON_RIGHT_BUMPER = 5,
    GAMEPAD_BUTTON_BACK         = 6,
    GAMEPAD_BUTTON_START        = 7,
    GAMEPAD_BUTTON_GUIDE        = 8,
    GAMEPAD_BUTTON_LEFT_THUMB   = 9,
    GAMEPAD_BUTTON_RIGHT_THUMB  = 10,
    GAMEPAD_BUTTON_DPAD_UP      = 11,
    GAMEPAD_BUTTON_DPAD_RIGHT   = 12,
    GAMEPAD_BUTTON_DPAD_DOWN    = 13,
    GAMEPAD_BUTTON_DPAD_LEFT    = 14,
    GAMEPAD_BUTTON_LAST         = GAMEPAD_BUTTON_DPAD_LEFT,
    GAMEPAD_BUTTON_CROSS        = GAMEPAD_BUTTON_A,
    GAMEPAD_BUTTON_CIRCLE       = GAMEPAD_BUTTON_B,
    GAMEPAD_BUTTON_SQUARE       = GAMEPAD_BUTTON_X,
    GAMEPAD_BUTTON_TRIANGLE     = GAMEPAD_BUTTON_Y,
} GamepadButton;

typedef enum GamepadAxis {
    GAMEPAD_AXIS_LEFT_X        = 0,
    GAMEPAD_AXIS_LEFT_Y        = 1,
    GAMEPAD_AXIS_RIGHT_X       = 2,
    GAMEPAD_AXIS_RIGHT_Y       = 3,
    GAMEPAD_AXIS_LEFT_TRIGGER  = 4,
    GAMEPAD_AXIS_RIGHT_TRIGGER = 5,
    GAMEPAD_AXIS_LAST          = GAMEPAD_AXIS_RIGHT_TRIGGER,
} GamepadAxis;
