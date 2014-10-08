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
    r = int(random(0, 255));
    g = int(random(0, 255));
    b = int(random(0, 255));
  }

  //Particle explode
  void run() {
    x = x + xspeed;
    y = y + yspeed;
    z = z + zspeed;
  }

  //Particle display on the screen
  void display() {
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

