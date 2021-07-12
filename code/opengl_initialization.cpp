#include <windows.h>
#include <gl/gl.h>
#include <cstdint>
#include "definitions.h"
#include "opengl_initialization.h"

// NOTE(Luke): `OpenGLInitialization` and `OPENGL_INITIALIZATION` are the stand in names for the program.

global_var wgl_choose_pixel_format_arb *wglChoosePixelFormatARB;
global_var wgl_create_context_attribs_arb *wglCreateContextAttribsARB;
global_var wgl_swap_interval_ext *wglSwapIntervalEXT;
global_var gl_create_shader *glCreateShader;
global_var gl_shader_source *glShaderSource;
global_var gl_compile_shader *glCompileShader;
global_var gl_create_program *glCreateProgram;
global_var gl_attach_shader *glAttachShader;
global_var gl_link_program *glLinkProgram;
global_var gl_delete_shader *glDeleteShader;
global_var gl_gen_vertex_arrays *glGenVertexArrays;
global_var gl_gen_buffers *glGenBuffers;
global_var gl_bind_vertex_array *glBindVertexArray;
global_var gl_bind_buffer *glBindBuffer;
global_var gl_buffer_data *glBufferData;
global_var gl_vertex_attrib_pointer *glVertexAttribPointer;
global_var gl_enable_vertex_attrib_array *glEnableVertexAttribArray;
global_var gl_use_program *glUseProgram;
global_var gl_bind_frame_buffer *glBindFramebuffer;
global_var gl_gen_frame_buffers *glGenFramebuffers;
global_var gl_gen_render_buffers *glGenRenderbuffers;
global_var gl_get_shader_iv *glGetShaderiv;

global_var HGLRC global_gl_rc;

