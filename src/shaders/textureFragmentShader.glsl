#version 330 core
in vec2 TexCoord;

uniform vec4 modulate = vec4(1.0, 1.0, 1.0, 1.0);
uniform sampler2D texture1;

void main()
{
    gl_FragColor = texture(texture1, TexCoord) * modulate;
}