$input a_position, a_texcoord0
$output v_texcoord0

#include <bgfx_shader.sh>

uniform mat4 u_transform;
uniform vec4 u_resolution;

void main()
{
	vec4 new_pos = vec4(a_position.xy * u_resolution.xy, a_position.z, 1.0);
	new_pos = u_transform * new_pos;
	new_pos.xy = new_pos.xy / u_resolution.xy;
	gl_Position = new_pos;
	v_texcoord0 = a_texcoord0;
}