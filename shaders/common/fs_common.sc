$input v_texcoord0

#include <bgfx_shader.sh>

SAMPLER2D(s_texColor, 0);

void main()
{
	vec2 uv = v_texcoord0;
	gl_FragColor = texture2D(s_texColor, uv);

}
