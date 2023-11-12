$input v_texcoord0, v_color0

#include <bgfx_shader.sh>

SAMPLER2D(s_texColor, 0);

void main()
{
	vec2 uv = v_texcoord0;
	gl_FragColor = texture2D(s_texColor, uv) * v_color0;

}
