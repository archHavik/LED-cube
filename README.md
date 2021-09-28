# LED-cube

This is an LED cube! It runs different patterns in a cube of 64 LEDs for aesthetic appeals. It doesn't do anything functional per say, but it does look nice!

The LED cube works on a simple principle. There are 4 layers of 16 LEDs. All LEDs in one layer are connected together via the cathodes (or positive side). This means that if I supply power (+5v) to the layer, and ground one of the anodes of the LEDs, that LED will light up. Thus, by seperating into 4 layers, orienting the LEDs so that the anodes are connected to all the LEDs, and supplying power to one layer and grounding one post at a time, I can light up any single LED in the array. Now, arduino Nanos do not have enough amps to light all the LEDs at once. So, we rapidly turn on and off the LEDs, tricking our eyes into believing that the LEDs are all on, when in fact they are not, only one is.

So, how did I make this thing?

# Components

-4 4x4x1/2" Knotty Alder squares\
2 Arduino Nanos\
1 16x2 LCD\
3 pushbuttons\
Alot of wires\
Solder\
perfboard\

# The Base

First, I created the base for the whole thing. I cut and glued together four 1/2 inch pieces of knotty alder wood. Then I sanded them all down together to create a rough cube shape. I drilled out the bottom to have room for the arduino nanos, and chiselled out where the drill couldn't reach to have some extra space. More holes went into the top for the post wires, and more in the sides for the LCD and buttons. Finally I stained the wood with original stain.

# Wiring/Soldering

To get this to work I had to solder all of the cathodes together on one layer (four layers total), and then solder the anodes of the vertically aligned LEDs together. You can see how I did that in the photos I uploaded.
