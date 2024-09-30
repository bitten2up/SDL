/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2023 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/
#include "../../SDL_internal.h"

#if SDL_VIDEO_DRIVER_N3DS && SDL_VIDEO_OPENGL_EGL

/* Nintendo 3ds SDL video driver implementation */

#include "SDL_video.h"
#include "SDL_n3dsgl.h"
#include "SDL_n3dsvideo.h"

/* EGL implementation of SDL OpenGL support */

void N3DS_GLES_DefaultProfileConfig(_THIS, int *mask, int *major, int *minor)
{
    *mask = SDL_GL_CONTEXT_PROFILE_ES;
    *major = 2;
    *minor = 0;
}

int N3DS_GLES_LoadLibrary(_THIS, const char *path)
{
    return SDL_EGL_LoadLibrary(_this, path, EGL_DEFAULT_DISPLAY, 0);
}

void N3DS_GLES_DeleteContext(_THIS, SDL_GLContext context)
{
    EGLContext egl_context = (EGLContext)context;

    /* Clean up GLES and EGL */
    if (!_this->egl_data) {
        return;
    }

    if (egl_context != NULL && egl_context != EGL_NO_CONTEXT) {
        _this->egl_data->eglDestroyContext(_this->egl_data->egl_display, egl_context);
    }
}

SDL_EGL_CreateContext_impl(N3DS)
SDL_EGL_MakeCurrent_impl(N3DS)
SDL_EGL_SwapWindow_impl(N3DS)

#endif /* SDL_VIDEO_DRIVER_N3DS */

/* vi: set ts=4 sw=4 expandtab: */
