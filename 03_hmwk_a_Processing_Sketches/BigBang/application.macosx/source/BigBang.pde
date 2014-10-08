int r = 0;
//Define 100 particles in an array;
Particle[] particles = new Particle[200];

void setup() {
  size(600, 600, P3D);

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
  println(frameCount);
  
  if(frameCount >= 200){
 
  stroke(255, 50);
  translate(width/2, height/2, 0);
  rotateX(frameCount * 0.05);
  rotateY(frameCount * 0.05);
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

