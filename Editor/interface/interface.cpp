#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT
#include "nuklear.h"
#include "interface.hpp"

extern const char* engine_name;

namespace Engine
{
  /* This function handles all interface drawing */
  void doInterface(SceneState* sceneState, nk_context *ctx, int* window_width, int* window_height)
  {
      static float increasing = 0.0f;
      increasing += 0.1f;

      /* Draw square window border with transparent background */
      nk_style_push_color(ctx, &ctx->style.window.fixed_background.data.color, nk_rgba(0, 0, 0, 0));
      nk_begin(ctx, "border", nk_rect(0, 0, (int)*window_width, (int)*window_height), NK_WINDOW_BORDER | NK_WINDOW_BACKGROUND | NK_WINDOW_NOT_INTERACTIVE);
      nk_end(ctx);
      nk_style_pop_color(ctx); // End Window Border


      /* Draw Topbar */
      if (nk_begin(ctx, engine_name, nk_rect(0, 0, (float)*window_width, 50), NK_WINDOW_BORDER | NK_WINDOW_NO_SCROLLBAR ))
      {
        // icon at top left
        nk_layout_row_static(ctx, 50, 50, 1);
        // create completely white nk_image

        nk_label(ctx, engine_name, NK_TEXT_CENTERED);

        /* Topbar Functionality */
        static int  last_clicked = 0;
        static bool dragging = false;
        static int  mouseX, mouseY;
        static int  drag_offsetX, drag_offsetY; 

        /* Topbar clicked */
        if (nk_window_is_active(ctx, engine_name) && nk_window_is_hovered(ctx) && nk_input_has_mouse_click(&ctx->input, NK_BUTTON_LEFT))
        {
          // if last time topbar was clicked was less than 0.5 seconds ago
          if (SDL_GetTicks() - last_clicked < 500)
          {
            // If unmaximized then maximize and vice versa
            if (SDL_GetWindowFlags(SDL_GL_GetCurrentWindow()) & SDL_WINDOW_MAXIMIZED)
              SDL_RestoreWindow(SDL_GL_GetCurrentWindow());
            else
              SDL_MaximizeWindow(SDL_GL_GetCurrentWindow());
            // update GL viewport
            glViewport(0, 0, *window_width, *window_height);
            // set last_clicked to current time
            last_clicked = SDL_GetTicks();
          }
          else
          {
            last_clicked = SDL_GetTicks();
          }
        }

        /* Topbar Held */
        if (nk_window_is_active(ctx, engine_name) && nk_window_is_hovered(ctx) && nk_input_is_mouse_down(&ctx->input, NK_BUTTON_LEFT))
        {
          if (!dragging)
          {
            // set offset
            SDL_GetGlobalMouseState(&mouseX, &mouseY);
            SDL_GetWindowPosition(SDL_GL_GetCurrentWindow(), &drag_offsetX, &drag_offsetY);
            drag_offsetX = mouseX - drag_offsetX;
            drag_offsetY = mouseY - drag_offsetY;
            if (SDL_GetWindowFlags(SDL_GL_GetCurrentWindow()) & SDL_WINDOW_MAXIMIZED)
              SDL_RestoreWindow(SDL_GL_GetCurrentWindow());
            dragging = true;
          }
          /* Window Drag Functionality */
          if (dragging)
          {
            SDL_GetGlobalMouseState(&mouseX, &mouseY);
            SDL_SetWindowPosition(SDL_GL_GetCurrentWindow(), mouseX - drag_offsetX, mouseY - drag_offsetY);
          }
        }
        /* Topbar released */
        if (nk_input_is_mouse_released(&ctx->input, NK_BUTTON_LEFT))
        {
          dragging = false;
        }


      }
      nk_end(ctx); // End Topbar

  }
} // namespace Engine