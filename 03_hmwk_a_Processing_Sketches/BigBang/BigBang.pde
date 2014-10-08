int r = 0;
//Define 100 particles in an array;
Particle[] particles = new Particle[200];

void setup() {
  size(600, 600);

  //Initialize 1000 particles
  for (int i = 0; i < particles.length; i++) {
    particles[i] = new Particle();
  }
}

void draw() {
  background(0);
 
  //Make each particle move and display on the screen
  for (int i = 0; i < particles.length; i++ ) { 
    particles[i].run();
    particles[i].display();
  }

}

