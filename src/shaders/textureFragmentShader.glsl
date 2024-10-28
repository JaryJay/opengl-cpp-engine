#version 330 core
in vec2 TexCoord;

uniform vec4 modulateColor;
uniform sampler2D texture1;

void main()
{
    gl_FragColor  = texture(texture1, TexCoord) * modulateColor;
}