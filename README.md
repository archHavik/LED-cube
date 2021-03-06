# LED-cube

This is an LED cube! It runs different patterns in a cube of 64 LEDs for aesthetic appeals. It doesn't do anything functional per say, but it does look nice!

The LED cube works on a simple principle. There are 4 layers of 16 LEDs. All LEDs in one layer are connected together via the cathodes (or positive side). This means that if I supply power (+5v) to the layer, and ground one of the anodes of the LEDs, that LED will light up. Thus, by seperating into 4 layers, orienting the LEDs so that the anodes are connected to all the LEDs, and supplying power to one layer and grounding one post at a time, I can light up any single LED in the array. Now, arduino Nanos do not have enough amps to light all the LEDs at once. So, we rapidly turn on and off the LEDs, tricking our eyes into believing that the LEDs are all on, when in fact they are not, only one is.

# Components

4 4x4x1/2" Knotty Alder squares\
2 Arduino Nanos\
1 16x2 LCD\
3 pushbuttons\
Alot of wires\
Solder\
perfboard

# The Base

First, I created the base for the whole thing. I cut and glued together four 1/2 inch pieces of knotty alder wood. Then I sanded them all down together to create a rough cube shape. I drilled out the bottom to have room for the arduino nanos, and chiselled out where the drill couldn't reach to have some extra space. More holes went into the top for the post wires, and more in the sides for the LCD and buttons. Finally I stained the wood with original stain.

# Wiring/Soldering

To get this to work I had to solder all of the cathodes together on one layer (four layers total), and then solder the anodes of the vertically aligned LEDs together. You can see how I did that in the photos I uploaded. So I pushed wires through the holes I drilled in the base. These I call the posts. I soldered each of these underneath the cube to piece of smaller more flexible wire to solder to the perfboard. Then I hot glued each one in place so that they don't shift. Then, I made a template from a block of wood with 16 holes in it. These holes are the size of the LEDs, so that they could fit in the template while I was soldering all the cathodes together. Once I soldered each of the layers together with the help of the template, I soldered them onto the base, keeping each equidistant.

Once the actual cube was wired, I soldered some flexible wire to each of the lines needed on the buttons and LCD, based on wiring diagrams and experience with simulated programs. I have added pictures from tinkerCad, software that emulates Arduinos. This is where I prototyped everything before creating it in real life.

Because the Arduino Nano powering the LED cube did not have enough ports to handle all of the LEDs at once, I added a shift register. This I also prototyped in tinkerCad first.

# Programming

Programming by far took the longest amount of time and energy. You can see my INO files. There are some intense calculations used to power each LED, especially with the added complication of the shift register. On top of that, I had to put the LCD on upside down, and the only way to use it upside down is to create custom upside down characters, and place them in manually. Lots of extra work. But here it is!! I did lots of prototyping on tinkerCad before creating it in the real world, even for programming! And as always, about 75 percent of the time creating this was spent debugging.

I uploaded LCD.ino to the arduino controlling the LCD, and I uploaded the rest to the other Arduino. If you have them in the same directory, the arduino IDE combines them into one file to upload.

Thanks for coming, and enjoy!

Here are some helpful websites:

https://www.arduino.cc/en/Tutorial/LibraryExamples/HelloWorld

https://lastminuteengineers.com/74hc595-shift-register-arduino-tutorial/

https://www.arduino.cc/en/Tutorial/Foundations/ShiftOut

https://www.youtube.com/watch?v=2BlVUKW5hL0
