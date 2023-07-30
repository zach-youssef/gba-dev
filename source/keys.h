#ifndef KEYS_H
#define KEYS_H

#include "memory.h"
#include "basic_types.h"

#define KEY_INPUT *((volatile u16*) (MEMORY_IO + 0x0130))

#define KEY_A        0x0001
#define KEY_B        0x0002
#define KEY_SELECT   0x0004
#define KEY_START    0x0008
#define KEY_RIGHT    0x0010
#define KEY_LEFT     0x0020
#define KEY_UP       0x0040
#define KEY_DOWN     0x0080
#define KEY_R        0x0100
#define KEY_L        0x0200

#define KEY_MASK     0x03FF

extern u16 _key_current, _key_previous;

inline void poll_keys() {
    _key_previous = _key_current;
    _key_current = ~KEY_INPUT & KEY_MASK;
}

inline u32 key_current()         {   return _key_current;          }
inline u32 key_previous()         {   return _key_previous;          }
inline u32 key_is_down(u32 key)     {   return  _key_current & key;   }
inline u32 key_is_up(u32 key)       {   return ~_key_current & key;   }
inline u32 key_was_down(u32 key)    {   return  _key_previous & key;   }
inline u32 key_was_up(u32 key)      {   return ~_key_previous & key;   }

inline u32 key_released(u32 key) {
    return key_was_down(key) && key_is_up(key);
}

inline u32 key_pressed(u32 key) {
    return key_was_up(key) && key_is_down(key);
}

#endif