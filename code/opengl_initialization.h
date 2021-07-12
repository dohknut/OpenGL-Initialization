/* date = July 11th 2021 5:53 pm */

#ifndef OPENGL_INITIALIZATION_H
#define OPENGL_INITIALIZATION_H

#define WGL_CONTEXT_MAJOR_VERSION_ARB             0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB             0x2092
#define WGL_CONTEXT_LAYER_PLANE_ARB               0x2093
#define WGL_CONTEXT_FLAGS_ARB                     0x2094
#define WGL_CONTEXT_PROFILE_MASK_ARB              0x9126

#define WGL_CONTEXT_DEBUG_BIT_ARB                 0x0001
#define WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB    0x0002

#define WGL_CONTEXT_CORE_PROFILE_BIT_ARB          0x00000001
#define WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB 0x00000002

#define WGL_DRAW_TO_WINDOW_ARB                    0x2001
#define WGL_ACCELERATION_ARB                      0x2003
#define WGL_SUPPORT_OPENGL_ARB                    0x2010
#define WGL_DOUBLE_BUFFER_ARB                     0x2011
#define WGL_PIXEL_TYPE_ARB                        0x2013
#define WGL_COLOR_BITS_ARB                        0x2014

#define WGL_TYPE_RGBA_ARB                         0x202B
#define WGL_FULL_ACCELERATION_ARB                 0x2027

#define WGL_FRAMEBUFFER_SRGB_CAPABLE_ARB          0x20A9

#define WGL_RED_BITS_ARB                          0x2015
#define WGL_GREEN_BITS_ARB                        0x2017
#define WGL_BLUE_BITS_ARB                         0x2019
#define WGL_ALPHA_BITS_ARB                        0x201B
#define WGL_DEPTH_BITS_ARB                        0x2022

#define GL_VERSION                        0x1F02
#define GL_ARRAY_BUFFER                   0x8892
#define GL_STATIC_DRAW                    0x88E4
#define GL_FRAGMENT_SHADER                0x8B30
#define GL_VERTEX_SHADER                  0x8B31
#define GL_COMPILE_STATUS                 0x8B81
#define GL_FRAMEBUFFER                    0x8D40

typedef BOOL WINAPI wgl_choose_pixel_format_arb(HDC hdc,
                                                const int *piAttribIList,
                                                const FLOAT *pfAttribFList,
                                                UINT nMaxFormats,
                                                int *piFormats,
                                                UINT *nNumFormats);
typedef HGLRC WINAPI wgl_create_context_attribs_arb(HDC hDC, HGLRC hShareContext,
                                                    const int *attribList);
typedef BOOL WINAPI wgl_swap_interval_ext(int interval);
typedef GLuint gl_create_shader(GLenum shader_type);
typedef void gl_shader_source(GLuint shader, GLsizei count, char **string, GLint *length);
typedef void gl_compile_shader(GLuint shader);
typedef GLuint gl_create_program();
typedef void gl_attach_shader(GLuint program, GLuint shader);
typedef void gl_link_program(GLuint program);
typedef void gl_delete_shader(GLuint shader);
typedef void gl_gen_vertex_arrays(GLsizei n, GLuint *arrays);
typedef void gl_gen_buffers(GLsizei n, GLuint *buffers);
typedef void gl_bind_vertex_array(GLuint array);
typedef void gl_bind_buffer(GLenum target, GLuint buffer);
typedef void gl_buffer_data(GLenum target, size_t size, GLvoid* data, GLenum usage);
typedef void gl_vertex_attrib_pointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLvoid* pointer);
typedef void gl_enable_vertex_attrib_array(GLuint index);
typedef void gl_use_program(GLuint program);
typedef void gl_bind_frame_buffer(GLenum target, GLuint framebuffer);
typedef void gl_gen_frame_buffers(GLsizei n, GLuint *ids);
typedef void gl_gen_render_buffers(GLsizei n, GLuint *render_buffers);
typedef void gl_get_shader_iv(GLuint shader, GLenum pname, GLint *params);

#endif //OPENGL_INITIALIZATION_H
