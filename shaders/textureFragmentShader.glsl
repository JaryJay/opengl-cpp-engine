#version 330 core
in vec2 TexCoord;

uniform vec4 modulate = vec4(1.0, 1.0, 1.0, 1.0);
uniform sampler2D texture1;
uniform vec2 regionTopLeft = vec2(0.0);
uniform vec2 regionBottomRight = vec2(1.0);

void main()
{
    float sampleX = mix(regionTopLeft.x, regionBottomRight.x, TexCoord.x);
    float sampleY = mix(regionTopLeft.y, regionBottomRight.y, 1 - TexCoord.y);
    gl_FragColor = texture(texture1, vec2(sampleX, sampleY)) * modulate;
}