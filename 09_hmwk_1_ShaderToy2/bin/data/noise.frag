#version 120

uniform vec2 resolution;
uniform float rad;

// Created by inigo quilez - iq/2014
// License Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License.

// The final product of some live coding improv. The process is live narrated in this
// video: https://www.youtube.com/watch?v=0ifChJ0nJfM

void main( void )
{
    vec2 p = gl_FragCoord.xy / resolution.xy;
    vec2 q = p - vec2(0.33,0.7);
    
    vec3 col = mix( vec3(1.0,0.3,0.0), vec3(1.0,0.8,0.3), sqrt(p.y) );
    
    float r = 0.2 + 0.1*cos( atan(q.y,q.x)*10.0 + 20.0*q.x + 1.0);
    col *= smoothstep( r, r+0.01, length( q ) );
    
    //these nums can be turned into variables and modify them in OF
    //r = 0.015;
    r = rad;
    r += 0.002*sin(120.0*q.y);
    r += exp(-40.0*p.y);
    col *= 1.0 - (1.0-smoothstep(r,r+0.002, abs(q.x-0.25*sin(2.0*q.y))))*(1.0-smoothstep(0.0,0.1,q.y));
    
    gl_FragColor = vec4(col,1.0);
}