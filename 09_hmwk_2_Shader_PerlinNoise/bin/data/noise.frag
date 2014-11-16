#version 120

uniform vec2 resolution;
uniform float time;

//https://www.shadertoy.com/view/XsB3zW


float snoise(vec3 uv, float res)
{
    const vec3 s = vec3(1e0, 1e2, 1e3);
    
    uv *= res;
    
    vec3 uv0 = floor(mod(uv, res))*s;
    vec3 uv1 = floor(mod(uv+vec3(1.), res))*s;
    
    vec3 f = fract(uv); f = f*f*(3.0-2.0*f);
    
    vec4 v = vec4(uv0.x+uv0.y+uv0.z, uv1.x+uv0.y+uv0.z,
                  uv0.x+uv1.y+uv0.z, uv1.x+uv1.y+uv0.z);
    
    vec4 r = fract(sin(v*1e-1)*1e3);
    float r0 = mix(mix(r.x, r.y, f.x), mix(r.z, r.w, f.x), f.y);
    
    r = fract(sin((v + uv1.z - uv0.z)*1e-1)*1e3);
    float r1 = mix(mix(r.x, r.y, f.x), mix(r.z, r.w, f.x), f.y);
    
    return mix(r0, r1, f.z)*2.-1.;
}


void main(void)
{
    
    vec2 uv = gl_FragCoord.xy / resolution.xy;
    float pnoise = 0.5 * snoise(vec3(time, 1.0, uv.x), 10.0);
    
    uv.y += pnoise;
    
    //get the colour
    float xCol = (uv.x - (time / 8.0)) * 3.0;
    xCol = mod(xCol, 3.0);
    vec3 horColour = vec3(0.25, 0.25, 0.25);
    
    if (xCol < 1.0) {
        
        horColour.r += 1.0 - xCol;
        horColour.g += xCol;
    }
    else if (xCol < 2.0) {
        
        xCol -= 1.0;
        horColour.g += 1.0 - xCol;
        horColour.b += xCol;
    }
    else {
        
        xCol -= 2.0;
        horColour.b += 1.0 - xCol;
        horColour.r += xCol;
    }
    
    //background lines
    float backValue = 1.0;
    float aspect = resolution.x / resolution.y;
    if (mod(uv.y * 100.0, 1.0) > 0.75 || mod(uv.x * 100.0 * aspect, 1.0) > 0.75) {
        
        backValue = 1.15;
    }
    
    vec3 backLines  = vec3(backValue);
    
    //main beam
    uv = (2.0 * uv) - 1.0;
    float beamWidth = abs(1.0 / (30.0 * uv.y));
    vec3 horBeam = vec3(beamWidth);
    
    gl_FragColor = vec4(((backLines * horBeam) * horColour), 1.0);
    
    
}

