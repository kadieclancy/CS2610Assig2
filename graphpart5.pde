
  import processing.serial.*;

  Serial myPort;        // The serial port
  int xPos = 1;         // horizontal position of the graph
  float inByte = 0;
  float sensors[] = new float[3];

  void setup () {
    // set the window size:
    size(400, 300);

    // List all the available serial ports
    println(Serial.list());

    myPort = new Serial(this, "/dev/cu.usbmodem1421", 9600);

    // don't generate a serialEvent() unless you get a newline character:
    myPort.bufferUntil('\n');

    // set initial background:
    background(1);
  }

  void draw () {
    // draw the line for photocell --> purple
    stroke(127, 34, 255);
    line(xPos, height, xPos, height - sensors[0]);
    
    // draw the line for force sensor 1 --> orange
    stroke(204, 102, 0);
    line(xPos, height, xPos, height - sensors[1]);
    
    // draw the line for force sensor 2 --> blue
    stroke(50, 34, 200);
    line(xPos, height, xPos, height - sensors[2]);

    // at the edge of the screen, go back to the beginning:
    if (xPos >= width) {
      xPos = 0;
      background(1);
    } else {
      // increment the horizontal position:
      xPos++;
    }
  }

  void serialEvent (Serial myPort) {
    // get the ASCII string:
    String inString = myPort.readStringUntil('\n');

    if (inString != null) {
      // trim off any whitespace:
      inString = trim(inString);
      
      // split the string at the tabs and convert the sections into integers:
      int mysensors[] = int(split(inString, '\t'));
      int count = mysensors.length;
 
      for (int i=0; i<count; i++)
      {
        // convert to float and map to the screen height:
        inByte = float(mysensors[i]);
        // print out the values we got:
        print(i + ": " + sensors[i] + "\t");
        
        // set sensor[i] value for use in draw() based on ratio
        if (i == 0){
          sensors[i] = map(int(inByte), 940, 1030, 0, height);
        }
        if (i == 1){
          sensors[i] = map(int(inByte), 0, 200, 0, height);
        }
        if (i == 2){
          sensors[i] = map(int(inByte), 0, 2000, 0, height);
        }
        
      }
      println();
    }
  }
