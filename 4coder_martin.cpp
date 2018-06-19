/*
4coder_default_bidings.cpp - Supplies the default bindings used for default 4coder behavior.

TYPE: 'build-target'
*/

// TOP

#if !defined(FCODER_MARTIN_BINDINGS)
#define FCODER_MARTIN_BINDINGS

#define EXTRA_KEYWORDS "4coder_martin_extension.h"

#include "4coder_default_include.cpp"

// NOTE(allen|a4.0.22): This no longer serves as very good example code.
// Good example code will be coming soon, but in the mean time you can go
// to 4coder_remapping_commands.cpp for examples of what binding code looks like.

#if !defined(NO_BINDING)
extern "C" int32_t
get_bindings(void *data, int32_t size){
    Bind_Helper context_ = begin_bind_helper(data, size);
    Bind_Helper *context = &context_;
    
    set_all_default_hooks(context);
#if defined(__APPLE__) && defined(__MACH__)
    mac_default_keys(context);
#else
    default_keys(context);
#endif
    
    begin_map(context, mapid_global);
    bind(context, key_right, MDFR_ALT, change_active_panel);
    bind(context, key_left, MDFR_ALT, change_active_panel_backwards);
    end_map(context);
    
    int32_t result = end_bind_helper(context);
    return(result);
}
#endif //NO_BINDING

#endif //FCODER_MARTIN_BINDINGS

// BOTTOM

