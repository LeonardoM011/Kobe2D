#shader VERTEX_SHADER

#version 330 core

layout(location = 0) in vec2 position;
layout(location = 1) in vec2 texCoords;

out vec2 out_texCoords;

uniform mat4 u_MVP;

void main() {
	out_texCoords = texCoords;
	gl_Position = u_MVP * vec4(position, 0.0, 1.0);
}

#shader FRAGMENT_SHADER

#version 330 core

in vec2 out_texCoords;

layout(location = 0) out vec4 color;

uniform sampler2D u_Texture;

void main() {
	vec4 texColor = texture(u_Texture, out_texCoords);
	color = texColor;
}