// TODO(Luke): Probably return success/error.
internal void
Win32LoadWGLExtensions()
{
    WNDCLASSA window_class = {};
    
    window_class.lpfnWndProc = DefWindowProcA;
    window_class.hInstance = GetModuleHandleA(0);
    window_class.lpszClassName = "OpenGLInitializationWGLLoader";
    
    if(RegisterClassA(&window_class))
    {
        HWND temporary_window = CreateWindowExA(
                                                0,
                                                window_class.lpszClassName,
                                                "OpenGLInitialization",
                                                0,
                                                CW_USEDEFAULT,
                                                CW_USEDEFAULT,
                                                CW_USEDEFAULT,
                                                CW_USEDEFAULT,
                                                0,
                                                0,
                                                window_class.hInstance,
                                                0);
        
        HDC window_dc = GetDC(temporary_window);
        
        int format_index = 0;
        PIXELFORMATDESCRIPTOR desired_format = {};
        desired_format.nSize = sizeof(desired_format);
        desired_format.nVersion = 1;
        desired_format.iPixelType = PFD_TYPE_RGBA;
        desired_format.dwFlags = PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW | PFD_DOUBLEBUFFER;
        desired_format.cColorBits = 32;
        desired_format.cAlphaBits = 8;
        
        format_index = ChoosePixelFormat(window_dc, &desired_format);
        
        PIXELFORMATDESCRIPTOR format_received;
        SetPixelFormat(window_dc, format_index, &format_received);
        HGLRC glrc = wglCreateContext(window_dc);
        
        if(wglMakeCurrent(window_dc, glrc))
        {
            wglChoosePixelFormatARB = (wgl_choose_pixel_format_arb *)wglGetProcAddress("wglChoosePixelFormatARB");
            wglCreateContextAttribsARB = (wgl_create_context_attribs_arb *)wglGetProcAddress("wglCreateContextAttribsARB");
            wglSwapIntervalEXT = (wgl_swap_interval_ext *)wglGetProcAddress("wglSwapIntervalEXT");
            glCreateShader = (gl_create_shader *)wglGetProcAddress("glCreateShader");
            glShaderSource = (gl_shader_source *)wglGetProcAddress("glShaderSource");
            glCompileShader = (gl_compile_shader *)wglGetProcAddress("glCompileShader");
            glCreateProgram = (gl_create_program *)wglGetProcAddress("glCreateProgram");
            glAttachShader = (gl_attach_shader *)wglGetProcAddress("glAttachShader");
            glLinkProgram = (gl_link_program *)wglGetProcAddress("glLinkProgram");
            glDeleteShader = (gl_delete_shader *)wglGetProcAddress("glDeleteShader");
            glGenVertexArrays = (gl_gen_vertex_arrays *)wglGetProcAddress("glGenVertexArrays");
            glGenBuffers = (gl_gen_buffers *)wglGetProcAddress("glGenBuffers");
            glBindVertexArray = (gl_bind_vertex_array *)wglGetProcAddress("glBindVertexArray");
            glBindBuffer = (gl_bind_buffer *)wglGetProcAddress("glBindBuffer");
            glBufferData = (gl_buffer_data *)wglGetProcAddress("glBufferData");
            glVertexAttribPointer = (gl_vertex_attrib_pointer *)wglGetProcAddress("glVertexAttribPointer");
            glEnableVertexAttribArray = (gl_enable_vertex_attrib_array *)wglGetProcAddress("glEnableVertexAttribArray");
            glUseProgram = (gl_use_program *)wglGetProcAddress("glUseProgram");
            glBindFramebuffer = (gl_bind_frame_buffer *)wglGetProcAddress("glBindFramebuffer");
            glGenFramebuffers = (gl_gen_frame_buffers *)wglGetProcAddress("glGenFramebuffers");
            glGenRenderbuffers = (gl_gen_render_buffers *)wglGetProcAddress("glGenRenderbuffers");
            glGetShaderiv = (gl_get_shader_iv *)wglGetProcAddress("glGetShaderiv");
            
            if(!glGetShaderiv) OutputDebugStringA("glGetShaderiv\n");
            if(!glGenRenderbuffers) OutputDebugStringA("glGenRenderbuffers\n");
            if(!glGenFramebuffers) OutputDebugStringA("glGenFramebuffers\n");
            if(!glBindFramebuffer) OutputDebugStringA("glBindFramebuffer\n");
            if(!glUseProgram) OutputDebugStringA("glUseProgram\n");
            if(!glEnableVertexAttribArray) OutputDebugStringA("glEnableVertexAttribArray\n");
            if(!glVertexAttribPointer) OutputDebugStringA("glVertexAttribPointer\n");
            if(!glBufferData) OutputDebugStringA("glBufferData\n");
            if(!glBindBuffer) OutputDebugStringA("glBindBuffer\n");
            if(!glBindVertexArray) OutputDebugStringA("glBindVertexArray\n");
            if(!glGenBuffers) OutputDebugStringA("glGenBuffers\n");
            if(!glGenVertexArrays) OutputDebugStringA("glGenVertexArrays\n");
            if(!glDeleteShader) OutputDebugStringA("glDeleteShader\n");
            if(!glLinkProgram) OutputDebugStringA("glLinkProgram\n");
            if(!glAttachShader) OutputDebugStringA("glAttachShader\n");
            if(!glCreateShader) OutputDebugStringA("glCreateShader\n");
            if(!glCompileShader) OutputDebugStringA("glCompileShader\n");
            if(!glShaderSource) OutputDebugStringA("glShaderSource\n");
            if(!glCreateShader) OutputDebugStringA("glCreateShader\n");
            if(!wglSwapIntervalEXT) OutputDebugStringA("wglSwapIntervalEXT\n");
            if(!wglCreateContextAttribsARB) OutputDebugStringA("wglCreateContextAttribsARB\n");
            if(!wglChoosePixelFormatARB) OutputDebugStringA("wglChoosePixelFormatARB\n");
            
            wglMakeCurrent(0, 0);
        }
        
        wglDeleteContext(glrc);
        ReleaseDC(temporary_window, window_dc);
        DestroyWindow(temporary_window);
    }
}

internal void
Win32SetupPixelFormat(HDC window_dc)
{
    int format_index = 0;
    UINT extended_pick = 0;
    if(wglChoosePixelFormatARB)
    {
        // NOTE(Luke): We might want to do SRGB. In that case 
        //             WGL_FRAMEBUFFER_SRGB_CAPABLE_ARB is what 
        //             we are looking for.
        int attributes_list[] = {
            WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
            WGL_ACCELERATION_ARB, WGL_FULL_ACCELERATION_ARB,
            WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
            WGL_DOUBLE_BUFFER_ARB, GL_TRUE,
            WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB,
            0
        };
        
        wglChoosePixelFormatARB(window_dc, attributes_list, 0, 1, &format_index, &extended_pick);
    }
    
    if(!extended_pick)
    {
        PIXELFORMATDESCRIPTOR desired_format = {};
        desired_format.nSize = sizeof(desired_format);
        desired_format.nVersion = 1;
        desired_format.iPixelType = PFD_TYPE_RGBA;
        desired_format.dwFlags = PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW | PFD_DOUBLEBUFFER;
        desired_format.cColorBits = 32;
        desired_format.cAlphaBits = 8;
        
        format_index = ChoosePixelFormat(window_dc, &desired_format);
    }
    
    PIXELFORMATDESCRIPTOR received_format;
    SetPixelFormat(window_dc, format_index, &received_format);
}

