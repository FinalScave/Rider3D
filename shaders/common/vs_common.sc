$input a_position, a_texcoord0, a_color0
$output v_texcoord0, v_color0

#include <bgfx_shader.sh>

uniform vec4 u_resolution;

void main()
{
	vec4 new_pos = vec4(a_position.xy * u_resolution.xy, a_position.z, 1.0);
	new_pos = mul(u_modelViewProj, new_pos);
	new_pos.xy = new_pos.xy / u_resolution.xy;
	gl_Position = new_pos;
	v_texcoord0 = a_texcoord0;
    v_color0 = a_color0;
}