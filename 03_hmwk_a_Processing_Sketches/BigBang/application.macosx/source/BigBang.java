import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class BigBang extends PApplet {

int r = 0;
//Define 100 particles in an array;
Particle[] particles = new Particle[200];

public void setup() {
  size(600, 600, P3D);

  //Initialize 1000 particles
  for (int i = 0; i < particles.length; i++) {
    particles[i] = new Particle();
  }
}

public void draw() {
  background(0);
  
  //Make each particle move and display on the screen
  for (int i = 0; i < particles.length; i++ ) { 
    particles[i].run();
    particles[i].display();
  }
  println(frameCount);
  
  if(frameCount >= 200){
 
  stroke(255, 50);
  translate(width/2, height/2, 0);
  rotateX(frameCount * 0.05f);
  rotateY(frameCount * 0.05f);
  //fill(frameCount * 2, 0, 160);
  fill(8,249,229);
  sphereDetail(frameCount / 4);
  
  if(r<100){
    r += 1;
  }
    sphere(r);
  //noStroke();
  //lights();
  //translate(58, 48, 0);
  //sphere(28);
  }
}

//Define a class
class Particle {
  //Define all the properties for each particle
  float x;
  float y;
  float z;
  float xspeed;
  float yspeed;
  float zspeed;
  int radius;
  int r;
  int g;
  int b;

  //Initialize each particle
  Particle() {
    x = width/2;
    y = height/2;
    z = 0;
    xspeed = random(-10, 10);
    yspeed = random(-10, 10);
    zspeed = random(-10, 10);
    radius = 10;
    r = PApplet.parseInt(random(0, 255));
    g = PApplet.parseInt(random(0, 255));
    b = PApplet.parseInt(random(0, 255));
  }

  //Particle explode
  public void run() {
    x = x + xspeed;
    y = y + yspeed;
    z = z + zspeed;
  }

  //Particle display on the screen
  public void display() {
    noStroke();
    fill(255, 255, 255, 100);
    //ellipse(x, y, radius, radius);
    pushMatrix();
    translate(x, y, z);
    lights();
    sphereDetail(20);
    sphere(radius);
    popMatrix();
  }
}

  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "--full-screen", "--bgcolor=#666666", "--stop-color=#cccccc", "BigBang" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