internal HGLRC
Win32InitOpenGL(HWND window)
{
    HDC window_dc = GetDC(window);
    Win32LoadWGLExtensions();
    Win32SetupPixelFormat(window_dc);
    
    b32 modern_context = true;
    HGLRC glrc = 0;
    int opengl_attributes[] =
    {
        WGL_CONTEXT_MAJOR_VERSION_ARB, 3,
        WGL_CONTEXT_MINOR_VERSION_ARB, 3,
        0,
    };
    
    if(wglCreateContextAttribsARB)
    {
        glrc = wglCreateContextAttribsARB(window_dc, 0, opengl_attributes);
    }
    
    if(!glrc)
    {
        modern_context = false;
        glrc = wglCreateContext(window_dc);
    }
    
    wglMakeCurrent(window_dc, glrc);
    
    ReleaseDC(window, window_dc);
    
    return glrc;
}

LRESULT CALLBACK
Win32MainWindowCallback(HWND window,
                        UINT message,
                        WPARAM wparam,
                        LPARAM lparam)
{
    LRESULT result = DefWindowProcA(window, message, wparam, lparam);
    return result;
}

int WinMain(HINSTANCE instance,
            HINSTANCE prev_instance,
            LPSTR     command_line,
            int       window_size_parameter)
{
    WNDCLASS window_class = {};
    window_class.style = CS_OWNDC|CS_HREDRAW|CS_VREDRAW;
    window_class.lpfnWndProc = Win32MainWindowCallback;
    window_class.hInstance = instance;
    window_class.lpszClassName = "BadTriangleWindowClass";
    
    if(RegisterClassA(&window_class))
    {
        HWND window = CreateWindowEx(0,
                                     window_class.lpszClassName,
                                     "BADTRIANGLE",
                                     WS_OVERLAPPEDWINDOW|WS_VISIBLE,
                                     CW_USEDEFAULT,
                                     CW_USEDEFAULT,
                                     CW_USEDEFAULT,
                                     CW_USEDEFAULT,
                                     0,
                                     0,
                                     instance,
                                     0);
        if(window)
        {
            if(Win32InitOpenGL(window))
            {
                if(!wglGetCurrentContext()) OutputDebugStringA("don't have a context\n");
                OutputDebugStringA((char *)glGetString(GL_VERSION));
                OutputDebugStringA("\n");
                RECT window_rect = {};
                GetWindowRect(window, &window_rect);
                int window_width = window_rect.right - window_rect.left;
                int window_height = window_rect.bottom - window_rect.top;
                if(window_height <= 0 || window_height <= 0) OutputDebugStringA("\nbad\n");
                glViewport(0, 0, window_width, window_height);
                char *vertex_shader_source = "#version 330 core\n"
                    "layout (location = 0) in vec3 aPos;\n"
                    "void main()\n"
                    "{\n"
                    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                    "}\0";
                char *fragment_shader_source = "#version 330 core\n"
                    "out vec4 FragColor;\n"
                    "void main()\n"
                    "{\n"
                    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                    "}\n\0";
                GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
                glShaderSource(vertex_shader, 1, &vertex_shader_source, 0);
                glCompileShader(vertex_shader);
                int success;
                glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
                if(!success)
                {
                    OutputDebugStringA("vertex_shader_failed");
                }
                
                GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
                glShaderSource(fragment_shader, 1, &fragment_shader_source, 0);
                glCompileShader(fragment_shader);
                glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
                if(!success)
                {
                    OutputDebugStringA("compile_shader_failed");
                }
                
                GLuint shader_program = glCreateProgram();
                glAttachShader(shader_program, vertex_shader);
                glAttachShader(shader_program, fragment_shader);
                glLinkProgram(shader_program);
                glDeleteShader(vertex_shader);
                glDeleteShader(fragment_shader);
                f32 vertices[] = {
                    // first triangle
                    -0.9f, -0.5f, 0.0f,  // left 
                    -0.0f, -0.5f, 0.0f,  // right
                    -0.45f, 0.5f, 0.0f  // top 
                };
                if(!glCreateProgram) OutputDebugStringA("failed to load glcreateprogram\n");
                GLuint VBO, VAO;
                glGenVertexArrays(1, &VAO);
                glGenBuffers(1, &VBO);
                glBindVertexArray(VAO);
                glBindBuffer(GL_ARRAY_BUFFER, VBO);
                glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(f32), (void*)0);
                glEnableVertexAttribArray(0);
                glBindBuffer(GL_ARRAY_BUFFER, 0);
                glBindVertexArray(0);
                glClearColor(0.129f, 0.586f, 0.949f, 1.0f); // rgb(33,150,243)
                glClear(GL_COLOR_BUFFER_BIT);
                glUseProgram(shader_program);
                glBindVertexArray(VAO);
                glDrawArrays(GL_TRIANGLES, 0, 3);
                SwapBuffers(GetDC(window));
                Sleep(10000);
            }
        }
    }
}