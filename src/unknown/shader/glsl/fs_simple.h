
static const unsigned int FS_SIMPLE_LEN = 82;

static const unsigned char FS_SIMPLE[82] =
{
	0x46, 0x53, 0x48, 0x0b, 0xa4, 0x8b, 0xef, 0x49, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x00, // FSH....I......?.
	0x00, 0x00, 0x69, 0x6e, 0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x76, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, // ..in vec4 v_colo
	0x72, 0x30, 0x3b, 0x0a, 0x76, 0x6f, 0x69, 0x64, 0x20, 0x6d, 0x61, 0x69, 0x6e, 0x20, 0x28, 0x29, // r0;.void main ()
	0x0a, 0x7b, 0x0a, 0x20, 0x20, 0x67, 0x6c, 0x5f, 0x46, 0x72, 0x61, 0x67, 0x43, 0x6f, 0x6c, 0x6f, // .{.  gl_FragColo
	0x72, 0x20, 0x3d, 0x20, 0x76, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x3b, 0x0a, 0x7d, 0x0a, // r = v_color0;.}.
	0x0a, 0x00,                                                                                     // ..
};
